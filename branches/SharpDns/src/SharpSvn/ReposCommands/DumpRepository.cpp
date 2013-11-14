// $Id: SvnRepositoryClient.cpp 300 2008-02-20 11:16:38Z bhuijben $
// Copyright (c) SharpSvn Project 2007
// The Sourcecode of this project is available under the Apache 2.0 license
// Please read the SharpSvnLicense.txt file for more details

#include "stdafx.h"
#include "SvnAll.h"

#include "SvnStreamWrapper.h"
#include "ReposArgs/DumpRepository.h"

#include "UnmanagedStructs.h" // Resolves linker warnings for opaque types

using namespace System::IO;
using namespace SharpSvn;
using namespace SharpSvn::Implementation;

bool SvnRepositoryClient::DumpRepository(String^ repositoryPath, Stream^ to)
{
	if (String::IsNullOrEmpty(repositoryPath))
		throw gcnew ArgumentNullException("repositoryPath");
	else if (!to)
		throw gcnew ArgumentNullException("to");

	return DumpRepository(repositoryPath, to, gcnew SvnDumpRepositoryArgs());
}

static void
warning_func(void *baton, svn_error_t *err)
{
	/* NOOP: Default handler aborts */
	UNUSED_ALWAYS(baton);
	UNUSED_ALWAYS(err);
}

/* Set *REVNUM to the revision specified by REVISION (or to
SVN_INVALID_REVNUM if that has the type 'unspecified'),
possibly making use of the YOUNGEST revision number in REPOS. */
static svn_error_t *
get_revnum(svn_revnum_t *revnum, const svn_opt_revision_t *revision,
		   svn_revnum_t youngest, svn_repos_t *repos, apr_pool_t *pool)
{
	if (revision->kind == svn_opt_revision_number)
		*revnum = revision->value.number;
	else if (revision->kind == svn_opt_revision_head)
		*revnum = youngest;
	else if (revision->kind == svn_opt_revision_date)
	{
		svn_error_t* r = svn_repos_dated_revision(revnum, repos, revision->value.date, pool);

		if(r)
			return r;
	}
	else if (revision->kind == svn_opt_revision_unspecified)
		*revnum = SVN_INVALID_REVNUM;
	else
		return svn_error_create(SVN_ERR_CL_ARG_PARSING_ERROR, NULL, "Invalid revision specifier");

	if (*revnum > youngest)
		return svn_error_createf
		(SVN_ERR_CL_ARG_PARSING_ERROR, NULL, "Revisions must not be greater than the youngest revision (%ld)",
		youngest);

	return SVN_NO_ERROR;
}

bool SvnRepositoryClient::DumpRepository(String^ repositoryPath, Stream^ to, SvnDumpRepositoryArgs^ args)
{
	if (String::IsNullOrEmpty(repositoryPath))
		throw gcnew ArgumentNullException("repositoryPath");
	else if (!to)
		throw gcnew ArgumentNullException("to");
	else if (!args)
		throw gcnew ArgumentNullException("args");
	else if (!IsNotUri(repositoryPath))
		throw gcnew ArgumentException(SharpSvnStrings::ArgumentMustBeAPathNotAUri, "repositoryPath");

	EnsureState(SvnContextState::ConfigLoaded);
	ArgsStore store(this, args);
	AprPool pool(%_pool);

	// based on subversion/svnadmin/main.c:

	svn_repos_t* repos = nullptr;
	svn_error_t* r;
	svn_revnum_t youngest;

	if(r = svn_repos_open(&repos, pool.AllocPath(repositoryPath), pool.Handle))
		return args->HandleResult(this, r);

	svn_fs_t *fs = svn_repos_fs(repos); // Always ok

	// Set a simple warning handler (see subversion/svnadmin/main.c:open_repos), otherwise we might abort()
	svn_fs_set_warning_func(svn_repos_fs(repos), warning_func, nullptr);

	r = svn_fs_youngest_rev(&youngest, fs, pool.Handle);
	if(!r)
		return args->HandleResult(this, r);

	svn_revnum_t start;
	svn_revnum_t end;

	r = get_revnum(&start, args->Start->Or(SvnRevision::Zero)->AllocSvnRevision(%pool), youngest, repos, pool.Handle);
	if(!r)
		return args->HandleResult(this, r);
	r = get_revnum(&end, args->End->Or(SvnRevision::Head)->AllocSvnRevision(%pool), youngest, repos, pool.Handle);
	if(!r)
		return args->HandleResult(this, r);

	if(start < end)
		return args->HandleResult(this, svn_error_create(SVN_ERR_CL_ARG_PARSING_ERROR, NULL, "First revision cannot be higher than second"));

	MemoryStream^ strResult = gcnew MemoryStream();
	SvnStreamWrapper strmTo(to, false, true, %pool);
	SvnStreamWrapper strmResponse(strResult, false, true, %pool);

	r = svn_repos_dump_fs2(
		repos, 
		strmTo.Handle, 
		strmResponse.Handle,
		start,
		end,
		args->Incremental,
		args->Deltas,
		nullptr,
		nullptr,
		pool.Handle);
	
	return args->HandleResult(this, r);
}
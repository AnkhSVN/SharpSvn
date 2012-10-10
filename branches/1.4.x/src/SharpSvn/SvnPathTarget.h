
#pragma once

#include "SvnTarget.h"

namespace SharpSvn {
	using namespace System;

	public ref class SvnPathTarget sealed : public SvnTarget
	{
		String^ _path;
		String^ _fullPath;

		String^ GetFullPath(String ^path)
		{
			return System::IO::Path::GetFullPath(path)->Replace(System::IO::Path::DirectorySeparatorChar, '/');
		}

	public:
		SvnPathTarget(String^ path, SvnRevision^ revision)
			: SvnTarget(revision)
		{
			if(String::IsNullOrEmpty(path))
				throw gcnew ArgumentNullException("path");

			_path = path;
			_fullPath = GetFullPath(path);
		}

		SvnPathTarget(String^ path)
			: SvnTarget(SvnRevision::None)
		{
			if(String::IsNullOrEmpty(path))
				throw gcnew ArgumentNullException("path");

			_path = path;
			_fullPath = GetFullPath(path);
		}

		SvnPathTarget(String^ path, long revision)
			: SvnTarget(gcnew SvnRevision(revision))
		{
			if(String::IsNullOrEmpty(path))
				throw gcnew ArgumentNullException("path");

			_path = path;
			_fullPath = GetFullPath(path);
		}

		SvnPathTarget(String^ path, DateTime date)
			: SvnTarget(gcnew SvnRevision(date))
		{
			if(String::IsNullOrEmpty(path))
				throw gcnew ArgumentNullException("path");

			_path = path;
			_fullPath = GetFullPath(path);
		}

		SvnPathTarget(String^ path, SvnRevisionType type)
			: SvnTarget(gcnew SvnRevision(type))
		{
			if(String::IsNullOrEmpty(path))
				throw gcnew ArgumentNullException("path");

			_path = path;
			_fullPath = GetFullPath(path);
		}

		property String^ TargetName
		{
			virtual String^ get() override
			{
				return _fullPath->Replace(System::IO::Path::DirectorySeparatorChar, '/');
			}
		}

		property String^ Path
		{
			String^ get()
			{
				return _path;
			}
		}

		property String^ FullPath
		{
			String^ get()
			{
				return _fullPath;
			}
		}

	public:
		static bool TryParse(String^ targetString, [Out] SvnPathTarget^% target)
		{
			if(String::IsNullOrEmpty(targetString))
				throw gcnew ArgumentNullException("targetString");

			AprPool ^pool = gcnew AprPool();
			try
			{
				return TryParse(targetString, target, pool);
			}
			finally
			{
				delete pool;
			}
		}

	internal:
		static bool TryParse(String^ targetString, [Out] SvnPathTarget ^% target, AprPool^ pool)
		{
			if(String::IsNullOrEmpty(targetString))
				throw gcnew ArgumentNullException("targetString");
			else if(!pool)
				throw gcnew ArgumentNullException("pool");

			svn_opt_revision_t rev;
			const char* truePath;

			const char* path = pool->AllocPath(targetString);

			if(!svn_opt_parse_path(&rev, &truePath, path, pool->Handle))
			{

				String^ realPath = Utf8_PtrToString(truePath);

				if(!realPath->Contains("://"))
				{
					SvnRevision^ pegRev = SvnRevision::Load(&rev);

					target = gcnew SvnPathTarget(realPath, pegRev);
					return true;
				}

			}

			target = nullptr;
			return false;
		}

	public:
		static SvnPathTarget^ FromString(String^ value);
		static operator SvnPathTarget^(String^ value) { return value ? FromString(value) : nullptr; }
	};
}
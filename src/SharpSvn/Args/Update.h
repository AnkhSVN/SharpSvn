// $Id$
// Copyright (c) SharpSvn Project 2007-2008
// The Sourcecode of this project is available under the Apache 2.0 license
// Please read the SharpSvnLicense.txt file for more details

#pragma once

// Included from SvnClientArgs.h

namespace SharpSvn {

	/// <summary>Extended Parameter container of <see cref="SvnClient::Update(String^, SvnUpdateArgs^)" /></summary>
	/// <threadsafety static="true" instance="false"/>
	public ref class SvnUpdateArgs : public SvnClientArgsWithConflict
	{
		SvnDepth _depth;
		bool _ignoreExternals;
		bool _allowObstructions;
		SvnRevision^ _revision;
		bool _keepDepth;

	public:
		SvnUpdateArgs()
		{
			_depth = SvnDepth::Unknown;
			_revision = SvnRevision::None;
		}

		virtual property SvnClientCommandType ClientCommandType
		{
			virtual SvnClientCommandType get() override sealed
			{
				return SvnClientCommandType::Update;
			}
		}

		/// <summary>Gets or sets the depth of the update</summary>
		/// <remarks>
		/// <para>If Depth is Infinity, update fully recursively. Else if it
		/// is Immediates or Files, update each target and its file
		/// entries, but not its subdirectories.  Else if Empty, update
		/// exactly each target, nonrecursively (essentially, update the
		/// target's properties).</para>
		/// <para>If Depth is Unknown, take the working depth from the specified paths
		/// </para>
		/// </remarks>
		property SvnDepth Depth
		{
			SvnDepth get()
			{
				return _depth;
			}
			void set(SvnDepth value)
			{
				_depth = EnumVerifier::Verify(value);
			}
		}

		/// <summary>
		/// Gets or sets whether in addition to updating paths also the
		/// sticky ambient depth value must be set to depth
		/// </summary>
		property bool KeepDepth
		{
			bool get()
			{
				return _keepDepth;
			}
			void set(bool value)
			{
				_keepDepth = value;
			}
		}

		/// <summary>Gets or sets a value indicating whether to ignore externals
		/// definitions as part of this operation.</summary>
		property bool IgnoreExternals
		{
			bool get()
			{
				return _ignoreExternals;
			}
			void set(bool value)
			{
				_ignoreExternals = value;
			}
		}

		/// <summary>The revision to update to; None by default</summary>
		/// <remarks>
		/// Revision must be of kind Number, Head or Date. If Revision
		/// does not meet these requirements, Updated returns the error
		/// SVN_ERR_CLIENT_BAD_REVISION.
		/// </remarks>
		property SvnRevision^ Revision
		{
			SvnRevision^ get()
			{
				return _revision;
			}
			void set(SvnRevision^ value)
			{
				if (value)
					_revision = value;
				else
					_revision = SvnRevision::None;
			}
		}

		/// <summary>If @a allow_unver_obstructions is <c>true</c> then the update tolerates
		/// existing unversioned items that obstruct added paths from @a URL</summary>
		/// <remarks>
		/// Only obstructions of the same type (file or dir) as the added item are
		/// tolerated.  The text of obstructing files is left as-is, effectively
		/// treating it as a user modification after the update.  Working
		/// properties of obstructing items are set equal to the base properties.
		/// If AllowUnversionedObstructions is <c>false</c> then the update will abort
		/// if there are any unversioned obstructing items.
		/// </remarks>
		property bool AllowObstructions
		{
			bool get()
			{
				return _allowObstructions;
			}
			void set(bool value)
			{
				_allowObstructions = value;
			}
		}
	};

}

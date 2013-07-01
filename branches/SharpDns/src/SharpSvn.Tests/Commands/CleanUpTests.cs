// $Id$
// Copyright (c) SharpSvn Project 2008, Copyright (c) Ankhsvn 2003-2007
using System;
using System.Collections;
using System.IO;
using System.Text.RegularExpressions;
using NUnit.Framework;
using NUnit.Framework.SyntaxHelpers;
using SharpSvn;

namespace SharpSvn.Tests.Commands
{
	/// <summary>
	/// Tests the Client::Cleanup method
	/// </summary>
	[TestFixture]
	public class CleanupTests : TestBase
	{
		[SetUp]
		public override void SetUp()
		{
			base.SetUp();

			this.ExtractWorkingCopy();
		}

		/// <summary>
		/// Test that Client::Cleanup removes the lock file
		/// </summary>
		[Test]
		public void TestRemoveLockFile()
		{
			// From Ankh testcases ;-)
			string lockPath = Path.Combine(this.WcPath, SvnClient.AdministrativeDirectoryName);
			lockPath = Path.Combine(lockPath, "lock");

			File.CreateText(lockPath).Close();

			this.Client.CleanUp(this.WcPath);

			Assert.That(!File.Exists(lockPath),
				"lock file still in place after running Client::Cleanup");
		}

	}
}
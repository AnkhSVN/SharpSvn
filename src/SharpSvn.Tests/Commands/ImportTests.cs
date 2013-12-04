// $Id$
//
// Copyright 2008-2009 The SharpSvn Project
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

// $Id$
// Copyright (c) SharpSvn Project 2008, Copyright (c) Ankhsvn 2003-2007
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using NUnit.Framework;
using SharpSvn;

namespace SharpSvn.Tests.Commands
{
	/// <summary>
	/// Tests for the Client::Import method
	/// </summary>
	[TestFixture]
	public class ImportTests : TestBase
	{
		[SetUp]
		public override void SetUp()
		{
			base.SetUp();
			notifications = new List<SvnNotifyEventArgs>();
		}

		[TearDown]
		public override void TearDown()
		{
			base.TearDown();
		}


		/// <summary>
		/// Tests importing an unverioned file into the repository with the new entry :
		/// testfile2.txt.
		/// </summary>
		[Test]
		public void TestImportFile()
		{
			string truePath = this.CreateTextFile("testfile.txt");
			Uri trueDstUrl = new Uri(ReposUrl, "testfile.txt");

			SvnImportArgs a = new SvnImportArgs();
			a.Depth = SvnDepth.Empty;

			Assert.That(Client.RemoteImport(truePath, trueDstUrl, a));

			String cmd = this.RunCommand("svn", "list " + this.ReposUrl.ToString());
			Assert.That(cmd.IndexOf("testfile.txt") >= 0, "File wasn't imported ");
		}

		/// <summary>
		/// Tests importing an unversioned directory into the repository recursively
		/// with the new entry: newDir2.
		/// </summary>
		[Test]
		public void TestImportDir()
		{
			string dir1, dir2, testFile1, testFile2;
			this.CreateSubdirectories(out dir1, out dir2, out testFile1, out testFile2);

			Uri trueDstUrl = new Uri(ReposUrl + "newDir2/");
			SvnImportArgs a = new SvnImportArgs();
			a.Depth = SvnDepth.Infinity;

			Assert.That(Client.Import(dir1, trueDstUrl, a));

			String cmd = this.RunCommand("svn", "list " + this.ReposUrl);
			Assert.That(cmd.IndexOf("newDir2") >= 0, "File wasn't imported");

		}

		private void CreateSubdirectories(out string dir1, out string dir2, out string testFile1, out string testFile2)
		{
			dir1 = Path.Combine(this.WcPath, "subdir");
			Directory.CreateDirectory(dir1);

			dir2 = Path.Combine(dir1, "subsubdir");
			Directory.CreateDirectory(dir2);

			testFile1 = this.CreateTextFile(@"subdir\testfile.txt");
			testFile2 = this.CreateTextFile(@"subdir\subsubdir\testfile2.txt");
		}
	}

}
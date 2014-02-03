﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.34003
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace SharpSvn.UI {
    using System;
    
    
    /// <summary>
    ///   A strongly-typed resource class, for looking up localized strings, etc.
    /// </summary>
    // This class was auto-generated by the StronglyTypedResourceBuilder
    // class via a tool like ResGen or Visual Studio.
    // To add or remove a member, edit your .ResX file then rerun ResGen
    // with the /str option, or rebuild your VS project.
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    internal class Strings {
        
        private static global::System.Resources.ResourceManager resourceMan;
        
        private static global::System.Globalization.CultureInfo resourceCulture;
        
        [global::System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        internal Strings() {
        }
        
        /// <summary>
        ///   Returns the cached ResourceManager instance used by this class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Resources.ResourceManager ResourceManager {
            get {
                if (object.ReferenceEquals(resourceMan, null)) {
                    global::System.Resources.ResourceManager temp = new global::System.Resources.ResourceManager("SharpSvn.UI.Strings", typeof(Strings).Assembly);
                    resourceMan = temp;
                }
                return resourceMan;
            }
        }
        
        /// <summary>
        ///   Overrides the current thread's CurrentUICulture property for all
        ///   resource lookups using this strongly typed resource class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Globalization.CultureInfo Culture {
            get {
                return resourceCulture;
            }
            set {
                resourceCulture = value;
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to A client certificate is required for accessing server {0}..
        /// </summary>
        internal static string ACertificateFileIsRequiredForAccessingServerX {
            get {
                return ResourceManager.GetString("ACertificateFileIsRequiredForAccessingServerX", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to A client certificate is required for accessing server {0} at {1}..
        /// </summary>
        internal static string ACertificateFileIsRequiredForAccessingServerXatY {
            get {
                return ResourceManager.GetString("ACertificateFileIsRequiredForAccessingServerXatY", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Connect to Subversion.
        /// </summary>
        internal static string ConnectToSubversion {
            get {
                return ResourceManager.GetString("ConnectToSubversion", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to WARNING - POTENTIAL SECURITY BREACH!
        ///
        ///The server&apos;s host key does not match what has been cached. This means that either the server administrator has changed the host key, or you have actually connected to another computer pretending to be the server.
        ///
        ///The new {0} key fingerprint is:
        ///{1}
        ///
        ///If you were expecting this change and trust the new key, choose YES.
        ///If you want to carry on connecting but without updating the cache, choose NO.
        ///
        ///If you want to abandon the connection completely, press CANCEL.
        /// [rest of string was truncated]&quot;;.
        /// </summary>
        internal static string SshCertificateMismatch {
            get {
                return ResourceManager.GetString("SshCertificateMismatch", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Update cached host key?.
        /// </summary>
        internal static string SshCertificateMismatchCaption {
            get {
                return ResourceManager.GetString("SshCertificateMismatchCaption", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The server&apos;s host key is not cached in the registry. You have no guarantee that the server is the computer you think it is.
        ///
        ///The server&apos;s {0} key fingerprint is:
        ///{1}
        ///
        ///If you trust this host, choose YES to add the key to the cache and carry on connecting.
        ///If you want to carry on connecting just once, without adding the key to the cache,
        ///choose NO. If you do not want to connect at all, choose Cancel..
        /// </summary>
        internal static string SshCertificateUnknown {
            get {
                return ResourceManager.GetString("SshCertificateUnknown", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to Store key in cache?.
        /// </summary>
        internal static string SshCertificateUnknownCaption {
            get {
                return ResourceManager.GetString("SshCertificateUnknownCaption", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The certificate for server {0} at {1} requires a passphrase..
        /// </summary>
        internal static string ThePassPhraseForTheClientCertificateForXatYIsRequired {
            get {
                return ResourceManager.GetString("ThePassPhraseForTheClientCertificateForXatYIsRequired", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The certificate for server {0} requires a passphrase..
        /// </summary>
        internal static string ThePassPhraseForTheClientCertificateForXIsRequired {
            get {
                return ResourceManager.GetString("ThePassPhraseForTheClientCertificateForXIsRequired", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The server {0} at {1} requires a username..
        /// </summary>
        internal static string TheServerXatYRequiresAUsername {
            get {
                return ResourceManager.GetString("TheServerXatYRequiresAUsername", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The server {0} at {1} requires a username and password..
        /// </summary>
        internal static string TheServerXatYRequiresAUsernameAndPassword {
            get {
                return ResourceManager.GetString("TheServerXatYRequiresAUsernameAndPassword", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The server {0} requires a username..
        /// </summary>
        internal static string TheServerXRequiresAUsername {
            get {
                return ResourceManager.GetString("TheServerXRequiresAUsername", resourceCulture);
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to The server {0} requires a username and password..
        /// </summary>
        internal static string TheServerXRequiresAUsernameAndPassword {
            get {
                return ResourceManager.GetString("TheServerXRequiresAUsernameAndPassword", resourceCulture);
            }
        }
    }
}

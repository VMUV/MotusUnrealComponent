// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

using System.IO; // ToDo: Replace with standard mechenism

public class MotusUnreal : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    //    //        private string ThirdPartyPath
    //   private string Motus1PluginPath
    //    {
    //        //            get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
    //        get { return Path.GetFullPath(Path.Combine(ModulePath, "Plugins/Motus1Plugin/")); }
    //    }

    public MotusUnreal(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

        LoadYourThirdPartyLibraries(Target);
    }

    public bool LoadYourThirdPartyLibraries(ReadOnlyTargetRules Target)
    {
        bool isLibrarySupported = false;

        // This will give oyu a relitive path to the module ../PseudoController/
        //            string ModulePath = Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name));
        string ModulePath = ModuleDirectory;
        // This will give you a relative path to ../PseudoController/ThirdParty/"LibraryDirName"/
        string MyLibraryPath = Path.Combine(ModulePath, "MotusComponent", "Libraries");
        //    string MyThirdPartyPath = Path.Combine(ModulePath, "ThirdParty");

        // Use this to keep Win32/Win64/e.t.c. library files in seprate subdirectories
        //            string ArchitecturePath = "";

        // When you are building for Win64
        //            if (Target.Platform == UnrealTargetPlatform.Win64 &&
        //                WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2013)
        //            {
        // We will look for the library in ../PseudoController/ThirdParty/MyLibrary/Win64/VS20##/
        //                ArchitecturePath = Path.Combine("Win64", "VS" + WindowsPlatform.GetVisualStudioCompilerVersionName());

        isLibrarySupported = true;
        //            }
        // When you are building for Win32
        //            else if (Target.Platform == UnrealTargetPlatform.Win32 &&
        //                WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2013)
        //            {
        // We will look for the library in ../PseudoController/ThirdParty/MyLibrary/Win32/VS20##/
        //                ArchitecturePath = Path.Combine("Win32", "VS" + WindowsPlatform.GetVisualStudioCompilerVersionName());

        //                isLibrarySupported = true;
        //            }
        // Add mac/linux/mobile support in much the same way

        // If the current build architecture was supported by the above if statements
        //            if (isLibrarySupported)
        //            {
        // Add the architecture spacific path to the library files
        //                PublicAdditionalLibraries.Add(Path.Combine(MyLibraryPath, "lib", ArchitecturePath, "MyLibrary.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(MyLibraryPath, "VMUV TCP Cpp.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(MyLibraryPath, "Trace Logger Cpp.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(MyLibraryPath, "Comms Protocol Cpp.lib"));

        // Add a more generic path to the include header files
        //            PublicIncludePaths.Add(Path.Combine(ModulePath, "../ThirdParty/Includes"));
        //                        PublicIncludePaths.Add("../ThirdParty/Includes");
        //            }

        // Defination lets us know whether we successfully found our library!
        Definitions.Add(string.Format("WITH_MY_LIBRARY_PATH_USE={0}", isLibrarySupported ? 1 : 0));

        return isLibrarySupported;
    }
}

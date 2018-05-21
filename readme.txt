Motus Unreal Engine Component Guide

Proceedure for checking out and running the Motus Unreal Engine Component.

This assumes that you have both Unreal Engine 4.18.0 and Visual Studio 2017 installed.

1. open Epic Games Launcher
2. click "Launch" button to open Unreal Editor Project Browser
3. click "New Project" tab
4. click "C++" tab to see C++ templates
5. select "First Person" template
6. we are using "Desktop/Console", "Maximum Quality", and "No Starter Content"
7. Type in project name: "MotusUnrealProject"
8. click "Create Project" button
9. both visual studio and the UE editor will open
10. in visual studio, do "Save All", then close visual studio
11. in UE editor, click "Play" to verify project functions. "Esc" to exit.

12. in UE Content Browser, click icon left of the "Filters" drop down box, to show the sources panel.
13. in the sources panel, expand the node "FirstPersonCPP" and click on "Blueprints"
14. double click the icon labeled "FirstPersonCharacter" in the right panel. This will open the blueprints editor.
15. in the blueprint editor, at the top of the "Class Defaults" panel, there is a blue link with the text "Open Full Blueprint Editor". Click it.
16. in the left pane, under the "Components" tab, there is a green button labeled "Add Component". click it.
17. click "New C++ Component...". This will open the "Add C++ Component" dialog, asking you to choose a parent class.
18. Hilight "Actor Component", then click Next
19. A dialog will open allowing you to name your component. In the "Path" text box of that dialog, add the text "MotusUnrealComponent/" to the path shown.
20. in the "Name" text box, replace the name with "MotusUnrealComponent". Click the green "Create Class" button
21. after creating and compiling the component, Visual Studio will open.
22. in UE blueprint editor, click "Compile" then "Save", then close the blueprint editor
23. in UE main editor, invoke File Save All, then close UE.
24. in VS invoke the "Build - Rebuild Solution" menu command.
25. after VS rebuilds the solution, close VS
26. relaunch UE and open the MotusUnrealProject project by double clicking on it's icon.
27. in UE, invoke the "File Open Visual Studio" menu command. VS should open.

 ... close UE and VS

note: these previous steps seem redundant, but there are issues with UE and VS related to which application has ownership of the project. Following these steps avoids encountering those issues, and verifies that everything is stable before proceeding.

28. open a File Explorer window, go to ".../Unreal Projects/MotusUnrealProject/Source/MotusUnrealProject"
29. delete the MotusUnrealComponent directory
30. start Git Bash, cd to ".../Unreal Projects/MotusUnrealProject/Source/MotusUnrealProject"
31. in Git Bash, type "git clone -b issue-1 git@github.com:VMUV/MotusUnrealComponent.git" to clone the MotusUnrealComponent repository from the issue-1 branch
32. back in the File Explorer window, replace the "MotusUnrealProject.Build.cs" file in the ".../Unreal Projects/MotusUnrealProject/Source/MotusUnrealProject" directory with the file of the same name in the ".../Unreal Projects/MotusUnrealProject/Source/MotusUnrealProject/MotusUnrealComponent" directory.

33. Relaunch the "MotusUnrealProject" project in Unreal Engine
34. in UE, invoke the "File Open Visual Studio" menu command. VS should open.
35. in VS invoke the "Build - Rebuild Solution" menu command.

36. open a DOS command prompt, and cd to the following directory:
	".../Unreal Projects/MotusUnrealProject/Source/MotusUnrealProject/MotusUnrealComponent/Executables"
37. start the motus test server by typing "TestServer -m". The command prompt window will display a few messages then stop - waiting for a client to connect.
38. In UE, click the Play button. You should see the command prompt displaying messages contineously, whilt the first person in UE starts moving in a circle. notice that it moves 8 times then pauses, then repeats. this is because the test server is emulating pressure on each of the platform pads (plus contineous pressure on the center pad). The pause is when only the center pad is getting pressure.
39. press the escape key to stop UE from executing the project. The test server detects the socket being closed so also terminates.
40. thats it!


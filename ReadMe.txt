========================================================================
       MICROSOFT FOUNDATION CLASS Library: JoyBricx
========================================================================

An application for remotely controlling Lego IR-controllable devices such as the RCX,
Spybot, and Bionicle RC Fighter via a Lego IR tower using a joystick or game pad.

Project Information
    Original Project Web Page – https://line.to/mac/MindStorms/JoyBricx/index-e.html
    Related TowerAPI Web Page – https://line.to/mac/MindStorms/LTremo76/

    File translated from the Japanese-language ReadMe via Google Translate


AppWizard-generated JoyBricx includes basic Microsoft Foundation Class
The usage is shown. Please use it as a template for creating applications.

This file contains a brief description of each of the files that make up JoyBricx.

JoyBricx.dsp
    This file (the project file) contains project-level information,
    Used to build a single project or subproject. other
    You can share project files (.dsp) with users, but make files
    Please export locally.

JoyBricx.h
    This file is the main include file for the application. this
    The file must be a unique include file for another project (including Resource.h).
    ) And declare the CJoyBricxApp application class.
    Say

JoyBricx.cpp
    This file is the application containing the CJoyBricxApp application class
    This is the main source file for.

JoyBricx.rc
    This file lists the Microsoft Windows resources used by the program.
    You. This file contains icons and bitmaps stored in the RES subdirectory.
    Includes top and cursor. This file is directly in Microsoft Visual C ++
    Can be edited.

JoyBricx.clw
    This file is used when ClassWizard edits an existing class or creates a new class.
    I have information to use when This file is also used by ClassWizard
    Edit and generate data maps and dialog data maps, and
    It also has the information needed to generate numbers.

res \ JoyBricx.ico
    This file contains the icon files used as application icons.
    Is This icon is included by the resource file JoyBricx.rc
    Will be

res \ JoyBricx.rc2
    This file contains resources that are not edited by Microsoft Visual C ++.
    You. This file describes all resources not edited by the resource editor
    please.




//////////////////////////////////////////////////////////////////////////////

AppWizard creates one dialog class:

JoyBricxDlg.h, JoyBricxDlg.cpp-dialog
    These files contain the CJoyBricxDlg class. This class is
    Defines the behavior of the main dialog of the application. dialog
    The template is included in JoyBricx.rc, which can be edited with Microsoft Visual C ++.
    Rare.


//////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are precompiled header files (PCH) JoyBricx.pch
    This file is used to build the precompiled type file StdAfx.obj.

Resource.h
    This file is a standard header file that defines new resource IDs.
    Microsoft Visual C ++ reads and updates this file.

//////////////////////////////////////////////////////////////////////////////
Other notes:

Comments beginning with "TODO:" indicate where source code needs to be added or customized.
To do.

If your application uses MFC in a shared DLL,
If you ’re using a language other than the language your operating system currently uses,
Serve localized resources from Microsoft Visual C ++ CD-ROM
Copy MFC42XXX.DLL to the system or system32 directory and rename the file.
MFC42LOC.DLL should be. ("XXX" stands for language abbreviation. For example,
MFC42JPN.DLL contains Japanese translated resources. )
Otherwise, some UI elements in the application will not operate.
It will remain in the rating system language.

//////////////////////////////////////////////////////////////////////////////

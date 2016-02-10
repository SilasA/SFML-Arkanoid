========================================================================
    CONSOLE APPLICATION : CACC-SFML Project Overview
========================================================================

AppWizard has created this CACC-SFML application for you.

This file contains a summary of what you will find in each of the files that
make up your CACC-SFML application.


CACC-SFML.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

CACC-SFML.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

CACC-SFML.cpp
    This is the main application source file.  It calls the menu window and then the game
	window.

Game.h, Game.cpp
	This the main code that maintains the game.  It creates the game objects according to
	to the specified parameters in GameConfig.h.  It maintains the game by testing collisions
	and updating object positions accordingly.

MainMenu.h, MainMenu.cpp
	This is the main menu that prompts the user when the application is executed.  It contains 
	buttons for the user to decide what they would like to do.  The Up and Down keys are used to
	control the selection process.

Button.h, Button.cpp
	This is the file that defines the button objects that make up the main menu.  The buttons
	are made up of a sprite that changes background color based on if the button is selected.  

Rectangle.h
	This is the base class for the Paddle and Brick objects.  It contains specific button position
	finding, the base shape, and the color.

Paddle.h, Paddle.cpp
	This contains the Paddle object and its methods maintain it throught the game.

GameConfig.h
	This class contains game mechanic and configuration variables.

Brick.h, Brick.cpp
	This contains the Brick objects that make up what the user must destroy.

Ball.h
	This contains the ball object that the user is to bounce around.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named CACC-SFML.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

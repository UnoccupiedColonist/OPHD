# OutpostHD Readme
OutpostHD is a remake of the original Outpost published by Siera On-Line in 1994. It is not a clone. It is complete redesign of the game taking the core concepts and build the game that Outpost should have been.

For up to the minute information, please visit The Outpost Universe's [online forum](http://forum.outpost2.net). You may also view [OutpostHD's Forum Thread](http://forum.outpost2.net/index.php/topic,5718.0.html) for additional details or to participate in the discussion.

## Requirements
*For Windows*

* Windows 7 (not tested on Vista or XP)
* 2GB RAM
* 5MB Available Hard Drive Space
* Graphics card that can support OpenGL 3.0 & GLSL v1.0 (basically any modern non-Intel GPU)

## Installation
Installation is simple: Extract the contents of the ZIP Archive into any folder. Double-click on OPHD.exe to launch the game.

As this is not an installer package it is not distributed with any necessary dependencies. Please see the following sections for the requirements needed for your particular OS of choice.

### Windows Dependencies
OutpostHD is built using Microsoft's Visual C++ 2015. If you haven't already, you may need to download and install the redistributable package from Microsoft. Follow this link and download the 32-Bit version of the Visual C++ runtime:

https://www.microsoft.com/en-us/download/details.aspx?id=48145

### MacOS X Dependencies
The only current build of OutpostHD is Windows but as I understand MacOS X development and program distribution, MacOS distributions come as a 'bundle' with all necessary dependencies packaged in.

### Linux
The only current build of OutpostHD is Windows but should, with a few minor modifications to some of its underlying libraries, build a run on Linux. As I have no experience with Linux and providing prebuilt binaries for said system, any and all libraries that OutpostHD links against will need to be installed. In the past I had to do this manually so you may need to as well.

See your distribution's readme files for information on how to download and install the necessary dependencies.

## Configuration
At the moment there are very few configurable options for OutpostHD. All of it must be done via the XML configuration file (config.xml) located in the 'data' subdirectory.

Please use SANE values as there is no sanity checking except for minimum resolution (800x600). You can set the video resolution to whatever you want but if your monitor or graphics card doesn't support it don't expect things to work.

When OutpostHD first starts it will start in full screen mode in the native resolution of your desktop. After the first time you run the game, a configuration file will be saved. From there you can change your video resolution and whether or not you want to skip the splash screen.

## Troubleshooting
OutpostHD is in an early state of development so there's not much to say other than make sure you have the latest graphics drivers. Head on over to [the forums](http://forum.outpost2.net) for help getting OutpostHD running if you run into trouble.

## Key Bindings

F2: Save Game

F3: Load Game

F10: Show debug info

F11: Toggle fullscreen/windowed mode

PAGE UP: Go up one level

PAGE DOWN: Go down one level

HOME: Go to surface

END: Go to max depth level

ENTER: End turn

ESCAPE: Cancel edit mode.

W / A / S / D: Move one tile UP / LEFT / DOWN / RIGHT

ARROWS: Same as WASD

0: Go to Surface

1: Go to Underground 1

2: Go to Underground 2

3: Go to Underground 3

4: Go to Underground 4

## FAQ
**Q: When I try to launch OutpostHD, I'm told that I'm missing "msvcp140.dll" and "vcruntime140.dll". How do I fix this?**

A: You are missing some dependencies that OutpostHD requires in order to run. See the section '[Windows Dependencies](#3)' above.

**Q: How do I get started?**

A: When you first start the game, the only structure available to you is the SEED Lander which can be found in the Structure Panel at the bottom left of the screen. When you select the SEED Lander from the panel, the mouse pointer will change to the diamond shaped 'place structure' pointer. Left click anywhere you think is a suitable landing location.

Keep in mind that the SEED Lander can't be placed within 3 tiles of any of the edges of the map and must have all tiles surrounding it be free of obstructions like Mines and Impassable Terrain.

After you place the SEED Lander, the Advance Turn button will become available to click on (you must place a SEED Lander before you can do anything else). After you left click on the Advance Turn button, other options will become available to you and the first structures of your colony will be built.

**Q: How can I lower the resolution or turn off fullscreen mode? **

A: By default OutpostHD sets itself to the native screen resolution of your desktop with a minimum resolution of 800x600. Eventually you'll be able to make changes in the game via an options menu but for now if you want to change the resolution you can open "data/config.xml" and modify the screenwidth and screenheight values. There is no sanity checking so set this to a sane value or you could get weird behavior including crashing.

To turn off fullscreen mode, simply change 'fullscreen="true"' to 'fullscreen="false"'.

**Q: Can I automatically skip the splash/logo screens?**

A: Yes. After the first time the game runs, an automatically generated configuration file is saved in the 'data' folder. Open this file in a text editor, look for the line that says 'skip-splash' and change 'value' from 'false' to 'true'.

**Q: I have a question that's not answered here. How can I get help?**

A: You can visit The Outpost Universe's Forums (http://forum.outpost2.net) and visit the Main Projects forum.

Alternatively, you can hop onto IRC and join OPU's official IRC channel and ask for help there. The lead developer, leeor_net, is often available during the day (US Eastern Time, UTC-5:00). (IRC Server: irc.quakenet.org, channel #Outpost2).

## Maintainers
OutpostHD is developed and maintained by the following contributors:

- Leeor Dicker (aka leeor_net): *Design & Programming*
- Goof: *Programming*
- lhark: *Programming*
- White Claw: *Graphics*
- Hooman: *Design & Programming Assistance*
- Casper van Heck (aka vomov): *Research Tree & Design*
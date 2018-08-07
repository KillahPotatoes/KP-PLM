# KP Player Menu
[![GitHub license](https://img.shields.io/github/license/KillahPotatoes/KP-PLM.svg)](https://github.com/KillahPotatoes/KP-PLM/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/KillahPotatoes/KP-PLM.svg)](https://github.com/KillahPotatoes/KP-PLM/releases)
[![GitHub Release Date](https://img.shields.io/github/release-date/KillahPotatoes/KP-PLM.svg)](https://github.com/KillahPotatoes/KP-PLM/releases)
[![Github All Releases](https://img.shields.io/github/downloads/KillahPotatoes/KP-PLM/total.svg)](https://github.com/KillahPotatoes/KP-PLM)

[![GitHub issues](https://img.shields.io/github/issues-raw/KillahPotatoes/KP-PLM.svg)](https://github.com/KillahPotatoes/KP-PLM/issues)
[![GitHub closed issues](https://img.shields.io/github/issues-closed-raw/KillahPotatoes/KP-PLM.svg)](https://github.com/KillahPotatoes/KP-PLM/issues?q=is%3Aissue+is%3Aclosed)
[![GitHub pull requests](https://img.shields.io/github/issues-pr-raw/KillahPotatoes/KP-PLM.svg)](https://github.com/KillahPotatoes/KP-PLM/pulls)
[![GitHub closed pull requests](https://img.shields.io/github/issues-pr-closed-raw/KillahPotatoes/KP-PLM.svg)](https://github.com/KillahPotatoes/KP-PLM/pulls?q=is%3Apr+is%3Aclosed)

[Discord](https://discord.gg/fjSPn8t)

If you like the work and think it's worth a small donation, feel free to use the following link:

[Donate via paypal.me](https://www.paypal.me/wyqer)

## Description
![plmpreview](https://user-images.githubusercontent.com/3811977/43684198-e4824120-989b-11e8-8261-26332fecd2e4.png)

With this dialog you can give the players of your mp mission the possibility to use their KP Player Menu settings, quality of life functionalities and the own lightweight group management. In the first place this dialog was created for the [KP Liberation Mission](https://github.com/KillahPotatoes/KP-Liberation), but we decided to provide it also as standalone version for other mission creators.

They can adjust their view distances depending if they're on foot, in a ground or air vehicle, as this is capped to 1600m in a normal mp mission, ignoring the players graphic settings. Same goes for the terrain detail, which is normally set to a value of 10 (that's basically between high and very high) in a mp mission by default. Also some new features like auto switch to 3rd person and disable radio chatter of AI units in your squad. As this player menu saves the settings in the player profile, the player will have the same settings on all servers/missions which use this menu. It also supports KP Ranks by providing a small overview about your progress and current state, but KP Ranks isn't needed at all to use the features.

## Features
* A lightweight group management
* Individual view distances
* Change of the terrain detail (like deactivating the grass)
* Automatic 3rd person view switch when entering a vehicle
* AI radio chatter disable (disable just the voice or the voice and chat)
* Adjustment of the in vehicle sound volume
* Persistent settings, which will apply for the player on each server and each mission who uses this menu

## Languages
Currently the mod is localized for:
* English
* German

## Mods
Required:
* [CBA_A3](https://steamcommunity.com/workshop/filedetails/?id=450814997)

## How to use
After downloading the latest release file from the [Releases Tab](https://github.com/KillahPotatoes/KP-PLM/releases) and extracting the rar archive you have to move the folders `KPGUI` and `KPPLM` to the root of your mission folder.

e.g.: `myFancyMission.Altis\KPGUI\` and `myFancyMission.Altis\KPPLM\`

The `stringtable.xml` goes also into the root of the mission folder.

If you don't already have a `description.ext` file you can just move the one from the release package to the root of your mission folder.

Should you already have an own `description.ext` file, add the following:

    #include "KPGUI\KP_uiDefines.hpp"
    #include "KPPLM\ui\KPPLM_dialog.hpp"

If you don't have a `CfgFunctions` definition in your `description.ext` you can append this:

    class CfgFunctions {
        #include "KPPLM\KPPLM_functions.hpp"
    };

If you have own defined functions in your `description.ext` you add at the line before the closing bracket just the `#include "KPPLM\KPPLM_functions.hpp"`

That's it. Your mission will now use and support the KP Player Menu.

## Licence
Copyright (C) 2018 [Wyqer](https://github.com/Wyqer)

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.

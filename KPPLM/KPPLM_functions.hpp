/*
    KP PLAYER MENU FUNCTIONS

    File: KPPLM_functions.hpp
    Author: Wyqer - https://github.com/KillahPotatoes
    Date: 2018-08-06
    Last Update: 2018-08-07
    License: GNU General Public License v3.0 - https://www.gnu.org/licenses/gpl-3.0.html

    Description:
    Function defines for the KP Player Menu.
*/

class KPPLM {
    class main {
        file = "KPPLM\fnc";

        // Apply and save settings
        class apply {};

        // Creates a new group
        class create {};

        // Apply view distance and sound volume
        class getInOut {};

        // Initialize the KP player menu
        class init {
            postInit = 1;
        };

        // Joins selected group
        class join {};

        // Manages action adding and removing
        class manageActions {};

        // Open the dialog
        class openDialog {};

        // Applies new name to group
        class rename {};

        // Save dialog settings
        class save {};

        // Get and display KP Ranks data
        class showRankData {};
    };
};

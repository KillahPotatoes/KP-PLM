/*
    KP PLAYER MENU INITIALIZATION

    File: KPPLM_init.sqf
    Author: Wyqer - https://github.com/KillahPotatoes
    Date: 2018-08-06
    Last Update: 2018-08-07
    License: GNU General Public License v3.0 - https://www.gnu.org/licenses/gpl-3.0.html

    Description:
    This will initialize the KP player menu functionalities.
    The chosen settings in this dialog will be persistent for a player on all servers which run a mission who uses this dialog.
    It provides the following functionalities to the player:
        * Group management
        * View distances
        * Terrain grid
        * Automatic 3rd person view switch
        * AI radio chatter disable
        * In vehicle sound

    Dependencies:
        * KPGUI
        * CBA_A3 - https://steamcommunity.com/workshop/filedetails/?id=450814997
*/

// Only run, when we've a real player
if (hasInterface) then {

    // Check if KP Ranks is running
    KPPLM_KPR = isClass (configFile >> "CfgPatches" >> "KP_Ranks");

    // Load settings, if available. Otherwise set default values
    private _settings = profileNamespace getVariable ["KPPLM_Settings", []];
    if !(_settings isEqualTo []) then {
        // View distance on foot
        KPPLM_viewFoot = _settings select 0;
        // View distance in land vehicle
        KPPLM_viewVeh = _settings select 1;
        // View distance in air vehicle
        KPPLM_viewAir = _settings select 2;
        // Terrain detail setting
        KPPLM_terrain = _settings select 3;
        // Auto 3rd Person setting
        KPPLM_tpv = _settings select 4;
        // Disable radio chatter setting
        KPPLM_radio = _settings select 5;
        // Sound volume inside a vehicle
        KPPLM_soundVeh = _settings select 6;
    } else {
        KPPLM_viewFoot = viewDistance;
        KPPLM_viewVeh = viewDistance;
        KPPLM_viewAir = viewDistance;
        KPPLM_terrain = 2;
        KPPLM_tpv = 0;
        KPPLM_radio = 0;
        KPPLM_soundVeh = soundVolume;
    };

    // Id of the open dialog action
    KPPLM_actionID = -1;

    // Remove and create action to open the dialog via respawn event handler
    player addEventHandler ["Respawn", {[_this select 1] call KPPLM_fnc_manageActions;}];

    // Event handlers to apply the view distances / 3rd person switching
    player addEventHandler ["GetInMan", {[] call KPPLM_fnc_getInOut}];
    player addEventHandler ["GetOutMan", {[] call KPPLM_fnc_getInOut}];

    // Add actions on mission join
    [] call KPPLM_fnc_manageActions;

    // Apply default/loaded values
    [] call KPPLM_fnc_apply;
};

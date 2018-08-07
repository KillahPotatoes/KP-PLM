/*
    KPPLM_fnc_manageActions

    File: fn_manageActions.sqf
    Author: Wyqer - https://github.com/KillahPotatoes
    Date: 2018-08-07
    Last Update: 2018-08-07
    License: GNU General Public License v3.0 - https://www.gnu.org/licenses/gpl-3.0.html

    Description:
    Adds actions to the vanilla action menu and removes action from corpse, if present.

    Parameter(s):
        0: OBJECT - Dead body after a respawn. (default: objNull)

    Returns:
    BOOL
*/

params [["_corpse", objNull]];

// Remove action from corpse, if there is one (not triggered on joining the server)
if (!isNull _corpse) then {
    _corpse removeAction KPPLM_actionID;
};

// Add the action
KPPLM_actionID = player addAction ["<t color='#FF8000'>" + localize "STR_KPPLM_ACTIONOPEN" + "</t>", {[] call KPPLM_fnc_openDialog;}, nil, -1120, false, true];

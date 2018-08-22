/*
    KPPLM_fnc_showRankData

    File: fn_showRankData.sqf
    Author: Wyqer - https://github.com/KillahPotatoes
    Date: 2018-08-06
    Last Update: 2018-08-22
    License: GNU General Public License v3.0 - https://www.gnu.org/licenses/gpl-3.0.html

    Description:
    Reads the KP Ranks data of the current player and displays it in the player menu dialog.

    Parameter(s):
    NONE

    Returns:
    BOOL
*/

// Dialog controls
private _dialog = findDisplay 758080;
private _ctrlRank = _dialog displayCtrl 75802;
private _ctrlScore = _dialog displayCtrl 75804;
private _ctrlPlaytime = _dialog displayCtrl 75806;
private _ctrlNoRanks = _dialog displayCtrl 75807;

// Disable no ranks hint
_ctrlNoRanks ctrlShow false;

// Show data in dialog
_ctrlRank ctrlSetText ([] call KPR_fnc_getRankName);
if (KPR_levelSystem) then {
    _ctrlScore ctrlSetText str ([] call KPR_fnc_getScore);
} else {
    _ctrlScore ctrlSetText (localize "STR_KPPLM_NOLVLSYSTEM");
};
_ctrlPlaytime ctrlSetText ([] call KPR_fnc_getPlaytime);

true

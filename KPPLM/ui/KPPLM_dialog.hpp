/*
    KP player menu dialog

    File: KPPLM_dialog.hpp
    Author: Wyqer - https://github.com/KillahPotatoes
    Date: 2018-08-03
    Last Update: 2018-08-07
    License: GNU General Public License v3.0 - https://www.gnu.org/licenses/gpl-3.0.html

    Description:
    Provides various functionalities for the players like group management, view distances, etc.
*/

class KPPLM_dialog {
    idd = 758080;
    movingEnable = 0;
    // Fetch all player groups when opened and free the variable when closed
    onLoad = "KPPLM_groups = allGroups select {isPlayer (leader _x)}";
    onUnload = "KPPLM_groups = nil";

    class controlsBackground {

        class KP_DialogTitle: KP_DialogTitleC {
            text = "$STR_KPPLM_TITLE";
        };

        class KP_DialogArea: KP_DialogBackgroundC {};

        class KP_LabelPlayer: KP_InlineTitle {
            text = "$STR_KPPLM_LABELPLAYER";
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,0,1);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,0,16);
            w = KP_GETW(KP_WIDTH_VAL_C,1);
            h = KP_GETH(KP_HEIGHT_VAL_C,16);
        };

        class KP_TextRank: KP_Text {
            idc = 75801;
            text = "$STR_KPPLM_RANK";
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,0,1);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,1,16);
            w = KP_GETW(KP_WIDTH_VAL_C,2);
            h = KP_GETH(KP_HEIGHT_VAL_C,24);
        };

        class KP_TextScore: KP_TextRank {
            idc = 75803;
            text = "$STR_KPPLM_SCORE";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,5,48);
        };

        class KP_TextPlaytime: KP_TextRank {
            idc = 75805;
            text = "$STR_KPPLM_PLAYTIME";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,7,48);
        };

        class KP_NoRanks: KP_LabelPlayer {
            idc = 75807;
            style = 2;
            colorText[] = {0.8, 0, 0, 0.75};
            text = "$STR_KPPLM_NORANKS";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,3,32);
            sizeEx = KP_TEXT_L
        };

        class KP_LabelGroups: KP_LabelPlayer {
            text = "$STR_KPPLM_LABELGROUPS";
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,0,1);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,3,16);
            w = KP_GETW(KP_WIDTH_VAL_C,1);
            h = KP_GETH(KP_HEIGHT_VAL_C,16);
        };

        class KP_LabelView: KP_LabelPlayer {
            text = "$STR_KPPLM_LABELVIEW";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,1,2);
        };

        class KP_TextViewFoot: KP_Text {
            text = "$STR_KPPLM_VIEWFOOT";
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,1,2);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,9,16);
            w = KP_GETW(KP_WIDTH_VAL_C,2);
            h = KP_GETH(KP_HEIGHT_VAL_C,24);
        };

        class KP_TextViewVehicle: KP_TextViewFoot {
            text = "$STR_KPPLM_VIEWVEHICLE";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,29,48);
        };

        class KP_TextViewAir: KP_TextViewFoot {
            text = "$STR_KPPLM_VIEWAIR";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,31,48);
        };

        class KP_LabelMisc: KP_LabelPlayer {
            text = "$STR_KPPLM_LABELMISC";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,11,16);
        };

        class KP_TextTerrain: KP_TextRank {
            text = "$STR_KPPLM_TEXTTERRAIN";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,12,16);
        };

        class KP_TextTPV: KP_TextRank {
            text = "$STR_KPPLM_TEXTTPV";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,19,24);
        };

        class KP_TextRadio: KP_TextRank {
            text = "$STR_KPPLM_TEXTRADIO";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,10,12);
        };

        class KP_TextSound: KP_TextRank {
            text = "$STR_KPPLM_TEXTSOUND";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,22,24);
        };
    };

    class controls {

        class KP_DialogCross: KP_DialogCrossC {};

        class KP_PlayerRank: KP_Text {
            idc = 75802;
            style = 2;
            text = "";
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,1,2);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,1,16);
            w = KP_GETW(KP_WIDTH_VAL_C,2);
            h = KP_GETH(KP_HEIGHT_VAL_C,24);
        };

        class KP_PlayerScore: KP_PlayerRank {
            idc = 75804;
            text = "";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,5,48);
        };

        class KP_PlayerTime: KP_PlayerRank {
            idc = 75806;
            text = "";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,7,48);
        };

        class KP_GroupList: KP_ListBox {
            idc = 75808;
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,0,1);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,4,16);
            w = KP_GETW(KP_WIDTH_VAL_C,(4/3));
            h = KP_GETH(KP_HEIGHT_VAL_C,(24/5));
            onLBSelChanged = "ctrlSetText [75809, groupId (KPPLM_groups select (lbCurSel 75808))]";
        };

        class KP_ButtonCreate: KP_InlineButton {
            text = "$STR_KPPLM_CREATE";
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,3,4);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,4,16);
            w = KP_GETW(KP_WIDTH_VAL_C,4);
            h = KP_GETH(KP_HEIGHT_VAL_C,(48/5));
            onButtonClick = "[] call KPPLM_fnc_create";
        };

        class KP_ButtonJoin: KP_ButtonCreate {
            text = "$STR_KPPLM_JOIN";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,17,48);
            onButtonClick = "[] call KPPLM_fnc_join";
        };

        class KP_RenameEdit: KP_EditBox {
            idc = 75809;
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,0,1);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,11,24);
            w = KP_GETW(KP_WIDTH_VAL_C,(4/3));
            h = KP_GETH(KP_HEIGHT_VAL_C,24);
        }

        class KP_ButtonRename: KP_ButtonCreate {
            text = "$STR_KPPLM_RENAME";
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,11,24);
            h = KP_GETH(KP_HEIGHT_VAL_C,24);
            onButtonClick = "[] call KPPLM_fnc_rename";
        };

        class KP_BoxViewFoot: KP_EditBox {
            idc = 758010;
            style = 65;
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,1,4);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,9,16);
            w = KP_GETW(KP_WIDTH_VAL_C,4);
            h = KP_GETH(KP_HEIGHT_VAL_C,24);
        };

        class KP_BoxViewVehicle: KP_BoxViewFoot {
            idc = 758011;
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,29,48);
        };

        class KP_BoxViewAir: KP_BoxViewFoot {
            idc = 758012;
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,31,48);
        };

        class KP_ComboTerrain: KP_Combo {
            idc = 758013;
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,1,2);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,12,16);
            w = KP_GETW(KP_WIDTH_VAL_C,2);
            h = KP_GETH(KP_HEIGHT_VAL_C,24);
        };

        class KP_ComboTPV: KP_ComboTerrain {
            idc = 758014;
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,19,24);
        };

        class KP_ComboRadio: KP_ComboTerrain {
            idc = 758015;
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,10,12);
        };

        class KP_TextSoundValue: KP_PlayerRank {
            idc = 758016;
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,22,24);
        };

        class KP_SliderSound: KP_Slider {
            idc = 758017;
            x = KP_GETCX(KP_X_VAL_C,KP_WIDTH_VAL_C,0,1);
            y = KP_GETCY(KP_Y_VAL_C,KP_HEIGHT_VAL_C,23,24);
            w = KP_GETW(KP_WIDTH_VAL_C,1);
            h = KP_GETH(KP_HEIGHT_VAL_C,24);
            tooltip = "$STR_KPPLM_TTSOUND"
            onSliderPosChanged = "ctrlSetText [758016, format ['%1%2', round (_this select 1), '%']]";
        };

        class KP_ApplyButton: KP_DialogButtonC {
            text = "$STR_KPPLM_APPLY";
            onButtonClick = "[] call KPPLM_fnc_save";
        };
    };
};

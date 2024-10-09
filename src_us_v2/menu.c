/* The comment below is needed for this file to be picked up by generate_ld */
/* RAM_POS: 0x8007F900 */

#include "menu.h"
#include "memory.h"
#include "fade_transition.h"

#include <PR/os_cont.h>
#include "asset_enums.h"
#include "types.h"
#include "macros.h"
#include "structs.h"
#include "f3ddkr.h"
#include "video.h"
#include "audio.h"
#include "camera.h"
#include "font.h"
#include "game_text.h"
#include "object_models.h"
#include "printf.h"
#include "textures_sprites.h"
#include "thread30_track_loading.h"
#include "objects.h"
#include "game.h"
#include "rcp_dkr.h"
#include "save_data.h"
#include "object_functions.h"
#include "audiosfx.h"
#include "racer.h"
#include "tracks.h"
#include "libultra/src/audio/synstartvoiceparam.h"
#include "controller_dkr.h"
#include "math_util.h"
#include "PRinternal/viint.h"

/**
 * @file Contains all the code used for every menu in the game.
 */

/************ .bss ************/

// The bss section needs to stay above the data section!
// Otherwise the bss variables will get reordered, which is bad.

char gCourseInitials[4]; // course initials
char gFLapInitials[4];   // flap initials
s32 gAdventureSaveGhost;
s32 gPreviousMenuID;
Gfx *sMenuCurrDisplayList;
char **gTTSaveGhostPakErrorText;
MatrixS *sMenuCurrHudMat;
Vertex *sMenuCurrHudVerts;
TriangleList *sMenuCurrHudTris;
unk801263C0 gMenuSelectedCharacter;
unk801263C0 D_801263B8;
s32 gOptionBlinkTimer;
unk801263C0 gMenuCurrentCharacter;

s32 gIgnorePlayerInputTime;  // A set amount of time to ignore player input.
UNUSED s32 sUnused_801263C8; // Set to 0 in menu_init, and never again.
CharacterSelectData (*gCurrCharacterSelectData)[10];
s32 gTrackmenuLoadedLevel;              // Compared for equality to gTrackIdForPreview
s8 gActivePlayersArray[MAXCONTROLLERS]; // Boolean value for each controller if it's active with a player.
s32 gOpacityDecayTimer;
s8 gCharselectStatus[MAXCONTROLLERS];
s32 gMenuStage;
UNUSED s32 D_801263E4;
s8 gPlayersCharacterArray[8]; // -1 = Non active player, or character id if >= 0
s8 gCharacterIdSlots[8];
s32 gRankingsPoints[8];
u8 gResultsPlayers[8];
u8 gRankingsPlayers[8];
u8 gResultsPlayerIDs[8];
u8 gRankingsPlayerIDs[8]; // Contains the order of racer indices that tell you what place they are in.
s8 D_80126438[16];

// Eeeprom save data bits stored at address 0xF
// bit 0      = Adventure Two is Unlocked
// bit 1      = Used to set the CHEAT_CONTROL_DRUMSTICK magic code flag. Drumstick is unlocked flag?
// bits 2-3   = Current language value
// bits 4-23  = Used to set the CHEAT_CONTROL_TT magic code flag. Could be tracks where TT has been beat?
// bit 24     = Unknown, but it's set as a default high bit.
// bit 25     = Seems to be a flag for whether subtitles are enabled or not.
// bits 26-55 = Unknown, but it could be a set of flags for unlocked tracks
// bits 56-63 = Checksum bits. These are calculated from the previous bits,
//              and validated using calculate_eeprom_settings_checksum.
//              If the checksum fails, the settings are reset to just
//              bits 24/25 being high.
u64 sEepromSettings;

f32 sBootScreenTimer;
s8 gControllersXAxisDelay[4];
s8 gControllersYAxisDelay[4];
s8 gControllersXAxisDirection[4]; // X axis (-1 = left, 1 = right) for controller
MenuElement *gGameSelectElements;
s8 gControllersYAxisDirection[4]; // Y axis (-1 = down, 1 = up) for controller
s8 gControllersXAxis[4];
s8 gControllersYAxis[4];
s32 sUnused_80126470; // Set to 0 in the magic codes menu and 0xD000 elsewhere, otherwise unused.
s32 gTrackSelectViewPortHalfX;
s32 gTrackSelectViewPortHalfY;
s32 gTrackSelectViewPortX;
s32 gTrackSelectViewportY;
s32 gFileCopy;
s32 gFileErase;
s32 gSaveFileIndex3;
s32 gSaveFileIndex2;
s32 gFileConfirm;
s32 gGhostMenuOption;
s32 D_8012649C;

SavefileInfo gSavefileInfo[4];

s32 gCpakGhostData;
s32 gGhostMenuTotal;
s8 gDialogueSubmenu;
u8 gGhostLevelIDsPak[4];
UNUSED s8 D_801264E0;
UNUSED s8 D_801264E1;
s8 sCurrentMenuID;
u8 gGhostCharacterIDsPak[4];
s32 D_801264E8;
u8 gGhostVehicleIDsPak[4];
s32 D_801264F0[2];
u16 gGhostChecksumIDsPak[6];
s8 sDialogueOptionMax;
u8 gGhostLevelIDsMenu[6];
s8 gDialogueOptionYOffset;
u8 gGhostCharacterIDsMenu[6];
s8 gDialogueItemSelection;
u8 gGhostVehicleIDsMenu[6];
u16 gGhostChecksumIDsMenu[6];
Settings *gSavefileData[4];
u8 gGhostWorldIDs[8];
s32 gMultiplayerSelectedNumberOfRacersCopy; // Saved version gMultiplayerSelectedNumberOfRacers?
void *gMenuAssets[128]; // lookup table? Contains Textures, Objects, and Sprites. Need to change name and type.
u8 gMenuAssetActive[128];
s32 gTrackmenuType;
UNUSED s32 D_801267D4;
s32 gMenuButtons[5]; // Buttons pressed per player plus an an extra containing each collective input.
s8 *gCinematicParams;
s32 buttonsPressed[5];
s8 *gCinematicPortraits;
SoundMask *gMenuSoundMasks[MAXCONTROLLERS]; // Soundmask values
s16 gMenuStickX[5];
s32 gCinematicEnd;
UNUSED s8 sUnused_80126828; // Set to 0 in menu_init, and never used again.
UNUSED s32 D_8012682C;
s16 gMenuStickY[5];
s16 D_8012683A;
s32 gCinematicSkipA;
SoundMask *gTrackTTSoundMask;
s32 gCinematicSkipB;
SoundMask *D_80126848;
s32 gCinematicMusicChangeOff;
s32 *D_80126850; // Never set, but it's read? Is it part of a larger struct being set?
s32 gMenuElementScaleTimer;
s32 gPostraceScaleIn;
s32 gPostraceScaleMiddle;
s32 gPostraceScaleOut;
s32 gTitleDemoIndex;
s16 gTitleDemoTimer;
s32 gTitleRevealTimer;
f32 gTitleAudioCounter;
s8 *sTitleScreenDemoIds; // Misc Asset 66 - title_screen_demo_ids.bin - 12 or 13 values.
unk80126878 D_80126878[8];
f32 D_801268D8;
UNUSED s32 D_801268DC; // Set to 0 during the title screen, never read.
s32 gOpeningNameID;
UNUSED s32 D_801268E4;
s16 gTrackSelectIDs[4][6]; // Track Select values?
s16 gFFLUnlocked;
UNUSED s32 D_8012691C;
UNUSED s32 D_80126920;
s32 gTrackSelectVertsFlip;
UNUSED s32 D_80126928; // Set to 64, but never used.
UNUSED s32 D_8012692C; // Set to 32, but never used.
TrackRenderDetails gTrackSelectRenderDetails[9];
s8 gPlayerSelectVehicle[4];
s8 gPlayerSelectConfirm[4];
s32 gTrackSelectCursorX;
s32 gTrackSelectCursorY;
char *gAudioOutputStrings[3];
f32 gTrackSelectX;
char *gMusicTestString;
f32 gTrackSelectY;
f32 gTrackSelectTargetX;
f32 gTrackSelectTargetY;
char *gTrackMenuHubName;
s32 gSelectedTrackX;
s32 gSelectedTrackY;
SoundMask *gSoundOptionMask;
s32 gSaveMenuOptionCountLower;
SaveFileData *gSaveMenuFilesDest;
s32 gSaveMenuOptionCountUpper;
SaveFileData *gSaveMenuFilesSource;
s32 gSaveMenuRumbleNag;
s32 gSaveMenuRumbleConnected;
s32 gSaveMenuSourceState;
s32 gSaveMenuDestState;
s32 sControllerPakNotesFree[MAXCONTROLLERS]; // Looks to be an array for number notes free in each controller memory pak
u8 sControllerPakIssueNotFound[MAXCONTROLLERS];   // Flag to see if there's no known issues for the given controller pak
u8 sControllerPakFatalErrorFound[MAXCONTROLLERS]; // Flag to see if there's a fatal error for the given controller pak
u8 sControllerPakNoFreeSpace[MAXCONTROLLERS];     // Flag to see if there's no free space for the given controller pak
u8 sControllerPakBadData[MAXCONTROLLERS];         // Flag to see if there's bad data for the given controller pak
char *gMenuOptionText[8];                         // Menu Text
u8 sControllerPakDataPresent[MAXCONTROLLERS];     // Flag to see if there's data present for the given controller pak?
char *D_80126A64;
s32 gMenuOption;
s32 gSaveMenuRumbleNagSet;
char **gDeviceStatusStrings;
s32 gSaveMenuMessageLines;
s32 gSaveMenuMessageOption;
UNUSED s32 D_80126A7C;
unk80126A80 *gSaveMenuText[4];
s32 gPostRace1Player;
s32 gPostRaceTimer;
s32 gTracksSaveGhost;
UNUSED s32 D_80126A9C;
char *gBootPakData[16];                         // Text to render
u8 *sCurrentControllerPakAllFileNames[16];      // Every file name on the controller pak
u8 *sCurrentControllerPakAllFileExtensions[16]; // Every file extension on the controller pak
u8 sCurrentControllerPakAllFileTypes[16];       // File type of all files on controller pak
u32 sCurrentControllerPakAllFileSizes[16];      // File size of all files on controller pak
u32 sCurrentControllerPakFreeSpace;             // Space available in current controller pak
s32 sControllerPakMenuNumberOfRows;             // 8 if PAL, 7 if not
TextureHeader *gMenuMosaic1;
TextureHeader *gMenuMosaic2;
s32 gMenuMosaicShift;
s32 D_80126BC4;               // gCreditsControlData - CurIndex?
PakError sControllerPakError; // 0 = no error, 1 = fatal error, 2 = no free space, 3 = bad data
s32 D_80126BCC;
UNUSED s32 D_80126BD0; // Set to zero, never read.
s32 gSaveMenuOptionSource;
s32 D_80126BD8;
f32 gSaveMenuScrollSource;
s32 D_80126BE0;
s32 gSaveMenuOptionDest;
s32 D_80126BE8;
f32 gSaveMenuScrollDest;
char *gResultOptionText[8];
s32 gCpakWriteTimer;
s32 gResultOptionCount;
s32 gBootMenuTimer;
char **gPostRaceMessage;
s32 gBootMenuPhase;
s32 gPostRaceLineCount;
s8 gPostraceFinishState;
unk80080BC8 (*gMenuGeometry)[2];
u16 (*gCheatsAssetData)[30]; // Cheat table.
s32 gNameEntryStickHeld;
s32 gNumberOfCheats;
s32 gNameEntryStickX;
s16 gCheatInputCurrentRow;
s16 gCheatInputCurrentColumn;
s16 gCheatInputStringLength;
s16 gOptionsMenuItemIndex;
s32 gNameSelectionDone;
s16 gNewCheatID;
f32 gNameEntryOffsetX;
unk80126C54 gPostRaceOld;
char gCheatInput[20];
s32 *gNameEntryTargetX;
unk80126C54 gPostRace;
s32 gNumOnscreenMagicCodes;
char *gNameEntryString;
s32 gNameEntryAllowedLength;
UNUSED s32 D_80126C7C;
s16 gUnlockedCheatIDs[32];
s32 gFileNew;

/******************************/

/************ .data ************/

// A boolean, set to TRUE if player has entered trophy race through adventure mode.
s8 gInAdvModeTrophyRace = FALSE;

// Height scale of the wooden frames in the track select menu.
f32 gTrackSelectWoodFrameHeightScale = 1.0f;

s32 gResetTitleScale = 1;

s32 gTitleScreenCurrentOption = 0; // 0 = "Start", 1 = "Options"

// Currently selected index for all menus.
s32 gMenuCurIndex = 0;

s32 unused_800DF464 = 4;
UNUSED s32 gMenuDisableObjAnim = FALSE; // Never set, but read once, always returning false.

// Used as a short delay before printing the missing controller text.
s32 gMissingControllerDelay = 0;

s32 gCurrentMenuId = 0;
s32 unused_800DF474 = 0;

// A boolean, set to TRUE when a track is loaded using gTrackIdToLoad.
s32 gTrackSpecifiedWithTrackIdToLoad = 0;

s32 gMenuDelay = 0;
s32 gNumberOfReadyPlayers = 0;
s32 D_800DF484 = 0;
s32 gTitleScreenLoaded = 0;
s32 unused_800DF48C = 0;
s32 unused_800DF490 = 0;
s32 gIsInAdventureTwo = 0;
s32 gPlayerHasSeenCautionMenu = 0;
s32 *gMenuTextLangTable = NULL;

char **gMenuText = NULL;

u8 sMenuGuiColourR = 0xFF;
u8 sMenuGuiColourG = 0xFF;
u8 sMenuGuiColourB = 0xFF;
u8 sMenuGuiColourBlendFactor = 0;

// Flags for menu/HUD sprites. Used in menu_element_render()
// Seems like it doesn't matter what you set it as?
s32 gMenuSpriteFlags = 0;

s32 gIsInTracksMode = 1;
s32 gNumberOfActivePlayers = 1;
s32 gIsInTwoPlayerAdventure = 0;
s32 gTrackIdForPreview = ASSET_LEVEL_CENTRALAREAHUB;
s32 gTrackSelectRow = 0; // 1 = Dino Domain, 2 = Sherbet Island, etc.
s32 gSaveFileIndex = 0;
s32 unused_800DF4D0 = 0;
s32 gTrackIdToLoad = 0;
s8 unused_800DF4D8 = TRUE;
s8 gNextTajChallengeMenu = FALSE;
s8 gNeedToCloseDialogueBox = FALSE;

// Array of booleans, set to TRUE when you are done talking to an NPC.
// This has (atleast) 5 elements, not 4!
s8 gDoneTalkingToNPC[5] = {
    FALSE, // Taj
    FALSE, // Unused?
    FALSE, // T.T.
    FALSE, // Taj Challenge
    FALSE  // Trophy Cabinet
};

s8 gDialogueOptionTangible = FALSE;

s32 unused_800DF4F0[] = { 0x4000, 0x8000, 0x1000, 0x2000, 0x8000, 0x10, 0x400, 0x00 };

MenuAsset sMenuImageProperties[18] = {
    { 0, 0, 0, 0x00, 1.0f, 0.0f, 0.0f, -32.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x01, 1.0f, 0.0f, 0.0f, -32.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x02, 1.0f, 0.0f, 0.0f, -32.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x03, 1.0f, 0.0f, 0.0f, -32.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x05, 0.215f, 0.0f, 0.0f, -500.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x06, 0.215f, 0.0f, 0.0f, -500.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x07, 0.215f, 0.0f, 0.0f, -500.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x04, 0.125f, 0.0f, -40.0f, -500.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x5B, 0.75f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x5C, 0.75f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x42, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x40, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x41, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x4C, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x4D, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x4E, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x4F, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0x5D, 1.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0 },
};

s16 *gAssetsMenuElementIds[1] = { NULL };
s16 gMenuElementIdCount = 0;
s16 gMenuObjectsCount = 0;
MenuAsset *gMenuImages = NULL;

s32 sMenuMusicVolume = 0x7F;
s32 sMenuGuiOpacity = 0xFF;
s32 unused_800DF768 = 1;

FadeTransition sMenuTransitionFadeInFast = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_NONE, FADE_COLOR_BLACK, 10, -1);
FadeTransition sMenuTransitionFadeIn = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_NONE, FADE_COLOR_BLACK, 18, -1);
FadeTransition sMenuTransitionFadeOut = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_OUT, FADE_COLOR_BLACK, 18, 0);
UNUSED FadeTransition sMenuTransitionFadeInWhite =
    FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_NONE, FADE_COLOR_WHITE, 18, -1);
UNUSED FadeTransition sMenuTransitionFadeOutWhite =
    FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_OUT, FADE_COLOR_WHITE, 18, 0);

s32 gPostraceState = POSTRACE_SLIDE_END;
MenuElement *gTrophyRankingsMenuElements = NULL;
s32 gPostraceTextOffset = 0;
s32 gPostraceTimestampOffset = 0;

char *gTitleMenuStrings[3] = { 0, 0, 0 };

// Version text shown on the title screen? See 1:15 in https://www.youtube.com/watch?v=OHSCLcA74ao.
char gVersionDisplayText[20] = "VERSION XXXXXXXX";

// "Diddy Kong Racing" logo texture indices
s16 sGameTitleTileTextures[12] = { TEXTURE_TITLE_SEGMENT_01, TEXTURE_TITLE_SEGMENT_02, TEXTURE_TITLE_SEGMENT_03,
                                   TEXTURE_TITLE_SEGMENT_04, TEXTURE_TITLE_SEGMENT_05, TEXTURE_TITLE_SEGMENT_06,
                                   TEXTURE_TITLE_SEGMENT_07, TEXTURE_TITLE_SEGMENT_08, TEXTURE_TITLE_SEGMENT_09,
                                   TEXTURE_TITLE_SEGMENT_10, TEXTURE_TITLE_SEGMENT_11, -1 };

DrawTexture sGameTitleTileOffsets[12] = { { NULL, -75, -32 }, { NULL, -60, -32 }, { NULL, -45, -32 },
                                          { NULL, -30, -32 }, { NULL, -15, -32 }, { NULL, 0, -32 },
                                          { NULL, 15, -32 },  { NULL, 30, -32 },  { NULL, 45, -32 },
                                          { NULL, 60, -32 },  { NULL, 75, -32 },  { NULL, 0, 0 } };

// Title screen cinematic text
unk800DF83C gTitleCinematicText[10] = {
    { "TIMBER", 14.0f, 14.5f, 16.5f, 17.0f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f },
    { "BUMPER", 19.0f, 19.5f, 21.5f, 22.0f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f },
    { "CONKER", 24.0f, 24.5f, 26.5f, 27.0f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f },
    { "TIPTUP", 29.0f, 29.5f, 31.5f, 32.0f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f },
    { "DRUMSTICK", 35.0f, 35.5f, 37.5f, 38.0f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f },
    { "PIPSY", 40.0f, 40.5f, 42.5f, 43.0f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f },
    { "BANJO", 45.0f, 45.5f, 47.5f, 48.0f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f },
    { "KRUNCH", 50.0f, 50.5f, 52.5f, 53.0f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f },
    { "WIZPIG", 57.5f, 58.0f, 60.0f, 60.5f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f },
    { "DIDDY", 63.5f, 64.0f, 66.0f, 66.5f, -80.0f, SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT_HALF,
      SCREEN_HEIGHT_FLOAT - 32.0f, SCREEN_WIDTH_FLOAT + 80.0f, SCREEN_HEIGHT_FLOAT - 32.0f }
};

// Number of active colours used in the title screen cinematic.
s32 gTitleCinematicTextColourCount = 0;

// Colours used for the Character Names during the title screen cinematic
MenuColour gTitleCinematicTextColours[4] = {
    { 255, 255, 0, 255, 204 }, // Yellow
    { 0, 255, 0, 255, 153 },   // Green
    { 0, 255, 255, 255, 102 }, // Cyan
    { 0, 0, 255, 255, 51 }     // Blue
};

UNUSED u8 unused_800DFA10[4] = { 0, 0, 15, 120 };

char *gOptionMenuStrings[7] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };

s16 gOptionMenuTextures[8] = { 0x3D, 0x3C, 0x3F, 0x3E, 0x44, -1, -1, 0 };

unk800DFA3C gAudioMenuStrings[8] = {
    { 160, 80, 0xFF, 0xFF, 0xFF, 0, 0xFF, 0, 0, 12, NULL },  { 160, 104, 0xFF, 0xFF, 0xFF, 0, 0xFF, 0, 0, 12, NULL },
    { 160, 144, 0xFF, 0xFF, 0xFF, 0, 0xFF, 0, 0, 12, NULL }, { 160, 192, 0xFF, 0xFF, 0xFF, 0, 0xFF, 0, 0, 12, NULL },
    { 161, 35, 0, 0, 0, 0xFF, 0x80, 2, 0, 12, NULL },        { 160, 32, 0xFF, 0x80, 0xFF, 0, 0xFF, 2, 0, 12, NULL },
    { 160, 188, 0xFF, 0xFF, 0xFF, 0, 0xFF, 0, 0, 12, NULL }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
};

// Current song index used in the music test (from JUKEBOX magic code)
s32 gMusicTestSongIndex = 0;

s32 gSfxVolumeSliderValue = 256;   // Value from 0 to 256
s32 gMusicVolumeSliderValue = 256; // Value from 0 to 256

StereoPanMode gAudioOutputType = STEREO;

// This is used for RGBA colors for the save options Controller Pak BG.
u32 gContPakSaveBgColours[MAXCONTROLLERS] = {
    COLOUR_RGBA32(64, 64, 255, 255),  // Blue for controller 1
    COLOUR_RGBA32(255, 64, 64, 255),  // Red for controller 2
    COLOUR_RGBA32(255, 208, 64, 255), // Yellow for controller 3
    COLOUR_RGBA32(64, 255, 64, 255)   // Green for controller 4
};

SIDeviceStatus gDeviceStatus = CONTROLLER_PAK_GOOD;
s32 gControllerIndex = 0;

// Strings related to the controller pak.
char *gContPakNotPresentStrings[6] = { 0, 0, 0, 0, 0, 0 };
char *gContPakCorruptDataRepairStrings[6] = { 0, 0, 0, 0, 0, 0 };
char *gContPakDamagedStrings[6] = { 0, 0, 0, 0, 0, 0 };
char *gContPakFullStrings[5] = { 0, 0, 0, 0, 0 };
char *gContPakDiffContStrings[7] = { 0, 0, 0, 0, 0, 0, 0 };
char *gContPakNoRoomForGhostsStrings[6] = { 0, 0, 0, 0, 0, 0 };
char *gContPakCorruptDataStrings[6] = { 0, 0, 0, 0, 0, 0 };
char *gContPakRumbleDetectedStrings[6] = { 0, 0, 0, 0, 0, 0 };
char *gContPakSwitchToRumbleStrings[6] = { 0, 0, 0, 0, 0, 0 };
char *gContPakNeed2ndAdvStrings[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

// Associated with SIDeviceStatus enum values.
char **gContPakStrings[11] = { NULL,
                               gContPakNotPresentStrings,
                               gContPakCorruptDataRepairStrings,
                               gContPakDamagedStrings,
                               gContPakFullStrings,
                               gContPakDiffContStrings,
                               gContPakNoRoomForGhostsStrings,
                               gContPakRumbleDetectedStrings,
                               gContPakSwitchToRumbleStrings,
                               gContPakCorruptDataStrings,
                               gContPakNeed2ndAdvStrings };

s32 unused_800DFC08 = 0;
s32 unused_800DFC0C = 0xFFFF;

/*** Icons in the save options menu. ***/
DrawTexture gDrawTexN64Icon[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gDrawTexTTIcon[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gDrawTexGhostIcon[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gDrawTexFileIcon[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gDrawTexContPakIcon[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gDrawTexTrashIcon[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };

u8 unused_800DFC70[8] = { 0x40, 0x40, 0x04, 0x04, 0xFF, 0, 0, 0 };

s16 gSaveMenuObjectIndices[26] = { 0x0024, 0x0025, 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x003D,
                                   0x003F, 0x003E, 0x003C, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048,
                                   0x0049, 0x004A, 0x004B, 0x0040, 0x0041, 0x0002, 0xFFFF, 0x0000 };

s16 gSaveMenuImageIndices[4] = { 0x000B, 0x000C, 0x0002, 0xFFFF };

MenuElement gControllerPakMenuElement[7] = {
    { 161, 32, 161, 33, 161, 32, 0, 0, 0, 255, 128, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 160, 30, 160, 30, 160, 30, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 160, 112, 160, 112, 160, 112, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 160, 128, 160, 128, 160, 128, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 160, 192, 160, 192, 160, 192, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 160, 208, 160, 208, 160, 208, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ASSET_FONTS_FUNFONT, 0, 0, { NULL }, { { 0, 0, 0, 0 } } },
};

s32 gShowControllerPakMenu = FALSE;

s32 gActiveMagicCodes = 0;
s32 gUnlockedMagicCodes = 0;

char *gMagicCodeMenuStrings[5] = { 0, 0, 0, 0, 0 };

u8 gCharacterVolumes[10][2] = {
    { 0x0F, 0x64 }, { 0x0C, 0x07 }, { 0x09, 0x64 }, { 0x0A, 0x64 }, { 0x08, 0x64 },
    { 0x0B, 0x64 }, { 0x0D, 0x64 }, { 0x0E, 0x64 }, { 0x05, 0x64 }, { 0x04, 0x64 },
};

s16 gCharSelectObjectIndices[2] = { -1, 0 };
s16 gCharSelectImageIndices[2] = { -1, 0 };

// Not sure what this is
// Used for gCurrCharacterSelectData when Neither T.T. Nor Drumstick are unlocked
// CharacterSelectData

#define NONE 0xFF
#define KRUNCH 0
#define DIDDY 1
#define BUMPER 2
#define BANJO 3
#define CONKER 4
#define TIPTUP 5
#define PIPSY 6
#define TIMBER 7
#define DRUMSTICK 8
#define TICTOC_8 8 // T.T's unlocked but Drumstick is not
#define TICTOC_9 9 // Everyone unlocked.

/**
 * Diddy Kong Racing's character select menu refers to these arrays below to know how
 * to handle some certain things. This includes which direction selects which index, which voice ID
 * they use, and which audio voices the BGM uses. It has a different table for each possible combination
 * of which characters are available to select. This system is far from conventional.
 * Unfortunately, because each entry is explicitly 14 bytes, it means a struct would not match, because
 * a struct would align itself to 16 bytes, creating an extra 2 bytes of padding inbetween.
 *
 * The layout shows which character is in each cardinal direction. Presumably so it knows
 * where to place extra cursors when a new player joins.
 * Frankly, this is a comically overcomplicated method.
 */

// Default character select screen with the initial 8 characters.
/*    Name         Up                  Down                Left                                Right Voice ID */
CharacterSelectData gCharacterSelectBytesDefault[] = {
    /*Krunch*/ { { NONE, NONE }, { CONKER, NONE }, { NONE, NONE, NONE, NONE }, { DIDDY, BUMPER, BANJO, NONE }, 0x0000 },
    /*Diddy*/ { { NONE, NONE }, { TIPTUP, NONE }, { KRUNCH, NONE, NONE, NONE }, { BUMPER, BANJO, NONE, NONE }, 0x0009 },
    /*Bumper*/ { { NONE, NONE }, { PIPSY, NONE }, { DIDDY, KRUNCH, NONE, NONE }, { BANJO, NONE, NONE, NONE }, 0x0001 },
    /*Banjo*/ { { NONE, NONE }, { TIMBER, NONE }, { BUMPER, DIDDY, KRUNCH, NONE }, { NONE, NONE, NONE, NONE }, 0x0005 },
    /*Conker*/
    { { KRUNCH, NONE }, { NONE, NONE }, { NONE, NONE, NONE, NONE }, { TIPTUP, PIPSY, TIMBER, NONE }, 0x0003 },
    /*Tiptup*/ { { DIDDY, NONE }, { NONE, NONE }, { CONKER, NONE, NONE, NONE }, { PIPSY, TIMBER, NONE, NONE }, 0x0002 },
    /*Pipsy*/
    { { BUMPER, NONE }, { NONE, NONE }, { TIPTUP, CONKER, NONE, NONE }, { TIMBER, NONE, NONE, NONE }, 0x0007 },
    /*Timber*/ { { BANJO, NONE }, { NONE, NONE }, { PIPSY, TIPTUP, CONKER, NONE }, { NONE, NONE, NONE, NONE }, 0x0004 }
};

// Drumstick is unlocked, but T.T is not.
/*    Name            Up                     Down                Left                                  Right Voice ID */
CharacterSelectData gCharacterSelectBytesDrumStick[] = {
    /*Krunch*/ {
        { NONE, NONE }, { CONKER, NONE }, { NONE, NONE, NONE, NONE }, { DIDDY, DRUMSTICK, BUMPER, BANJO }, 0x0000 },
    /*Diddy*/
    { { NONE, NONE }, { CONKER, TIPTUP }, { KRUNCH, NONE, NONE, NONE }, { DRUMSTICK, BUMPER, BANJO, NONE }, 0x0009 },
    /*Bumper*/
    { { NONE, NONE }, { PIPSY, TIMBER }, { DRUMSTICK, DIDDY, KRUNCH, NONE }, { BANJO, NONE, NONE, NONE }, 0x0001 },
    /*Banjo*/
    { { NONE, NONE }, { TIMBER, NONE }, { BUMPER, DRUMSTICK, DIDDY, KRUNCH }, { NONE, NONE, NONE, NONE }, 0x0005 },
    /*Conker*/
    { { KRUNCH, DIDDY }, { NONE, NONE }, { NONE, NONE, NONE, NONE }, { TIPTUP, PIPSY, TIMBER, NONE }, 0x0003 },
    /*Tiptup*/
    { { DIDDY, DRUMSTICK }, { NONE, NONE }, { CONKER, NONE, NONE, NONE }, { PIPSY, TIMBER, NONE, NONE }, 0x0002 },
    /*Pipsy*/
    { { DRUMSTICK, BUMPER }, { NONE, NONE }, { TIPTUP, CONKER, NONE, NONE }, { TIMBER, NONE, NONE, NONE }, 0x0007 },
    /*Timber*/
    { { BUMPER, BANJO }, { NONE, NONE }, { PIPSY, TIPTUP, CONKER, NONE }, { NONE, NONE, NONE, NONE }, 0x0004 },
    /*Drumstick*/
    { { NONE, NONE }, { TIPTUP, PIPSY }, { DIDDY, KRUNCH, NONE, NONE }, { BUMPER, BANJO, NONE, NONE }, 0x0006 }
};

// Under the unlikely chance you have T.T unlocked, but not Drumstick.
/*    Name         Up                 Down                  Left                                 Right Voice ID */
CharacterSelectData gCharacterSelectBytesTT[] = {
    /*Krunch*/ { { NONE, NONE }, { CONKER, NONE }, { NONE, NONE, NONE, NONE }, { DIDDY, BUMPER, BANJO, NONE }, 0x0000 },
    /*Diddy*/
    { { NONE, NONE }, { TIPTUP, TICTOC_8 }, { KRUNCH, NONE, NONE, NONE }, { BUMPER, BANJO, NONE, NONE }, 0x0009 },
    /*Bumper*/
    { { NONE, NONE }, { TICTOC_8, PIPSY }, { DIDDY, KRUNCH, NONE, NONE }, { BANJO, NONE, NONE, NONE }, 0x0001 },
    /*Banjo*/
    { { NONE, NONE }, { PIPSY, TIMBER }, { BUMPER, DIDDY, KRUNCH, NONE }, { NONE, NONE, NONE, NONE }, 0x0005 },
    /*Conker*/
    { { KRUNCH, NONE }, { NONE, NONE }, { NONE, NONE, NONE, NONE }, { TIPTUP, TICTOC_8, PIPSY, TIMBER }, 0x0003 },
    /*Tiptup*/
    { { KRUNCH, DIDDY }, { NONE, NONE }, { CONKER, NONE, NONE, NONE }, { TICTOC_8, PIPSY, TIMBER, NONE }, 0x0002 },
    /*Pipsy*/
    { { BUMPER, BANJO }, { NONE, NONE }, { TICTOC_8, TIPTUP, CONKER, NONE }, { TIMBER, NONE, NONE, NONE }, 0x0007 },
    /*Timber*/
    { { BANJO, NONE }, { NONE, NONE }, { PIPSY, TICTOC_8, TIPTUP, CONKER }, { NONE, NONE, NONE, NONE }, 0x0004 },
    /*T.T*/ { { DIDDY, BUMPER }, { NONE, NONE }, { TIPTUP, CONKER, NONE, NONE }, { PIPSY, TIMBER, NONE, NONE }, 0x0008 }
};

// With everyone unlocked.
/*    Name            Up                   Down                Left                                 Right Voice ID */
CharacterSelectData gCharacterSelectBytesComplete[] = {
    /*Krunch*/ {
        { NONE, NONE }, { CONKER, NONE }, { NONE, NONE, NONE, NONE }, { DIDDY, DRUMSTICK, BUMPER, BANJO }, 0x0000 },
    /*Diddy*/
    { { NONE, NONE }, { TIPTUP, NONE }, { KRUNCH, NONE, NONE, NONE }, { DRUMSTICK, BUMPER, BANJO, NONE }, 0x0009 },
    /*Bumper*/
    { { NONE, NONE }, { PIPSY, NONE }, { DRUMSTICK, DIDDY, KRUNCH, NONE }, { BANJO, NONE, NONE, NONE }, 0x0001 },
    /*Banjo*/
    { { NONE, NONE }, { TIMBER, NONE }, { BUMPER, DRUMSTICK, DIDDY, KRUNCH }, { NONE, NONE, NONE, NONE }, 0x0005 },
    /*Conker*/
    { { KRUNCH, NONE }, { NONE, NONE }, { NONE, NONE, NONE, NONE }, { TIPTUP, TICTOC_9, PIPSY, TIMBER }, 0x0003 },
    /*Tiptup*/
    { { DIDDY, NONE }, { NONE, NONE }, { CONKER, NONE, NONE, NONE }, { TICTOC_9, PIPSY, TIMBER, NONE }, 0x0002 },
    /*Pipsy*/
    { { BUMPER, NONE }, { NONE, NONE }, { TICTOC_9, TIPTUP, CONKER, NONE }, { TIMBER, NONE, NONE, NONE }, 0x0007 },
    /*Timber*/
    { { BANJO, NONE }, { NONE, NONE }, { PIPSY, TICTOC_9, TIPTUP, CONKER }, { NONE, NONE, NONE, NONE }, 0x0004 },
    /*Drumstick*/
    { { NONE, NONE }, { TICTOC_9, NONE }, { DIDDY, KRUNCH, NONE, NONE }, { BUMPER, BANJO, NONE, NONE }, 0x0006 },
    /*T.T*/
    { { DRUMSTICK, NONE }, { TIPTUP, NONE }, { TIPTUP, CONKER, NONE, NONE }, { PIPSY, TIMBER, NONE, NONE }, 0x0008 }
    //!@bug T.T's down input selects Tiptup. It should be set to NONE.
};

UNUSED s32 unused_800DFFCC = 0;

// Set from charselect_prev()
// Is either 0, 1, or 2. However it is never set to 2?
// Set to 0 upon entering the Character Select menu normally.
// Set to 1 upon entering the Char Select from the
//   "Select Character" option on the "Pause Options" screen in a race.
s32 gEnteredCharSelectFrom = 0;

// Set from charselect_prev()
// Set to the value *arg1 when arg0 is 2, but that never happens.
// Not read from anywhere, so I'd consider this to be unused.
UNUSED s32 unused_800DFFD4 = -1;

// clang-format off

MenuElement gCautionMenuTextElements[14] = {
    { SCREEN_WIDTH_HALF + 1, 35, SCREEN_WIDTH_HALF + 1, 35, SCREEN_WIDTH_HALF + 1, 35, 0, 0, 0, 255, 128, ASSET_FONTS_BIGFONT, 12,0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 32, SCREEN_WIDTH_HALF, 32, SCREEN_WIDTH_HALF, 32, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 72, SCREEN_WIDTH_HALF, 68, SCREEN_WIDTH_HALF, 72, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 86, SCREEN_WIDTH_HALF, 82, SCREEN_WIDTH_HALF, 86, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 100, SCREEN_WIDTH_HALF, 96, SCREEN_WIDTH_HALF, 100, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 114, SCREEN_WIDTH_HALF, 110, SCREEN_WIDTH_HALF, 114, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 128, SCREEN_WIDTH_HALF, 124, SCREEN_WIDTH_HALF, 128, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 142, SCREEN_WIDTH_HALF, 138, SCREEN_WIDTH_HALF, 142, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 156, SCREEN_WIDTH_HALF, 152, SCREEN_WIDTH_HALF, 156, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 156, SCREEN_WIDTH_HALF, 166, SCREEN_WIDTH_HALF, 156, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 186, SCREEN_WIDTH_HALF, 180, SCREEN_WIDTH_HALF, 186, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 200, SCREEN_WIDTH_HALF, 194, SCREEN_WIDTH_HALF, 200, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 200, SCREEN_WIDTH_HALF, 208, SCREEN_WIDTH_HALF, 200, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    {NULL},
};

MenuElement gGameSelectTextElemsNoAdv2[7] = {
    { SCREEN_WIDTH_HALF + 1, 35, SCREEN_WIDTH_HALF + 1, 35, SCREEN_WIDTH_HALF + 1, 35, 0, 0, 0, 255, 128, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 32, SCREEN_WIDTH_HALF, 32, SCREEN_WIDTH_HALF, 32, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { -96, 39, -96, 39, -96, 39, 176, 224, 192, 255, 255, ASSET_FONTS_FUNFONT, 0, 7, { NULL }, { { 192, 44, 4, 4 } } },
    { SCREEN_WIDTH_HALF, 104, SCREEN_WIDTH_HALF, 104, SCREEN_WIDTH_HALF, 104, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { -96, -9, -96, -9, -96, -9, 176, 224, 192, 255, 255, ASSET_FONTS_FUNFONT, 0, 7, { NULL }, { { 192, 44, 4, 4 } } },
    { SCREEN_WIDTH_HALF, 152, SCREEN_WIDTH_HALF, 152, SCREEN_WIDTH_HALF, 152, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0,  { NULL }, { { 0, 0, 0, 0 } } },
    {NULL},
};

MenuElement gGameSelectTextElemsWithAdv2[9] = {
    { SCREEN_WIDTH_HALF + 1, 35, SCREEN_WIDTH_HALF + 1, 35, SCREEN_WIDTH_HALF + 1, 35, 0, 0, 0, 255, 128, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { SCREEN_WIDTH_HALF, 32, SCREEN_WIDTH_HALF, 32, SCREEN_WIDTH_HALF, 32, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { -112, 55, -112, 55, -112, 55, 176, 224, 192, 255, 255, ASSET_FONTS_FUNFONT, 0, 7, { NULL }, { { 224, 44, 4, 4 } } },
    { SCREEN_WIDTH_HALF, 88, SCREEN_WIDTH_HALF, 88, SCREEN_WIDTH_HALF, 88, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { -112, 7, -112, 7, -112, 7, 176, 224, 192, 255, 255, ASSET_FONTS_FUNFONT, 0, 7, { NULL }, { { 224, 44, 4, 4 } } },
    { SCREEN_WIDTH_HALF, 136, SCREEN_WIDTH_HALF, 136, SCREEN_WIDTH_HALF, 136, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { -112, -41, -112, -41, -112, -41, 176, 224, 192, 255, 255, ASSET_FONTS_FUNFONT, 0, 7, { NULL }, { { 224, 44, 4, 4 } } },
    { SCREEN_WIDTH_HALF, 184, SCREEN_WIDTH_HALF, 184, SCREEN_WIDTH_HALF, 184, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    {NULL},
};

s16 gFileSelectObjectIndices[6] = { 0x00, 0x43, 0x40, 0x41, 0x42, -1 };

s16 gFileSelectImageIndices[6] = { 0x00, 0x0B, 0x0C, 0x0A, -1, 0 };

char *gFilenames[3] = { NULL, NULL, NULL };

u16 unused_800E03BC[8] = {
    0x004C, 0x0070, 0x00F4, 0x0070, 0x004C, 0x00D0, 0x00F4, 0x00D0,
};

ButtonElement gFileSelectButtons[3] = {
    { 24, 81, 88, 64, 4, 4, GPACK_RGBA5551(64, 16, 0, 0), GPACK_RGBA5551(255, 255, 0, 0) },  // File A
    { 116, 81, 88, 64, 4, 4, GPACK_RGBA5551(64, 16, 0, 0), GPACK_RGBA5551(255, 255, 0, 0) }, // File B
    { 208, 81, 88, 64, 4, 4, GPACK_RGBA5551(64, 16, 0, 0), GPACK_RGBA5551(255, 255, 0, 0) }, // File C
};

s16 gFileSelectElementPos[10] = {
    44, 54, // game name
    21, 25, // Balloon icon
    44, 27, // New Text
    63, 25, // Balloon count
    45, 25  // Balloon count x
};

// Either 0 (2 racers), 1 (4 racers), or 2 (6 racers)
s32 gMultiplayerSelectedNumberOfRacers = 0;

// Highlighted option index for time trial in tracks mode.
//   0 = Time Trial off
//   1 = Time Trial on
s32 gTracksMenuTimeTrialHighlightIndex = 0;

// Highlighted option index for adventure 1 or 2 in tracks mode.
//   0 = Adventure 1 (Normal)
//   1 = Adventure 2 (Mirrored)
s32 gTracksMenuAdventureHighlightIndex = 0;

DrawTexture gMenuSelectionArrowUp[2] = { { NULL, -12, -8 }, { NULL, 0, 0 } };
DrawTexture gMenuSelectionArrowLeft[2] = { { NULL, -8, -12 }, { NULL, 0, 0 } };
DrawTexture gMenuSelectionArrowDown[2] = { { NULL, -12, -8 }, { NULL, 0, 0 } };
DrawTexture gMenuSelectionArrowRight[2] = { { NULL, -8, -12 }, { NULL, 0, 0 } };

DrawTexture gRaceSelectionCarTex[3] = { { NULL, 0, 0 }, { NULL, 0, 32 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionHoverTex[3] = { { NULL, 0, 0 }, { NULL, 0, 32 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionPlaneTex[3] = { { NULL, 0, 0 }, { NULL, 0, 32 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionTTOn[3] = { { NULL, 0, 0 }, { NULL, 0, 32 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionTTOff[3] = { { NULL, 0, 0 }, { NULL, 0, 32 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionCarOptHighlight[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionCarOpt[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionHoverOptHighlight[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionHoverOpt[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionPlaneOptHighlight[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionPlaneOpt[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionTTOnOptHighlight[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionTTOffOptHighlight[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionTTOnOpt[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionTTOffOpt[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionPlayer1Texture[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionPlayer2Texture[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionPlayer3Texture[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionPlayer4Texture[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionVehicleTitleTexture[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionTTTitleTexture[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture D_800E05D4[4] = { { NULL, 0, -48 }, { NULL, 0, -16 }, { NULL, 0, 16 }, { NULL, 0, 0 } };
DrawTexture D_800E05F4[4] = { { NULL, 0, -48 }, { NULL, 0, -16 }, { NULL, 0, 16 }, { NULL, 0, 0 } };
DrawTexture gRaceSelectionTTTexture[2] = { { NULL, -16, -16 }, { NULL, 0, 0 } };

DrawTexture *gRaceSelectionImages[9] = {
    gRaceSelectionCarTex,   gRaceSelectionCarOptHighlight,   gRaceSelectionCarOpt,
    gRaceSelectionHoverTex, gRaceSelectionHoverOptHighlight, gRaceSelectionHoverOpt,
    gRaceSelectionPlaneTex, gRaceSelectionPlaneOptHighlight, gRaceSelectionPlaneOpt

};

DrawTexture *gTrackSelectTTImage[6] = { gRaceSelectionTTOff, gRaceSelectionTTOffOptHighlight, gRaceSelectionTTOffOpt,
                                        gRaceSelectionTTOn,  gRaceSelectionTTOnOptHighlight,  gRaceSelectionTTOnOpt };

DrawTexture *gTrackSelectPlayerImage[6] = { gRaceSelectionPlayer1Texture,      gRaceSelectionPlayer2Texture,
                                            gRaceSelectionPlayer3Texture,      gRaceSelectionPlayer4Texture,
                                            gRaceSelectionVehicleTitleTexture, gRaceSelectionTTTitleTexture };

DrawTexture *gMenuSelectionArrows[4] = { gMenuSelectionArrowUp, gMenuSelectionArrowLeft, gMenuSelectionArrowDown,
                                         gMenuSelectionArrowRight };

// X/Y offsets for the "Player" icon
s16 gTracksMenuPlayerNamePositions[20] = {
    // X, Y
    0x44, 0x72,                                     // 1 player
    0x44, 0x72, 0xCC, 0x72,                         // 2 players
    0x21, 0x72, 0x88, 0x72, 0xEF, 0x72,             // 3 players
    0x21, 0x72, 0x66, 0x72, 0xAA, 0x72, 0xEF, 0x72, // 4 players
};

// X offsets for "Car", "Hover", and "Plane" choices in track select.
s16 gTracksMenuVehicleNamePositions[10] = {
    0x68,                  // 1 player
    0x21, 0xFB,            // 2 players
    0x27, 0x8E, 0xF5,      // 3 players
    0x27, 0x6C, 0xB0, 0xF5 // 4 players
};

// Paired X / Y Offsets. X Is First, Y is Second. For NTSC.
s16 gTracksMenuArrowPositionsNTSC[8] = {
    0x0000, 0xFFC2, 0x0055, 0x0000, 0x0000, 0x003E, 0xFFAB, 0x0000,
};

// Paired X / Y Offsets. X Is First, Y is Second. For PAL.
s16 gTracksMenuArrowPositionsPAL[8] = {
    0x0000, 0xFFB6, 0x0055, 0x0000, 0x0000, 0x004A, 0xFFAB, 0x0000,
};

ButtonTextElement gTwoPlayerRacerCountMenu = {
    SCREEN_WIDTH_HALF - 80, 140, 160, 64, 4, 4, { 80, 20, 58, 40, 80, 40, 102, 40 }
};

// Adventure 1/2 button in the track select menu.
// Note: The first element (.x) is not actually used.
ButtonElement gTracksMenuAdventureButton = { 80, 152, 160, 40, 4, 4, 80, 14 };

// Often access like D_800E0710[i * 3 + 1].
// Texture indices for the backgrounds in the Track Select
// Seems like the 3rd number of a group of 3 is not used for anything?
s16 gTracksMenuBgTextureIndices[15] = {
    0x0E, 0x0F, 0x00, // Dino domain
    0x10, 0x11, 0x20, // Sherbet Island
    0x12, 0x13, 0x00, // Snowflake Mountain
    0x14, 0x15, 0x20, // Dragon Forest
    0x16, 0x17, 0x20  // Future Fun Land
};

TextureHeader *gTracksMenuBgTextures[10] = {
    NULL, NULL, // Dino domain
    NULL, NULL, // Sherbet Island
    NULL, NULL, // Snowflake Mountain
    NULL, NULL, // Dragon Forest
    NULL, NULL  // Future Fun Land
};

// ID for T.Ts voice lines for each track id.
// T.T. will say nothing for tracks with -1
s16 gTTVoiceLines[53] = { -1,
                          -1,
                          SOUND_VOICE_TT_DRAGON_FOREST,
                          SOUND_VOICE_TT_FOSSIL_CANYON,
                          SOUND_VOICE_TT_PIRATE_LAGOON,
                          SOUND_VOICE_TT_ANCIENT_LAKE,
                          SOUND_VOICE_TT_WALRUS_COVE,
                          SOUND_VOICE_TT_HOT_TOP_VOLCANO,
                          SOUND_VOICE_TT_WHALE_BAY,
                          SOUND_VOICE_TT_SNOWBALL_VALLEY,
                          SOUND_VOICE_TT_CRESCENT_ISLAND,
                          SOUND_VOICE_TT_FIRE_MOUNTAIN,
                          SOUND_VOICE_TT_DINO_DOMAIN,
                          SOUND_VOICE_TT_EVERFROST_PEAK,
                          SOUND_VOICE_TT_SHERBET_ISLAND,
                          SOUND_VOICE_TT_SPACEPORT_ALPHA,
                          -1,
                          SOUND_VOICE_TT_SPACEDUST_VALLEY,
                          SOUND_VOICE_TT_GREENWOOD_VILLAGE,
                          SOUND_VOICE_TT_BOULDER_CANYON,
                          SOUND_VOICE_TT_WINDMILL_PLAINS,
                          -1,
                          -1,
                          -1,
                          SOUND_VOICE_TT_SNOWFLAKE_MOUNTAIN,
                          SOUND_VOICE_TT_SMOKEY_CASTLE,
                          SOUND_VOICE_TT_DARKWATER_BEACH,
                          SOUND_VOICE_TT_ICICLE_PYRAMID,
                          SOUND_VOICE_TT_FROSTY_VILLAGE,
                          SOUND_VOICE_TT_JUNGLE_FALLS,
                          SOUND_VOICE_TT_TREASURE_CAVES,
                          SOUND_VOICE_TT_HAUNTED_WOODS,
                          SOUND_VOICE_TT_DARKMOON_CAVERNS,
                          SOUND_VOICE_TT_STAR_CITY,
                          SOUND_VOICE_TT_TROPHY_RACE,
                          SOUND_VOICE_TT_FUTURE_FUN_LAND,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1,
                          -1 };

s16 gTrackSelectObjectIndices[14] = {
    0x05, 0x06, 0x07, 0x3D, 0x3C, 0x3F, 0x3E, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, -1
};

s16 gTrackSelectImageIndices[4] = { 0x04, 0x05, 0x06, -1 };

s16 gTrackSelectPreviewObjectIndices[36] = { 0x0004, 0x0000, 0x0001, 0x0002, 0x0003, 0x0018, 0x0019, 0x001A, 0x001B,
                                             0x001C, 0x001D, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A,
                                             0x002B, 0x001E, 0x001F, 0x0020, 0x0021, 0x0022, 0x0023, 0x002C, 0x002D,
                                             0x002E, 0x002F, 0x0030, 0x0031, 0x0040, 0x0041, 0x0043, 0x005E, 0xFFFF };

s16 gTrackSelectPreviewImageIndices[8] = { 0x07, 0x00, 0x01, 0x02, 0x03, 0x0B, 0x0C, -1 };

// Not a struct, since the entries can *technically* be either 4 or 5 bytes. But it is always 5 in the final game.
/*
    Offset 0: u8 index;
    Offset 1: u8 indexInto800E0730;
    Offset 2: u8 alpha;
    Offset 3: u8 alpha2;
    Offset 4: u8 texCoordUFactor;
*/
u8 gTrackSelectBgData[295] = {
    0,  0, 255, 255, 0,  1,  1, 255, 255, 0,  2,  0, 255, 255, 0,  3,   1, 255, 255, 0,  4,  0, 255, 255, 0,
    5,  1, 255, 255, 0,  6,  0, 255, 255, 0,  6,  2, 0,   64,  0,  7,   1, 255, 255, 0,  7,  3, 64,  128, 0,
    8,  0, 255, 255, 0,  8,  2, 128, 192, 32, 9,  1, 255, 255, 0,  9,   3, 192, 255, 32, 10, 2, 255, 255, 0,
    11, 3, 255, 255, 0,  12, 2, 255, 255, 32, 13, 3, 255, 255, 32, 14,  2, 255, 255, 0,  14, 4, 0,   64,  0,
    15, 3, 255, 255, 0,  15, 5, 64,  128, 0,  16, 2, 255, 255, 32, 16,  4, 128, 192, 0,  17, 3, 255, 255, 32,
    17, 5, 192, 255, 0,  18, 4, 255, 255, 0,  19, 5, 255, 255, 0,  20,  4, 255, 255, 0,  21, 5, 255, 255, 0,
    22, 4, 255, 255, 0,  22, 6, 0,   64,  0,  23, 5, 255, 255, 0,  23,  7, 64,  128, 0,  24, 4, 255, 255, 0,
    24, 6, 128, 192, 32, 25, 5, 255, 255, 0,  25, 7, 192, 255, 32, 26,  6, 255, 255, 0,  27, 7, 255, 255, 0,
    28, 6, 255, 255, 32, 29, 7, 255, 255, 32, 30, 6, 255, 255, 0,  30,  8, 0,   64,  0,  31, 7, 255, 255, 0,
    31, 9, 64,  128, 0,  32, 6, 255, 255, 32, 32, 8, 128, 192, 32, 33,  7, 255, 255, 32, 33, 9, 192, 255, 32,
    34, 8, 255, 255, 0,  35, 9, 255, 255, 0,  36, 8, 255, 255, 32, 37,  9, 255, 255, 32, 38, 8, 255, 255, 0,
    39, 9, 255, 255, 0,  40, 8, 255, 255, 32, 41, 9, 255, 255, 32, 255, 0, 0,   0,   0
};
Vertex *gTrackSelectBgVertices[2] = { NULL, NULL };
Triangle *gTrackSelectBgTriangles[2] = { NULL, NULL };
char *gQMarkPtr = "?";

// Boolean. Set to TRUE once in the Track Select menu, then
//   set to FALSE when leaving the menu.
// This is effectively unused, since it is only read from the
//   unused function trackmenu_active()
s32 gIsInTracksMenu = FALSE;

s32 gTrackNameVoiceDelay = 0;
s32 gMenuOptionCap = 0;
s32 gMenuSubOption = 0;

// Index of the last player who paused.
s32 gLastPlayerWhoPaused = 0;

ColourRGBA gPlayerPauseBgColour[4] = {
    { { { 64, 64, 255, 160 } } },  // Blue for player 1
    { { { 255, 64, 64, 160 } } },  // Red for player 2
    { { { 208, 192, 32, 176 } } }, // Yellow for player 3
    { { { 32, 192, 64, 176 } } },  // Green for player 4
};

ColourRGBA gPlayerPauseOptionsTextColour[4] = {
    { { { 0, 255, 0, 128 } } }, // Green for Player 1
    { { { 0, 255, 0, 96 } } },  // Green for Player 2
    { { { 0, 0, 255, 96 } } },  // Blue for Player 3
    { { { 0, 0, 255, 128 } } }, // Blue for Player 4
};

// BAD CONTROLLER PAK / If you wish to change / Controller Pak or Rumble Pak, / please do so now.
char *sBadControllerPakMenuText[5] = { 0, 0, 0, 0, 0 };

// CONTROLLER PAK FULL / If you wish to change / Controller Pak or Rumble Pak, / please do so now.
char *sControllerPakFullMenuText[5] = { 0, 0, 0, 0, 0 };

// NO CONTROLLER PAK / If you wish to change / Controller Pak or Rumble Pak, / please do so now.
char *sNoControllerPakMenuText[5] = { 0, 0, 0, 0, 0 };

// CORRUPT DATA / If you wish to change / Controller Pak or Rumble Pak, / please do so now.
char *sCorruptDataMenuText[3] = { 0, 0, 0 }; // This should be 5 in size? This is unclear still.

char *D_800E09F8[3] = { 0, 0, 0 };

// If you wish to use / the Controller Pak / insert it now!
char *sInsertControllerPakMenuText[3] = { 0, 0, 0 };

s16 D_800E0A10[2] = { 0x0000, 0x0000 };

// If you wish to use / the Rumble Pak / insert it now!
char *sInsertRumblePakMenuText[4] = { 0, 0, 0, 0 };

s16 gRaceResultsObjectIndices[14] = { 0x0005, 0x003B, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036,
                                      0x0039, 0x0037, 0x0038, 0x003A, 0x0000, 0x0001, 0xFFFF };

s16 gRaceResultsImageIndices[8] = { 0x0004, 0x0000, 0x0001, 0xFFFF, 0x0300, 0x0000, 0x0012, 0xFFFF };

DrawTexture gMenuPortraitKrunch[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gMenuPortraitDiddy[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gMenuPortraitDrumstick[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gMenuPortraitBumper[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gMenuPortraitBanjo[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gMenuPortraitConker[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gMenuPortraitTiptup[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gMenuPortraitTT[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gMenuPortraitPipsy[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };
DrawTexture gMenuPortraitTimber[2] = { { NULL, 0, 0 }, { NULL, 0, 0 } };

DrawTexture *gRacerPortraits[10] = { gMenuPortraitKrunch, gMenuPortraitDiddy, gMenuPortraitDrumstick,
                                     gMenuPortraitBumper, gMenuPortraitBanjo, gMenuPortraitConker,
                                     gMenuPortraitTiptup, gMenuPortraitTT,    gMenuPortraitPipsy,
                                     gMenuPortraitTimber };

s16 unused_800E0B18[74] = { 0x0140, 0x017C, 0x01B8, 0x01F4, 0x0230, 0x026C, 0x02A8, 0x02E4, 0x01E0, 0x0000, 0x0018,
                            0x0039, 0x005A, 0x007B, 0x009C, 0x00BD, 0x00DE, 0x00FF, 0x00A0, 0x0000, 0x0140, 0x01B8,
                            0x0230, 0x02A8, 0x01E0, 0x0000, 0x0018, 0x0065, 0x00B3, 0x0100, 0x00A0, 0x0000, 0x0140,
                            0x01F4, 0x02A8, 0x01E0, 0x0028, 0x008C, 0x00F0, 0x00A0, 0x01E0, 0x00C0, 0x00A0, 0x00C0,
                            0xFF60, 0x00C0, 0xFF80, 0xFFEC, 0xFFE4, 0xFFE6, 0x0050, 0xFFF8, 0xFFE4, 0xFFF4, 0xFFE4,
                            0x0006, 0xFFE4, 0x0018, 0x0050, 0x0008, 0x0000, 0x0078, 0x0000, 0x003C, 0x0000, 0x001E,
                            0x0000, 0x0384, 0x0000, 0x001E, 0x0000, 0x001E, 0x0000, 0x0384 };

char gFirstPlace[4] = "1ST";
char gSecondPlace[4] = "2ND";
char gThirdPlace[4] = "3RD";
char gFourthPlace[4] = "4TH";
char gFifthPlace[4] = "5TH";
char gSixthPlace[4] = "6TH";
char gSeventhPlace[4] = "7TH";
char gEighthPlace[4] = "8TH";

char *gRacePlacementsArray[8] = { gFirstPlace, gSecondPlace, gThirdPlace,   gFourthPlace,
                                  gFifthPlace, gSixthPlace,  gSeventhPlace, gEighthPlace };

MenuElement gRaceResultsMenuElements[8] = {
    { 352, 172, 32, 172, -288, 172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 452, 166, 132, 166, -188, 166, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 560, 184, 240, 184, -80, 184, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 452, 180, 132, 180, -188, 180, 255, 192, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 1, { NULL }, { { 0, 0, 0, 0 } } },
    { 452, 198, 132, 198, -188, 198, 255, 192, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 1, { NULL }, { { 0, 0, 0, 0 } } },
    { 452, 216, 132, 216, -188, 216, 255, 192, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 1, { NULL }, { { 0, 0, 0, 0 } } },
    { 560, 200, 240, 200, -80, 200, 128, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 1, { NULL }, { { 0, 0, 0, 0 } } },
    {NULL}
};

MenuElement gRaceOrderMenuElements[11] = {
    { 575, 172, 255, 172, -65, 172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 542, 172, 222, 172, -98, 172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 509, 172, 189, 172, -131, 172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 476, 172, 156, 172, -164, 172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 443, 172, 123, 172, -197, 172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 410, 172, 90, 172, -230, 172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 377, 172, 57, 172, -263, 172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 344, 172, 24, 172, -296, 166, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 481, 166, 161, 166, -159, 166, 0, 0, 0, 255, 128, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 479, 164, 159, 164, -161, 164, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    {NULL}

};

MenuElement gRecordTimesMenuElements[9] = {
    { 481, 174, 161, 174, -159, 174, 0, 0, 0, 255, 128, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 479, 172, 159, 172, -161, 172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 12, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 368, 192, 48, 192, -272, 192, 255, 64, 64, 96, 255, ASSET_FONTS_FUNFONT, 8, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 506, 187, 186, 187, -134, 187, 255, 192, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 1, { NULL }, { { 0, 0, 0, 0 } } },
    { 578, 192, 258, 192, -62, 192, 255, 128, 255, 96, 255, ASSET_FONTS_FUNFONT, 12, 0, { &gCourseInitials }, { { 0, 0, 0, 0 } } },
    { 368, 212, 48, 212, -272, 212, 255, 64, 64, 96, 255, ASSET_FONTS_FUNFONT, 8, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 506, 207, 186, 207, -134, 207, 128, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 1, { NULL }, { { 0, 0, 0, 0 } } },
    { 578, 212, 258, 212, -62, 212, 255, 128, 255, 96, 255, ASSET_FONTS_FUNFONT, 12, 0, { &gFLapInitials }, { { 0, 0, 0, 0 } } }, {NULL}
};

// Valid characters for name input. Must be u8, not char.
// The length of the array must be a power of two.
u8 gFileNameValidChars[32] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.?    ";

char gCurFilenameCharBeingDrawn = '\0';
s32 gEnterInitalsY = 192;
s32 gFilenameX = 160;
s32 gFilenameY = 120;
s32 gFilenameFont = ASSET_FONTS_BIGFONT;
s32 gNameEntryLength = 0;
s32 D_800E0FA4 = 0;
char gCheckAdvEnterInitials[4] = "DKR"; // Default file name?
s32 D_800E0FAC = 0;
s32 gIndexOfCurInputCharacter = 0;

s16 gAdvTrackInitObjectIndices[18] = { 0x0004, 0x0000, 0x0001, 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D,
                                       0x001E, 0x001F, 0x0020, 0x0021, 0x0022, 0x0023, 0x0030, 0x005E, -1 };

s16 gAdvTrackInitImageIndices[6] = { 7, 0, 1, 2, 3, -1 };

s32 gRankingPlayerCount = 8; // Number of racers in trophy race? (1 to 8)
s32 gTrophyRaceWorldId = 0;
s32 gTrophyRaceRound = 0; // Rounds 1 - 4 (as 0 - 3)
s32 gPrevTrophyRaceRound = 0;

u32 unused_800E0FF4[4] = { 0x01FFFFFF, 0x0012FFFF, 0x81FFFFFF, 0x00120000 };

// Number of points to award in trophy race for each place.
s32 gTrophyRacePointsArray[8] = { 9, 7, 5, 3, 1, 0, 0, 0 };

s16 gTrophyRankingsObjectIndices[14] = { 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
                                         0x39, 0x3A, 0x3B, 0x00, 0x01, -1,   0x00 };

s16 gTrophyRaceImageIndices[3] = { 0, 1, -1 };

MenuElement gTrophyRankingsTitle[] = {
    { 320 + 160 + 1, 35, SCREEN_WIDTH_HALF + 1, 35, -159, 35, 0, 0, 0, 255, 128, ASSET_FONTS_BIGFONT, 12, 0, { 0 }, { { 0, 0, 0, 0 } } },
    { 320 + 160, 32, SCREEN_WIDTH_HALF, 32, -160, 32, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 12, 0, { 0 }, { { 0, 0, 0, 0 } } },
};
MenuElement gTrophyRankingsRacers[] = {
    { 64, -192, 64, 48, 64, 288, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 32, -192, 32, 48, 32, 288, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 0, { gFirstPlace }, { { 0, 0, 0, 0 } } },
    { 130, -172, 130, 68, 130, 308, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 4, 2, { &gTrophyRacePointsArray[0] }, { { 0, 0, 0, 0 } } },
    { 64, -150, 64, 90, 64, 330, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 32, -150, 32, 90, 32, 330, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 0, { gSecondPlace }, { { 0, 0, 0, 0 } } },
    { 130, -130, 130, 110, 130, 350, 255, 192, 255, 0, 255, ASSET_FONTS_FUNFONT, 4, 2, { &gTrophyRacePointsArray[1] }, { { 0, 0, 0, 0 } } },
    { 64, -108, 64, 132, 64, 372, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 32, -108, 32, 132, 32, 372, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 0, { gThirdPlace }, { { 0, 0, 0, 0 } } },
    { 130, -88, 130, 152, 130, 392, 255, 128, 255, 0, 255, ASSET_FONTS_FUNFONT, 4, 2, { &gTrophyRacePointsArray[2] }, { { 0, 0, 0, 0 } } },
    { 64, -66, 64, 174, 64, 414, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 32, -66, 32, 174, 32, 414, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 0, { gFourthPlace }, { { 0, 0, 0, 0 } } },
    { 130, -46, 130, 194, 130, 434, 255, 64, 255, 0, 255, ASSET_FONTS_FUNFONT, 4, 2, { &gTrophyRacePointsArray[3] }, { { 0, 0, 0, 0 } } },
    { 220, 288, 220, 48, 220, -192, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 188, 288, 188, 48, 188, -192, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 0, { gFifthPlace }, { { 0, 0, 0, 0 } } },
    { 286, 308, 286, 68, 286, -172, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 4, 2, { &gTrophyRacePointsArray[4] }, { { 0, 0, 0, 0 } } },
    { 220, 330, 220, 90, 220, -160, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 188, 330, 188, 90, 188, -150, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 0, { gSixthPlace }, { { 0, 0, 0, 0 } } },
    { 286, 350, 286, 110, 286, -130, 255, 192, 255, 0, 255, ASSET_FONTS_FUNFONT, 4, 2, { &gTrophyRacePointsArray[5] }, { { 0, 0, 0, 0 } } },
    { 220, 372, 220, 132, 220, -108, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 188, 372, 188, 132, 188, -108, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 0, { gSeventhPlace }, { { 0, 0, 0, 0 } } },
    { 286, 392, 286, 152, 286, -88, 255, 128, 255, 0, 255, ASSET_FONTS_FUNFONT, 4, 2, { &gTrophyRacePointsArray[6] }, { { 0, 0, 0, 0 } } },
    { 220, 414, 220, 174, 220, -66, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 3, { &gMenuPortraitKrunch }, { { 0, 0, 0, 0 } } },
    { 188, 414, 188, 174, 188, -66, 255, 255, 255, 0, 255, ASSET_FONTS_FUNFONT, 0, 0,  { gEighthPlace }, { { 0, 0, 0, 0 } } },
    { 286, 434, 286, 194, 286, -46, 255, 64, 255, 0, 255, ASSET_FONTS_FUNFONT, 4, 2, { &gTrophyRacePointsArray[7] }, { { 0, 0, 0, 0 } } },
    {NULL}
};
s16 gTrophyRankingsRawIconPositions[138] = {
    0x0040, 0x0020, 0x0082, 0x0040, 0x0020, 0x0082, 0x0040, 0x0020, 0x0082, 0x0040, 0x0020, 0x0082, 0x00DC, 0x00BC,
    0x011E, 0x00DC, 0x00BC, 0x011E, 0x00DC, 0x00BC, 0x011E, 0x00DC, 0x00BC, 0x011E, 0x0030, 0x0030, 0x0044, 0x005A,
    0x005A, 0x006E, 0x0084, 0x0084, 0x0098, 0x00AE, 0x00AE, 0x00C2, 0x0030, 0x0030, 0x0044, 0x005A, 0x005A, 0x006E,
    0x0084, 0x0084, 0x0098, 0x00AE, 0x00AE, 0x00C2, 0x0038, 0x0038, 0x0040, 0x006A, 0x006A, 0x0072, 0x009C, 0x009C,
    0x00A4, 0x00CE, 0x00CE, 0x00D6, 0x0038, 0x0038, 0x0040, 0x006A, 0x006A, 0x0072, 0x009C, 0x009C, 0x00A4, 0x00CE,
    0x00CE, 0x00D6, 0x0040, 0x0020, 0x0082, 0x0040, 0x0020, 0x0082, 0x0040, 0x0020, 0x0082, 0x00DC, 0x00BC, 0x011E,
    0x00DC, 0x00BC, 0x011E, 0x00DC, 0x00BC, 0x011E, 0x0034, 0x0034, 0x0048, 0x006F, 0x006F, 0x0083, 0x00AA, 0x00AA,
    0x00BE, 0x0034, 0x0034, 0x0048, 0x006F, 0x006F, 0x0083, 0x00AA, 0x00AA, 0x00BE, 0x004C, 0x004C, 0x0054, 0x007E,
    0x007E, 0x0086, 0x00B0, 0x00B0, 0x00B8, 0x004C, 0x004C, 0x0054, 0x007E, 0x007E, 0x0086, 0x00B0, 0x00B0, 0x00B8,
    0x008C, 0x006C, 0x00CE, 0x008C, 0x006C, 0x00CE, 0x008C, 0x006C, 0x00CE, 0x008C, 0x006C, 0x00CE
};

s16 *gTrophyRankingsIconPositions[32] = { NULL,
                                          NULL,
                                          NULL,
                                          NULL,
                                          &gTrophyRankingsRawIconPositions[126],
                                          &gTrophyRankingsRawIconPositions[90],
                                          &gTrophyRankingsRawIconPositions[126],
                                          &gTrophyRankingsRawIconPositions[24],
                                          NULL,
                                          NULL,
                                          &gTrophyRankingsRawIconPositions[72],
                                          &gTrophyRankingsRawIconPositions[90],
                                          NULL,
                                          NULL,
                                          &gTrophyRankingsRawIconPositions[0],
                                          &gTrophyRankingsRawIconPositions[24],
                                          NULL,
                                          NULL,
                                          NULL,
                                          NULL,
                                          &gTrophyRankingsRawIconPositions[126],
                                          &gTrophyRankingsRawIconPositions[108],
                                          &gTrophyRankingsRawIconPositions[126],
                                          &gTrophyRankingsRawIconPositions[48],
                                          NULL,
                                          NULL,
                                          &gTrophyRankingsRawIconPositions[72],
                                          &gTrophyRankingsRawIconPositions[108],
                                          NULL,
                                          NULL,
                                          &gTrophyRankingsRawIconPositions[0],
                                          &gTrophyRankingsRawIconPositions[48] };

// clang-format on

// DrawTextures for Dino Domain ghost background.
DrawTexture gDrawTexDinoDomainGhostBg[] = { { NULL, 0, 0 },    { NULL, 64, 0 },   { NULL, 128, 0 }, { NULL, 192, 0 },
                                            { NULL, 256, 0 },  { NULL, 0, 32 },   { NULL, 64, 32 }, { NULL, 128, 32 },
                                            { NULL, 192, 32 }, { NULL, 256, 32 }, { NULL, 0, 0 } };

// DrawTextures for Sherbet Island ghost background.
DrawTexture gDrawTexSherbetIslandGhostBg[] = { { NULL, 0, 0 },    { NULL, 64, 0 },   { NULL, 128, 0 },
                                               { NULL, 192, 0 },  { NULL, 256, 0 },  { NULL, 0, 32 },
                                               { NULL, 64, 32 },  { NULL, 128, 32 }, { NULL, 192, 32 },
                                               { NULL, 256, 32 }, { NULL, 0, 0 } };

// DrawTextures for Snowflake Mountain ghost background.
DrawTexture gDrawTexSnowflakeMountainGhostBg[] = { { NULL, 0, 0 },    { NULL, 64, 0 },   { NULL, 128, 0 },
                                                   { NULL, 192, 0 },  { NULL, 256, 0 },  { NULL, 0, 32 },
                                                   { NULL, 64, 32 },  { NULL, 128, 32 }, { NULL, 192, 32 },
                                                   { NULL, 256, 32 }, { NULL, 0, 0 } };

// DrawTextures for Dragon Forest ghost background.
DrawTexture gDrawTexDragonForestGhostBg[] = { { NULL, 0, 0 },    { NULL, 64, 0 },   { NULL, 128, 0 }, { NULL, 192, 0 },
                                              { NULL, 256, 0 },  { NULL, 0, 32 },   { NULL, 64, 32 }, { NULL, 128, 32 },
                                              { NULL, 192, 32 }, { NULL, 256, 32 }, { NULL, 0, 0 } };

// DrawTextures for Future Fun Land ghost background.
DrawTexture gDrawTexFutureFunLandGhostBg[] = { { NULL, 0, 0 },    { NULL, 64, 0 },   { NULL, 128, 0 },
                                               { NULL, 192, 0 },  { NULL, 256, 0 },  { NULL, 0, 32 },
                                               { NULL, 64, 32 },  { NULL, 128, 32 }, { NULL, 192, 32 },
                                               { NULL, 256, 32 }, { NULL, 0, 0 } };

DrawTexture *gDrawTexWorldBgs[5] = {
    gDrawTexDinoDomainGhostBg,        // Dino Domain
    gDrawTexSherbetIslandGhostBg,     // Sherbet Island
    gDrawTexSnowflakeMountainGhostBg, // Snowflake Mountain
    gDrawTexDragonForestGhostBg,      // Dragon Forest
    gDrawTexFutureFunLandGhostBg      // Future Fun Land
};

s16 gGhostDataObjectIndices[34] = { 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,
                                    0x1A, 0x1B, 0x1C, 0x1D, 0x32, 0x33, 0x34, 0x36, 0x35, 0x37, 0x38, 0x39,
                                    0x3A, 0x3B, 0x00, 0x01, 0x04, 0x3D, 0x3C, 0x3F, 0x3E, -1 };

s16 gGhostDataImageIndices[4] = { 0, 1, 7, -1 };

s16 gGhostDataElementPositions[10] = { 0x78, 0x12, 0x08, 0x06, 0xC0, 0x06, 0xD4, 0x1A, 0x78, 0x22 };

s16 gCinematicObjectIndices[12] = { 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, -1, 0 };

Gfx dCreditsFade[11] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_CLD_SURF, G_RM_CLD_SURF2),
    gsSPEndDisplayList(),
};

s16 gCreditsObjectIndices[12] = {
    0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, -1, 0
};

s16 gCreditsImageIndices[2] = { -1, 0 };

#define CREDITS_NO_FLAG (0)
#define CREDITS_END_FLAG (0x1000)
#define CREDITS_NEW_TITLE_FLAG (0x2000)
#define CREDITS_CONTINUE_TITLE_FLAG (0x3000)
#define CREDITS_NEXT_LEVEL_FLAG (0x4000)
#define CREDITS_UNK_FLAG (0x5000)
#define CREDITS_DEV_TIMES_FLAG (0x6000)

#define CREDITS_END (CREDITS_END_FLAG)
#define CREDITS_NEW_TITLE(seconds) (CREDITS_NEW_TITLE_FLAG | ((s16) (seconds * 60.0)))
#define CREDITS_CONTINUE_TITLE(seconds) (CREDITS_CONTINUE_TITLE_FLAG | ((s16) (seconds * 60.0)))
#define CREDITS_NEXT_LEVEL (CREDITS_NEXT_LEVEL_FLAG)
#define CREDITS_DEV_TIMES(seconds) (CREDITS_DEV_TIMES_FLAG | ((s16) (seconds * 60.0)))

// Number of seconds for each section in the credits.
#define CREDITS_DEFAULT_TITLE_TIME 2.75
#define CREDITS_MAGIC_CODE_TIME 4.5
#define CREDITS_DEV_TIMES_TIME 8.334

// clang-format off

// Data used to control the credits.
s16 gCreditsControlData[] = {
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    0, // "CREDITS"
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    1, 2, // "Software Director", "R.Harrison"
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    3, 4, 5, 6,
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    7, 8,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    9, 10, 11, 12,
    CREDITS_CONTINUE_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    13, 14, 15,
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    16, 17,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    18, 19,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    20,
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    21, 22,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    23, 24,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    25, 26,
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    27, 28, 29, 30, 31,
    CREDITS_CONTINUE_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    32, 33, 34, 35,
    CREDITS_CONTINUE_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    36, 37, 38,
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    39, 40, 41, 42, 43,
    CREDITS_CONTINUE_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    44, 45, 46,
    CREDITS_CONTINUE_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    47, 48, 49,
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    50, 51, 52, 53, 54,
    CREDITS_CONTINUE_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    55, 56, 57, 58,
    CREDITS_CONTINUE_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    59, 60, 61, 62,
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    63, 64, 65,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    66, 67, 68, 69, 70,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    71, 72, 73,
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    74, 75, // "Special Thanks To", "J.HOCHBERG"
    CREDITS_CONTINUE_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    76, // "H.LINCOLN"
    CREDITS_CONTINUE_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    77, // "M.ARAKAWA"
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    78, 79,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    80, 81,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    82, 83,
    CREDITS_NEXT_LEVEL,
    CREDITS_NEW_TITLE(CREDITS_DEFAULT_TITLE_TIME),
    84, // "THE END"
    CREDITS_NEW_TITLE(CREDITS_MAGIC_CODE_TIME),
    85, 86, // Magic Code Description, Magic Code
    CREDITS_NEXT_LEVEL,
    CREDITS_END, // Set to CREDITS_DEV_TIMES(CREDITS_DEV_TIMES_TIME) if you've beaten wizpig 2.
    0, 1, 2, 3,
    CREDITS_NEXT_LEVEL,
    CREDITS_DEV_TIMES(CREDITS_DEV_TIMES_TIME),
    4, 5, 6, 7,
    CREDITS_NEXT_LEVEL,
    CREDITS_DEV_TIMES(CREDITS_DEV_TIMES_TIME),
    8, 9, 10, 11,
    CREDITS_NEXT_LEVEL,
    CREDITS_DEV_TIMES(CREDITS_DEV_TIMES_TIME),
    12, 13, 14, 15,
    CREDITS_NEXT_LEVEL,
    CREDITS_DEV_TIMES(CREDITS_DEV_TIMES_TIME),
    16, 17, 18, 19,
    CREDITS_NEXT_LEVEL,
    CREDITS_END
};

// List of amazing people.
char *gCreditsArray[87] = { 
    "CREDITS",
    "Software Director",
    "R.Harrison",
    "Software Engineers",
    "P.Mountain", "J.Pegg", "R.Gale",
    "Art Director",
    "K.Bayliss",
    "3D Artists",
    "L.Musgrave", "K.Rabbette", "D.Smith", "J.Christensen", "B.Smyth", "P.Cunningham",
    "Music",
    "D.Wise",
    "Sound Effects",
    "G.Norgate",
    "ALSO",
    "Additional Design",
    "M.Wakeley", 
    "Documentation", 
    "L.Loveday", "Liason", "E.Hochberg",
    "Character Voices",
    "K.Bayliss", "J.Christensen", "E.Fischer", "K.Rabbette", "L.Ray", "L.Schuneman",
    "C.Seavor", "D.Smith", "J.Stamper", "K.Stamper", "C.Sutherland",
    "Rare Quality Assurance",
    "H.Ward", "G.Richards", "S.Farmer", "J.Williams", "D.Wong", "G.Jones", "M.Penny",
    "S.Brand", "S.Malpass", "A.Wilson",
    "NOA Thanks To",
    "M.Fukuda", "K.Lobb", "M.Kelbaugh", "A.Williams", "R.Johnson", "M.Forrest",
    "P.Sandhop", "H.Sterchi", "T.Hertzog", "D.Bridgham", "G.Richardson", "B.Smith",
    "NOA Thanks To",
    "NOA Tree House", "NOA Tree Branch", 
    "NCL Thank You's",
    "K.Terasaki", "M.Goto", "H.Yamada", "Mario Club",
    "NOE Thank You's",
    "J.Kraft", "J.Bardakoff",
    "Special Thanks To",
    "J.Hochberg", "H.Lincoln", "M.Arakawa",
    "Game Director",
    "L.Schuneman",
    "Producer",
    "C.Stamper",
    "Executive Producer",
    "T.Stamper",
    NULL,
    NULL,
    NULL };


// clang-format off

// Developer's best times for each track
char *gCreditsBestTimesArray[20] = {
    /***** Dino Domain *****/ "0:53:43", "1:21:55", "0:54:13", "1:22:48",
    /** Snowflake Mountain */ "1:04:11", "1:13:51", "1:25:01", "0:55:05",
    /**** Sherbet Island ***/ "1:37:63", "1:56:60", "0:57:81", "1:28:01",
    /**** Dragon Forest ****/ "1:51:15", "1:31:80", "2:03:16", "0:58:25",
    /*** Future Fun Land ***/ "2:00:38", "2:05:68", "1:52:96", "1:55:00"
};

char *gCreditsLastMessageArray[5] = {
    "THE END?", "TO BE CONTINUED ...", // Appears after beating the first wizpig race.
    "THE END",                         // Appears after beating the second wizpig race.
    "NO CHEAT", "THIS TIME.",          // Appears if you use the "WHODIDTHIS" cheat.
};

// Cheats that are shown in the credits.
s32 gCheatsInCreditsArray[21] = { CHEAT_BIG_CHARACTERS,
                                  CHEAT_SMALL_CHARACTERS,
                                  CHEAT_MUSIC_MENU,
                                  CHEAT_START_WITH_10_BANANAS,
                                  CHEAT_HORN_CHEAT,
                                  CHEAT_DISPLAY_CREDITS,
                                  CHEAT_DISABLE_WEAPONS,
                                  CHEAT_DISABLE_BANANAS,
                                  CHEAT_BANANAS_REDUCE_SPEED,
                                  CHEAT_NO_LIMIT_TO_BANANAS,
                                  CHEAT_ALL_BALLOONS_ARE_RED,
                                  CHEAT_ALL_BALLOONS_ARE_GREEN,
                                  CHEAT_ALL_BALLOONS_ARE_BLUE,
                                  CHEAT_ALL_BALLOONS_ARE_YELLOW,
                                  CHEAT_ALL_BALLOONS_ARE_RAINBOW,
                                  CHEAT_MAXIMUM_POWER_UP,
                                  CHEAT_TURN_OFF_ZIPPERS,
                                  CHEAT_SELECT_SAME_PLAYER,
                                  CHEAT_FOUR_WHEEL_DRIVER,
                                  CHEAT_TWO_PLAYER_ADVENTURE,
                                  CHEAT_ULTIMATE_AI };
#define NUMBER_CHEATS_IN_CREDITS sizeof(gCheatsInCreditsArray) / sizeof(s32)

s32 gViewingCreditsFromCheat = FALSE; // Set to 1 if viewing credits from "WHODIDTHIS" cheat

MenuElement gCreditsMenuElements[9] = {
    { 480, 104, 160, 104, -160, 104, 255, 0, 255, 48, 255, ASSET_FONTS_FUNFONT, 4, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 480, 132, 160, 132, -160, 132, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 4, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 480, 104, 160, 104, -160, 104, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 4, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 480, 132, 160, 132, -160, 132, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 4, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 480, 104, 160, 104, -160, 104, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 4, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 480, 132, 160, 132, -160, 132, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 4, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 480, 104, 160, 104, -160, 104, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 4, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 480, 132, 160, 132, -160, 132, 255, 255, 255, 0, 255, ASSET_FONTS_BIGFONT, 4, 0, { NULL }, { { 0, 0, 0, 0 } } },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, { NULL }, { { 0, 0, 0, 0 } } },
};

Gfx dMenuHudSettings[] = {
    gsDPPipeSync(),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPClearGeometryMode(G_ZBUFFER | G_FOG),
    gsSPEndDisplayList(),
};

UNUSED Gfx dMenuHudDrawModes[][2] = {
    {
        gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
        gsDPSetOtherMode(DKR_OMH_1CYC_POINT_NOPERSP, DKR_OML_COMMON | G_RM_XLU_SURF | G_RM_XLU_SURF2),
    },
    {
        gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_MODULATEIA),
        gsDPSetOtherMode(DKR_OMH_1CYC_BILERP, DKR_OML_COMMON | G_RM_XLU_SURF | G_RM_XLU_SURF2),
    },
    {
        gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
        gsDPSetOtherMode(DKR_OMH_1CYC_POINT_NOPERSP, DKR_OML_COMMON | G_RM_XLU_SURF | G_RM_XLU_SURF2),
    }
};

// Triangle indices for the wood panels used in multiple menus.
s8 gWoodPanelsIndices[32] = { 0,  1,  2,  0,  2,  3,  4,  5,  6,  4,  6,  7,  8,  9,  10, 8,
                              10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 0,  0 };

// UV coordinate indices the wood panels.
u8 gWoodPanelTexCoords[5][12] = { { 0, 0, 3, 0, 2, 1, 0, 0, 2, 1, 1, 1 },
                                  { 2, 1, 3, 0, 3, 3, 2, 1, 3, 3, 2, 2 },
                                  { 1, 2, 2, 2, 3, 3, 1, 2, 3, 3, 0, 3 },
                                  { 0, 0, 1, 1, 1, 2, 0, 0, 1, 2, 0, 3 },
                                  { 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2 } };

// Position offsets for the wood panels.
u16 gWoodPanelVertCoords[10][4] = { { 0, 0, 256, 0 },         { 511, 255, 1, 255 },   { 511, 255, 256, 0 },
                                    { 256, -256, 511, -255 }, { 1, -255, 511, -255 }, { 256, -256, 0, -256 },
                                    { 0, 0, 1, 255 },         { 1, -255, 0, -256 },   { 1, 255, 511, 255 },
                                    { 511, -255, 1, -255 } };

// Colour filter, used for the shadows on the side of the panels.
s16 gWoodPanelVertColours[5][4] = {
    { 216, 216, 216, 256 }, // Colour for top part of the panel
    { 176, 176, 176, 256 }, // Colour for right part of the panel
    { 96, 96, 96, 256 },    // Colour for bottom part of the panel
    { 136, 136, 136, 256 }, // Colour for left part of the panel
    { 256, 256, 256, 256 }  // Colour for the center of the panel
};

s32 *gWoodPanelVertices[2] = { NULL, NULL };

s32 *gWoodPanelTriangles[2] = { NULL, NULL };

s32 gMenuTrisFlip = 0;
s32 gWoodPanelCount = 0;
s32 gWoodPanelAllocCount = 0;

// U tex scale for wood panels (32 is 1.0x)
s32 gWoodPanelTexScaleU = 32;
// V tex scale for wood panels (32 is 1.0x)
s32 gWoodPanelTexScaleV = 32;

// Related to the file select wood panel highlight.
s16 D_800E1DC8[16] = { 1, 1, -1, 1, -1, 1, -1, -1, 1, -1, -1, -1, 1, 1, 1, -1 };

// Fade transition from the logo screen to the title screen.
FadeTransition gFadeLogoToTitleScreen = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_NONE, FADE_COLOR_BLACK, 120, -1);

char gRareCopyrightString[24] = "(C) COPYRIGHT RARE 1997";

// Fade transition between levels in the title screen demo.
FadeTransition gFadeTitleScreenDemo = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_NONE, FADE_COLOR_BLACK, 52, -1);

// Used in savemenu_render_element(). Used for controller pak adventure saves.
// So the first save in the pak would be (ADV.A), second save (ADV.B), etc.
char *gConPakAdvSavePrefix = " (ADV.";

/*******************************/

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/load_menu_text.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_button_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_8007FFEC.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_button_uvs.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_80080580.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_80080BC8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_geometry_end.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_80080E90.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/init_save_data.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/reset_title_logo_scale.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_timestamp_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_number_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/postrace_offsets.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/postrace_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/draw_menu_elements.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trackmenu_set_records.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_missing_controller.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_logos_screen_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_logo_screen_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/init_title_screen_variables.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_80083098.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_title_screen_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/render_title_screen.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_title_screen_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/titlescreen_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_options_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/optionscreen_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_options_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/optionscreen_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_audio_options_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_80084854.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_audio_options_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/soundoptions_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_save_options_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_render_element.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8240_E8E40.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8248_E8E48.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8250_E8E50.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8258_E8E58.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8260_E8E60.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E826C_E8E6C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8274_E8E74.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E827C_E8E7C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8284_E8E84.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E828C_E8E8C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8294_E8E94.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8298_E8E98.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E82A0_E8EA0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E82B4_E8EB4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E82C0_E8EC0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E82D4_E8ED4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E82E0_E8EE0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E82E8_E8EE8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E82F0_E8EF0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8300_E8F00.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E830C_E8F0C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8318_E8F18.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8324_E8F24.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8330_E8F30.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8338_E8F38.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8348_E8F48.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8350_E8F50.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8360_E8F60.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8368_E8F68.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8370_E8F70.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8380_E8F80.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E838C_E8F8C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8394_E8F94.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E83A8_E8FA8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E83B4_E8FB4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E83C4_E8FC4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E83D0_E8FD0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E83D8_E8FD8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E83E4_E8FE4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E83F8_E8FF8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8404_E9004.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8414_E9014.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8420_E9020.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E842C_E902C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8434_E9034.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8440_E9040.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E844C_E904C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8454_E9054.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8460_E9060.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E846C_E906C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E847C_E907C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8494_E9094.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E849C_E909C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E84A8_E90A8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E84B4_E90B4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E84C0_E90C0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E84C8_E90C8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E84D0_E90D0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E84D8_E90D8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E84E0_E90E0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E84EC_E90EC.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E84F8_E90F8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8508_E9108.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8514_E9114.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E851C_E911C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8528_E9128.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8534_E9134.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8540_E9140.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E854C_E914C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8558_E9158.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8564_E9164.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8570_E9170.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E857C_E917C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E858C_E918C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8594_E9194.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E85A4_E91A4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E85B4_E91B4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E85C4_E91C4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E85D4_E91D4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E85E0_E91E0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E85E8_E91E8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E85F4_E91F4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8600_E9200.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8610_E9210.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8618_E9218.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8624_E9224.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8638_E9238.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8644_E9244.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8650_E9250.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E865C_E925C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E866C_E926C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8678_E9278.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8684_E9284.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8690_E9290.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86A4_E92A4.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86B0_E92B0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86B8_E92B8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86C0_E92C0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86C8_E92C8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86D0_E92D0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86D8_E92D8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86E0_E92E0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86E8_E92E8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86F0_E92F0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E86F8_E92F8.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8700_E9300.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8708_E9308.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8710_E9310.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8718_E9318.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8720_E9320.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8728_E9328.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8730_E9330.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8738_E9338.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8740_E9340.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8748_E9348.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8750_E9350.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E875C_E935C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8770_E9370.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8778_E9378.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8784_E9384.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/D_800E8790_E9390.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_check_space.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_blank_save_destination.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_load_sources.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_load_destinations.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_move.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_write.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_render_error.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_input_source.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_input_dest.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_input_confirm.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_input_message.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_save_options_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/savemenu_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_80087F14.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/check_for_controller_pak_errors.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_boot_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_boot_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/bootscreen_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/bootscreen_init_cpak.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/pakmenu_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_controller_pak_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/pakmenu_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_magic_codes_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/cheatmenu_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_magic_codes_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/cheatmenu_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_magic_codes_list_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/cheatlist_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/cheatlist_exclusive.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_magic_codes_list_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/cheatlist_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/cheatmenu_checksum.s")

// These vars have to be defined after cheatmenu_checksum since that function has a static var in it.

s32 gTrackSelectSound = FALSE;

s8 D_800E1E20[8] = { 0, -1, 1, 0, 0, 1, -1, 0 };

s8 gGameStatusVisible = FALSE;

// TT Game Status textures, think these are potentially multi-part images.
s16 D_800E1E2C[10] = { 0x4C, 0x4D, 0x4E, 0x4F, 0x5B, 0x5C, 0x00, 0x42, -1, 0 };

// TT game status textures. And these maybe just standalone ones.
s16 D_800E1E40[10] = { 0x0D, 0x0E, 0x0F, 0x10, 0x08, 0x09, 0x00, 0x0A, -1, 0 };

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_prev.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/titlescreen_controller_assign.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_character_select_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_render_text.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_new_player.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_pick.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_input.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_assign_ai.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_character_select_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_move.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_music_channels.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_caution_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_caution_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/caution_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_game_select_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/gameselect_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_game_select_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/gameselect_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_file_select_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/fileselect_render_element.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/fileselect_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/fileselect_input_root.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/fileselect_input_copy.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/fileselect_input_erase.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_file_select_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/fileselect_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_init_vehicle_textures.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_init_arrow_textures.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_input.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trackmenu_active.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_track_select_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trackmenu_assets.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_track_select_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_track_select_unload.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_8008F618.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trackmenu_render_2D.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_8008FF1C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trackmenu_track_view.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trackmenu_input.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trackmenu_timetrial_sound.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trackmenu_setup_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_80092188.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trackmenu_staff_beaten.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_adventure_track_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/adventuretrack_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_adventure_track_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/adventuretrack_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_pause_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/pausemenu_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_pause_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_dialogue_end.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_close_dialogue.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_racer_portraits.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/postrace_start.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/postrace_load.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/postrace_music_fade.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_80094D28.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/postrace_message.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_postrace.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/postrace_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_results_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/results_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_results_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/results_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/filename_decompress.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/filename_compress.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/filename_trim.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/filename_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/filename_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/filename_enter.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_unload_bigfont.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trophyround_adventure.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_trophy_race_round_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trophyround_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_trophy_race_round_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trophyround_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_80098774.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_trophy_race_rankings_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/rankings_render_order.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_trophy_race_rankings_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/rankings_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_trophy_race_world_id.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/ghostmenu_generate.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/ghostmenu_erase.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_ghost_data_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/ghostmenu_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_ghost_data_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/ghostmenu_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/cinematic_start.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_cinematic_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_cinematic_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/cinematic_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_credits_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/credits_fade.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_credits_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/credits_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_camera_centre.s")

void func_8009BE54(void) {
}

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/reset_controller_sticks.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/update_controller_sticks.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/reset_character_id_slots.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_save_file_index.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_track_id_to_load.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_character_id_from_slot.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_character_id_from_slot_unused.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_player_selected_vehicle.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/set_player_selected_vehicle.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/charselect_status.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_player_character.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/enable_tracks_mode.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/is_in_tracks_mode.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/set_magic_code_flags.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_filtered_cheats.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_number_of_active_players.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_active_player_count.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_multiplayer_racer_count.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_all_save_files_ptr.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_title_reset.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_assetgroup_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_asset_free.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_assetgroup_load.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_asset_load.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_imagegroup_load.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_image_load.s")

void menu_imagegroup_free(void) {
}

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/menu_element_render.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/render_track_selection_viewport_border.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/dialogue_npc_finish.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/dialogue_try_close.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/npc_dialogue_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/set_option_text_colour.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/render_dialogue_option.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/handle_menu_joystick_input.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/func_8009D324.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/set_next_taj_challenge_menu.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/set_menu_id_if_option_equal.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/taj_menu_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/dialogue_race_defeat.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/tt_menu_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/dialogue_tt_gamestatus.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/trophy_race_cabinet_menu_loop.s")

void dialogue_open_stub(void) {
}

void dialogue_close_stub(void) {
}

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/dialogue_ortho.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_eeprom_settings_pointer.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/set_eeprom_settings_value.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/unset_eeprom_settings_value.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_eeprom_settings.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/get_language.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/set_language.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/is_adventure_two_unlocked.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/is_in_adventure_two.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/is_in_two_player_adventure.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/is_tt_unlocked.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/menu/is_drumstick_unlocked.s")

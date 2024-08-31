#include "common.h"
#include "thread3_main.h"

/************ .data ************/

UNUSED char gBuildString[40] = "Version 7.7 29/09/97 15.00 L.Schuneman";

s8 sAntiPiracyTriggered = 0;
UNUSED s32 D_800DD378 = 1;
s32 gSaveDataFlags = 0; // Official Name: load_save_flags
s32 gScreenStatus = OSMESG_SWAP_BUFFER;
s32 sControllerStatus = 0;
UNUSED s32 D_800DD388 = 0;
s8 gSkipGfxTask = FALSE;
s8 gDrumstickSceneLoadTimer = 0;
s16 gLevelLoadTimer = 0;
s8 gPauseLockTimer = 0; // If this is above zero, the player cannot pause the game.
s8 gFutureFunLandLevelTarget = FALSE;
s8 gDmemInvalid = FALSE;
UNUSED s32 D_800DD3A4 = 0;
UNUSED s32 D_800DD3A8 = 0;
UNUSED s32 D_800DD3AC = 0;
s32 gNumF3dCmdsPerPlayer[4] = { 4500, 7000, 11000, 11000 };
s32 gNumHudVertsPerPlayer[4] = { 300, 600, 850, 900 };
s32 gNumHudMatPerPlayer[4] = { 300, 400, 550, 600 };
s32 gNumHudTrisPerPlayer[4] = { 20, 30, 40, 50 };
s8 gDrawFrameTimer = 0;
FadeTransition D_800DD3F4 = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_OUT, FADE_COLOR_BLACK, 20, 0);
UNUSED FadeTransition D_800DD3FC = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_NONE, FADE_COLOR_WHITE, 20, -1);
s32 sLogicUpdateRate = LOGIC_5FPS;
FadeTransition gDrumstickSceneTransition = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_NONE, FADE_COLOR_WHITE, 30, -1);
UNUSED char *D_800DD410[3] = { "CAR", "HOV", "PLN" };
FadeTransition gLevelFadeOutTransition = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_NONE, FADE_COLOR_BLACK, 30, -1);
FadeTransition D_800DD424 = FADE_TRANSITION(FADE_FULLSCREEN, FADE_FLAG_NONE, FADE_COLOR_BLACK, 260, -1);

/*******************************/

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/thread3_main.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/init_game.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/main_game_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006CAE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/load_level_game.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/unload_level_game.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/ingame_logic_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006D8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006D8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006D8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006D968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/get_render_context.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/set_render_context.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/load_menu_with_level_background.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/set_level_default_vehicle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006DB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/get_level_default_vehicle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/load_level_menu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/unload_level_menu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/update_menu_scene.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006DCF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/load_level_for_menu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/calc_and_alloc_heap_for_settings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006E5BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006E770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006E994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006EA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/get_settings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/is_game_paused.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/is_postrace_viewport_active.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/is_reset_pressed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/get_ingame_map_id.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_to_read_flap_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_to_read_course_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_to_read_flap_and_course_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_read_save_file.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_read_all_save_files.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_to_write_flap_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_to_write_course_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_to_write_flap_and_course_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/force_mark_write_save_file.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/safe_mark_write_save_file.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_save_file_to_erase.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_read_eeprom_settings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/mark_write_eeprom_settings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/alloc_displaylist_heap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/check_dmem_validity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/default_alloc_displaylist_heap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006F140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006F20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/begin_trophy_race_teleport.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/begin_lighthouse_rocket_cutscene.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/begin_level_teleport.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006F388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/func_8006F398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/set_frame_blackout_timer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/pre_intro_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/is_controller_missing.s")

#pragma GLOBAL_ASM("asm/nonmatchings/thread3_main/check_imem_validity.s")

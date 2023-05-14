#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/game/init_level_globals.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006ABB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/search_level_properties_forwards.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/search_level_properties_backwards.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006B018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_world_level_count.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_map_default_vehicle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_map_available_vehicles.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_map_race_type.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_map_world_id.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_hub_area_id.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_number_of_levels_and_worlds.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/check_if_in_race.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/load_level.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006BD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006BD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_current_level_race_type.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_current_level_header.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_total_level_header_count.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_level_name.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/clear_audio_and_track.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006BFC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/frontCleanupMultiSelect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006C18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006C19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/push_level_property_stack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/pop_level_property_stack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/clear_level_property_stack.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_level_property_stack_pos.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006C300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/thread3_main.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/init_game.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/main_game_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006CAE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/load_level_game.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/unload_level_game.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/ingame_logic_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006D8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006D8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006D8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006D968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_render_context.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/set_render_context.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/load_menu_with_level_background.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/set_level_default_vehicle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006DB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_level_default_vehicle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/load_level_menu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/unload_level_menu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/update_menu_scene.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006DCF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/load_level_for_menu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/calc_and_alloc_heap_for_settings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006E5BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006E770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006E994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006EA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_settings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/is_game_paused.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/is_postrace_viewport_active.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/is_reset_pressed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/get_ingame_map_id.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_to_read_flap_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_to_read_course_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_to_read_flap_and_course_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_read_save_file.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_read_all_save_files.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_to_write_flap_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_to_write_course_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_to_write_flap_and_course_times.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/force_mark_write_save_file.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/safe_mark_write_save_file.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_save_file_to_erase.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_read_eeprom_settings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/mark_write_eeprom_settings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/alloc_displaylist_heap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/check_dmem_validity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/default_alloc_displaylist_heap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006F140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006F20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/begin_trophy_race_teleport.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/begin_lighthouse_rocket_cutscene.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/begin_level_teleport.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006F388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/func_8006F398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/set_frame_blackout_timer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/pre_intro_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/is_controller_missing.s")

#pragma GLOBAL_ASM("asm/nonmatchings/game/check_imem_validity.s")

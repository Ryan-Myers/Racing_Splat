#include "common.h"

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/input_get_id.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_80072378_72F78.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/rumble_init.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/rumble_exists.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/rumble_set.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/rumble_set_fade.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/rumble_start.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/rumble_stop.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/rumble_kill.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/rumble_update.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_80072C54.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_80072E28.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/populate_settings_from_save_data.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_800732E8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_80073588.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_800738A4.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_game_data_file_size.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_time_data_file_size.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_file_extension.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/read_game_data_from_controller_pak.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/write_game_data_to_controller_pak.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/read_time_data_from_controller_pak.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/write_time_data_to_controller_pak.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/read_save_file.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/erase_save_file.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/write_save_data.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/read_eeprom_data.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/write_eeprom_data.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/calculate_eeprom_settings_checksum.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/read_eeprom_settings.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/write_eeprom_settings.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/calculate_ghost_header_checksum.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_80074AA8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_ghost_data_file_size.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_80074B34.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_80074EB8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_80075000.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_800753D8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/func_800756D4.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_si_device_status.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/start_reading_controller_data.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/init_controller_paks.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/check_for_rumble_pak.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/repair_controller_pak.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/reformat_controller_pak.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_controller_pak_file_list.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/packDirectoryFree.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_free_space.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/delete_file.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/copy_controller_pak_data.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_file_number.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/read_data_from_controller_pak.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/write_controller_pak_file.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_file_size.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/font_codes_to_string.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/string_to_font_codes.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/save_data/get_file_type.s")

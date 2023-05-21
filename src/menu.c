#include "common.h"

// //gCreditsArray
// const char D_800E7D08[] = "CREDITS";
// const char D_800E7D10[] = "Software Director";
// const char D_800E7D24[] = "R.Harrison";
// const char D_800E7D30[] = "Software Engineers";
// const char D_800E7D44[] = "P.Mountain";
// const char D_800E7D50[] = "J.Pegg";
// const char D_800E7D58[] = "R.Gale";
// const char D_800E7D60[] = "Art Director";
// const char D_800E7D70[] = "K.Bayliss";
// const char D_800E7D7C[] = "3D Artists";
// const char D_800E7D88[] = "L.Musgrave";
// const char D_800E7D94[] = "K.Rabbette";
// const char D_800E7DA0[] = "D.Smith";
// const char D_800E7DA8[] = "J.Christensen";
// const char D_800E7DB8[] = "B.Smyth";
// const char D_800E7DC0[] = "P.Cunningham";
// const char D_800E7DD0[] = "Music";
// const char D_800E7DD8[] = "D.Wise";
// const char D_800E7DE0[] = "Sound Effects";
// const char D_800E7DF0[] = "G.Norgate";
// const char D_800E7DFC[] = "ALSO";
// const char D_800E7E04[] = "Additional Design";
// const char D_800E7E18[] = "M.Wakeley";
// const char D_800E7E24[] = "Documentation";
// const char D_800E7E34[] = "L.Loveday";
// const char D_800E7E40[] = "Liason";
// const char D_800E7E48[] = "E.Hochberg";
// const char D_800E7E54[] = "Character Voices";
// const char D_800E7E68[] = "K.Bayliss";
// const char D_800E7E74[] = "J.Christensen";
// const char D_800E7E84[] = "E.Fischer";
// const char D_800E7E90[] = "K.Rabbette";
// const char D_800E7E9C[] = "L.Ray";
// const char D_800E7EA4[] = "L.Schuneman";
// const char D_800E7EB0[] = "C.Seavor";
// const char D_800E7EBC[] = "D.Smith";
// const char D_800E7EC4[] = "J.Stamper";
// const char D_800E7ED0[] = "K.Stamper";
// const char D_800E7EDC[] = "C.Sutherland";
// const char D_800E7EEC[] = "Rare Quality Assurance";
// const char D_800E7F04[] = "H.Ward";
// const char D_800E7F0C[] = "G.Richards";
// const char D_800E7F18[] = "S.Farmer";
// const char D_800E7F24[] = "J.Williams";
// const char D_800E7F30[] = "D.Wong";
// const char D_800E7F38[] = "G.Jones";
// const char D_800E7F40[] = "M.Penny";
// const char D_800E7F48[] = "S.Brand";
// const char D_800E7F50[] = "S.Malpass";
// const char D_800E7F5C[] = "A.Wilson";
// const char D_800E7F68[] = "NOA Thanks To";
// const char D_800E7F78[] = "M.Fukuda";
// const char D_800E7F84[] = "K.Lobb";
// const char D_800E7F8C[] = "M.Kelbaugh";
// const char D_800E7F98[] = "A.Williams";
// const char D_800E7FA4[] = "R.Johnson";
// const char D_800E7FB0[] = "M.Forrest";
// const char D_800E7FBC[] = "P.Sandhop";
// const char D_800E7FC8[] = "H.Sterchi";
// const char D_800E7FD4[] = "T.Hertzog";
// const char D_800E7FE0[] = "D.Bridgham";
// const char D_800E7FEC[] = "G.Richardson";
// const char D_800E7FFC[] = "B.Smith";
// const char D_800E8004[] = "NOA Thanks To";
// const char D_800E8014[] = "NOA Tree House";
// const char D_800E8024[] = "NOA Tree Branch";
// const char D_800E8034[] = "NCL Thank You's";
// const char D_800E8044[] = "K.Terasaki";
// const char D_800E8050[] = "M.Goto";
// const char D_800E8058[] = "H.Yamada";
// const char D_800E8064[] = "Mario Club";
// const char D_800E8070[] = "NOE Thank You's";
// const char D_800E8080[] = "J.Kraft";
// const char D_800E8088[] = "J.Bardakoff";
// const char D_800E8094[] = "Special Thanks To";
// const char D_800E80A8[] = "J.Hochberg";
// const char D_800E80B4[] = "H.Lincoln";
// const char D_800E80C0[] = "M.Arakawa";
// const char D_800E80CC[] = "Game Director";
// const char D_800E80DC[] = "L.Schuneman";
// const char D_800E80E8[] = "Producer";
// const char D_800E80F4[] = "C.Stamper";
// const char D_800E8100[] = "Executive Producer";
// const char D_800E8114[] = "T.Stamper";

// //glabel gCreditsBestTimesArray
// const char D_800E8120[] = "0:53:43";
// const char D_800E8128[] = "1:21:55";
// const char D_800E8130[] = "0:54:13";
// const char D_800E8138[] = "1:22:48";
// const char D_800E8140[] = "1:04:11";
// const char D_800E8148[] = "1:13:51";
// const char D_800E8150[] = "1:25:01";
// const char D_800E8158[] = "0:55:05";
// const char D_800E8160[] = "1:37:63";
// const char D_800E8168[] = "1:56:60";
// const char D_800E8170[] = "0:57:81";
// const char D_800E8178[] = "1:28:01";
// const char D_800E8180[] = "1:51:15";
// const char D_800E8188[] = "1:31:80";
// const char D_800E8190[] = "2:03:16";
// const char D_800E8198[] = "0:58:25";
// const char D_800E81A0[] = "2:00:38";
// const char D_800E81A8[] = "2:05:68";
// const char D_800E81B0[] = "1:52:96";
// const char D_800E81B8[] = "1:55:00";

// //glabel gCreditsLastMessageArray
// const char D_800E81C0[] = "THE END?";
// const char D_800E81CC[] = "TO BE CONTINUED ...";
// const char D_800E81E0[] = "THE END";
// const char D_800E81E8[] = "NO CHEAT";
// const char D_800E81F4[] = "THIS TIME.";

// //D_800DF83C
// const char D_800E7CB0[] = "TIMBER";
// const char D_800E7CB8[] = "BUMPER";
// const char D_800E7CC0[] = "CONKER";
// const char D_800E7CC8[] = "TIPTUP";
// const char D_800E7CD0[] = "DRUMSTICK";
// const char D_800E7CDC[] = "PIPSY";
// const char D_800E7CE4[] = "BANJO";
// const char D_800E7CEC[] = "KRUNCH";
// const char D_800E7CF4[] = "WIZPIG";
// const char D_800E7CFC[] = "DIDDY";

// //glabel gQMarkPtr
// const char D_800E7D04[] = "?";

// //glabel D_800E1E10
// const char D_800E8200[] = " (ADV.";

#pragma GLOBAL_ASM("asm/nonmatchings/menu/load_menu_text.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8007FF88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8007FFEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80080518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80080580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80080BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80080E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80080E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80081218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/reset_title_logo_scale.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/show_timestamp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80081C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80081E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80081F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/draw_menu_elements.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800828B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/print_missing_controller_text.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_logos_screen_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_logo_screen_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/init_title_screen_variables.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80083098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_title_screen_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008377C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_title_screen_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/title_screen_exit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_options_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_options_menu_ui.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_options_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/unload_big_font_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_audio_options_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80084854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_audio_options_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800851FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_save_options_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800853D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80085B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800860A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800861C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800862C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800867D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80086A48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80086AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800871D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800874D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800875E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800876CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80087734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_save_options_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80087EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80087F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/check_for_controller_pak_errors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_boot_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_boot_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800887C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800887E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_controller_pak_ui.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_controller_pak_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800895A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_magic_codes_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_magic_codes_ui.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_magic_codes_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/unload_big_font_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_magic_codes_list_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_magic_codes_list_menu_text.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008A8F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_magic_codes_list_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008AD1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/calculate_and_display_rom_checksum.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008AEB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/set_active_player_index.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_character_select_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/draw_character_select_text.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008B358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008B4C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008B758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/randomise_ai_racer_slots.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_character_select_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008BFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008C128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008C168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_caution_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_caution_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/unload_big_font_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_game_select_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008C698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_game_select_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008CACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_file_select_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_menu_image.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_file_select_menu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008D5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008D8BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008DC7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_file_select_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008E428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/assign_vehicle_icon_textures.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008E4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008E4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008E790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_track_select_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008F00C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_track_select_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008F534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008F618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/renderTrackSelect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8008FF1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800904E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80090918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80090ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_track_select_setup_ui.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80092188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80092BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_adventure_track_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_adventure_track_setup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_adventure_track_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80093A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80093A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80093D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_pause_menu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/n_alSynRemovePlayer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/n_alSeqpDelete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/assign_racer_portrait_textures.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80094688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80094A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80094C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80094D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80095624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80095728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80096790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_11_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80096978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_results_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800976CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/decompress_filename_string.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/compress_filename_string.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/trim_filename_string.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80097874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_enter_filename_ui.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_enter_filename_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/unload_big_font_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80098208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_trophy_race_round_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/draw_trophy_race_text.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_trophy_race_round_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/unload_big_font_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80098774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_trophy_race_rankings_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80098EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_trophy_race_rankings_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80099600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_trophy_race_world_id.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009963C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_800998E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_ghost_data_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_80099E8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_ghost_data_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009ABAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009ABD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_23_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_23_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009AF18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_credits_init.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_credits_fade.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/menu_credits_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009BCF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009BD5C.s")

void func_8009BE54(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/menu/reset_controller_sticks.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/update_controller_sticks.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/reset_character_id_slots.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_save_file_index.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_track_id_to_load.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_character_id_from_slot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_character_id_from_slot_unused.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_player_selected_vehicle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/set_player_selected_vehicle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009C274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_player_character.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/enable_tracks_mode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/is_in_tracks_mode.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/set_magic_code_flags.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_filtered_cheats.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_number_of_active_players.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_active_player_count.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_multiplayer_racer_count.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_all_save_files_ptr.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009C49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009C4A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009C508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009C674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009C6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/allocate_menu_images.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/allocate_and_set_menu_image_properties.s")

void func_8009CA58(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009CA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_track_selection_viewport_border.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009CF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009CFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009CFEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/set_option_text_colour.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/render_dialogue_option.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/handle_menu_joystick_input.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009D324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/set_next_taj_challenge_menu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/set_menu_id_if_option_equal.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/taj_menu_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/dialogue_race_defeat.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/tt_menu_loop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009E3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/trophy_race_cabinet_menu_loop.s")

void dialogue_open_stub(void) {
}

void dialogue_close_stub(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8009E9B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_eeprom_settings_pointer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/set_eeprom_settings_value.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/unset_eeprom_settings_value.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_eeprom_settings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/get_language.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/set_language.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/is_adventure_two_unlocked.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/is_in_adventure_two.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/is_in_two_player_adventure.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/is_tt_unlocked.s")

#pragma GLOBAL_ASM("asm/nonmatchings/menu/is_drumstick_unlocked.s")

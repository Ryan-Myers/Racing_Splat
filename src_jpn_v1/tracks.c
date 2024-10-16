#include "common.h"

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/set_scene_viewport_num.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/init_track.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/render_scene.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_80025510.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_800257D0.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002581C.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_80026070.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_80026430.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_80026C14.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_80026E54.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_80027184.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_80027568.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_800278E8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/animate_level_textures.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/spawn_skydome.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/set_skydome_visbility.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_80028050.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/draw_gradient_background.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/render_skydome.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/initialise_player_viewport_vars.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/set_anti_aliasing.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/render_level_geometry_and_objects.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/render_level_segment.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/traverse_segments_bsp_tree.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/add_segment_to_order.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/check_if_inside_segment.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/get_level_segment_index_from_position.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/get_inside_segment_count_xz.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/get_inside_segment_count_xyz.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/get_segment.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/get_segment_bounding_box.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002A31C.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/should_segment_be_visible.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/check_if_in_draw_range.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002AC00.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/dayGetTrackFade.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002ACC8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002ACD4.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/get_wave_properties.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002B0F4.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002B9BC.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002BAB0.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002C0C4.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002C71C.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/get_current_level_model.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/free_track.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002C954.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002CC30.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/trackMakeAbsolute.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/render_object_shadow.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/render_object_water_effects.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/update_shadows.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002DE30.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002E234.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002E904.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002EEEC.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002F2AC.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002F440.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002FA64.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002FD74.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_8002FF6C.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/func_800304C8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/set_fog.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/get_fog_settings.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/reset_fog.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/update_fog.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/apply_fog.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/obj_loop_fogchanger.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/slowly_change_fog.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/update_perspective_and_envmap.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/tracks/compute_scene_camera_transform_matrix.s")

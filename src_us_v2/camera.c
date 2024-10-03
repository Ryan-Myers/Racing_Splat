#include "common.h"

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/camera_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/func_80066060.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/set_viewport_tv_type.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/func_800660C0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/func_800660D0.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_current_camera_fov.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/update_camera_fov.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/calculate_camera_perspective.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/matrix_get_model_s16.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_viewport_count.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_current_viewport.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/camera_init_tracks_menu.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_distance_to_active_camera.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/camera_reset.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/write_to_object_render_stack.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/check_if_showing_cutscene_camera.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/disable_cutscene_camera.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/set_active_viewports_and_max.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/set_active_camera.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/copy_viewports_to_stack.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/camEnableUserView.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/camDisableUserView.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/check_viewport_background_flag.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/viewport_menu_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/set_viewport_properties.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/copy_viewport_background_size_to_coords.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/copy_viewport_frame_size_to_coords.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/copy_framebuffer_size_to_coords.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/func_80066CDC.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/viewport_scissor.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/func_80067D3C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/set_ortho_matrix_height.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/set_ortho_matrix_view.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/func_8006807C.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/viewport_rsp_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/viewport_reset.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/matrix_world_origin.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/sprite_anim_off.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/render_sprite_billboard.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/render_ortho_triangle_image.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/apply_object_shear_matrix.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/camera_push_model_mtx.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/apply_head_turning_matrix.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_modelmatrix_vector.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/apply_matrix_from_stack.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/translate_camera_segment.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/transform_camera_segment.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/rotate_camera_segment.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_active_camera_segment_no_cutscenes.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_active_camera_segment.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_cutscene_camera_segment.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_projection_matrix_f32.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_projection_matrix_s16.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_camera_matrix.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/get_distance_to_camera.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/set_camera_shake_by_distance.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/set_camera_shake.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/debug_print_fixed_matrix_values.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/camera/debug_print_float_matrix_values.s")

#include "common.h"

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/audio_init.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_volume_reset.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_volume_change.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_change_off.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_change_on.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_play.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_voicelimit_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_voicelimit_change_off.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_voicelimit_change_on.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_jingle_voicelimit_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/func_80000C68.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_fade.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_volume_reset.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_update_queue.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_play_delayed.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_clear_delayed.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_get_mask.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_dynamic_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_off.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_active.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_on.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_pan_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_volume_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_volume.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_fade_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_fade.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_channel_reset_all.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/func_80001358.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/func_80001440.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_tempo_set_relative.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_tempo_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_tempo.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_is_playing.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_animation_fraction.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_get_properties.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_jingle_play_safe.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_jingle_tempo_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_stop.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_enabled_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_can_play.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_jingle_stop.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_current_sequence.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_next.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_jingle_current.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_volume_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_volume_config_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_volume.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_volume_config.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_jingle_volume_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_jingle_pan_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_jingle_play.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_jingle_playing.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_channel_volume_all.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_distance.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_play.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_play_spatial.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/func_80001F14.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_volume_set_relative.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_volume_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_pitch_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_count.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_sequence_count.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_table_properties.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_table_properties.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/gSoundBank_GetSoundDecayTime.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_seqplayer_init.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_sequence_start.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_sequence_init.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/music_sequence_stop.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_reverb_set.s")

#pragma GLOBAL_ASM("asm_pal_v1/nonmatchings/audio/sound_reverb_enabled.s")

#include "common.h"

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/audio_init.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/reset_sound_volume.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/adjust_audio_volume.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80000B18.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80000B28.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/play_music.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/set_music_player_voice_limit.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80000C1C.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80000C2C.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/set_sndfx_player_voice_limit.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80000C68.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/set_music_fade_timer.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80000CBC.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/handle_music_fade.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80000FDC.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001050.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/musicGetChanMask.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001074.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001114.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/musicGetChnlActive.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001170.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/musicSetChlPan.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/musicSetChlVol.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/musicGetChlVol.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001268.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_800012A8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_800012E8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001358.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001440.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/multiply_music_tempo.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/musicSetTempo.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/musicGetTempo.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/music_is_playing.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/audio_get_chr_select_anim_frac.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001728.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001784.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/sfxSetTempo.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001844.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001878.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_800018D0.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_800018E0.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001918.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001954.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001980.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/set_relative_volume_for_music.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/set_music_volume_slider.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/musicGetRelativeVolume.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/musicGetVolSliderPercentage.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/sfxSetRelativeVolume.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/sfxSetPan.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/play_sequence.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001C08.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/set_all_channel_volume.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001CB8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/play_sound_global.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/play_sound_spatial.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001F14.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80001FB8.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_8000208C.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/amSndSetPitchDirect.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/ALBankFile_80115D14_GetSoundCount.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/ALSeqFile_80115CF8_GetSeqCount.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80002128.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_8000216C.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/ALBankFile_80115D14_GetSoundDecayTime.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80002224.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_800022BC.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_8000232C.s")

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80002570.s")

void func_800649FC(u8 arg0);
void func_80002608(u8 arg0) {
    func_800649FC(arg0);
}

#pragma GLOBAL_ASM("asm_jpn_v1/nonmatchings/audio/func_80002630.s")

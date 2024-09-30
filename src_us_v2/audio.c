#include "common.h"

/* The comment below is needed for this file to be picked up by generate_ld */
/* RAM_POS: 0x80000450 */

#include "audio.h"
#include "memory.h"

#include "types.h"
#include "macros.h"
#include "asset_enums.h"
#include "asset_loading.h"
#include "audio_internal.h"
#include "audiomgr.h"
#include "audiosfx.h"
#include "sched.h"
#include "libultra/src/audio/seqchannel.h"

/************ .data ************/

ALSeqPlayer *gMusicPlayer = NULL;
ALSeqPlayer *gJinglePlayer = NULL;
u8 gMusicBaseVolume = 127;
u8 sfxRelativeVolume = 127;
u8 gCanPlayMusic = TRUE;
u8 gCanPlayJingle = FALSE;
s32 gBlockMusicChange = FALSE;
s32 audioPrevCount = 0;
f32 sMusicFadeVolume = 1.0f;
s32 gMusicSliderVolume = 256;
s32 gDelayedSoundsCount = 0;
u8 gMusicNextSeqID = SEQUENCE_NONE;
u8 gJingleNextSeqID = SEQUENCE_NONE;
UNUSED s32 D_800DC664 = 0;
UNUSED s32 D_800DC668 = 0;
s32 gGlobalMusicVolume = 256; // This is never not 256...
u8 gBlockVoiceLimitChange = FALSE;

/*******************************/

/************ .bss ************/

// The audio heap is located at the start of the BSS section.
u8 gBssSectionStart[AUDIO_HEAP_SIZE];

ALHeap gALHeap;
ALSeqFile *gSequenceTable;
void *gMusicSequenceData;
void *gJingleSequenceData;
u8 gCurrentSequenceID;
u8 gCurrentJingleID;
s32 gMusicTempo;
u32 *gSeqLengthTable;
ALBankFile *gSequenceBank;
ALBankFile *gSoundBank;
SoundData *gSoundTable;
MusicData *gSeqSoundTable;
s32 gSoundCount;
s32 gSeqSoundCount;
u32 gSoundTableSize;
u32 gSeqSoundTableSize;
s16 sMusicTempo;
f32 gMusicAnimationTick;
s32 sMusicDelayTimer;
s32 sMusicDelayLength;
u8 gMusicPlaying;
u8 gJinglePlaying;
DelayedSound gDelayedSounds[8];
ALCSeq gMusicSequence;
ALCSeq gJingleSequence;
u8 gSkipResetChannels; // Stored and used by a single function, but redundant.
u8 gAudioVolumeSetting;
u32 gDynamicMusicChannelMask;
SoundMask *gGlobalSoundMask;
SoundMask *gSpatialSoundMask;
SoundMask *gRacerSoundMask;


#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/audio_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_volume_reset.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_volume_change.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_change_off.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_change_on.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_play.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_voicelimit_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_voicelimit_change_off.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_voicelimit_change_on.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_jingle_voicelimit_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/func_80000C68.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_fade.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_volume_reset.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_update_queue.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_play_delayed.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_clear_delayed.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_get_mask.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_dynamic_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_off.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_active.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_on.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_pan_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_volume_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_volume.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_fade_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_fade.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_channel_reset_all.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/func_80001358.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/func_80001440.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_tempo_set_relative.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_tempo_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_tempo.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_is_playing.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_animation_fraction.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_get_properties.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_jingle_play_safe.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_jingle_tempo_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_stop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_enabled_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_can_play.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_jingle_stop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_current_sequence.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_next.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_jingle_current.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_volume_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_volume_config_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_volume.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_volume_config.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_jingle_volume_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_jingle_pan_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_jingle_play.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_jingle_playing.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_channel_volume_all.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_distance.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_play.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_play_spatial.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/func_80001F14.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_volume_set_relative.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_volume_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_pitch_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_count.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_sequence_count.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_table_properties.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_table_properties.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/gSoundBank_GetSoundDecayTime.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_seqplayer_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_sequence_start.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_sequence_init.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/music_sequence_stop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_reverb_set.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/audio/sound_reverb_enabled.s")

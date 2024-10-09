/* The comment below is needed for this file to be picked up by generate_ld */
/* RAM_POS: 0x80076BA0 */

#include "asset_loading.h"

// #include "assets.h"
#include "macros.h"
#include "ultra64.h"

/************ .bss ************/

OSIoMesg gAssetsDmaIoMesg;
OSMesg gDmaMesg;
OSMesgQueue gDmaMesgQueue;
OSMesg gPIMesgBuf[16];
OSMesgQueue gPIMesgQueue;
u32 *gAssetsLookupTable;
OSMesgQueue *D_80124818_ED178; // NEW BSS
u32 *D_80124830_ED190; // NEW BSS

/*******************************/

// These are both defined in the generated dkr.ld file.
extern u8 __ASSETS_LUT_START[], __ASSETS_LUT_END[]; // __ASSETS_LUT_START = 0xECB60, _END = 0xECC30


#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/asset_loading/init_PI_mesg_queue.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/asset_loading/load_asset_section_from_rom.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/asset_loading/load_compressed_asset_from_rom.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/asset_loading/load_asset_section_from_rom_to_address.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/asset_loading/load_asset_to_address.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/asset_loading/get_rom_offset_of_asset.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/asset_loading/get_size_of_asset_section.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/asset_loading/dmacopy.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/asset_loading/func_800773D4_77FD4.s")

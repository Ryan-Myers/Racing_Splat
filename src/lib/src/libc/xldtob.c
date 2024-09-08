
/* The comment below is needed for this file to be picked up by generate_ld */
/* RAM_POS: 0x800D69A0 */

#include "macros.h"

const double pows[] = {10e0L, 10e1L, 10e3L, 10e7L, 10e15L, 10e31L, 10e63L, 10e127L, 10e255L};
const char Ldtob_NaN[] = "NaN";
const char Ldtob_Inf[] = "Inf";
const char _Genld_0_string[] = "0";

#pragma GLOBAL_ASM("asm/nonmatchings/lib/src/libc/xldtob/_Genld.s")
#pragma GLOBAL_ASM("asm/nonmatchings/lib/src/libc/xldtob/_Ldtob.s")

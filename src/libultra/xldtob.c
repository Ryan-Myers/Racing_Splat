#include "common.h"
#include "stdlib.h"
#include "string.h"
#include "xstdio.h"

static s16 _Ldunscale(s16* pex, _Pft* px);
static void _Genld(_Pft* px, char code, u8* p, s16 nsig, s16 xexp);

static const double pows[] = {10e0L, 10e1L, 10e3L, 10e7L, 10e15L, 10e31L, 10e63L, 10e127L, 10e255L};

#pragma GLOBAL_ASM("asm/nonmatchings/libultra/xldtob/_Genld.s")

#pragma GLOBAL_ASM("asm/nonmatchings/libultra/xldtob/_Ldtob.s")

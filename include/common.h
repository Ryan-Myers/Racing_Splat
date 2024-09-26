#include "types.h"

#if   defined(VERSION_us_v1)
#define Func80019808Checksum 0x35281
#define ViewportFuncChecksum 0x585E
#define TractionTableChecksum 116315
#define ObjLoopGoldenBalloonChecksum 0xA597
#elif defined(VERSION_pal_v1)
#define Func80019808Checksum 0x34E72
#define ViewportFuncChecksum 0x59E5
#define TractionTableChecksum 0x1C38F
#define ObjLoopGoldenBalloonChecksum 0xA6FF
#else
#define Func80019808Checksum 0x35281
#define ViewportFuncChecksum 0x585E
#define TractionTableChecksum 116315
#define ObjLoopGoldenBalloonChecksum 0xA597
#endif

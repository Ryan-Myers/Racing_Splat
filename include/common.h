#ifndef COMMON_H
#define COMMON_H

#define VERSION_77 77 // NA / PAL V1
#define VERSION_79 79 // Japan
#define VERSION_80 80 // NA / PAL V2

#define REGION_NA  1
#define REGION_PAL 2
#define REGION_JP  3

#if   defined(VERSION_us_v1)
#define Func80019808Checksum 0x35281
#define ViewportFuncChecksum 0x585E
#define TractionTableChecksum 0x1C65B
#define ObjLoopGoldenBalloonChecksum 0xA597
#define VERSION VERSION_77
#define REGION REGION_NA
#elif defined(VERSION_pal_v1)
#define Func80019808Checksum 0x34E72
#define ViewportFuncChecksum 0x59E5
#define TractionTableChecksum 0x1C38F
#define ObjLoopGoldenBalloonChecksum 0xA6FF
#define VERSION VERSION_77
#define REGION REGION_PAL
#elif defined(VERSION_jp_v1)
#define Func80019808Checksum 0x0000
#define ViewportFuncChecksum 0x0000
#define TractionTableChecksum 0x0000
#define ObjLoopGoldenBalloonChecksum 0xA597
#define VERSION VERSION_79
#define REGION REGION_NA
#elif defined(VERSION_us_v2)
#define Func80019808Checksum 0x34B94
#define ViewportFuncChecksum 0x5881
#define TractionTableChecksum 0x1CA13
#define ObjLoopGoldenBalloonChecksum 0xA745
#define VERSION VERSION_80
#define REGION REGION_NA
#elif defined(VERSION_pal_v2)
#define Func80019808Checksum 0x0000
#define ViewportFuncChecksum 0x0000
#define TractionTableChecksum 0x0000
#define ObjLoopGoldenBalloonChecksum 0x0000
#define VERSION VERSION_80
#define REGION REGION_PAL
#else
// Default to NA V1 if somehow we don't have a proper define.
#define Func80019808Checksum 0x35281
#define ViewportFuncChecksum 0x585E
#define TractionTableChecksum 0x1C65B
#define ObjLoopGoldenBalloonChecksum 0xA597
#define VERSION VERSION_77
#define REGION REGION_NA
#endif

#endif // COMMON_H

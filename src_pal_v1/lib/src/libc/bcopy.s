.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.30.0 */

/* Handwritten function */
glabel bcopy
/* CAA30 800C9E30 10C0001A */  beqz       $a2, .L800C9E9C_CAA9C
/* CAA34 800C9E34 00A03825 */   or        $a3, $a1, $zero
/* CAA38 800C9E38 10850018 */  beq        $a0, $a1, .L800C9E9C_CAA9C
/* CAA3C 800C9E3C 00A4082A */   slt       $at, $a1, $a0
/* CAA40 800C9E40 54200008 */  bnel       $at, $zero, .L800C9E64_CAA64
/* CAA44 800C9E44 28C10010 */   slti      $at, $a2, 0x10
/* CAA48 800C9E48 00861020 */  add        $v0, $a0, $a2 /* handwritten instruction */
/* CAA4C 800C9E4C 00A2082A */  slt        $at, $a1, $v0
/* CAA50 800C9E50 50200004 */  beql       $at, $zero, .L800C9E64_CAA64
/* CAA54 800C9E54 28C10010 */   slti      $at, $a2, 0x10
/* CAA58 800C9E58 1000005B */  b          .L800C9FC8_CABC8
/* CAA5C 800C9E5C 28C10010 */   slti      $at, $a2, 0x10
/* CAA60 800C9E60 28C10010 */  slti       $at, $a2, 0x10
.L800C9E64_CAA64:
/* CAA64 800C9E64 14200005 */  bnez       $at, .L800C9E7C_CAA7C
/* CAA68 800C9E68 00000000 */   nop
/* CAA6C 800C9E6C 30820003 */  andi       $v0, $a0, 0x3
/* CAA70 800C9E70 30A30003 */  andi       $v1, $a1, 0x3
/* CAA74 800C9E74 1043000B */  beq        $v0, $v1, .L800C9EA4_CAAA4
/* CAA78 800C9E78 00000000 */   nop
.L800C9E7C_CAA7C:
/* CAA7C 800C9E7C 10C00007 */  beqz       $a2, .L800C9E9C_CAA9C
/* CAA80 800C9E80 00000000 */   nop
/* CAA84 800C9E84 00861821 */  addu       $v1, $a0, $a2
.L800C9E88_CAA88:
/* CAA88 800C9E88 80820000 */  lb         $v0, 0x0($a0)
/* CAA8C 800C9E8C 24840001 */  addiu      $a0, $a0, 0x1
/* CAA90 800C9E90 24A50001 */  addiu      $a1, $a1, 0x1
/* CAA94 800C9E94 1483FFFC */  bne        $a0, $v1, .L800C9E88_CAA88
/* CAA98 800C9E98 A0A2FFFF */   sb        $v0, -0x1($a1)
.L800C9E9C_CAA9C:
/* CAA9C 800C9E9C 03E00008 */  jr         $ra
/* CAAA0 800C9EA0 00E01025 */   or        $v0, $a3, $zero
.L800C9EA4_CAAA4:
/* CAAA4 800C9EA4 10400018 */  beqz       $v0, .L800C9F08_CAB08
/* CAAA8 800C9EA8 24010001 */   addiu     $at, $zero, 0x1
/* CAAAC 800C9EAC 1041000F */  beq        $v0, $at, .L800C9EEC_CAAEC
/* CAAB0 800C9EB0 24010002 */   addiu     $at, $zero, 0x2
/* CAAB4 800C9EB4 50410008 */  beql       $v0, $at, .L800C9ED8_CAAD8
/* CAAB8 800C9EB8 84820000 */   lh        $v0, 0x0($a0)
/* CAABC 800C9EBC 80820000 */  lb         $v0, 0x0($a0)
/* CAAC0 800C9EC0 24840001 */  addiu      $a0, $a0, 0x1
/* CAAC4 800C9EC4 24A50001 */  addiu      $a1, $a1, 0x1
/* CAAC8 800C9EC8 24C6FFFF */  addiu      $a2, $a2, -0x1
/* CAACC 800C9ECC 1000000E */  b          .L800C9F08_CAB08
/* CAAD0 800C9ED0 A0A2FFFF */   sb        $v0, -0x1($a1)
/* CAAD4 800C9ED4 84820000 */  lh         $v0, 0x0($a0)
.L800C9ED8_CAAD8:
/* CAAD8 800C9ED8 24840002 */  addiu      $a0, $a0, 0x2
/* CAADC 800C9EDC 24A50002 */  addiu      $a1, $a1, 0x2
/* CAAE0 800C9EE0 24C6FFFE */  addiu      $a2, $a2, -0x2
/* CAAE4 800C9EE4 10000008 */  b          .L800C9F08_CAB08
/* CAAE8 800C9EE8 A4A2FFFE */   sh        $v0, -0x2($a1)
.L800C9EEC_CAAEC:
/* CAAEC 800C9EEC 80820000 */  lb         $v0, 0x0($a0)
/* CAAF0 800C9EF0 84830001 */  lh         $v1, 0x1($a0)
/* CAAF4 800C9EF4 24840003 */  addiu      $a0, $a0, 0x3
/* CAAF8 800C9EF8 24A50003 */  addiu      $a1, $a1, 0x3
/* CAAFC 800C9EFC 24C6FFFD */  addiu      $a2, $a2, -0x3
/* CAB00 800C9F00 A0A2FFFD */  sb         $v0, -0x3($a1)
/* CAB04 800C9F04 A4A3FFFE */  sh         $v1, -0x2($a1)
.L800C9F08_CAB08:
/* CAB08 800C9F08 28C10020 */  slti       $at, $a2, 0x20
/* CAB0C 800C9F0C 54200016 */  bnel       $at, $zero, .L800C9F68_CAB68
/* CAB10 800C9F10 28C10010 */   slti      $at, $a2, 0x10
/* CAB14 800C9F14 8C820000 */  lw         $v0, 0x0($a0)
/* CAB18 800C9F18 8C830004 */  lw         $v1, 0x4($a0)
/* CAB1C 800C9F1C 8C880008 */  lw         $t0, 0x8($a0)
/* CAB20 800C9F20 8C89000C */  lw         $t1, 0xC($a0)
/* CAB24 800C9F24 8C8A0010 */  lw         $t2, 0x10($a0)
/* CAB28 800C9F28 8C8B0014 */  lw         $t3, 0x14($a0)
/* CAB2C 800C9F2C 8C8C0018 */  lw         $t4, 0x18($a0)
/* CAB30 800C9F30 8C8D001C */  lw         $t5, 0x1C($a0)
/* CAB34 800C9F34 24840020 */  addiu      $a0, $a0, 0x20
/* CAB38 800C9F38 24A50020 */  addiu      $a1, $a1, 0x20
/* CAB3C 800C9F3C 24C6FFE0 */  addiu      $a2, $a2, -0x20
/* CAB40 800C9F40 ACA2FFE0 */  sw         $v0, -0x20($a1)
/* CAB44 800C9F44 ACA3FFE4 */  sw         $v1, -0x1C($a1)
/* CAB48 800C9F48 ACA8FFE8 */  sw         $t0, -0x18($a1)
/* CAB4C 800C9F4C ACA9FFEC */  sw         $t1, -0x14($a1)
/* CAB50 800C9F50 ACAAFFF0 */  sw         $t2, -0x10($a1)
/* CAB54 800C9F54 ACABFFF4 */  sw         $t3, -0xC($a1)
/* CAB58 800C9F58 ACACFFF8 */  sw         $t4, -0x8($a1)
/* CAB5C 800C9F5C 1000FFEA */  b          .L800C9F08_CAB08
/* CAB60 800C9F60 ACADFFFC */   sw        $t5, -0x4($a1)
.L800C9F64_CAB64:
/* CAB64 800C9F64 28C10010 */  slti       $at, $a2, 0x10
.L800C9F68_CAB68:
/* CAB68 800C9F68 5420000E */  bnel       $at, $zero, .L800C9FA4_CABA4
/* CAB6C 800C9F6C 28C10004 */   slti      $at, $a2, 0x4
/* CAB70 800C9F70 8C820000 */  lw         $v0, 0x0($a0)
/* CAB74 800C9F74 8C830004 */  lw         $v1, 0x4($a0)
/* CAB78 800C9F78 8C880008 */  lw         $t0, 0x8($a0)
/* CAB7C 800C9F7C 8C89000C */  lw         $t1, 0xC($a0)
/* CAB80 800C9F80 24840010 */  addiu      $a0, $a0, 0x10
/* CAB84 800C9F84 24A50010 */  addiu      $a1, $a1, 0x10
/* CAB88 800C9F88 24C6FFF0 */  addiu      $a2, $a2, -0x10
/* CAB8C 800C9F8C ACA2FFF0 */  sw         $v0, -0x10($a1)
/* CAB90 800C9F90 ACA3FFF4 */  sw         $v1, -0xC($a1)
/* CAB94 800C9F94 ACA8FFF8 */  sw         $t0, -0x8($a1)
/* CAB98 800C9F98 1000FFF2 */  b          .L800C9F64_CAB64
/* CAB9C 800C9F9C ACA9FFFC */   sw        $t1, -0x4($a1)
.L800C9FA0_CABA0:
/* CABA0 800C9FA0 28C10004 */  slti       $at, $a2, 0x4
.L800C9FA4_CABA4:
/* CABA4 800C9FA4 1420FFB5 */  bnez       $at, .L800C9E7C_CAA7C
/* CABA8 800C9FA8 00000000 */   nop
/* CABAC 800C9FAC 8C820000 */  lw         $v0, 0x0($a0)
/* CABB0 800C9FB0 24840004 */  addiu      $a0, $a0, 0x4
/* CABB4 800C9FB4 24A50004 */  addiu      $a1, $a1, 0x4
/* CABB8 800C9FB8 24C6FFFC */  addiu      $a2, $a2, -0x4
/* CABBC 800C9FBC 1000FFF8 */  b          .L800C9FA0_CABA0
/* CABC0 800C9FC0 ACA2FFFC */   sw        $v0, -0x4($a1)
/* CABC4 800C9FC4 28C10010 */  slti       $at, $a2, 0x10
.L800C9FC8_CABC8:
/* CABC8 800C9FC8 00862020 */  add        $a0, $a0, $a2 /* handwritten instruction */
/* CABCC 800C9FCC 14200005 */  bnez       $at, .L800C9FE4_CABE4
/* CABD0 800C9FD0 00A62820 */   add       $a1, $a1, $a2 /* handwritten instruction */
/* CABD4 800C9FD4 30820003 */  andi       $v0, $a0, 0x3
/* CABD8 800C9FD8 30A30003 */  andi       $v1, $a1, 0x3
/* CABDC 800C9FDC 1043000D */  beq        $v0, $v1, .L800CA014_CAC14
/* CABE0 800C9FE0 00000000 */   nop
.L800C9FE4_CABE4:
/* CABE4 800C9FE4 10C0FFAD */  beqz       $a2, .L800C9E9C_CAA9C
/* CABE8 800C9FE8 00000000 */   nop
/* CABEC 800C9FEC 2484FFFF */  addiu      $a0, $a0, -0x1
/* CABF0 800C9FF0 24A5FFFF */  addiu      $a1, $a1, -0x1
/* CABF4 800C9FF4 00861823 */  subu       $v1, $a0, $a2
.L800C9FF8_CABF8:
/* CABF8 800C9FF8 80820000 */  lb         $v0, 0x0($a0)
/* CABFC 800C9FFC 2484FFFF */  addiu      $a0, $a0, -0x1
/* CAC00 800CA000 24A5FFFF */  addiu      $a1, $a1, -0x1
/* CAC04 800CA004 1483FFFC */  bne        $a0, $v1, .L800C9FF8_CABF8
/* CAC08 800CA008 A0A20001 */   sb        $v0, 0x1($a1)
/* CAC0C 800CA00C 03E00008 */  jr         $ra
/* CAC10 800CA010 00E01025 */   or        $v0, $a3, $zero
.L800CA014_CAC14:
/* CAC14 800CA014 10400018 */  beqz       $v0, .L800CA078_CAC78
/* CAC18 800CA018 24010003 */   addiu     $at, $zero, 0x3
/* CAC1C 800CA01C 1041000F */  beq        $v0, $at, .L800CA05C_CAC5C
/* CAC20 800CA020 24010002 */   addiu     $at, $zero, 0x2
/* CAC24 800CA024 50410008 */  beql       $v0, $at, .L800CA048_CAC48
/* CAC28 800CA028 8482FFFE */   lh        $v0, -0x2($a0)
/* CAC2C 800CA02C 8082FFFF */  lb         $v0, -0x1($a0)
/* CAC30 800CA030 2484FFFF */  addiu      $a0, $a0, -0x1
/* CAC34 800CA034 24A5FFFF */  addiu      $a1, $a1, -0x1
/* CAC38 800CA038 24C6FFFF */  addiu      $a2, $a2, -0x1
/* CAC3C 800CA03C 1000000E */  b          .L800CA078_CAC78
/* CAC40 800CA040 A0A20000 */   sb        $v0, 0x0($a1)
/* CAC44 800CA044 8482FFFE */  lh         $v0, -0x2($a0)
.L800CA048_CAC48:
/* CAC48 800CA048 2484FFFE */  addiu      $a0, $a0, -0x2
/* CAC4C 800CA04C 24A5FFFE */  addiu      $a1, $a1, -0x2
/* CAC50 800CA050 24C6FFFE */  addiu      $a2, $a2, -0x2
/* CAC54 800CA054 10000008 */  b          .L800CA078_CAC78
/* CAC58 800CA058 A4A20000 */   sh        $v0, 0x0($a1)
.L800CA05C_CAC5C:
/* CAC5C 800CA05C 8082FFFF */  lb         $v0, -0x1($a0)
/* CAC60 800CA060 8483FFFD */  lh         $v1, -0x3($a0)
/* CAC64 800CA064 2484FFFD */  addiu      $a0, $a0, -0x3
/* CAC68 800CA068 24A5FFFD */  addiu      $a1, $a1, -0x3
/* CAC6C 800CA06C 24C6FFFD */  addiu      $a2, $a2, -0x3
/* CAC70 800CA070 A0A20002 */  sb         $v0, 0x2($a1)
/* CAC74 800CA074 A4A30000 */  sh         $v1, 0x0($a1)
.L800CA078_CAC78:
/* CAC78 800CA078 28C10020 */  slti       $at, $a2, 0x20
/* CAC7C 800CA07C 54200016 */  bnel       $at, $zero, .L800CA0D8_CACD8
/* CAC80 800CA080 28C10010 */   slti      $at, $a2, 0x10
/* CAC84 800CA084 8C82FFFC */  lw         $v0, -0x4($a0)
/* CAC88 800CA088 8C83FFF8 */  lw         $v1, -0x8($a0)
/* CAC8C 800CA08C 8C88FFF4 */  lw         $t0, -0xC($a0)
/* CAC90 800CA090 8C89FFF0 */  lw         $t1, -0x10($a0)
/* CAC94 800CA094 8C8AFFEC */  lw         $t2, -0x14($a0)
/* CAC98 800CA098 8C8BFFE8 */  lw         $t3, -0x18($a0)
/* CAC9C 800CA09C 8C8CFFE4 */  lw         $t4, -0x1C($a0)
/* CACA0 800CA0A0 8C8DFFE0 */  lw         $t5, -0x20($a0)
/* CACA4 800CA0A4 2484FFE0 */  addiu      $a0, $a0, -0x20
/* CACA8 800CA0A8 24A5FFE0 */  addiu      $a1, $a1, -0x20
/* CACAC 800CA0AC 24C6FFE0 */  addiu      $a2, $a2, -0x20
/* CACB0 800CA0B0 ACA2001C */  sw         $v0, 0x1C($a1)
/* CACB4 800CA0B4 ACA30018 */  sw         $v1, 0x18($a1)
/* CACB8 800CA0B8 ACA80014 */  sw         $t0, 0x14($a1)
/* CACBC 800CA0BC ACA90010 */  sw         $t1, 0x10($a1)
/* CACC0 800CA0C0 ACAA000C */  sw         $t2, 0xC($a1)
/* CACC4 800CA0C4 ACAB0008 */  sw         $t3, 0x8($a1)
/* CACC8 800CA0C8 ACAC0004 */  sw         $t4, 0x4($a1)
/* CACCC 800CA0CC 1000FFEA */  b          .L800CA078_CAC78
/* CACD0 800CA0D0 ACAD0000 */   sw        $t5, 0x0($a1)
.L800CA0D4_CACD4:
/* CACD4 800CA0D4 28C10010 */  slti       $at, $a2, 0x10
.L800CA0D8_CACD8:
/* CACD8 800CA0D8 5420000E */  bnel       $at, $zero, .L800CA114_CAD14
/* CACDC 800CA0DC 28C10004 */   slti      $at, $a2, 0x4
/* CACE0 800CA0E0 8C82FFFC */  lw         $v0, -0x4($a0)
/* CACE4 800CA0E4 8C83FFF8 */  lw         $v1, -0x8($a0)
/* CACE8 800CA0E8 8C88FFF4 */  lw         $t0, -0xC($a0)
/* CACEC 800CA0EC 8C89FFF0 */  lw         $t1, -0x10($a0)
/* CACF0 800CA0F0 2484FFF0 */  addiu      $a0, $a0, -0x10
/* CACF4 800CA0F4 24A5FFF0 */  addiu      $a1, $a1, -0x10
/* CACF8 800CA0F8 24C6FFF0 */  addiu      $a2, $a2, -0x10
/* CACFC 800CA0FC ACA2000C */  sw         $v0, 0xC($a1)
/* CAD00 800CA100 ACA30008 */  sw         $v1, 0x8($a1)
/* CAD04 800CA104 ACA80004 */  sw         $t0, 0x4($a1)
/* CAD08 800CA108 1000FFF2 */  b          .L800CA0D4_CACD4
/* CAD0C 800CA10C ACA90000 */   sw        $t1, 0x0($a1)
.L800CA110_CAD10:
/* CAD10 800CA110 28C10004 */  slti       $at, $a2, 0x4
.L800CA114_CAD14:
/* CAD14 800CA114 1420FFB3 */  bnez       $at, .L800C9FE4_CABE4
/* CAD18 800CA118 00000000 */   nop
/* CAD1C 800CA11C 8C82FFFC */  lw         $v0, -0x4($a0)
/* CAD20 800CA120 2484FFFC */  addiu      $a0, $a0, -0x4
/* CAD24 800CA124 24A5FFFC */  addiu      $a1, $a1, -0x4
/* CAD28 800CA128 24C6FFFC */  addiu      $a2, $a2, -0x4
/* CAD2C 800CA12C 1000FFF8 */  b          .L800CA110_CAD10
/* CAD30 800CA130 ACA20000 */   sw        $v0, 0x0($a1)
/* CAD34 800CA134 00000000 */  nop
/* CAD38 800CA138 00000000 */  nop
/* CAD3C 800CA13C 00000000 */  nop
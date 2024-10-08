.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.30.0 */

/* Handwritten function */
glabel object_animate
/* 62B70 80061F70 27BDFFF8 */  addiu      $sp, $sp, -0x8
/* 62B74 80061F74 AFB10004 */  sw         $s1, 0x4($sp)
/* 62B78 80061F78 AFB00000 */  sw         $s0, 0x0($sp)
/* 62B7C 80061F7C 8088003A */  lb         $t0, 0x3A($a0)
/* 62B80 80061F80 05030003 */  bgezl      $t0, .L80061F90_62B90
/* 62B84 80061F84 8C890040 */   lw        $t1, 0x40($a0)
/* 62B88 80061F88 00004025 */  or         $t0, $zero, $zero
/* 62B8C 80061F8C 8C890040 */  lw         $t1, 0x40($a0)
.L80061F90_62B90:
/* 62B90 80061F90 812A0055 */  lb         $t2, 0x55($t1)
/* 62B94 80061F94 010A082A */  slt        $at, $t0, $t2
/* 62B98 80061F98 54200003 */  bnel       $at, $zero, .L80061FA8_62BA8
/* 62B9C 80061F9C 8C890068 */   lw        $t1, 0x68($a0)
/* 62BA0 80061FA0 01404025 */  or         $t0, $t2, $zero
/* 62BA4 80061FA4 8C890068 */  lw         $t1, 0x68($a0)
.L80061FA8_62BA8:
/* 62BA8 80061FA8 00084080 */  sll        $t0, $t0, 2
/* 62BAC 80061FAC 01284820 */  add        $t1, $t1, $t0 /* handwritten instruction */
/* 62BB0 80061FB0 8D250000 */  lw         $a1, 0x0($t1)
/* 62BB4 80061FB4 8CA60000 */  lw         $a2, 0x0($a1)
/* 62BB8 80061FB8 8CC80044 */  lw         $t0, 0x44($a2)
/* 62BBC 80061FBC 55000004 */  bnel       $t0, $zero, .L80061FD0_62BD0
/* 62BC0 80061FC0 84990018 */   lh        $t9, 0x18($a0)
/* 62BC4 80061FC4 1000013D */  b          .L800624BC_630BC
/* 62BC8 80061FC8 00001025 */   or        $v0, $zero, $zero
/* 62BCC 80061FCC 84990018 */  lh         $t9, 0x18($a0)
.L80061FD0_62BD0:
/* 62BD0 80061FD0 84A80014 */  lh         $t0, 0x14($a1)
/* 62BD4 80061FD4 8087003B */  lb         $a3, 0x3B($a0)
/* 62BD8 80061FD8 17280006 */  bne        $t9, $t0, .L80061FF4_62BF4
/* 62BDC 80061FDC 00000000 */   nop
/* 62BE0 80061FE0 84A80010 */  lh         $t0, 0x10($a1)
/* 62BE4 80061FE4 14E80003 */  bne        $a3, $t0, .L80061FF4_62BF4
/* 62BE8 80061FE8 00000000 */   nop
/* 62BEC 80061FEC 10000133 */  b          .L800624BC_630BC
/* 62BF0 80061FF0 00001025 */   or        $v0, $zero, $zero
.L80061FF4_62BF4:
/* 62BF4 80061FF4 04E30003 */  bgezl      $a3, .L80062004_62C04
/* 62BF8 80061FF8 84C80048 */   lh        $t0, 0x48($a2)
/* 62BFC 80061FFC 00003825 */  or         $a3, $zero, $zero
/* 62C00 80062000 84C80048 */  lh         $t0, 0x48($a2)
.L80062004_62C04:
/* 62C04 80062004 00E8082A */  slt        $at, $a3, $t0
/* 62C08 80062008 14200002 */  bnez       $at, .L80062014_62C14
/* 62C0C 8006200C 00000000 */   nop
/* 62C10 80062010 2507FFFF */  addiu      $a3, $t0, -0x1
.L80062014_62C14:
/* 62C14 80062014 19000006 */  blez       $t0, .L80062030_62C30
/* 62C18 80062018 00005025 */   or        $t2, $zero, $zero
/* 62C1C 8006201C 8CC90044 */  lw         $t1, 0x44($a2)
/* 62C20 80062020 000710C0 */  sll        $v0, $a3, 3
/* 62C24 80062024 01224820 */  add        $t1, $t1, $v0 /* handwritten instruction */
/* 62C28 80062028 8D2A0004 */  lw         $t2, 0x4($t1)
/* 62C2C 8006202C 214AFFFE */  addi       $t2, $t2, -0x2 /* handwritten instruction */
.L80062030_62C30:
/* 62C30 80062030 00192102 */  srl        $a0, $t9, 4
/* 62C34 80062034 04830004 */  bgezl      $a0, .L80062048_62C48
/* 62C38 80062038 0144082A */   slt       $at, $t2, $a0
/* 62C3C 8006203C 0140C825 */  or         $t9, $t2, $zero
/* 62C40 80062040 000A2102 */  srl        $a0, $t2, 4
/* 62C44 80062044 0144082A */  slt        $at, $t2, $a0
.L80062048_62C48:
/* 62C48 80062048 50200006 */  beql       $at, $zero, .L80062064_62C64
/* 62C4C 8006204C 84A80010 */   lh        $t0, 0x10($a1)
/* 62C50 80062050 2408FFFF */  addiu      $t0, $zero, -0x1
/* 62C54 80062054 0000C825 */  or         $t9, $zero, $zero
/* 62C58 80062058 00002025 */  or         $a0, $zero, $zero
/* 62C5C 8006205C A4A80010 */  sh         $t0, 0x10($a1)
/* 62C60 80062060 84A80010 */  lh         $t0, 0x10($a1)
.L80062064_62C64:
/* 62C64 80062064 8CB1000C */  lw         $s1, 0xC($a1)
/* 62C68 80062068 50E80004 */  beql       $a3, $t0, .L8006207C_62C7C
/* 62C6C 8006206C 84B00012 */   lh        $s0, 0x12($a1)
/* 62C70 80062070 10000002 */  b          .L8006207C_62C7C
/* 62C74 80062074 2410FFFF */   addiu     $s0, $zero, -0x1
/* 62C78 80062078 84B00012 */  lh         $s0, 0x12($a1)
.L8006207C_62C7C:
/* 62C7C 8006207C A4A70010 */  sh         $a3, 0x10($a1)
/* 62C80 80062080 A4B90014 */  sh         $t9, 0x14($a1)
/* 62C84 80062084 A4A40012 */  sh         $a0, 0x12($a1)
/* 62C88 80062088 10800006 */  beqz       $a0, .L800620A4_62CA4
/* 62C8C 8006208C 3338000F */   andi      $t8, $t9, 0xF
/* 62C90 80062090 2401FFFF */  addiu      $at, $zero, -0x1
/* 62C94 80062094 52010004 */  beql       $s0, $at, .L800620A8_62CA8
/* 62C98 80062098 8CC20044 */   lw        $v0, 0x44($a2)
/* 62C9C 8006209C 10000026 */  b          .L80062138_62D38
/* 62CA0 800620A0 84C3004A */   lh        $v1, 0x4A($a2)
.L800620A4_62CA4:
/* 62CA4 800620A4 8CC20044 */  lw         $v0, 0x44($a2)
.L800620A8_62CA8:
/* 62CA8 800620A8 000718C0 */  sll        $v1, $a3, 3
/* 62CAC 800620AC 8CCD004C */  lw         $t5, 0x4C($a2)
/* 62CB0 800620B0 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 62CB4 800620B4 8C4E0000 */  lw         $t6, 0x0($v0)
/* 62CB8 800620B8 84C20024 */  lh         $v0, 0x24($a2)
/* 62CBC 800620BC 8CCF0004 */  lw         $t7, 0x4($a2)
/* 62CC0 800620C0 25CE000C */  addiu      $t6, $t6, 0xC
/* 62CC4 800620C4 00021040 */  sll        $v0, $v0, 1
/* 62CC8 800620C8 01A25820 */  add        $t3, $t5, $v0 /* handwritten instruction */
.L800620CC_62CCC:
/* 62CCC 800620CC 85A20000 */  lh         $v0, 0x0($t5)
/* 62CD0 800620D0 2401FFFF */  addiu      $at, $zero, -0x1
/* 62CD4 800620D4 50410013 */  beql       $v0, $at, .L80062124_62D24
/* 62CD8 800620D8 25AD0002 */   addiu     $t5, $t5, 0x2
/* 62CDC 800620DC 00021880 */  sll        $v1, $v0, 2
/* 62CE0 800620E0 00021040 */  sll        $v0, $v0, 1
/* 62CE4 800620E4 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 62CE8 800620E8 02221820 */  add        $v1, $s1, $v0 /* handwritten instruction */
/* 62CEC 800620EC 01C21020 */  add        $v0, $t6, $v0 /* handwritten instruction */
/* 62CF0 800620F0 85E80000 */  lh         $t0, 0x0($t7)
/* 62CF4 800620F4 84490000 */  lh         $t1, 0x0($v0)
/* 62CF8 800620F8 01095020 */  add        $t2, $t0, $t1 /* handwritten instruction */
/* 62CFC 800620FC A46A0000 */  sh         $t2, 0x0($v1)
/* 62D00 80062100 85E80002 */  lh         $t0, 0x2($t7)
/* 62D04 80062104 84490002 */  lh         $t1, 0x2($v0)
/* 62D08 80062108 01095020 */  add        $t2, $t0, $t1 /* handwritten instruction */
/* 62D0C 8006210C A46A0002 */  sh         $t2, 0x2($v1)
/* 62D10 80062110 85E80004 */  lh         $t0, 0x4($t7)
/* 62D14 80062114 84490004 */  lh         $t1, 0x4($v0)
/* 62D18 80062118 01095020 */  add        $t2, $t0, $t1 /* handwritten instruction */
/* 62D1C 8006211C A46A0004 */  sh         $t2, 0x4($v1)
/* 62D20 80062120 25AD0002 */  addiu      $t5, $t5, 0x2
.L80062124_62D24:
/* 62D24 80062124 01AB082A */  slt        $at, $t5, $t3
/* 62D28 80062128 1420FFE8 */  bnez       $at, .L800620CC_62CCC
/* 62D2C 8006212C 25EF000A */   addiu     $t7, $t7, 0xA
/* 62D30 80062130 00008025 */  or         $s0, $zero, $zero
/* 62D34 80062134 84C3004A */  lh         $v1, 0x4A($a2)
.L80062138_62D38:
/* 62D38 80062138 0204082A */  slt        $at, $s0, $a0
/* 62D3C 8006213C 00631020 */  add        $v0, $v1, $v1 /* handwritten instruction */
/* 62D40 80062140 00436020 */  add        $t4, $v0, $v1 /* handwritten instruction */
/* 62D44 80062144 10200026 */  beqz       $at, .L800621E0_62DE0
/* 62D48 80062148 258C000C */   addiu     $t4, $t4, 0xC
/* 62D4C 8006214C 8CC20044 */  lw         $v0, 0x44($a2)
/* 62D50 80062150 000718C0 */  sll        $v1, $a3, 3
/* 62D54 80062154 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 62D58 80062158 26030002 */  addiu      $v1, $s0, 0x2
/* 62D5C 8006215C 01830019 */  multu      $t4, $v1
/* 62D60 80062160 8C4A0000 */  lw         $t2, 0x0($v0)
/* 62D64 80062164 00001812 */  mflo       $v1
/* 62D68 80062168 01435020 */  add        $t2, $t2, $v1 /* handwritten instruction */
/* 62D6C 8006216C 00000000 */  nop
/* 62D70 80062170 84C2004A */  lh         $v0, 0x4A($a2)
.L80062174_62D74:
/* 62D74 80062174 01407025 */  or         $t6, $t2, $zero
/* 62D78 80062178 02206825 */  or         $t5, $s1, $zero
/* 62D7C 8006217C 00021880 */  sll        $v1, $v0, 2
/* 62D80 80062180 00021040 */  sll        $v0, $v0, 1
/* 62D84 80062184 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 62D88 80062188 014C5020 */  add        $t2, $t2, $t4 /* handwritten instruction */
/* 62D8C 8006218C 01A25820 */  add        $t3, $t5, $v0 /* handwritten instruction */
.L80062190_62D90:
/* 62D90 80062190 85A80000 */  lh         $t0, 0x0($t5)
/* 62D94 80062194 81C90000 */  lb         $t1, 0x0($t6)
/* 62D98 80062198 25AD0006 */  addiu      $t5, $t5, 0x6
/* 62D9C 8006219C 01AB082A */  slt        $at, $t5, $t3
/* 62DA0 800621A0 01094020 */  add        $t0, $t0, $t1 /* handwritten instruction */
/* 62DA4 800621A4 A5A8FFFA */  sh         $t0, -0x6($t5)
/* 62DA8 800621A8 85A8FFFC */  lh         $t0, -0x4($t5)
/* 62DAC 800621AC 81C90001 */  lb         $t1, 0x1($t6)
/* 62DB0 800621B0 25CE0003 */  addiu      $t6, $t6, 0x3
/* 62DB4 800621B4 01094020 */  add        $t0, $t0, $t1 /* handwritten instruction */
/* 62DB8 800621B8 A5A8FFFC */  sh         $t0, -0x4($t5)
/* 62DBC 800621BC 85A8FFFE */  lh         $t0, -0x2($t5)
/* 62DC0 800621C0 81C9FFFF */  lb         $t1, -0x1($t6)
/* 62DC4 800621C4 01094020 */  add        $t0, $t0, $t1 /* handwritten instruction */
/* 62DC8 800621C8 1420FFF1 */  bnez       $at, .L80062190_62D90
/* 62DCC 800621CC A5A8FFFE */   sh        $t0, -0x2($t5)
/* 62DD0 800621D0 26100001 */  addiu      $s0, $s0, 0x1
/* 62DD4 800621D4 0204082A */  slt        $at, $s0, $a0
/* 62DD8 800621D8 5420FFE6 */  bnel       $at, $zero, .L80062174_62D74
/* 62DDC 800621DC 84C2004A */   lh        $v0, 0x4A($a2)
.L800621E0_62DE0:
/* 62DE0 800621E0 0090082A */  slt        $at, $a0, $s0
/* 62DE4 800621E4 50200027 */  beql       $at, $zero, .L80062284_62E84
/* 62DE8 800621E8 8CC20044 */   lw        $v0, 0x44($a2)
/* 62DEC 800621EC 8CC20044 */  lw         $v0, 0x44($a2)
/* 62DF0 800621F0 000718C0 */  sll        $v1, $a3, 3
/* 62DF4 800621F4 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 62DF8 800621F8 26030002 */  addiu      $v1, $s0, 0x2
/* 62DFC 800621FC 01830019 */  multu      $t4, $v1
/* 62E00 80062200 8C4A0000 */  lw         $t2, 0x0($v0)
/* 62E04 80062204 00001812 */  mflo       $v1
/* 62E08 80062208 01435020 */  add        $t2, $t2, $v1 /* handwritten instruction */
/* 62E0C 8006220C 00000000 */  nop
/* 62E10 80062210 84C2004A */  lh         $v0, 0x4A($a2)
.L80062214_62E14:
/* 62E14 80062214 014C5022 */  sub        $t2, $t2, $t4 /* handwritten instruction */
/* 62E18 80062218 02206825 */  or         $t5, $s1, $zero
/* 62E1C 8006221C 00021880 */  sll        $v1, $v0, 2
/* 62E20 80062220 00021040 */  sll        $v0, $v0, 1
/* 62E24 80062224 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 62E28 80062228 2610FFFF */  addiu      $s0, $s0, -0x1
/* 62E2C 8006222C 01407025 */  or         $t6, $t2, $zero
/* 62E30 80062230 01A25820 */  add        $t3, $t5, $v0 /* handwritten instruction */
.L80062234_62E34:
/* 62E34 80062234 85A80000 */  lh         $t0, 0x0($t5)
/* 62E38 80062238 81C90000 */  lb         $t1, 0x0($t6)
/* 62E3C 8006223C 25AD0006 */  addiu      $t5, $t5, 0x6
/* 62E40 80062240 01AB082A */  slt        $at, $t5, $t3
/* 62E44 80062244 01094022 */  sub        $t0, $t0, $t1 /* handwritten instruction */
/* 62E48 80062248 A5A8FFFA */  sh         $t0, -0x6($t5)
/* 62E4C 8006224C 85A8FFFC */  lh         $t0, -0x4($t5)
/* 62E50 80062250 81C90001 */  lb         $t1, 0x1($t6)
/* 62E54 80062254 25CE0003 */  addiu      $t6, $t6, 0x3
/* 62E58 80062258 01094022 */  sub        $t0, $t0, $t1 /* handwritten instruction */
/* 62E5C 8006225C A5A8FFFC */  sh         $t0, -0x4($t5)
/* 62E60 80062260 85A8FFFE */  lh         $t0, -0x2($t5)
/* 62E64 80062264 81C9FFFF */  lb         $t1, -0x1($t6)
/* 62E68 80062268 01094022 */  sub        $t0, $t0, $t1 /* handwritten instruction */
/* 62E6C 8006226C 1420FFF1 */  bnez       $at, .L80062234_62E34
/* 62E70 80062270 A5A8FFFE */   sh        $t0, -0x2($t5)
/* 62E74 80062274 0090082A */  slt        $at, $a0, $s0
/* 62E78 80062278 5420FFE6 */  bnel       $at, $zero, .L80062214_62E14
/* 62E7C 8006227C 84C2004A */   lh        $v0, 0x4A($a2)
/* 62E80 80062280 8CC20044 */  lw         $v0, 0x44($a2)
.L80062284_62E84:
/* 62E84 80062284 000718C0 */  sll        $v1, $a3, 3
/* 62E88 80062288 3C0D8012 */  lui        $t5, %hi(D_8011D644)
/* 62E8C 8006228C 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 62E90 80062290 8C4E0000 */  lw         $t6, 0x0($v0)
/* 62E94 80062294 26020002 */  addiu      $v0, $s0, 0x2
/* 62E98 80062298 01820019 */  multu      $t4, $v0
/* 62E9C 8006229C 84C2004A */  lh         $v0, 0x4A($a2)
/* 62EA0 800622A0 8DADDBC4 */  lw         $t5, %lo(D_8011D644)($t5)
/* 62EA4 800622A4 00001812 */  mflo       $v1
/* 62EA8 800622A8 01C37020 */  add        $t6, $t6, $v1 /* handwritten instruction */
/* 62EAC 800622AC 00021880 */  sll        $v1, $v0, 2
/* 62EB0 800622B0 00021040 */  sll        $v0, $v0, 1
/* 62EB4 800622B4 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 62EB8 800622B8 01A25820 */  add        $t3, $t5, $v0 /* handwritten instruction */
.L800622BC_62EBC:
/* 62EBC 800622BC 81C80000 */  lb         $t0, 0x0($t6)
/* 62EC0 800622C0 25AD0006 */  addiu      $t5, $t5, 0x6
/* 62EC4 800622C4 01AB082A */  slt        $at, $t5, $t3
/* 62EC8 800622C8 01180019 */  multu      $t0, $t8
/* 62ECC 800622CC 25CE0003 */  addiu      $t6, $t6, 0x3
/* 62ED0 800622D0 00004012 */  mflo       $t0
/* 62ED4 800622D4 00084102 */  srl        $t0, $t0, 4
/* 62ED8 800622D8 A5A8FFFA */  sh         $t0, -0x6($t5)
/* 62EDC 800622DC 81C9FFFE */  lb         $t1, -0x2($t6)
/* 62EE0 800622E0 01380019 */  multu      $t1, $t8
/* 62EE4 800622E4 00004812 */  mflo       $t1
/* 62EE8 800622E8 00094902 */  srl        $t1, $t1, 4
/* 62EEC 800622EC A5A9FFFC */  sh         $t1, -0x4($t5)
/* 62EF0 800622F0 81CAFFFF */  lb         $t2, -0x1($t6)
/* 62EF4 800622F4 01580019 */  multu      $t2, $t8
/* 62EF8 800622F8 00005012 */  mflo       $t2
/* 62EFC 800622FC 000A5102 */  srl        $t2, $t2, 4
/* 62F00 80062300 1420FFEE */  bnez       $at, .L800622BC_62EBC
/* 62F04 80062304 A5AAFFFE */   sh        $t2, -0x2($t5)
/* 62F08 80062308 8CC20044 */  lw         $v0, 0x44($a2)
/* 62F0C 8006230C 000718C0 */  sll        $v1, $a3, 3
/* 62F10 80062310 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 62F14 80062314 10800006 */  beqz       $a0, .L80062330_62F30
/* 62F18 80062318 8C4E0000 */   lw        $t6, 0x0($v0)
/* 62F1C 8006231C 24820001 */  addiu      $v0, $a0, 0x1
/* 62F20 80062320 01820019 */  multu      $t4, $v0
/* 62F24 80062324 00001812 */  mflo       $v1
/* 62F28 80062328 01C37020 */  add        $t6, $t6, $v1 /* handwritten instruction */
/* 62F2C 8006232C 25CEFFF4 */  addiu      $t6, $t6, -0xC
.L80062330_62F30:
/* 62F30 80062330 81C20000 */  lb         $v0, 0x0($t6)
/* 62F34 80062334 91C30001 */  lbu        $v1, 0x1($t6)
/* 62F38 80062338 00021200 */  sll        $v0, $v0, 8
/* 62F3C 8006233C 00434025 */  or         $t0, $v0, $v1
/* 62F40 80062340 81C20002 */  lb         $v0, 0x2($t6)
/* 62F44 80062344 91C30003 */  lbu        $v1, 0x3($t6)
/* 62F48 80062348 00021200 */  sll        $v0, $v0, 8
/* 62F4C 8006234C 00434825 */  or         $t1, $v0, $v1
/* 62F50 80062350 81C20004 */  lb         $v0, 0x4($t6)
/* 62F54 80062354 91C30005 */  lbu        $v1, 0x5($t6)
/* 62F58 80062358 00021200 */  sll        $v0, $v0, 8
/* 62F5C 8006235C 00435025 */  or         $t2, $v0, $v1
/* 62F60 80062360 81C2000A */  lb         $v0, 0xA($t6)
/* 62F64 80062364 91C3000B */  lbu        $v1, 0xB($t6)
/* 62F68 80062368 01CC7020 */  add        $t6, $t6, $t4 /* handwritten instruction */
/* 62F6C 8006236C 00021200 */  sll        $v0, $v0, 8
/* 62F70 80062370 14800003 */  bnez       $a0, .L80062380_62F80
/* 62F74 80062374 00435825 */   or        $t3, $v0, $v1
/* 62F78 80062378 01CC7020 */  add        $t6, $t6, $t4 /* handwritten instruction */
/* 62F7C 8006237C 25CEFFF4 */  addiu      $t6, $t6, -0xC
.L80062380_62F80:
/* 62F80 80062380 81C20000 */  lb         $v0, 0x0($t6)
/* 62F84 80062384 91C30001 */  lbu        $v1, 0x1($t6)
/* 62F88 80062388 3C198012 */  lui        $t9, %hi(D_8011D644)
/* 62F8C 8006238C 00021200 */  sll        $v0, $v0, 8
/* 62F90 80062390 00431025 */  or         $v0, $v0, $v1
/* 62F94 80062394 00481022 */  sub        $v0, $v0, $t0 /* handwritten instruction */
/* 62F98 80062398 00580019 */  multu      $v0, $t8
/* 62F9C 8006239C 00001012 */  mflo       $v0
/* 62FA0 800623A0 00021102 */  srl        $v0, $v0, 4
/* 62FA4 800623A4 01024020 */  add        $t0, $t0, $v0 /* handwritten instruction */
/* 62FA8 800623A8 A4A80016 */  sh         $t0, 0x16($a1)
/* 62FAC 800623AC 81C20002 */  lb         $v0, 0x2($t6)
/* 62FB0 800623B0 91C30003 */  lbu        $v1, 0x3($t6)
/* 62FB4 800623B4 00021200 */  sll        $v0, $v0, 8
/* 62FB8 800623B8 00431025 */  or         $v0, $v0, $v1
/* 62FBC 800623BC 00491022 */  sub        $v0, $v0, $t1 /* handwritten instruction */
/* 62FC0 800623C0 00580019 */  multu      $v0, $t8
/* 62FC4 800623C4 00001012 */  mflo       $v0
/* 62FC8 800623C8 00021102 */  srl        $v0, $v0, 4
/* 62FCC 800623CC 01224820 */  add        $t1, $t1, $v0 /* handwritten instruction */
/* 62FD0 800623D0 A4A90018 */  sh         $t1, 0x18($a1)
/* 62FD4 800623D4 81C20004 */  lb         $v0, 0x4($t6)
/* 62FD8 800623D8 91C30005 */  lbu        $v1, 0x5($t6)
/* 62FDC 800623DC 00021200 */  sll        $v0, $v0, 8
/* 62FE0 800623E0 00431025 */  or         $v0, $v0, $v1
/* 62FE4 800623E4 004A1022 */  sub        $v0, $v0, $t2 /* handwritten instruction */
/* 62FE8 800623E8 00580019 */  multu      $v0, $t8
/* 62FEC 800623EC 00001012 */  mflo       $v0
/* 62FF0 800623F0 00021102 */  srl        $v0, $v0, 4
/* 62FF4 800623F4 01425020 */  add        $t2, $t2, $v0 /* handwritten instruction */
/* 62FF8 800623F8 A4AA001A */  sh         $t2, 0x1A($a1)
/* 62FFC 800623FC 81C2000A */  lb         $v0, 0xA($t6)
/* 63000 80062400 91C3000B */  lbu        $v1, 0xB($t6)
/* 63004 80062404 00021200 */  sll        $v0, $v0, 8
/* 63008 80062408 00431025 */  or         $v0, $v0, $v1
/* 6300C 8006240C 004B1022 */  sub        $v0, $v0, $t3 /* handwritten instruction */
/* 63010 80062410 00580019 */  multu      $v0, $t8
/* 63014 80062414 24A30004 */  addiu      $v1, $a1, 0x4
/* 63018 80062418 00001012 */  mflo       $v0
/* 6301C 8006241C 00021102 */  srl        $v0, $v0, 4
/* 63020 80062420 01625820 */  add        $t3, $t3, $v0 /* handwritten instruction */
/* 63024 80062424 80A2001F */  lb         $v0, 0x1F($a1)
/* 63028 80062428 A4AB001C */  sh         $t3, 0x1C($a1)
/* 6302C 8006242C 38420001 */  xori       $v0, $v0, 0x1
/* 63030 80062430 A0A2001F */  sb         $v0, 0x1F($a1)
/* 63034 80062434 00021080 */  sll        $v0, $v0, 2
/* 63038 80062438 00621820 */  add        $v1, $v1, $v0 /* handwritten instruction */
/* 6303C 8006243C 84C20024 */  lh         $v0, 0x24($a2)
/* 63040 80062440 8CCD004C */  lw         $t5, 0x4C($a2)
/* 63044 80062444 8C6E0000 */  lw         $t6, 0x0($v1)
/* 63048 80062448 00021040 */  sll        $v0, $v0, 1
/* 6304C 8006244C 8F39DBC4 */  lw         $t9, %lo(D_8011D644)($t9)
/* 63050 80062450 01A25820 */  add        $t3, $t5, $v0 /* handwritten instruction */
.L80062454_63054:
/* 63054 80062454 85A20000 */  lh         $v0, 0x0($t5)
/* 63058 80062458 2401FFFF */  addiu      $at, $zero, -0x1
/* 6305C 8006245C 21AD0002 */  addi       $t5, $t5, 0x2 /* handwritten instruction */
/* 63060 80062460 50410013 */  beql       $v0, $at, .L800624B0_630B0
/* 63064 80062464 01AB082A */   slt       $at, $t5, $t3
/* 63068 80062468 00021880 */  sll        $v1, $v0, 2
/* 6306C 8006246C 00021040 */  sll        $v0, $v0, 1
/* 63070 80062470 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 63074 80062474 03224820 */  add        $t1, $t9, $v0 /* handwritten instruction */
/* 63078 80062478 02224020 */  add        $t0, $s1, $v0 /* handwritten instruction */
/* 6307C 8006247C 85020000 */  lh         $v0, 0x0($t0)
/* 63080 80062480 85230000 */  lh         $v1, 0x0($t1)
/* 63084 80062484 00435020 */  add        $t2, $v0, $v1 /* handwritten instruction */
/* 63088 80062488 A5CA0000 */  sh         $t2, 0x0($t6)
/* 6308C 8006248C 85020002 */  lh         $v0, 0x2($t0)
/* 63090 80062490 85230002 */  lh         $v1, 0x2($t1)
/* 63094 80062494 00435020 */  add        $t2, $v0, $v1 /* handwritten instruction */
/* 63098 80062498 A5CA0002 */  sh         $t2, 0x2($t6)
/* 6309C 8006249C 85020004 */  lh         $v0, 0x4($t0)
/* 630A0 800624A0 85230004 */  lh         $v1, 0x4($t1)
/* 630A4 800624A4 00435020 */  add        $t2, $v0, $v1 /* handwritten instruction */
/* 630A8 800624A8 A5CA0004 */  sh         $t2, 0x4($t6)
/* 630AC 800624AC 01AB082A */  slt        $at, $t5, $t3
.L800624B0_630B0:
/* 630B0 800624B0 1420FFE8 */  bnez       $at, .L80062454_63054
/* 630B4 800624B4 21CE000A */   addi      $t6, $t6, 0xA /* handwritten instruction */
/* 630B8 800624B8 24020001 */  addiu      $v0, $zero, 0x1
.L800624BC_630BC:
/* 630BC 800624BC 8FB00000 */  lw         $s0, 0x0($sp)
/* 630C0 800624C0 8FB10004 */  lw         $s1, 0x4($sp)
/* 630C4 800624C4 03E00008 */  jr         $ra
/* 630C8 800624C8 27BD0008 */   addiu     $sp, $sp, 0x8
/* 630CC 800624CC 00000000 */  nop

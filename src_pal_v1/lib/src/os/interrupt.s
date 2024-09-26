.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.30.0 */

/* Handwritten function */
glabel __osDisableInt
/* D31F0 800D25F0 40086000 */  mfc0       $t0, $12 /* handwritten instruction */
/* D31F4 800D25F4 2401FFFE */  addiu      $at, $zero, -0x2
/* D31F8 800D25F8 01014824 */  and        $t1, $t0, $at
/* D31FC 800D25FC 40896000 */  mtc0       $t1, $12 /* handwritten instruction */
/* D3200 800D2600 31020001 */  andi       $v0, $t0, 0x1
/* D3204 800D2604 00000000 */  nop
/* D3208 800D2608 03E00008 */  jr         $ra
/* D320C 800D260C 00000000 */   nop

/* Handwritten function */
glabel __osRestoreInt
/* D3210 800D2610 40086000 */  mfc0       $t0, $12 /* handwritten instruction */
/* D3214 800D2614 01044025 */  or         $t0, $t0, $a0
/* D3218 800D2618 40886000 */  mtc0       $t0, $12 /* handwritten instruction */
/* D321C 800D261C 00000000 */  nop
/* D3220 800D2620 00000000 */  nop
/* D3224 800D2624 03E00008 */  jr         $ra
/* D3228 800D2628 00000000 */   nop
/* D322C 800D262C 00000000 */  nop
.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.30.0 */

/* Handwritten function */
glabel __osSetCompare
/* D80F0 800D74F0 40845800 */  mtc0       $a0, $11 /* handwritten instruction */
/* D80F4 800D74F4 03E00008 */  jr         $ra
/* D80F8 800D74F8 00000000 */   nop
/* D80FC 800D74FC 00000000 */  nop
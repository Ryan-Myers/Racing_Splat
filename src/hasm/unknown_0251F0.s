.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.30.0 */

leaf func_800245F0
/* 251F0 800245F0 8CA70054 */  lw         $a3, 0x54($a1)
/* 251F4 800245F4 10E00051 */  beqz       $a3, .L8002473C
/* 251F8 800245F8 00000000 */   nop
/* 251FC 800245FC 8CE20000 */  lw         $v0, 0x0($a3)
/* 25200 80024600 44863000 */  mtc1       $a2, $f6
/* 25204 80024604 3C014320 */  lui        $at, (0x43200000 >> 16)
/* 25208 80024608 44822000 */  mtc1       $v0, $f4
/* 2520C 8002460C 44814000 */  mtc1       $at, $f8
/* 25210 80024610 84880028 */  lh         $t0, 0x28($a0)
/* 25214 80024614 46062102 */  mul.s      $f4, $f4, $f6
/* 25218 80024618 8C8D0038 */  lw         $t5, 0x38($a0)
/* 2521C 8002461C 84F8001C */  lh         $t8, 0x1C($a3)
/* 25220 80024620 84EF001E */  lh         $t7, 0x1E($a3)
/* 25224 80024624 84EE0020 */  lh         $t6, 0x20($a3)
/* 25228 80024628 8C870040 */  lw         $a3, 0x40($a0)
/* 2522C 8002462C 8CA50044 */  lw         $a1, 0x44($a1)
/* 25230 80024630 46082102 */  mul.s      $f4, $f4, $f8
/* 25234 80024634 4442F800 */  cfc1       $v0, $31
/* 25238 80024638 00000000 */  nop
/* 2523C 8002463C 34430003 */  ori        $v1, $v0, 0x3
/* 25240 80024640 38630002 */  xori       $v1, $v1, 0x2
/* 25244 80024644 44C3F800 */  ctc1       $v1, $31
/* 25248 80024648 00081880 */  sll        $v1, $t0, 2
/* 2524C 8002464C 46002124 */  cvt.w.s    $f4, $f4
/* 25250 80024650 44C2F800 */  ctc1       $v0, $31
/* 25254 80024654 000810C0 */  sll        $v0, $t0, 3
/* 25258 80024658 00432020 */  add        $a0, $v0, $v1 /* handwritten instruction */
/* 2525C 8002465C 44062000 */  mfc1       $a2, $f4
/* 25260 80024660 008D2020 */  add        $a0, $a0, $t5 /* handwritten instruction */
/* 25264 80024664 91A80006 */  lbu        $t0, 0x6($t5)
.L80024668:
/* 25268 80024668 85A20002 */  lh         $v0, 0x2($t5)
/* 2526C 8002466C 85A3000E */  lh         $v1, 0xE($t5)
/* 25270 80024670 240100FF */  addiu      $at, $zero, 0xFF
/* 25274 80024674 1501000C */  bne        $t0, $at, .L800246A8
/* 25278 80024678 00626022 */   sub       $t4, $v1, $v0 /* handwritten instruction */
/* 2527C 8002467C 8DA90008 */  lw         $t1, 0x8($t5)
/* 25280 80024680 000C10C0 */  sll        $v0, $t4, 3
/* 25284 80024684 000C1840 */  sll        $v1, $t4, 1
/* 25288 80024688 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 2528C 8002468C 31298000 */  andi       $t1, $t1, 0x8000
/* 25290 80024690 11200026 */  beqz       $t1, .L8002472C
/* 25294 80024694 00A22820 */   add       $a1, $a1, $v0 /* handwritten instruction */
/* 25298 80024698 000C1080 */  sll        $v0, $t4, 2
/* 2529C 8002469C 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 252A0 800246A0 10000022 */  b          .L8002472C
/* 252A4 800246A4 00E23820 */   add       $a3, $a3, $v0 /* handwritten instruction */
.L800246A8:
/* 252A8 800246A8 84E80000 */  lh         $t0, 0x0($a3)
/* 252AC 800246AC 01180018 */  mult       $t0, $t8
/* 252B0 800246B0 0000C812 */  mflo       $t9
/* 252B4 800246B4 84E90002 */  lh         $t1, 0x2($a3)
/* 252B8 800246B8 258CFFFF */  addiu      $t4, $t4, -0x1
/* 252BC 800246BC 012F0018 */  mult       $t1, $t7
/* 252C0 800246C0 00001012 */  mflo       $v0
/* 252C4 800246C4 84EA0004 */  lh         $t2, 0x4($a3)
/* 252C8 800246C8 0322C820 */  add        $t9, $t9, $v0 /* handwritten instruction */
/* 252CC 800246CC 014E0018 */  mult       $t2, $t6
/* 252D0 800246D0 00001012 */  mflo       $v0
/* 252D4 800246D4 24E70006 */  addiu      $a3, $a3, 0x6
/* 252D8 800246D8 0322C820 */  add        $t9, $t9, $v0 /* handwritten instruction */
/* 252DC 800246DC 0019CAC3 */  sra        $t9, $t9, 11
/* 252E0 800246E0 1F200003 */  bgtz       $t9, .L800246F0
/* 252E4 800246E4 00000000 */   nop
/* 252E8 800246E8 10000009 */  b          .L80024710
/* 252EC 800246EC 00C0C825 */   or        $t9, $a2, $zero
.L800246F0:
/* 252F0 800246F0 03260018 */  mult       $t9, $a2
/* 252F4 800246F4 0000C812 */  mflo       $t9
/* 252F8 800246F8 0019CC02 */  srl        $t9, $t9, 16
/* 252FC 800246FC 0326C820 */  add        $t9, $t9, $a2 /* handwritten instruction */
/* 25300 80024700 2B210100 */  slti       $at, $t9, 0x100
/* 25304 80024704 54200003 */  bnel       $at, $zero, .L80024714
/* 25308 80024708 00191200 */   sll       $v0, $t9, 8
/* 2530C 8002470C 241900FF */  addiu      $t9, $zero, 0xFF
.L80024710:
/* 25310 80024710 00191200 */  sll        $v0, $t9, 8
.L80024714:
/* 25314 80024714 0322C825 */  or         $t9, $t9, $v0
/* 25318 80024718 A4B90006 */  sh         $t9, 0x6($a1)
/* 2531C 8002471C 373900FF */  ori        $t9, $t9, 0xFF
/* 25320 80024720 A4B90008 */  sh         $t9, 0x8($a1)
/* 25324 80024724 1580FFE0 */  bnez       $t4, .L800246A8
/* 25328 80024728 24A5000A */   addiu     $a1, $a1, 0xA
.L8002472C:
/* 2532C 8002472C 25AD000C */  addiu      $t5, $t5, 0xC
/* 25330 80024730 01A4082A */  slt        $at, $t5, $a0
/* 25334 80024734 5420FFCC */  bnel       $at, $zero, .L80024668
/* 25338 80024738 91A80006 */   lbu       $t0, 0x6($t5)
.L8002473C:
/* 2533C 8002473C 03E00008 */  jr         $ra
/* 25340 80024740 00000000 */   nop
.end func_800245F0

leaf calc_dynamic_lighting_for_object_2
/* 25344 80024744 27BDFF80 */  addiu      $sp, $sp, -0x80
/* 25348 80024748 AFB00080 */  sw         $s0, 0x80($sp)
/* 2534C 8002474C AFBF0078 */  sw         $ra, 0x78($sp)
/* 25350 80024750 AFB10084 */  sw         $s1, 0x84($sp)
/* 25354 80024754 AFB20088 */  sw         $s2, 0x88($sp)
/* 25358 80024758 AFB3008C */  sw         $s3, 0x8C($sp)
/* 2535C 8002475C 00808025 */  or         $s0, $a0, $zero
/* 25360 80024760 8E190054 */  lw         $t9, 0x54($s0)
/* 25364 80024764 00A08825 */  or         $s1, $a1, $zero
/* 25368 80024768 00C09025 */  or         $s2, $a2, $zero
/* 2536C 8002476C 13200093 */  beqz       $t9, .L800249BC
/* 25370 80024770 00E09825 */   or        $s3, $a3, $zero
/* 25374 80024774 8728001C */  lh         $t0, 0x1C($t9)
/* 25378 80024778 8729001E */  lh         $t1, 0x1E($t9)
/* 2537C 8002477C 872A0020 */  lh         $t2, 0x20($t9)
/* 25380 80024780 00084080 */  sll        $t0, $t0, 2
/* 25384 80024784 00094880 */  sll        $t1, $t1, 2
/* 25388 80024788 000A5080 */  sll        $t2, $t2, 2
/* 2538C 8002478C 44882000 */  mtc1       $t0, $f4
/* 25390 80024790 44893000 */  mtc1       $t1, $f6
/* 25394 80024794 448A4000 */  mtc1       $t2, $f8
/* 25398 80024798 46802120 */  cvt.s.w    $f4, $f4
/* 2539C 8002479C 27B80010 */  addiu      $t8, $sp, 0x10
/* 253A0 800247A0 468031A0 */  cvt.s.w    $f6, $f6
/* 253A4 800247A4 E7040000 */  swc1       $f4, 0x0($t8)
/* 253A8 800247A8 46804220 */  cvt.s.w    $f8, $f8
/* 253AC 800247AC E7060004 */  swc1       $f6, 0x4($t8)
/* 253B0 800247B0 10C00007 */  beqz       $a2, .L800247D0
/* 253B4 800247B4 E7080008 */   swc1      $f8, 0x8($t8)
/* 253B8 800247B8 0C01A769 */  jal        get_projection_matrix_f32
/* 253BC 800247BC 00000000 */   nop
/* 253C0 800247C0 27A50010 */  addiu      $a1, $sp, 0x10
/* 253C4 800247C4 00402025 */  or         $a0, $v0, $zero
/* 253C8 800247C8 0C01BDBB */  jal        f32_matrix_dot
/* 253CC 800247CC 00A03025 */   or        $a2, $a1, $zero
.L800247D0:
/* 253D0 800247D0 86080000 */  lh         $t0, 0x0($s0)
/* 253D4 800247D4 27B8001C */  addiu      $t8, $sp, 0x1C
/* 253D8 800247D8 24030000 */  addiu      $v1, $zero, 0x0
/* 253DC 800247DC 00084022 */  neg        $t0, $t0 /* handwritten instruction */
/* 253E0 800247E0 A7080000 */  sh         $t0, 0x0($t8)
/* 253E4 800247E4 86090002 */  lh         $t1, 0x2($s0)
/* 253E8 800247E8 3C023F80 */  lui        $v0, (0x3F800000 >> 16)
/* 253EC 800247EC 27A40034 */  addiu      $a0, $sp, 0x34
/* 253F0 800247F0 00094822 */  neg        $t1, $t1 /* handwritten instruction */
/* 253F4 800247F4 A7090002 */  sh         $t1, 0x2($t8)
/* 253F8 800247F8 860A0004 */  lh         $t2, 0x4($s0)
/* 253FC 800247FC AF020008 */  sw         $v0, 0x8($t8)
/* 25400 80024800 AF03000C */  sw         $v1, 0xC($t8)
/* 25404 80024804 000A5022 */  neg        $t2, $t2 /* handwritten instruction */
/* 25408 80024808 A70A0004 */  sh         $t2, 0x4($t8)
/* 2540C 8002480C AF030010 */  sw         $v1, 0x10($t8)
/* 25410 80024810 AF030014 */  sw         $v1, 0x14($t8)
/* 25414 80024814 0C01BF9D */  jal        object_transform_to_matrix_2
/* 25418 80024818 03002825 */   or        $a1, $t8, $zero
/* 2541C 8002481C 27A50010 */  addiu      $a1, $sp, 0x10
/* 25420 80024820 27A40034 */  addiu      $a0, $sp, 0x34
/* 25424 80024824 0C01BDBB */  jal        f32_matrix_dot
/* 25428 80024828 00A03025 */   or        $a2, $a1, $zero
/* 2542C 8002482C 8E190054 */  lw         $t9, 0x54($s0)
/* 25430 80024830 44933000 */  mtc1       $s3, $f6
/* 25434 80024834 3C01437F */  lui        $at, (0x437F0000 >> 16)
/* 25438 80024838 8F220000 */  lw         $v0, 0x0($t9)
/* 2543C 8002483C 44814000 */  mtc1       $at, $f8
/* 25440 80024840 8F23002C */  lw         $v1, 0x2C($t9)
/* 25444 80024844 44822000 */  mtc1       $v0, $f4
/* 25448 80024848 8F220028 */  lw         $v0, 0x28($t9)
/* 2544C 8002484C 27A80010 */  addiu      $t0, $sp, 0x10
/* 25450 80024850 46062102 */  mul.s      $f4, $f4, $f6
/* 25454 80024854 44823000 */  mtc1       $v0, $f6
/* 25458 80024858 8D060000 */  lw         $a2, 0x0($t0)
/* 2545C 8002485C 8D070004 */  lw         $a3, 0x4($t0)
/* 25460 80024860 8D0E0008 */  lw         $t6, 0x8($t0)
/* 25464 80024864 86280028 */  lh         $t0, 0x28($s1)
/* 25468 80024868 8E2D0038 */  lw         $t5, 0x38($s1)
/* 2546C 8002486C 46082102 */  mul.s      $f4, $f4, $f8
/* 25470 80024870 44834000 */  mtc1       $v1, $f8
/* 25474 80024874 8E130044 */  lw         $s3, 0x44($s0)
/* 25478 80024878 8E240040 */  lw         $a0, 0x40($s1)
/* 2547C 8002487C 46043182 */  mul.s      $f6, $f6, $f4
/* 25480 80024880 00000000 */  nop
/* 25484 80024884 46044202 */  mul.s      $f8, $f8, $f4
/* 25488 80024888 44862000 */  mtc1       $a2, $f4
/* 2548C 8002488C 4442F800 */  cfc1       $v0, $31
/* 25490 80024890 00000000 */  nop
/* 25494 80024894 34430003 */  ori        $v1, $v0, 0x3
/* 25498 80024898 38630002 */  xori       $v1, $v1, 0x2
/* 2549C 8002489C 44C3F800 */  ctc1       $v1, $31
/* 254A0 800248A0 00081880 */  sll        $v1, $t0, 2
/* 254A4 800248A4 460031A4 */  cvt.w.s    $f6, $f6
/* 254A8 800248A8 46004224 */  cvt.w.s    $f8, $f8
/* 254AC 800248AC 44183000 */  mfc1       $t8, $f6
/* 254B0 800248B0 44873000 */  mtc1       $a3, $f6
/* 254B4 800248B4 46002124 */  cvt.w.s    $f4, $f4
/* 254B8 800248B8 440F4000 */  mfc1       $t7, $f8
/* 254BC 800248BC 448E4000 */  mtc1       $t6, $f8
/* 254C0 800248C0 460031A4 */  cvt.w.s    $f6, $f6
/* 254C4 800248C4 44062000 */  mfc1       $a2, $f4
/* 254C8 800248C8 46004224 */  cvt.w.s    $f8, $f8
/* 254CC 800248CC 44073000 */  mfc1       $a3, $f6
/* 254D0 800248D0 44C2F800 */  ctc1       $v0, $31
/* 254D4 800248D4 000810C0 */  sll        $v0, $t0, 3
/* 254D8 800248D8 00439020 */  add        $s2, $v0, $v1 /* handwritten instruction */
/* 254DC 800248DC 440E4000 */  mfc1       $t6, $f8
/* 254E0 800248E0 024D9020 */  add        $s2, $s2, $t5 /* handwritten instruction */
/* 254E4 800248E4 91A80006 */  lbu        $t0, 0x6($t5)
.L800248E8:
/* 254E8 800248E8 85A20002 */  lh         $v0, 0x2($t5)
/* 254EC 800248EC 85A3000E */  lh         $v1, 0xE($t5)
/* 254F0 800248F0 240100FF */  addiu      $at, $zero, 0xFF
/* 254F4 800248F4 1501000C */  bne        $t0, $at, .L80024928
/* 254F8 800248F8 00626022 */   sub       $t4, $v1, $v0 /* handwritten instruction */
/* 254FC 800248FC 8DA90008 */  lw         $t1, 0x8($t5)
/* 25500 80024900 000C10C0 */  sll        $v0, $t4, 3
/* 25504 80024904 000C1840 */  sll        $v1, $t4, 1
/* 25508 80024908 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 2550C 8002490C 31298000 */  andi       $t1, $t1, 0x8000
/* 25510 80024910 11200026 */  beqz       $t1, .L800249AC
/* 25514 80024914 02629820 */   add       $s3, $s3, $v0 /* handwritten instruction */
/* 25518 80024918 000C1080 */  sll        $v0, $t4, 2
/* 2551C 8002491C 00431020 */  add        $v0, $v0, $v1 /* handwritten instruction */
/* 25520 80024920 10000022 */  b          .L800249AC
/* 25524 80024924 00822020 */   add       $a0, $a0, $v0 /* handwritten instruction */
.L80024928:
/* 25528 80024928 84880000 */  lh         $t0, 0x0($a0)
/* 2552C 8002492C 01060018 */  mult       $t0, $a2
/* 25530 80024930 00002812 */  mflo       $a1
/* 25534 80024934 84890002 */  lh         $t1, 0x2($a0)
/* 25538 80024938 258CFFFF */  addiu      $t4, $t4, -0x1
/* 2553C 8002493C 01270018 */  mult       $t1, $a3
/* 25540 80024940 00001012 */  mflo       $v0
/* 25544 80024944 848A0004 */  lh         $t2, 0x4($a0)
/* 25548 80024948 00A22820 */  add        $a1, $a1, $v0 /* handwritten instruction */
/* 2554C 8002494C 014E0018 */  mult       $t2, $t6
/* 25550 80024950 00001012 */  mflo       $v0
/* 25554 80024954 24840006 */  addiu      $a0, $a0, 0x6
/* 25558 80024958 00A22820 */  add        $a1, $a1, $v0 /* handwritten instruction */
/* 2555C 8002495C 000529C3 */  sra        $a1, $a1, 7
/* 25560 80024960 1CA00003 */  bgtz       $a1, .L80024970
/* 25564 80024964 00000000 */   nop
/* 25568 80024968 10000009 */  b          .L80024990
/* 2556C 8002496C 03002825 */   or        $a1, $t8, $zero
.L80024970:
/* 25570 80024970 00AF0018 */  mult       $a1, $t7
/* 25574 80024974 00002812 */  mflo       $a1
/* 25578 80024978 00052D42 */  srl        $a1, $a1, 21
/* 2557C 8002497C 00B82820 */  add        $a1, $a1, $t8 /* handwritten instruction */
/* 25580 80024980 28A10100 */  slti       $at, $a1, 0x100
/* 25584 80024984 54200003 */  bnel       $at, $zero, .L80024994
/* 25588 80024988 00051200 */   sll       $v0, $a1, 8
/* 2558C 8002498C 240500FF */  addiu      $a1, $zero, 0xFF
.L80024990:
/* 25590 80024990 00051200 */  sll        $v0, $a1, 8
.L80024994:
/* 25594 80024994 00A22825 */  or         $a1, $a1, $v0
/* 25598 80024998 A6650006 */  sh         $a1, 0x6($s3)
/* 2559C 8002499C 34A500FF */  ori        $a1, $a1, 0xFF
/* 255A0 800249A0 A6650008 */  sh         $a1, 0x8($s3)
/* 255A4 800249A4 1580FFE0 */  bnez       $t4, .L80024928
/* 255A8 800249A8 2673000A */   addiu     $s3, $s3, 0xA
.L800249AC:
/* 255AC 800249AC 25AD000C */  addiu      $t5, $t5, 0xC
/* 255B0 800249B0 01B2082A */  slt        $at, $t5, $s2
/* 255B4 800249B4 5420FFCC */  bnel       $at, $zero, .L800248E8
/* 255B8 800249B8 91A80006 */   lbu       $t0, 0x6($t5)
.L800249BC:
/* 255BC 800249BC 8FBF0078 */  lw         $ra, 0x78($sp)
/* 255C0 800249C0 8FB00080 */  lw         $s0, 0x80($sp)
/* 255C4 800249C4 8FB10084 */  lw         $s1, 0x84($sp)
/* 255C8 800249C8 8FB20088 */  lw         $s2, 0x88($sp)
/* 255CC 800249CC 8FB3008C */  lw         $s3, 0x8C($sp)
/* 255D0 800249D0 03E00008 */  jr         $ra
/* 255D4 800249D4 27BD0080 */   addiu     $sp, $sp, 0x80
/* 255D8 800249D8 00000000 */  nop
.end calc_dynamic_lighting_for_object_2

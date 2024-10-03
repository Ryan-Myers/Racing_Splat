#include "common.h"

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/thread0_create.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/thread0_Main.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/enable_interupts_on_main.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/stop_all_threads_except_main.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/write_epc_data_to_cpak.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/dump_memory_to_cpak.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/update_object_stack_trace.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/get_lockup_status.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/lockup_screen_loop.s")

#pragma GLOBAL_ASM("asm_us_v2/nonmatchings/thread0_epc/render_epc_lock_up_display.s")

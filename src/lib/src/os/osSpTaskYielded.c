/* The comment below is needed for this file to be picked up by generate_ld */
/* RAM_POS: 0x800D1DF0 */

#include "libultra_internal.h"
#include "PRinternal/viint.h"
#include "PR/sptask.h"

OSYieldResult osSpTaskYielded(OSTask *tp) {
    u32 status;
    OSYieldResult result;
    status = __osSpGetStatus();
    if (status & SP_STATUS_YIELDED)
        result = OS_TASK_YIELDED;
    else
        result = 0;
    if (status & SP_STATUS_YIELD) {
        tp->t.flags |= result;
        tp->t.flags &= ~(OS_TASK_DP_WAIT);
    }
    return result;
}

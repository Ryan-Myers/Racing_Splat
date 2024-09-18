/* The comment below is needed for this file to be picked up by generate_ld */
/* RAM_POS: 0x800D2480 */

#include "types.h"
#include "macros.h"
#include "libultra_internal.h"

#define PI_Q_BUF_LEN 1
OSMesg piAccessBuf[PI_Q_BUF_LEN]; //Should be static, but this works for now
OSMesgQueue __osPiAccessQueue;
OSTimer __osBaseTimer;
OSTime __osCurrentTime;
u32 __osBaseCounter;
u32 __osViIntrCount;
u32 __osTimerCounter;
u32 D_8012D238[2];
OSThread gInterruptedThread;

#define PI_Q_BUF_LEN 1
extern u32 __osPiAccessQueueEnabled;
extern OSMesg piAccessBuf[PI_Q_BUF_LEN];
extern OSMesgQueue __osPiAccessQueue;
void __osPiCreateAccessQueue(void) {
    __osPiAccessQueueEnabled = 1;
    osCreateMesgQueue(&__osPiAccessQueue, piAccessBuf, PI_Q_BUF_LEN);
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osPiGetAccess(void) {
    OSMesg dummyMesg;
    if (!__osPiAccessQueueEnabled)
        __osPiCreateAccessQueue();
    osRecvMesg(&__osPiAccessQueue, &dummyMesg, OS_MESG_BLOCK);
}

void __osPiRelAccess(void) {
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

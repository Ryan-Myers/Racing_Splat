/* The comment below is needed for this file to be picked up by generate_ld */
/* RAM_POS: 0x800CD600 */

#include "libultra_internal.h"
#include "PRinternal/controller.h"
#include "src/memory.h"

u32 __osSiAccessQueueEnabled = 0;

// Ok, so I completely gave up on the rest of these bss variables.
// This is probably not the right place for them, but we can always 
// fix that later.
#define SI_Q_BUF_LEN 1
static OSMesg siAccessBuf[SI_Q_BUF_LEN];
OSMesgQueue __osSiAccessQueue;

void __osSiCreateAccessQueue(void) {
	__osSiAccessQueueEnabled = 1;
	osCreateMesgQueue(&__osSiAccessQueue, siAccessBuf, SI_Q_BUF_LEN);
	osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osSiGetAccess(void) {
	OSMesg dummyMesg;
	if (!__osSiAccessQueueEnabled)
		__osSiCreateAccessQueue();
	osRecvMesg(&__osSiAccessQueue, &dummyMesg, OS_MESG_BLOCK);
}

void __osSiRelAccess(void) {
	osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

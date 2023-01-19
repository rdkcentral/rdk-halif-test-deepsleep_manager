#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdint.h>
//#include "cmock.h"
#include "deepSleepMgr.h"


int PLAT_DS_INIT(void)
{
  /*TODO: Implement Me!*/
  return (int)0;
}

int PLAT_DS_SetDeepSleep(uint32_t deep_sleep_timeout, bool* isGPIOWakeup, bool networkStandby)
{
  /*TODO: Implement Me!*/
  (void)deep_sleep_timeout;
  (void)isGPIOWakeup;
  (void)networkStandby;
  return (int)0;
}

void PLAT_DS_DeepSleepWakeup(void)
{
  /*TODO: Implement Me!*/
}

void PLAT_DS_TERM(void)
{
  /*TODO: Implement Me!*/
}

int PLAT_DS_GetLastWakeupReason(DeepSleep_WakeupReason_t* wakeupReason)
{
  /*TODO: Implement Me!*/
  (void)wakeupReason;
  return (int)0;
}

int PLAT_DS_GetLastWakeupKeyCode(IARM_Bus_DeepSleepMgr_WakeupKeyCode_Param_t* wakeupKeyCode)
{
  /*TODO: Implement Me!*/
  (void)wakeupKeyCode;
  return (int)0;
}


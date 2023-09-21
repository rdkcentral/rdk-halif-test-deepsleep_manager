#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "deepSleepMgr.h"


DeepSleep_Return_Status_t PLAT_DS_INIT(void)
{
  /*TODO: Implement Me!*/
  return (DeepSleep_Return_Status_t)0;
}

DeepSleep_Return_Status_t PLAT_DS_SetDeepSleep(uint32_t deep_sleep_timeout, bool* isGPIOWakeup, bool networkStandby)
{
  /*TODO: Implement Me!*/
  (void)deep_sleep_timeout;
  (void)isGPIOWakeup;
  (void)networkStandby;
  return (DeepSleep_Return_Status_t)0;
}

DeepSleep_Return_Status_t PLAT_DS_DeepSleepWakeup(void)
{
  /*TODO: Implement Me!*/
  return (DeepSleep_Return_Status_t)0;
}

DeepSleep_Return_Status_t PLAT_DS_GetLastWakeupReason(DeepSleep_WakeupReason_t* wakeupReason)
{
  /*TODO: Implement Me!*/
  (void)wakeupReason;
  return (DeepSleep_Return_Status_t)0;
}

DeepSleep_Return_Status_t PLAT_DS_GetLastWakeupKeyCode(DeepSleepMgr_WakeupKeyCode_Param_t* wakeupKeyCode)
{
  /*TODO: Implement Me!*/
  (void)wakeupKeyCode;
  return (DeepSleep_Return_Status_t)0;
}

DeepSleep_Return_Status_t PLAT_DS_TERM(void)
{
  /*TODO: Implement Me!*/
  return (DeepSleep_Return_Status_t)0;
}


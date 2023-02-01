#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdint.h>
//#include "cmock.h"
#include "deepSleepMgr.h"


deepSleepError_t PLAT_DS_INIT(void)
{
  /*TODO: Implement Me!*/
  return DEEPSLEEP_SUCCESS;
}

deepSleepError_t PLAT_DS_SetDeepSleep(uint32_t deep_sleep_timeout, bool* isGPIOWakeup, bool networkStandby)
{
  /*TODO: Implement Me!*/
  if(isGPIOWakeup == NULL) {
      return DEEPSLEEP_INVALID_ARGUMENT;
  }
  else {
      return DEEPSLEEP_SUCCESS;
  }
}

deepSleepError_t PLAT_DS_DeepSleepWakeup(void)
{
  /*TODO: Implement Me!*/
  return DEEPSLEEP_SUCCESS;
}

void PLAT_DS_TERM(void)
{
  /*TODO: Implement Me!*/
}

deepSleepError_t PLAT_DS_GetLastWakeupReason(DeepSleep_WakeupReason_t* wakeupReason)
{
  /*TODO: Implement Me!*/
  if(wakeupReason == NULL)
  {
      return DEEPSLEEP_INVALID_ARGUMENT; 
  }
  else
      return DEEPSLEEP_SUCCESS;
}

deepSleepError_t PLAT_DS_GetLastWakeupKeyCode(IARM_Bus_DeepSleepMgr_WakeupKeyCode_Param_t* wakeupKeyCode)
{
  /*TODO: Implement Me!*/
  if(wakeupKeyCode == NULL)
  {
      return DEEPSLEEP_INVALID_ARGUMENT; 
  }
  else
      return DEEPSLEEP_SUCCESS;
}


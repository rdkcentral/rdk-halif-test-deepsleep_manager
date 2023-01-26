/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include <string.h>
#include <stdlib.h>

#include <ut.h>
#include <stdint.h>
#include "deepSleepMgr.h"

void test_l1_PLAT_DS_INIT(void)
{
    int result = -1;
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, 0 );
} 

void test_l1_PLAT_DS_SetDeepSleep(void)
{
    int result = -1;
    uint32_t deep_sleep_timeout = 120;
    bool isGPIOWakeup;
    bool networkStandby = false;

    printf("Device entered to Deep sleep Mode with deep_sleep_timeout (%d) and networkStandby (%d). \n", 
            deep_sleep_timeout, networkStandby);
    printf("This is Blocking call, it will resume after timeout or Pressing Remote key.");
    result = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL( result, 0 );

    printf("Device resumed from Deep sleep Mode. \n");

    if (isGPIOWakeup) 
    {
        printf("Resumed due to user action.\n");
    }
    else {
        printf("Resumed due to non-user action.\n");
    }
} 

void test_l1_PLAT_DS_DeepSleepWakeup(void)
{
    /* TBD: How to check?
    */
    PLAT_DS_DeepSleepWakeup();
    printf("[%s:%d]Device resumed from Deep sleep Mode. \n", __FUNCTION__, __LINE__);
}

void test_l1_PLAT_DS_GetLastWakeupReason(void)
{
    int result = -1;
    DeepSleep_WakeupReason_t wakeupReason = DEEPSLEEP_WAKEUPREASON_UNKNOWN;
    result = PLAT_DS_GetLastWakeupReason(&wakeupReason);
    UT_ASSERT_EQUAL( result, 0 );
    printf("[%s:%d]PLAT_DS_GetLastWakeupReason is %d. \n",
     __FUNCTION__, __LINE__, wakeupReason);
}

void test_l1_PLAT_DS_GetLastWakeupKeyCode(void)
{
	int result = -1;
    IARM_Bus_DeepSleepMgr_WakeupKeyCode_Param_t wakeupKeyCode;
    result = PLAT_DS_GetLastWakeupKeyCode(&wakeupKeyCode);
    UT_ASSERT_EQUAL( result, 0 );
    printf("[%s:%d]PLAT_DS_GetLastWakeupReason is %d. \n",
     __FUNCTION__, __LINE__, wakeupKeyCode.keyCode);
}

static UT_test_suite_t *pSuite = NULL;

/**
 * @brief Register the main tests for this module
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_l1_register( void )
{
    /* add a suite to the registry */
    pSuite = UT_add_suite("[L1 test_Example]", NULL, NULL);
    if (NULL == pSuite) 
    {
        return -1;
    }

    UT_add_test( pSuite, "ds_level1_test_PLAT_DS_INIT", test_l1_PLAT_DS_INIT);
    UT_add_test( pSuite, "ds_level1_test_PLAT_DS_SetDeepSleep", test_l1_PLAT_DS_SetDeepSleep);
    UT_add_test( pSuite, "ds_level1_test_PLAT_DS_DeepSleepWakeup", test_l1_PLAT_DS_DeepSleepWakeup);
    UT_add_test( pSuite, "ds_test_l1_test_PLAT_DS_GetLastWakeupReason", test_l1_PLAT_DS_GetLastWakeupReason);
    UT_add_test( pSuite, "ds_test_l1_test_PLAT_DS_GetLastWakeupKeyCode", test_l1_PLAT_DS_GetLastWakeupKeyCode);
    return 0;
}

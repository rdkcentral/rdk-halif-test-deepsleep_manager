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

void test_l2_function(void)
{
	UT_FAIL("Need to implement");
    /* Positive */
    /* Negative */
} 

static UT_test_suite_t *pSuite = NULL;

/**
 * @brief Register the main tests for this module
 * 
 * @return int - 0 on success, otherwise failure
 */

/**
 * @brief This routine will verify PLAT_DS_SetDeepSleep is working fine.
 * This call is blocking call, once executed it will unblocked by deepsleep timeout value or through GPIO Wakeup.
 * This function will set the Deepsleep based on different values of deepsleep time out and network standby flag.
 * This api will wake up based on value (in Seconds) of deep_sleep_timeout or GPIO Wakeup from any source.
 * If the deep_sleep_timeout time is expired earlier than GPIO Wakeup, then this call will unblocked.
 * If this api is wakeup by GPIO earlier than deepsleep timer then this call will be unblocked.      
 */
void test_l2_PLAT_DS_SetDeepSleep(void)
{
    deepSleepError_t result;
    uint32_t deep_sleep_timeout = 60;
    bool isGPIOWakeup;
    bool networkStandby = false;
    
    /* Calling to initialized the Platform Deepsleep HAL */
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS);

    /* Calling with proper arguments */
    /* After calling this function successfully, the device will go for deepsleep state. 
     * User has to press Remote key to wakeup or check the possible DeepSleep_WakeupReason_t to wakeup. 
     * The isGPIOWakeup flag will turn true/false based on user input.  
     */
    result = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS );

    if(isGPIOWakeup) {
        UT_ASSERT_TRUE(isGPIOWakeup);
        printf ("\n [%s] Resume wakeup from DeepSleep with User Input after deepsleep timeout (%d).\n", __FUNCTION__ , deep_sleep_timeout);
    }
    else {
        UT_ASSERT_FALSE(isGPIOWakeup); 
        printf ("\n [%s] Resume wakeup from DeepSleep without User Input after deepsleep timeout (%d).\n", __FUNCTION__ , deep_sleep_timeout);
    }

    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM();

    /* When networkStandby set to TRUE*/
    networkStandby = true; 

        /* Calling to initialized the Platform Deepsleep HAL */
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS);
    printf ("\n [%s] Set PLAT_DS_SetDeepSleep() with networkStandby to TRUE\n", __FUNCTION__ ); 
    /* Calling with proper arguments */
    /* After calling this function successfully, the device will go for deepsleep state. 
     * User has to press Remote key to wakeup or check the possible DeepSleep_WakeupReason_t to wakeup. 
     * The isGPIOWakeup flag will turn true/false based on user input  
     */
    result = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS );

    UT_ASSERT_TRUE(networkStandby);
        
    if(isGPIOWakeup) {
        UT_ASSERT_TRUE(isGPIOWakeup);
        printf ("\n [%s] Resume wakeup from DeepSleep with User Input\n", __FUNCTION__ );
    }
    else {
        UT_ASSERT_FALSE(isGPIOWakeup); 
        printf ("\n [%s] Resume wakeup from DeepSleep without User Input\n", __FUNCTION__ );
    }
    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM();   

} 

/**
 * @brief This routine will verify PLAT_DS_GetLastWakeupReason is working fine
 * This function will get the last Wakeup Reason mentioned under DeepSleep_WakeupReason_t. 
 */
void test_l2_PLAT_DS_GetLastWakeupReason(void)
{
    deepSleepError_t result;
    DeepSleep_WakeupReason_t wakeupReason;
    
    /* Positive result */
    /* Calling to initialized the Platform Deepsleep HAL */
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS); 
    
    /* Calling PLAT_DS_GetLastWakeupReason with proper argument */ 
    result = PLAT_DS_GetLastWakeupReason(&wakeupReason);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS );

    printf ("\n [%s] The GetLastWakeupReason is [%d]. \n", __FUNCTION__, wakeupReason);

    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM();

}

/**
 * @brief This routine will verify PLAT_DS_GetLastWakeupKeyCode module is working fine
 * This function will get the last Wakeup KeyCode. 
 */
void test_l2_PLAT_DS_GetLastWakeupKeyCode(void)
{
	deepSleepError_t result = -1;
    IARM_Bus_DeepSleepMgr_WakeupKeyCode_Param_t wakeupKeyCode;
    
     /* Positive  Value*/
    /* Calling to initialized the Platform Deepsleep HAL */
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS); 

    /* Calling PLAT_DS_GetLastWakeupKeyCode with proper argument */  
    result = PLAT_DS_GetLastWakeupKeyCode(&wakeupKeyCode);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS );

    printf ("\n [%s] The Last Wakeup keyCode is [%d]. \n", __FUNCTION__, wakeupKeyCode);
    
    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM();
}

int test_l2_register( void )
{
    /* add a suite to the registry */
    pSuite = UT_add_suite("[L2 test_Example]", NULL, NULL);
    if (NULL == pSuite) 
    {
        return -1;
    }

    UT_add_test( pSuite, "ds_level2_test_PLAT_DS_SetDeepSleep", test_l2_PLAT_DS_SetDeepSleep);
    UT_add_test( pSuite, "ds_test_l2_test_PLAT_DS_GetLastWakeupReason", test_l2_PLAT_DS_GetLastWakeupReason);
    UT_add_test( pSuite, "ds_test_l2_test_PLAT_DS_GetLastWakeupKeyCode", test_l2_PLAT_DS_GetLastWakeupKeyCode);

    return 0;
}

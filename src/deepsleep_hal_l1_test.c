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


/**
 * @brief This function will do the unit testing of PLAT_DS_INIT ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * DEEPSLEEP_SUCCESS: will be returned if PLAT_DS_INIT() is executed successfully.
 * DEEPSLEEP_GENERAL_ERROR : will be returned if PLAT_DS_INIT is called second time or 
 * underlying platform implementation is failed.
 */
void test_l1_PLAT_DS_INIT(void)
{
    deepSleepError_t result;
    /* Positive result */
    /* Calling to Initialized Platform Deepsleep HAL */
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS);

    /* Negative result */
    /*Calling PLAT_DS_INIT second time, should return the general failure*/
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_GENERAL_ERROR);

    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM(); 
} 

/**
 * @brief This function will do the unit testing of PLAT_DS_SetDeepSleep ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * DEEPSLEEP_SUCCESS - It will be returned if PLAT_DS_SetDeepSleep() is executed successfully.
 * DEEPSLEEP_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_DS_INIT().
 * DEEPSLEEP_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * DEEPSLEEP_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_DS_SetDeepSleep(void)
{
    deepSleepError_t result;
    uint32_t deep_sleep_timeout = 120;
    bool isGPIOWakeup;
    bool networkStandby = false;
    
    /* Positive result */
    /* Calling to initialized the Platform Deepsleep HAL */
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS);

    /* Calling with proper arguments */
    /* After calling this function successfully, the device will go for deepsleep state. 
     * User has to press Remote key to wakeup or check the possible DeepSleep_WakeupReason_t to wakeup. 
     */
    result = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS );

    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM();

    /* Negative result */
    /* Calling without Initialized Platform Deepsleep HAL */
    result = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_INVALID_STATE );

    /* Negative result */
    /* Calling with invalid argument after Initialized Platform Deepsleep HAL */
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS);

    /* Calling with Invalid argument */
    result = PLAT_DS_SetDeepSleep(deep_sleep_timeout, NULL, networkStandby);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_INVALID_ARGUMENT);

     /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM();
    
    /* #TODO: Unclear how the function will fail, it may be due failure in underneath layer */

} 

void test_l1_PLAT_DS_DeepSleepWakeup(void)
{
    /* TBD: How to check?
    */
    /* #TODO: Unclear how this function can be tested,  */
    PLAT_DS_DeepSleepWakeup();
}

/**
 * @brief This function will do the unit testing of PLAT_DS_GetLastWakeupReason ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * DEEPSLEEP_SUCCESS - It will be returned if PLAT_DS_GetLastWakeupReason() is executed successfully.
 * DEEPSLEEP_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_DS_INIT().
 * DEEPSLEEP_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * DEEPSLEEP_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_DS_GetLastWakeupReason(void)
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

    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM();

    /* Negative  Value*/
    /* Calling PLAT_DS_GetLastWakeupReason without PLAT_DS_INIT() */ 
    result = PLAT_DS_GetLastWakeupReason(&wakeupReason);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_INVALID_STATE );

    /* Calling to initialized the Platform Deepsleep HAL */
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS); 
    
    /* Calling PLAT_DS_GetLastWakeupReason with NULL/Invalid argument */ 
    result = PLAT_DS_GetLastWakeupReason(NULL);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_INVALID_ARGUMENT );

    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM();
}

/**
 * @brief This function will do the unit testing of PLAT_DS_GetLastWakeupKeyCode ().
 * This function will ensure underlying API implementation is handling
 * the invalid call sequences to the API properly.
 * This UT implementation will verify it by calling the function in all
 * invalid possibilities.
 * In all the invalid call sequence 
 * scenarios API should return the expected error codes defined in the respective HAL
 * documentation. Please see all the expected error codes and respective scenarios
 * in which the error codes will be returned.
 * DEEPSLEEP_SUCCESS - It will be returned if PLAT_DS_GetLastWakeupKeyCode() is executed successfully.
 * DEEPSLEEP_INVALID_STATE - It's invalid failure state, it will returns if calling without platform initialized method PLAT_DS_INIT().
 * DEEPSLEEP_INVALID_ARGUMENT - It will returned if invalid argument passed to this method.
 * DEEPSLEEP_GENERAL_ERROR - It will returns if any error or general failure occured in underneath layer.
 */
void test_l1_PLAT_DS_GetLastWakeupKeyCode(void)
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
    
    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM();

    /* Negative  Value*/
    /* Calling PLAT_DS_GetLastWakeupKeyCode without PLAT_DS_INIT() */ 
    result = PLAT_DS_GetLastWakeupKeyCode(&wakeupKeyCode);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_INVALID_STATE );

    /* Calling to initialized the Platform Deepsleep HAL */
    result = PLAT_DS_INIT();
    UT_ASSERT_EQUAL( result, DEEPSLEEP_SUCCESS); 
    
    /* Calling PLAT_DS_GetLastWakeupKeyCode with NULL/Invalid argument */ 
    result = PLAT_DS_GetLastWakeupKeyCode(NULL);
    UT_ASSERT_EQUAL( result, DEEPSLEEP_INVALID_ARGUMENT );

    /* Calling to deinitialized the Platform Deepsleep HAL */
    PLAT_DS_TERM(); 
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

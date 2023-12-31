/**
 *  If not stated otherwise in this file or this component's LICENSE
 *  file the following copyright and licenses apply:
 *
 *  Copyright 2022 RDK Management
 *
 *  Licensed under the Apache License, Version 2.0 (the License);
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an AS IS BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/**
 * @addtogroup HPK Hardware Porting Kit
 * @{
 * @par The Hardware Porting Kit
 * HPK is the next evolution of the well-defined Hardware Abstraction Layer
 * (HAL), but augmented with more comprehensive documentation and test suites
 * that OEM or SOC vendors can use to self-certify their ports before taking
 * them to RDKM for validation or to an operator for final integration and
 * deployment. The Hardware Porting Kit effectively enables an OEM and/or SOC
 * vendor to self-certify their own Video Accelerator devices, with minimal RDKM
 * assistance.
 *
 */

/**
 * @addtogroup Deepsleep_Manager Deep Sleep Manager
 * @{
 *
 */

/**
 * @addtogroup Deepsleep_Manager_HALTEST Deep Sleep Manager HALTEST
 * @{
 */

/**
 * @defgroup Deepsleep_Mgr_HALTEST_L1 Deep Sleep Manager HALTEST L1 File
 * @{
 * @parblock
 *
 * ### L1 Tests for Deep Sleep Manager HAL :
 *
 * This module includes Level 1 functional tests (success and failure scenarios) for all APIs of Deepsleep Manager HAL
 *
 * **Pre-Conditions:**  None@n
 * **Dependencies:** None@n
 *
 * Ref to API Definition specification documentation : [deepsleep-manager_halSpec.md](../../docs/pages/deepsleep-manager_halSpec.md)
 *
 * @endparblock
 */

/**
 * @file test_l1_deepSleepMgr.c
 *
 */

#include <string.h>
#include <stdlib.h>

#include "deepSleepMgr.h"
#include <ut.h>
#include <ut_log.h>

static int gTestGroup = 1;
static int gTestID = 1;

/**
 * @brief Ensure PLAT_DS_INIT() returns correct error codes during positive scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 001@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_INIT (void)
{
    gTestID = 1;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	// Define expected results
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  

    // Variation 02: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);

    // Variation 03: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit2 = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit2, expectedInit);  

    // Variation 04: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm2 = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm2, expectedTerm);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_INIT() returns correct error codes during negative scenarios
 * 
 * @note The error code DEEPSLEEPMGR_INIT_FAILURE is not able to be tested here.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 002@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_INIT() again | | DEEPSLEEP_ALREADY_INITIALIZED | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_INIT (void)
{
    gTestID = 2;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedAlreadyInitialized = DEEPSLEEPMGR_ALREADY_INITIALIZED;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  

    // Variation 02: Call PLAT_DS_INIT() again and expect it to be already initialized
    DeepSleep_Return_Status_t resultAlreadyInitialized = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultAlreadyInitialized, expectedAlreadyInitialized);

    // Variation 03: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_TERM() returns correct error codes during positive scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 003@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_TERM (void)
{
    gTestID = 3;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  

    // Variation 02: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_TERM() returns correct error codes during negative scenarios
 * 
 * @note The error code DEEPSLEEPMGR_TERM_FAILURE is not able to be tested here.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 004@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_TERM() - attempt to close interface before initialization | | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |04|Call PLAT_DS_TERM() - attempt to close interface after termination | | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */

void test_l1_deepSleepMgr_negative_PLAT_DS_TERM (void)
{
    gTestID = 4;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedNotInitialized = DEEPSLEEPMGR_NOT_INITIALIZED;
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Attempt to close interface before initialization and check the result
    DeepSleep_Return_Status_t resultNotInitialized1 = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  

    // Variation 02: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);

    // Variation 03: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);

    // Variation 04: Attempt to close interface after termination and check the result
    DeepSleep_Return_Status_t resultNotInitialized2 = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultNotInitialized2, expectedNotInitialized);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_DeepSleepWakeup() returns correct error codes during positive scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 005@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_DeepSleepWakeup (void)
{
    gTestID = 5;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedWakeup = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  

    // Variation 02: Call PLAT_DS_DeepSleepWakeup() and check the result
    DeepSleep_Return_Status_t resultWakeup = PLAT_DS_DeepSleepWakeup();
    UT_ASSERT_EQUAL(resultWakeup, expectedWakeup);

    // Variation 03: Call PLAT_DS_DeepSleepWakeup() and check the result
    DeepSleep_Return_Status_t resultWakeup2 = PLAT_DS_DeepSleepWakeup();
    UT_ASSERT_EQUAL(resultWakeup2, expectedWakeup);

    // Variation 04: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_DeepSleepWakeup() returns correct error codes during negative scenarios
 * 
 * @note The error code DEEPSLEEP_WAKEUP_FAILURE cannot be tested
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 006@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_DeepSleepWakeup() - call before initialization| | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |04|Call PLAT_DS_DeepSleepWakeup() - call after termination| | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_DeepSleepWakeup (void)
{
    gTestID = 6;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	 // Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedNotInitialized = DEEPSLEEPMGR_NOT_INITIALIZED;
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_DeepSleepWakeup() before initialization and check the result
    DeepSleep_Return_Status_t resultNotInitialized1 = PLAT_DS_DeepSleepWakeup();
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  

    // Variation 02: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);

    // Variation 03: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);

    // Variation 04: Call PLAT_DS_DeepSleepWakeup() after termination and check the result
    DeepSleep_Return_Status_t resultNotInitialized2 = PLAT_DS_DeepSleepWakeup();
    UT_ASSERT_EQUAL(resultNotInitialized2, expectedNotInitialized);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_SetDeepSleep() returns correct error codes during positive scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 007@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=30, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_DS_SetDeepSleep() - initiate device deep sleepp | deep_sleep_timeout=30, *isGPIOWakeup=false, networkStandby=true | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |06|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_SetDeepSleep (void)
{
    gTestID = 7;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedSetDeepSleep = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedWakeup = DEEPSLEEPMGR_SUCCESS;

    // Parameters for PLAT_DS_SetDeepSleep
    int deep_sleep_timeout = 30;
    bool isGPIOWakeup = false;
    bool networkStandby = false;


    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  

    // Variation 02: Call PLAT_DS_SetDeepSleep() with networkStandby=false and check the result
    UT_LOG("\n [%s] Device going to sleep for %d seconds\n",__FUNCTION__, deep_sleep_timeout);
    DeepSleep_Return_Status_t resultSetDeepSleep1 = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL(resultSetDeepSleep1, expectedSetDeepSleep);

    // Variation 03: Call PLAT_DS_DeepSleepWakeup() and check the result
    DeepSleep_Return_Status_t resultWakeup = PLAT_DS_DeepSleepWakeup();
    UT_ASSERT_EQUAL(resultWakeup, expectedWakeup);

    // Update parameters for next call
    networkStandby = true;

    // Variation 04: Call PLAT_DS_SetDeepSleep() with networkStandby=true and check the result
    UT_LOG("\n [%s] Device going to sleep for %d seconds\n",__FUNCTION__, deep_sleep_timeout);
    DeepSleep_Return_Status_t resultSetDeepSleep2 = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL(resultSetDeepSleep2, expectedSetDeepSleep);

    // Variation 05: Call PLAT_DS_DeepSleepWakeup() and check the result
    DeepSleep_Return_Status_t resultWakeup2 = PLAT_DS_DeepSleepWakeup();
    UT_ASSERT_EQUAL(resultWakeup2, expectedWakeup);

    // Variation 06: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_SetDeepSleep() returns correct error codes during negative scenarios
 * 
 * @note The error code DEEPSLEEP_SET_FAILURE is not able to be tested here.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 008@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_SetDeepSleep() - call before initialization | deep_sleep_timeout=60, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_SetDeepSleep() set deep sleep | deep_sleep_timeout=30, *isGPIOWakeup=NULL, networkStandby=false | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |05|Call PLAT_DS_SetDeepSleep() - call after termination | deep_sleep_timeout=60, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_SetDeepSleep (void)
{
    gTestID = 8;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedNotInitialized = DEEPSLEEPMGR_NOT_INITIALIZED;
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedInvalidArgument = DEEPSLEEPMGR_INVALID_ARGUMENT;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Parameters for PLAT_DS_SetDeepSleep
    int deep_sleep_timeout;
    bool isGPIOWakeup;
    bool networkStandby;

    // Variation 01: Call before initialization
    deep_sleep_timeout = 60;
    isGPIOWakeup = false;
    networkStandby = false;
    DeepSleep_Return_Status_t resultNotInitialized1 = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  

    // Variation 02: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);

    // Variation 03: Call PLAT_DS_SetDeepSleep() with NULL pointer for isGPIOWakeup
    deep_sleep_timeout = 30;
    DeepSleep_Return_Status_t resultInvalidArgument = PLAT_DS_SetDeepSleep(deep_sleep_timeout, NULL, networkStandby);
    UT_ASSERT_EQUAL(resultInvalidArgument, expectedInvalidArgument);

    // Variation 04: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);

    // Variation 05: Call PLAT_DS_SetDeepSleep() after termination
    deep_sleep_timeout = 60;
    DeepSleep_Return_Status_t resultNotInitialized2 = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL(resultNotInitialized2, expectedNotInitialized);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_GetLastWakeupReason() returns correct error codes during positive scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 009@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |04|Verify that the returns from PLAT_DS_GetLastWakeupReason are the same | |  | Should Pass |
 * |05|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupReason (void)
{
    gTestID = 9;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedGetReason = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Placeholder for the wakeup reason
    DeepSleep_WakeupReason_t wakeupReason1;
    DeepSleep_WakeupReason_t wakeupReason2;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  

    // Variation 02: Call PLAT_DS_GetLastWakeupReason() and check the result
    DeepSleep_Return_Status_t resultGetReason = PLAT_DS_GetLastWakeupReason(&wakeupReason1);
    UT_ASSERT_EQUAL(resultGetReason, expectedGetReason);

    // Variation 03: Call PLAT_DS_GetLastWakeupReason() and check the result
    DeepSleep_Return_Status_t resultGetReason2 = PLAT_DS_GetLastWakeupReason(&wakeupReason2);
    UT_ASSERT_EQUAL(resultGetReason2, expectedGetReason);

    // Variation 04: Verify that the returns are the same
    UT_ASSERT_EQUAL(wakeupReason1, wakeupReason2);

    // At this point, you may want to further verify if 'wakeupReason' contains valid data.
    // This is dependent on your specific requirements and what PLAT_DS_GetLastWakeupReason() actually does.

    // Variation 03: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_GetLastWakeupReason() returns correct error codes during negative scenarios
 * 
 * @note The error code DEEPSLEEPMGR_TERM_FAILURE is not able to be tested here.
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 010@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_GetLastWakeupReason() - call function without initializing | *wakeupReason | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_GetLastWakeupReason() - call function invalid inputs | *wakeupReason=NULL | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |05|Call PLAT_DS_GetLastWakeupReason() - call after termination | *wakeupReason | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupReason (void)
{
    gTestID = 10;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    // Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedNotInitialized = DEEPSLEEPMGR_NOT_INITIALIZED;
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedInvalidArgument = DEEPSLEEPMGR_INVALID_ARGUMENT;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Placeholder for the wakeup reason
    DeepSleep_WakeupReason_t wakeupReason;

    // Variation 01: Call PLAT_DS_GetLastWakeupReason() before initialization and check the result
    DeepSleep_Return_Status_t resultNotInitialized1 = PLAT_DS_GetLastWakeupReason(&wakeupReason);
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  

    // Variation 02: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);

    // Variation 03: Call PLAT_DS_GetLastWakeupReason() with NULL pointer and check the result
    DeepSleep_Return_Status_t resultInvalidArgument = PLAT_DS_GetLastWakeupReason(NULL);
    UT_ASSERT_EQUAL(resultInvalidArgument, expectedInvalidArgument);

    // Variation 04: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);

    // Variation 05: Call PLAT_DS_GetLastWakeupReason() after termination and check the result
    DeepSleep_Return_Status_t resultNotInitialized2 = PLAT_DS_GetLastWakeupReason(&wakeupReason);
    UT_ASSERT_EQUAL(resultNotInitialized2, expectedNotInitialized);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}


/**
 * @brief Ensure PLAT_DS_GetLastWakeupKeyCode() returns correct error codes during positive scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 011@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_GetLastWakeupKeyCode() - call get last wakeup keycode | *wakeupKeyCode | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_GetLastWakeupKeyCode() - call get last wakeup keycode | *wakeupKeyCode | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |04|Verify the returns of PLAT_DS_GetLastWakeupKeyCode are the same  |  | | Should Pass |
 * |05|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

void test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupKeyCode (void)
{
    gTestID = 11;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	 // Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedGetKeyCode = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Placeholder for the wakeup keycode
    DeepSleepMgr_WakeupKeyCode_Param_t wakeupKeyCode1;
    DeepSleepMgr_WakeupKeyCode_Param_t wakeupKeyCode2;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  

    // Variation 02: Call PLAT_DS_GetLastWakeupKeyCode() and check the result
    DeepSleep_Return_Status_t resultGetKeyCode = PLAT_DS_GetLastWakeupKeyCode(&wakeupKeyCode1);
    UT_ASSERT_EQUAL(resultGetKeyCode, expectedGetKeyCode);

    // Variation 03: Call PLAT_DS_GetLastWakeupKeyCode() and check the result
    DeepSleep_Return_Status_t resultGetKeyCode2 = PLAT_DS_GetLastWakeupKeyCode(&wakeupKeyCode2);
    UT_ASSERT_EQUAL(resultGetKeyCode2, expectedGetKeyCode);

    // Variation 04: Verify that the returns contain the same value
    UT_ASSERT_EQUAL(wakeupKeyCode2.keyCode, wakeupKeyCode1.keyCode);

    // Variation 05: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

/**
 * @brief Ensure PLAT_DS_GetLastWakeupKeyCode() returns correct error codes during negative scenarios
 * 
 * **Test Group ID:** Basic: 01@n
 * **Test Case ID:** 012@n
 * 
 * **Pre-Conditions:**@n
 * None.
 * 
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * |01|Call PLAT_DS_GetLastWakeupKeyCode() - call without initializing | *wakeupKeyCode | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_GetLastWakeupKeyCode() - call with invalid inputs | *wakeupKeyCode=NULL | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |05|Call PLAT_DS_GetLastWakeupKeyCode() - call after closing module | *wakeupKeyCode | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupKeyCode (void)
{
    gTestID = 12;
    UT_LOG("\n In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
	 // Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedNotInitialized = DEEPSLEEPMGR_NOT_INITIALIZED;
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedInvalidArgument = DEEPSLEEPMGR_INVALID_ARGUMENT;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Placeholder for the wakeup keycode
    DeepSleepMgr_WakeupKeyCode_Param_t wakeupKeyCode;

    // Variation 01: Call PLAT_DS_GetLastWakeupKeyCode() before initialization and check the result
    DeepSleep_Return_Status_t resultNotInitialized1 = PLAT_DS_GetLastWakeupKeyCode(&wakeupKeyCode);
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  

    // Variation 02: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);

    // Variation 03: Call PLAT_DS_GetLastWakeupKeyCode() with NULL pointer and check the result
    DeepSleep_Return_Status_t resultInvalidArgument = PLAT_DS_GetLastWakeupKeyCode(NULL);
    UT_ASSERT_EQUAL(resultInvalidArgument, expectedInvalidArgument);

    // Variation 04: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);

    // Variation 05: Call PLAT_DS_GetLastWakeupKeyCode() after termination and check the result
    DeepSleep_Return_Status_t resultNotInitialized2 = PLAT_DS_GetLastWakeupKeyCode(&wakeupKeyCode);
    UT_ASSERT_EQUAL(resultNotInitialized2, expectedNotInitialized); 
    UT_LOG("\n Out  %s\n",__FUNCTION__);
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main test(s) for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_l1_deepSleepMgr_register ( void )
{
    /* add a suite to the registry */
    pSuite = UT_add_suite( "[L1 deepSleepMgr]", NULL, NULL );
    if ( NULL == pSuite )
    {
    	return -1;
    }	
        
    UT_add_test( pSuite, "PLAT_DS_INIT_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_INIT );
    UT_add_test( pSuite, "PLAT_DS_INIT_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_INIT );
    UT_add_test( pSuite, "PLAT_DS_TERM_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_TERM );
    UT_add_test( pSuite, "PLAT_DS_TERM_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_TERM );
    UT_add_test( pSuite, "PLAT_DS_DeepSleepWakeup_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_DeepSleepWakeup );
    UT_add_test( pSuite, "PLAT_DS_DeepSleepWakeup_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_DeepSleepWakeup );
    UT_add_test( pSuite, "PLAT_DS_SetDeepSleep_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_SetDeepSleep );
    UT_add_test( pSuite, "PLAT_DS_SetDeepSleep_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_SetDeepSleep );
    UT_add_test( pSuite, "PLAT_DS_GetLastWakeupReason_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupReason );
    UT_add_test( pSuite, "PLAT_DS_GetLastWakeupReason_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupReason );
    UT_add_test( pSuite, "PLAT_DS_GetLastWakeupKeyCode_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupKeyCode );
    UT_add_test( pSuite, "PLAT_DS_GetLastWakeupKeyCode_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupKeyCode );

	return 0;
} 
/** @} */ // End of Deepsleep_Mgr_HALTEST_L1
/** @} */ // End of Deepsleep_Manager_HALTEST
/** @} */ // End Deepsleep_Manager
/** @} */ // End of HPK

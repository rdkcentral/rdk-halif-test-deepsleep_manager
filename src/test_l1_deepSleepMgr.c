/**
*  If not stated otherwise in this file or this component's Licenses.txt
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
* @file TODO: test_l1_deepSleepMgr.c
* @page module_name TODO: Required field, name of the main module
* @subpage sub_page_name TODO: Add a function group if relevant
*
* ## Module's Role
* TODO: Explain the module's role in the system in general
* This is to ensure that the API meets the operational requirements of the module across all vendors.
*
* **Pre-Conditions:**  TODO: Add pre-conditions if any@n
* **Dependencies:** TODO: Add dependencies if any@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <string.h>
#include <stdlib.h>

#include <ut.h>
#include <ut_log.h>

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
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_INIT (void)
{
	// Define expected results
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

    // Variation 02: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
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
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedAlreadyInitialized = DEEPSLEEPMGR_ALREADY_INITIALIZED;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

    // Variation 02: Call PLAT_DS_INIT() again and expect it to be already initialized
    DeepSleep_Return_Status_t resultAlreadyInitialized = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultAlreadyInitialized, expectedAlreadyInitialized);

    // Variation 03: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
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
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

    // Variation 02: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
}

/**
 * @brief Ensure PLAT_DS_TERM() returns correct error codes during negative scenarios
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
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |01|Call PLAT_DS_TERM() - attempt to close interface after termination | | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */

void test_l1_deepSleepMgr_negative_PLAT_DS_TERM (void)
{
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedNotInitialized = DEEPSLEEPMGR_NOT_INITIALIZED;
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Attempt to close interface before initialization and check the result
    DeepSleep_Return_Status_t resultNotInitialized1 = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);

    // Variation 02: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);

    // Variation 01: Attempt to close interface after termination and check the result
    DeepSleep_Return_Status_t resultNotInitialized2 = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultNotInitialized2, expectedNotInitialized);
}

/**
 * @brief Ensure PLAT_DS_SetDeepSleep() returns correct error codes during positive scenarios
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
 * |02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=30, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_SetDeepSleep() - initiate device deep sleepp | deep_sleep_timeout=30, *isGPIOWakeup=false, networkStandby=true | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_SetDeepSleep (void)
{
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedSetDeepSleep = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

    // Parameters for PLAT_DS_SetDeepSleep
    int deep_sleep_timeout = 30;
    bool isGPIOWakeup = false;
    bool networkStandby = false;

    // Variation 02: Call PLAT_DS_SetDeepSleep() with networkStandby=false and check the result
    DeepSleep_Return_Status_t resultSetDeepSleep1 = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL(resultSetDeepSleep1, expectedSetDeepSleep);

    // Update parameters for next call
    networkStandby = true;

    // Variation 03: Call PLAT_DS_SetDeepSleep() with networkStandby=true and check the result
    DeepSleep_Return_Status_t resultSetDeepSleep2 = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_ASSERT_EQUAL(resultSetDeepSleep2, expectedSetDeepSleep);

    // Variation 04: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
}

/**
 * @brief Ensure PLAT_DS_SetDeepSleep() returns correct error codes during negative scenarios
 * 
 * @note The error code DEEPSLEEP_SET_FAILURE is not able to be tested here.
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
 * |01|Call PLAT_DS_SetDeepSleep() - call before initialization | deep_sleep_timeout=60, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_SetDeepSleep() set deep sleep | deep_sleep_timeout=30, *isGPIOWakeup=NULL, networkStandby=false | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |05|Call PLAT_DS_SetDeepSleep() - call after termination | deep_sleep_timeout=60, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_SetDeepSleep (void)
{
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
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

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
}

/**
 * @brief Ensure PLAT_DS_DeepSleepWakeup() returns correct error codes during positive scenarios
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
 * |02|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_DeepSleepWakeup (void)
{
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedWakeup = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

    // Variation 02: Call PLAT_DS_DeepSleepWakeup() and check the result
    DeepSleep_Return_Status_t resultWakeup = PLAT_DS_DeepSleepWakeup();
    UT_ASSERT_EQUAL(resultWakeup, expectedWakeup);

    // Variation 03: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
}

/**
 * @brief Ensure PLAT_DS_DeepSleepWakeup() returns correct error codes during negative scenarios
 * 
 * @note The error code DEEPSLEEP_WAKEUP_FAILURE cannot be tested
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
 * |01|Call PLAT_DS_DeepSleepWakeup() - call before initialization| | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |04|Call PLAT_DS_DeepSleepWakeup() - call after termination| | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_DeepSleepWakeup (void)
{
	 // Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedNotInitialized = DEEPSLEEPMGR_NOT_INITIALIZED;
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Variation 01: Call PLAT_DS_DeepSleepWakeup() before initialization and check the result
    DeepSleep_Return_Status_t resultNotInitialized1 = PLAT_DS_DeepSleepWakeup();
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

    // Variation 02: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);

    // Variation 03: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);

    // Variation 04: Call PLAT_DS_DeepSleepWakeup() after termination and check the result
    DeepSleep_Return_Status_t resultNotInitialized2 = PLAT_DS_DeepSleepWakeup();
    UT_ASSERT_EQUAL(resultNotInitialized2, expectedNotInitialized);
}

/**
 * @brief Ensure PLAT_DS_GetLastWakeupReason() returns correct error codes during positive scenarios
 * @todo add wake up with timeout test
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
 * |02|Call PLAT_DS_GetLastWakeupReason() Get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupReason (void)
{
	// Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedGetReason = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Placeholder for the wakeup reason
    int wakeupReason;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

    // Variation 02: Call PLAT_DS_GetLastWakeupReason() and check the result
    DeepSleep_Return_Status_t resultGetReason = PLAT_DS_GetLastWakeupReason(&wakeupReason);
    UT_ASSERT_EQUAL(resultGetReason, expectedGetReason);

    // At this point, you may want to further verify if 'wakeupReason' contains valid data.
    // This is dependent on your specific requirements and what PLAT_DS_GetLastWakeupReason() actually does.

    // Variation 03: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
}

/**
 * @brief Ensure PLAT_DS_GetLastWakeupReason() returns correct error codes during negative scenarios
 * 
 * @todo add negative cases after term has been called
 * 
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
	void test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupReason (void)
{
    // Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedNotInitialized = DEEPSLEEPMGR_NOT_INITIALIZED;
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedInvalidArgument = DEEPSLEEPMGR_INVALID_ARGUMENT;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Placeholder for the wakeup reason
    int wakeupReason;

    // Variation 01: Call PLAT_DS_GetLastWakeupReason() before initialization and check the result
    DeepSleep_Return_Status_t resultNotInitialized1 = PLAT_DS_GetLastWakeupReason(&wakeupReason);
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

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
}
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
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

void test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupKeyCode (void)
{
	 // Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedGetKeyCode = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Placeholder for the wakeup keycode
    int wakeupKeyCode;

    // Variation 01: Call PLAT_DS_INIT() and check the result
    DeepSleep_Return_Status_t resultInit = PLAT_DS_INIT();
    UT_ASSERT_EQUAL(resultInit, expectedInit);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

    // Variation 02: Call PLAT_DS_GetLastWakeupKeyCode() and check the result
    DeepSleep_Return_Status_t resultGetKeyCode = PLAT_DS_GetLastWakeupKeyCode(&wakeupKeyCode);
    UT_ASSERT_EQUAL(resultGetKeyCode, expectedGetKeyCode);

    // At this point, you may want to further verify if 'wakeupKeyCode' contains valid data.
    // This is dependent on your specific requirements and what PLAT_DS_GetLastWakeupKeyCode() actually does.

    // Variation 03: Call PLAT_DS_TERM() and check the result
    DeepSleep_Return_Status_t resultTerm = PLAT_DS_TERM();
    UT_ASSERT_EQUAL(resultTerm, expectedTerm);
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
	 // Define expected results for each variation/step
    const DeepSleep_Return_Status_t expectedNotInitialized = DEEPSLEEPMGR_NOT_INITIALIZED;
    const DeepSleep_Return_Status_t expectedInit = DEEPSLEEPMGR_SUCCESS;
    const DeepSleep_Return_Status_t expectedInvalidArgument = DEEPSLEEPMGR_INVALID_ARGUMENT;
    const DeepSleep_Return_Status_t expectedTerm = DEEPSLEEPMGR_SUCCESS;

    // Placeholder for the wakeup keycode
    int wakeupKeyCode;

    // Variation 01: Call PLAT_DS_GetLastWakeupKeyCode() before initialization and check the result
    DeepSleep_Return_Status_t resultNotInitialized1 = PLAT_DS_GetLastWakeupKeyCode(&wakeupKeyCode);
    UT_ASSERT_EQUAL(resultNotInitialized1, expectedNotInitialized);  // Assuming UT_ASSERT_EQUAL is a function in your UT framework

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
	UT_add_test( pSuite, "PLAT_DS_SetDeepSleep_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_SetDeepSleep );
	UT_add_test( pSuite, "PLAT_DS_SetDeepSleep_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_SetDeepSleep );
	UT_add_test( pSuite, "PLAT_DS_DeepSleepWakeup_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_DeepSleepWakeup );
	UT_add_test( pSuite, "PLAT_DS_DeepSleepWakeup_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_DeepSleepWakeup );
	UT_add_test( pSuite, "PLAT_DS_GetLastWakeupReason_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupReason );
	UT_add_test( pSuite, "PLAT_DS_GetLastWakeupReason_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupReason );
	UT_add_test( pSuite, "PLAT_DS_GetLastWakeupKeyCode_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupKeyCode );
	UT_add_test( pSuite, "PLAT_DS_GetLastWakeupKeyCode_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupKeyCode );

	return 0;
} 

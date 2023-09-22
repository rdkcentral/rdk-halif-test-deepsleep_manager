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
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_DS_SetDeepSleep() returns correct error codes during positive scenarios
 * 
 * @todo remove the next four lines for everyone
 * @todo Add additional varaitions for the positive inputs to cover all descrete cases
 * @todo add interrupt to wake us up from deepsleep
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
 * |02|Call PLAT_DS_SetDeepSleep() set deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Manual key press to wake up the device |
 * |04|Call PLAT_DS_SetDeepSleep() set deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=true | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |05|Manual key press to wake up the device |
 * |06|Call PLAT_DS_SetDeepSleep() set deep sleep | deep_sleep_timeout=10, *isGPIOWakeup=false, networkStandby=true | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |07|Manual key press to wake up the device |
 * |08|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_SetDeepSleep (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_DS_SetDeepSleep() returns correct error codes during negative scenarios
 * 
 * @note The error code DEEPSLEEP_SET_FAILURE is not able to be tested here.
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
 * |01|Call PLAT_DS_SetDeepSleep() again | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_SetDeepSleep() set deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=NULL, networkStandby=false | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_SetDeepSleep (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
 * |02|Call PLAT_DS_SetDeepSleep() set deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Manual key press to wake up the device |
 * |04|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |05|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_DeepSleepWakeup (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
 * |01|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up without initializing the module| | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_DeepSleepWakeup (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_DS_GetLastWakeupReason() returns correct error codes during positive scenarios
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
 * |02|Call PLAT_DS_GetLastWakeupReason() Get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupReason (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_DS_GetLastWakeupReason() returns correct error codes during negative scenarios
 * 
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
 * |01|Call PLAT_DS_GetLastWakeupReason() Call function without initializing | *wakeupReason | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_GetLastWakeupReason() Call function invalid inputs | *wakeupReason=NULL | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupReason (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_DS_GetLastWakeupKeyCode() returns correct error codes during positive scenarios
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
 * |02|Call PLAT_DS_GetLastWakeupKeyCode() Call get last wakeup keycode | *wakeupKeyCode | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

void test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupKeyCode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_DS_GetLastWakeupKeyCode() returns correct error codes during negative scenarios
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
 * |01|Call PLAT_DS_GetLastWakeupKeyCode() again | *wakeupKeyCode | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_GetLastWakeupKeyCode() again | *wakeupKeyCode=NULL | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupKeyCode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_DS_TERM() returns correct error codes during positive scenarios
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
 * |02|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */
void test_l1_deepSleepMgr_positive_PLAT_DS_TERM (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Ensure PLAT_DS_TERM() returns correct error codes during negative scenarios
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
 * |01|Call PLAT_DS_TERM() - close interface | | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */

void test_l1_deepSleepMgr_negative_PLAT_DS_TERM (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_add_test( pSuite, "PLAT_DS_SetDeepSleep_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_SetDeepSleep );
	UT_add_test( pSuite, "PLAT_DS_SetDeepSleep_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_SetDeepSleep );
	UT_add_test( pSuite, "PLAT_DS_DeepSleepWakeup_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_DeepSleepWakeup );
	UT_add_test( pSuite, "PLAT_DS_DeepSleepWakeup_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_DeepSleepWakeup );
	UT_add_test( pSuite, "PLAT_DS_GetLastWakeupReason_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupReason );
	UT_add_test( pSuite, "PLAT_DS_GetLastWakeupReason_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupReason );
	UT_add_test( pSuite, "PLAT_DS_GetLastWakeupKeyCode_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_GetLastWakeupKeyCode );
	UT_add_test( pSuite, "PLAT_DS_GetLastWakeupKeyCode_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_GetLastWakeupKeyCode );
	UT_add_test( pSuite, "PLAT_DS_TERM_L1_positive" ,test_l1_deepSleepMgr_positive_PLAT_DS_TERM );
	UT_add_test( pSuite, "PLAT_DS_TERM_L1_negative" ,test_l1_deepSleepMgr_negative_PLAT_DS_TERM );
	

	return 0;
} 

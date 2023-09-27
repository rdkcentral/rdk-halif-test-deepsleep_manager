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
* @file TODO: test_l2_deepSleepMgr.c
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
 * @brief Test to make sure PLAT_DS_SetDeepSleep() wakes up properly when woken via user input.
 *
 * In this test, we set the wake up timer to 0 to enforce needing to wake up via user input (e.g. Remote key press).
 *
 * **Test Group ID:** Module: 02@n
 * **Test Case ID:** 01@n
 *
 * **Test Procedure:**
 * Refer to UT specification documentation [l2_module_test_specification.md](l2_module_test_specification.md)
 * 
 */
void test_l2_deepSleepMgr_PLAT_DS_SetDeepSleep (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Test to make sure PLAT_DS_GetLastWakeupReason() returns the proper value when woken up in the corresponding manner.
 * 
 * @todo Discuss the deepsleep wake up reasons that cannot be easily tested.
 *
 * Set deepsleep multiple times, and make sure that when the device is woken up in a specific manner (e.g. key press, motion, voice, timer, etc)
 *          the device returns the corresponding wake up reason
 *
 * **Test Group ID:** Module: 02@n
 * **Test Case ID:** 02@n
 *
 * **Test Procedure:**
 * Refer to UT specification documentation [l2_module_test_specification.md](l2_module_test_specification.md)
 * 
 */
void test_l2_deepSleepMgr_PLAT_DS_GetLastWakeupReason (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
 * @brief Test to make sure PLAT_DS_GetLastWakeupKeyCode() returns the proper value when woken up in the corresponding manner.
 * 
 * @todo figure out how to test to make sure we get the proper keycode on return
 * @todo Discuss the deepsleep wake up reasons that cannot be easily tested.
 *
 * Set deepsleep multiple times, and make sure that when the device is woken up in a specific manner (e.g. key press, motion, voice, timer, etc)
 *          the device returns the corresponding wake up keycode
 *
 * **Test Group ID:** Module: 02@n
 * **Test Case ID:** 03@n
 *
 * **Test Procedure:**
 * Refer to UT specification documentation [l2_module_test_specification.md](l2_module_test_specification.md)
 * 
 */
void test_l2_deepSleepMgr_PLAT_DS_GetLastWakeupKeyCode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main test(s) for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_l2_deepSleepMgr_register ( void )
{
	/* add a suite to the registry */
	pSuite = UT_add_suite( "[L2 deepSleepMgr]", NULL, NULL );
	if ( NULL == pSuite )
	{
		return -1;
	}	

	
	UT_add_test( pSuite, "test_l2_deepSleepMgr" ,test_l2_deepSleepMgr );

	return 0;
} 

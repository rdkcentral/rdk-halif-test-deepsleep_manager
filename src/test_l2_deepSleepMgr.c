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
 * @par Application API Specification
 */
/**
 * @addtogroup Deepsleep_Manager_HALTEST Deep Sleep Manager HALTEST
 * @{
 */
/**
 * @defgroup Deepsleep_Mgr_HALTEST_L2 Deep Sleep Manager HALTEST L2
 * @{
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
* Ref to API Definition specification documentation : [deepsleep-manager_halSpec.md](../../docs/pages/deepsleep-manager_halSpec.md)
*/

#include <string.h>
#include <stdlib.h>

#include <ut.h>
#include <ut_log.h>

/**
* @brief TODO: Describe the object of the test
*
* TODO: Add the description of what is tested and why in this test
*
* **Test Group ID:** TODO: Add the group this test belongs to - Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
*
* **Test Procedure:**
* Refer to UT specification documentation [l2_module_test_specification.md](l2_module_test_specification.md)
*/
void test_l2_deepSleepMgr_power (void)
{
	UT_FAIL_FATAL("This function needs to be implemented!"); 
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

	
	UT_add_test( pSuite, "test_l2_deepSleepMgr" ,test_l2_deepSleepMgr_power );

	return 0;
} 

/** @} */ // End of Deepsleep_Mgr_HALTEST_L2
/** @} */ // End of Deepsleep_Manager_HALTEST
/** @} */ // End Deepsleep_Manager
/** @} */ // End of HPK

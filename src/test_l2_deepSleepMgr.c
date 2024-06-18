/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2024 RDK Management
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

/**
* @file test_l2_deepSleepMgr.c
* @page deepSleepMgr Level 2 Tests
*
* ## Module's Role
* This module includes Level 2 functional tests (success and failure scenarios).
* This is to ensure that the deepSleepMgr APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [deepSleepMgr_halSpec.md](../../docs/pages/deepSleepMgr_halSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include <ut_kvp_profile.h>
#include "deepSleepMgr.h"

static int gTestGroup = 2;
static int gTestID = 1;

/**
* @brief Test to verify the deep sleep and wakeup functionality
*
* This test case verifies the deep sleep and wakeup functionality of the L2 deep sleep manager. It checks if the system can successfully enter deep sleep mode and wake up from it.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 001@n
*
* **Test Procedure:**
* Refer to UT specification documentation [deepSleepMgr_L2_Low-Level_TestSpecification.md](../../docs/pages/deepSleepMgr_L2_Low-Level_TestSpecification.md)
*/

void test_l2_deepSleepMgr_SetDeepSleepAndVerifyWakeup1(void)
{
    gTestID = 1;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    DeepSleep_Return_Status_t status;
    bool isGPIOWakeup ;

    UT_LOG_DEBUG("Invoking PLAT_DS_INIT");
    status = PLAT_DS_INIT();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, DEEPSLEEPMGR_SUCCESS);

    UT_LOG_DEBUG("Invoking PLAT_DS_SetDeepSleep with deep_sleep_timeout=1, isGPIOWakeup= valid pointer, networkStandby=FALSE");
    status = PLAT_DS_SetDeepSleep(1, &isGPIOWakeup, false);
    UT_LOG_DEBUG("Return status: %d, isGPIOWakeup: %d", status, isGPIOWakeup);
    UT_ASSERT_EQUAL(status, DEEPSLEEPMGR_SUCCESS);
    if (status != DEEPSLEEPMGR_SUCCESS)
    {
        UT_LOG_ERROR("PLAT_DS_SetDeepSleep failed with status: %d", status);
        UT_LOG_DEBUG("Invoking PLAT_DS_TERM");
        PLAT_DS_TERM();
        return;
    }

    UT_LOG_DEBUG("Invoking PLAT_DS_DeepSleepWakeup");
    status = PLAT_DS_DeepSleepWakeup();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, DEEPSLEEPMGR_SUCCESS);
    UT_ASSERT_EQUAL(isGPIOWakeup, false);
    if (status != DEEPSLEEPMGR_SUCCESS)
    {
        UT_LOG_ERROR("PLAT_DS_DeepSleepWakeup failed with status: %d", status);
        UT_LOG_DEBUG("Invoking PLAT_DS_TERM");
        PLAT_DS_TERM();
        return;
    }

    UT_LOG_DEBUG("Invoking PLAT_DS_TERM");
    status = PLAT_DS_TERM();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, DEEPSLEEPMGR_SUCCESS);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the deep sleep and wake up functionality
*
* This test case sets the system into deep sleep and verifies if the system wakes up correctly. The test is crucial to ensure the power management functionality of the system is working as expected.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 002@n
*
* **Test Procedure:**
* Refer to UT specification documentation [deepSleepMgr_L2_Low-Level_TestSpecification.md](../../docs/pages/deepSleepMgr_L2_Low-Level_TestSpecification.md)
*/

void test_l2_deepSleepMgr_SetDeepSleepAndVerifyWakeUp10(void)
{
    gTestID = 2;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    DeepSleep_Return_Status_t status;
    bool isGPIOWakeup;
    uint32_t deep_sleep_timeout = 10;
    bool networkStandby = false;

    UT_LOG_DEBUG("Invoking PLAT_DS_INIT");
    status = PLAT_DS_INIT();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, DEEPSLEEPMGR_SUCCESS);

    UT_LOG_DEBUG("Invoking PLAT_DS_SetDeepSleep with deep_sleep_timeout: %d, isGPIOWakeup: valid pointer, networkStandby: %d", deep_sleep_timeout, networkStandby);
    status = PLAT_DS_SetDeepSleep(deep_sleep_timeout, &isGPIOWakeup, networkStandby);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, DEEPSLEEPMGR_SUCCESS);
    UT_LOG_DEBUG("isGPIOWakeup: %d", isGPIOWakeup);
    if (status != DEEPSLEEPMGR_SUCCESS)
    {
        UT_LOG_ERROR("PLAT_DS_SetDeepSleep failed with status: %d", status);
        UT_LOG_DEBUG("Invoking PLAT_DS_TERM");
        PLAT_DS_TERM();
        return;
    }

    UT_LOG_DEBUG("Invoking PLAT_DS_DeepSleepWakeup");
    status = PLAT_DS_DeepSleepWakeup();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, DEEPSLEEPMGR_SUCCESS);
    UT_ASSERT_EQUAL(isGPIOWakeup, false);
    if (status != DEEPSLEEPMGR_SUCCESS)
    {
        UT_LOG_ERROR("PLAT_DS_DeepSleepWakeup failed with status: %d", status);
        UT_LOG_DEBUG("Invoking PLAT_DS_TERM");
        PLAT_DS_TERM();
        return;
    }

    UT_LOG_DEBUG("Invoking PLAT_DS_TERM");
    status = PLAT_DS_TERM();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, DEEPSLEEPMGR_SUCCESS);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */

int test_deepSleepMgr_l2_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L2 deepSleepMgr]", NULL, NULL);
    if (pSuite == NULL)
    {
        return -1;
    }
    // List of test function names and strings

    UT_add_test( pSuite, "l2_deepSleepMgr_SetDeepSleepAndVerifyWakeup1", test_l2_deepSleepMgr_SetDeepSleepAndVerifyWakeup1);
    UT_add_test( pSuite, "l2_deepSleepMgr_SetDeepSleepAndVerifyWakeUp10", test_l2_deepSleepMgr_SetDeepSleepAndVerifyWakeUp10);

    return 0;
}
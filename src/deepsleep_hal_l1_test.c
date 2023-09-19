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
 * @brief Ensure PLAT_DS_INIT() returns correct error codes during positive scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 2. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
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

/**
 * @brief Ensure PLAT_DS_INIT() returns correct error codes during negative scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 2. PLAT_DS_INIT() should return DEEPSLEEP_ALREADY_INITIALIZED when trying to initialize again.
 * 3. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
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

/**
 * @brief Ensure PLAT_DS_SetDeepSleep() returns correct error codes during positive scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 2. PLAT_DS_SetDeepSleep() should return DEEPSLEEPMGR_SUCCESS.
 * 3. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
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
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

/**
 * @brief Ensure PLAT_DS_SetDeepSleep() returns correct error codes during negative scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_SetDeepSleep() should return DEEPSLEEPMGR_NOT_INITIALIZED.
 * 2. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 3. PLAT_DS_SetDeepSleep() should return DEEPSLEEPMGR_INVALID_ARGUMENT.
 * 4. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
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
 * |03|Call PLAT_DS_SetDeepSleep() set deep sleep | deep_sleep_timeout=-1, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_SetDeepSleep() set deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=NULL, networkStandby=false | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |05|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

/**
 * @brief Ensure PLAT_DS_DeepSleepWakeup() returns correct error codes during positive scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 2. PLAT_DS_DeepSleepWakeup() should return DEEPSLEEPMGR_SUCCESS.
 * 3. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
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
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

/**
 * @brief Ensure PLAT_DS_GetLastWakeupReason() returns correct error codes during positive scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 2. PLAT_DS_GetLastWakeupReason() should return DEEPSLEEPMGR_SUCCESS.
 * 3. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
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
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_GetLastWakeupReason() Get last wakeup reason | *wakeupReason=DEEPSLEEP_WAKEUPREASON_IR | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

/**
 * @brief Ensure PLAT_DS_GetLastWakeupReason() returns correct error codes during negative scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_GetLastWakeupReason() should return DEEPSLEEPMGR_NOT_INITIALIZED.
 * 2. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 3. PLAT_DS_GetLastWakeupReason() should return DEEPSLEEPMGR_INVALID_ARGUMENT.
 * 4. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
 * 
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
 * |01|Call PLAT_DS_GetLastWakeupReason() Call function without initializing | *wakeupReason | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_GetLastWakeupReason() Call function invalid inputs | *wakeupReason=NULL | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

/**
 * @brief Ensure PLAT_DS_GetLastWakeupKeyCode() returns correct error codes during positive scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 2. PLAT_DS_GetLastWakeupKeyCode() should return DEEPSLEEPMGR_SUCCESS.
 * 3. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
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
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_GetLastWakeupKeyCode() Call get last wakeup keycode | *wakeupKeyCode | DEEPSLEEPMGR_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

/**
 * @brief Ensure PLAT_DS_GetLastWakeupKeyCode() returns correct error codes during negative scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_GetLastWakeupKeyCode() should return DEEPSLEEPMGR_NOT_INITIALIZED.
 * 2. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 3. PLAT_DS_GetLastWakeupKeyCode() should return DEEPSLEEPMGR_INVALID_ARGUMENT.
 * 4. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
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
 * |01|Call PLAT_DS_GetLastWakeupKeyCode() again | *wakeupKeyCode | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * |02|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |03|Call PLAT_DS_GetLastWakeupKeyCode() again | *wakeupKeyCode=NULL | DEEPSLEEPMGR_INVALID_ARGUMENT | Should Pass |
 * |04|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */



/**
 * @brief Ensure PLAT_DS_TERM() returns correct error codes during positive scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_INIT() should return DEEPSLEEP_SUCCESS when initializing the module.
 * 2. PLAT_DS_TERM() should return DEEPSLEEP_SUCCESS after successful termination.
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
 * |01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * |02|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
 * 
 */

/**
 * @brief Ensure PLAT_DS_TERM() returns correct error codes during negative scenarios
 * 
 * This test case ensures the following conditions:
 * 1. PLAT_DS_TERM() should return DEEPSLEEPMGR_NOT_INITIALIZED after successful termination.
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
 * |01|Call PLAT_DS_TERM() - close interface | | DEEPSLEEPMGR_NOT_INITIALIZED | Should Pass |
 * 
 */

# L2 Test Specification template
## History

| Version | Date(YY-MM-DD) | Author |Comments |
| -------| ----- | ----- | ----- |
| 1.0.0 | 22/02/23 | Anjali Thampi| Inital Document |

## Table of Contents

- [Overview](#overview)
  - [Acronyms](#acronyms)
  - [Definitions](#definitions)
  - [References](#references)
- [Level 2 Test Suite](#level-2-test-suite)
  - [Test 1](#test-1)
  - [Test 2](#test-2)

## Overview

This document describes the level 2 testing suite for the <component> module.

### Acronyms, Terms and Abbreviations

- `HAL` \- Hardware Abstraction Layer, may include some common components
- `HAL.h`  \- Abstracted defined API to control the hardware
- `HAL.c`  \- Implementation wrapper layer created by the `OEM` or `SoC` Vendor.
- `RDK`  \- Reference Design Kit for All Devices
- `RDK-B`  \- Reference Design Kit for Broadband Devices
- `RDK-V`  \- Reference Design Kit for Video Devices
- `UT`  \- Unit Test(s)
- `OEM`  \- Original Equipment Manufacture (Sky is also an OEM)
- `SoC`  \- System on a Chip

### Definitions

- `Broadcom` \- `SoC` manufacturer <https://www.broadcom.com/>
- `Amlogic` \- `SoC` manufacturer <https://en.wikipedia.org/wiki/Amlogic>
- `Soc Vendor` \- Definition to encompass multiple vendors
- `Unit Tests` \- C Function tests that run on the target hardware
- `Common Testing Framework` \- Off the shelf 3rd Party Testing Framework, or framework that does not require infrastructure to control it. That's not to say it cannot be controlled via infrastructure if required. Examples of which are.
  - `GTest` \- Google Test Suit <https://google.github.io/googletest>
  - `CUnit` \- C Testing Suit <http://cunit.sourceforge.net/>
  - `Unity` \- C Embedded Testing Suit <http://www.throwtheswitch.org/unity>
  - `ut-core` \- Common Testing Framework <https://github.com/comcast-sky/rdk-components-ut-core>, which wraps a open-source framework that can be expanded to the requirements for future comcast-sky framework.

### References

- `Feedback Loops` \- <https://www.softwaretestingnews.co.uk/4-methods-to-improve-your-feedback-loops-and-supercharge-your-testing-process/>
- `Doxygen` \- SourceCode documentation tool - <https://www.doxygen.nl/index.html>
- `Black Box Testing` \- <https://en.wikipedia.org/wiki/Black-box_testing>

## Level 2 Test Suite

The following functions are expecting to test the module operates correctly.

### Test 1

|Title|Details|
|--|--|
|Function Name|`test_l2_deepSleepMgr_PLAT_DS_SetDeepSleep`|
|Description|Ensure PLAT_DS_SetDeepSleep() functionally works as intended when manual wake up is needed.|
|Test Group|Module: 02@n |
|Test Case ID|01@n|
|Priority|High|

**Pre-Conditions :**
TODO: Add pre-conditions, if any

**Dependencies :** TODO: Add dependencies for this test, if any

**User Interaction :** User action is required to take the device up after it goes into deep sleep without a timeout set.

@todo send out a mail on the points we need to discuss

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
|01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=30, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|04|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=true | DEEPSLEEPMGR_SUCCESS | Should Pass |
|04|Manual button press to trigger wake up from deepsleep | | | Should Pass |
|05|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|06|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |

### Test 2

|Title|Details|
|--|--|
|Function Name|`test_l2_deepSleepMgr_PLAT_GetLastWakeupReason`|
|Description|Ensure that PLAT_DS_GetLastWakeupReason returns the proper wake up reason.|
|Test Group|Module: 02@n)|
|Test Case ID|02@n|
|Priority|High|

**Pre-Conditions :**
TODO: Add pre-conditions, if any

**Dependencies :** TODO: Add dependencies for this test, if any

**User Interaction :** User action is required to take the device up after it goes into deep sleep without a timeout set.

#### Test Procedure :

TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
|Variation / Step|Description|Test Data|Expected Result|Notes|
|:--:|---------|----------|--------------|-----|
|01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger IR wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger RCU_BT wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger RCU_RF4CE wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger GPIO wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger LAN wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger WLAN wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=30, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Let device wake up through timer |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger through Front Panel wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Watchdog wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger CEC wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Voice wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Presence wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Software Reset wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Thermal Reset wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Cold boot wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger STR Auth Failure wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Warm Reset wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupReason() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |

|05|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |


### Test 1

|Title|Details|
|--|--|
|Function Name|`test_l2_deepSleepMgr_PLAT_DS_GetLastWakeupKeyCode`|
|Description|Ensure PLAT_DS_SetDeepSleep() functionally works as intended when manual wake up is needed.|
|Test Group|Module: 02@n |
|Test Case ID|03@n|
|Priority|High|

**Pre-Conditions :**
TODO: Add pre-conditions, if any

**Dependencies :** TODO: Add dependencies for this test, if any

**User Interaction :** User action is required to take the device up after it goes into deep sleep without a timeout set.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
|01|Call PLAT_DS_INIT() - open interface | | DEEPSLEEP_SUCCESS | Should Pass |
|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger IR wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger RCU_BT wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger RCU_RF4CE wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger GPIO wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger LAN wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger WLAN wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=30, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Let device wake up through timer |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger through Front Panel wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Watchdog wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger CEC wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Voice wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Presence wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Software Reset wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Thermal Reset wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Cold boot wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger STR Auth Failure wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |


|02|Call PLAT_DS_SetDeepSleep() - initiate device deep sleep | deep_sleep_timeout=0, *isGPIOWakeup=false, networkStandby=false | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Manually trigger Warm Reset wake up |  |  | Should Pass |
|03|Call PLAT_DS_DeepSleepWakeup() Trigger deep sleep wake up | | DEEPSLEEPMGR_SUCCESS | Should Pass |
|02|Call PLAT_DS_GetLastWakeupKeyCode() - get last wakeup reason | *wakeupReason | DEEPSLEEPMGR_SUCCESS | Should Pass |

|05|Call PLAT_DS_TERM() - close interface | | DEEPSLEEP_SUCCESS | Should Pass |
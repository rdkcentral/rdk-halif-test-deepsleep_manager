# Deep Sleep Manager High Level Test Specification Documentation

## Acronyms, Terms and Abbreviations

- `HAL`- Hardware Abstraction Layer
- `API`- Application Programming Interface
- `L2` - Level2 Testing
- `L3` - Level3 Testing
- `NA` - Not Applicable
- `Y` - Yes

## Introduction

This document provides an overview of High Level testing requirements for the Deep Sleep Manager module. It outlines the scope of testing, objectives, testing levels and approaches, specific test requirements, control plane emulator requirements and expected deliverables.

Interface of the test is available here: [DeepSleep Manager HAL header](https://github.com/rdkcentral/rdk-halif-deepsleep_manager/blob/main/include/deepSleepMgr.h)

The Power manager Hal Spec document: [DeepSleep Manager HAL Spec](https://github.com/rdkcentral/rdk-halif-deepsleep_manager/blob/main/docs/pages/deepsleep-manager_halSpec.md)

## Test Scenarios

The Deep-sleep Manager layer facilitates the deep-sleep sleep and wake up procedures.

|#|Test Functionality|Description|
|-|------------------|-----------|
|1|[Set deep sleep with timeout](#set-deep-sleep-with-timeout)|Set the deep sleep with timeout and verify the wake-up source |
|2|[Test with Wake-up Source](#test-with-wake-up-source)|Configure the deep sleep mode with no timeout, ensuring that the Deep Sleep Manager facilitates wake-up sources, allowing the device to awaken from deep sleep.|

### Set Deep Sleep with timeout

|Description|HAL APIs|L2|L3|Control plane requirements|
|-----------|--------|--|--|--------------------------|
|Set the deep sleep with  of one second and verify the wake-up source |PLAT_DS_SetDeepSleep|`Y`|`NA`|`NA`|
|Set the deep sleep with  of ten seconds and verify the wake-up source |PLAT_DS_SetDeepSleep|`Y`|`NA`|`NA`|
|Verify that the device has come out of deep-sleep after the specified timeout period has ended. Verify that, based on how long the device sleep, it comes out with a time difference based on the platform configuration file. Also verify that the internal clock matches the network clock after wake up.|PLAT_DS_SetDeepSleep|`N`|`Y`|`NA`|

#### Test Startup Requirement - Set Deep Sleep with timeout

`NA`

#### Emulator Requirements - Set Deep Sleep with timeout

- Boot configuration: Wake-up sources supported by the device read from the platform profile. See DeepSleep_WakeupReason_t.

#### Control Plane Requirements - Set Deep Sleep with timeout

- Control plane must have some way to verify the time the device slept for before waking up.

### Test with Wake-up Source

|Description|HAL APIs|L2|L3|Control plane requirements|
|-----------|--------|--|--|--------------------------|
|Configure the deep sleep mode with no timeout, ensuring that the Deep Sleep Manager facilitates wake-up sources( PLAT_API_SetWakeupSrc ) for all wake-up sources that the device supports, allowing the device to awaken from deep sleep.|PLAT_DS_SetDeepSleep|`NA`|`Y`|Control plane requirements to trigger non-timeout wake up source.|
|Configure the deep sleep mode with a timeout, before triggering a wake-up from an external wake up source( PLAT_API_SetWakeupSrc ) for all wake-up sources that the device supports, allowing the device to awaken from deep sleep.|PLAT_DS_SetDeepSleep|`NA`|`Y`|Control plane requirements to trigger non-timeout wake up source.|
|Configure the deep sleep mode with a one minute timeout. Verify that is a wake up source is not enabled, the device does not wake up when that external wake up source( PLAT_API_SetWakeupSrc ) is triggered. |PLAT_DS_SetDeepSleep, PLAT_API_GetWakeupSrc|`NA`|`Y`|Control plane requirements to trigger non-timeout wake up source.|
|Configure the deep sleep mode with no timeout, ensuring that the Deep Sleep Manager does not wake up from deepsleep until an external wake up source triggers. Wait thirty seconds.|PLAT_DS_SetDeepSleep|`NA`|`Y`|Control plane requirements to trigger non-timeout wake up source.|
|Configure the deep sleep mode with a ten second timeout but timeout wake up source is disabled, ensuring that the Deep Sleep Manager does not wake up from deepsleep until an external wake up source triggers. Wait thirty seconds.|PLAT_DS_SetDeepSleep, PLAT_API_SetWakeupSrc|`NA`|`Y`|Control plane requirements to trigger non-timeout wake up source.|
|Configure the deep sleep mode with no timeout, ensuring that the Deep Sleep Manager facilitates wake-up sources( PLAT_API_SetWakeupSrc ) for different combinations of wake up sources being enabled. (PWRMGR_WAKEUPSRC_WIFI/PWRMGR_WAKEUPSRC_LAN) |PLAT_DS_SetDeepSleep PLAT_API_GetWakeupSrc|`NA`|`Y`|Control plane requirements to trigger non-timeout wake up source.|

#### Test Startup Requirement - Test with Wake-up Source

`NA`

#### Emulator Requirements - Test with Wake-up Source

- Boot configuration: Wake-up sources supported by the device read from the platform profile. See DeepSleep_WakeupReason_t.

#### Control Plane Requirements - Test with Wake-up Source

- Control panel to trigger the wake-up source and supported wake-up sources are:
- Ability to trigger a power cycle if the a test fails a device remains within deepsleep for too long. The limit should be two minutes. It should be on a test by case basis.

### Check Power consumption

|Description|HAL APIs|L2|L3|Control plane requirements|
|-----------|--------|--|--|--------------------------|
|Set the deep sleep with and check that the decrease in power comsumption based on the test configuration file with network standby disabled.|PLAT_DS_SetDeepSleep|`NA`|`Y`|`NA`|
|Set the deep sleep with and check that the decrease in power comsumption based on the test configuration file with network standby enabled.|PLAT_DS_SetDeepSleep|`NA`|`Y`|`NA`|

#### Test Startup Requirement - Check Power consumption

`NA`

#### Emulator Requirements -Check Power consumption

- Boot configuration: Wake-up sources supported by the device read from the platform profile. See DeepSleep_WakeupReason_t.

#### Control Plane Requirements - Check Power consumption

- Control plane must have way to capture the power consumption changes when the device enters deep sleep

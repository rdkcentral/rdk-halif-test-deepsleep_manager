# Deepsleep Manager L3 Low Level Test Specification and Procedure Documentation

## Table of Contents

- [Overview](#overview)
- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [References](#references)
- [Level 3 Test cases High Level Overview](#level-3-test-cases-high-level-overview)

## Overview

This document describes the L3 Low Level Test Specification and Procedure Documentation for the Deepsleep Manager module.

### Acronyms, Terms and Abbreviations

- `HAL` \- Hardware Abstraction Layer, may include some common components
- `UT`  \- Unit Test(s)
- `OEM` \- Original Equipment Manufacture
- `SoC` \- System on a Chip
- `LAN` \- Local Area Network
- `Y`   \- yes supported
- `NA`  \- Not Supported

### References

- `High Level Test Specification` - [DeepSleep Manager High Level TestSpec](deep-sleep-manager_High-Level_TestSpec.md)
- `HAL Interface file` -  [DeepSleep Manager HAL header](https://github.com/rdkcentral/rdk-halif-deepsleep_manager/blob/main/include/deepSleepMgr.h)

## Level 3 Test Cases High Level Overview

|#|Test-case|Description|HAL APIs|Source|Sink|
|-|---------|-----------|--------|------|----|
|1|Verify the deepsleep wake up from Voice|Trigger deepsleep, and trigger wake up from voice up source|`PLAT_DS_SetDeepSleep()`|`Y`|`Y`|
|2|Verify the deepsleep wake up from Presence Detection| Trigger deepsleep, and trigger wake up from presence detection|`PLAT_DS_SetDeepSleep()`|`Y`|`Y`|
|3|Verify the deepsleep wake up from Bluetooth| Trigger deepsleep, and trigger wake up from bluetooth|`PLAT_DS_SetDeepSleep()`|`Y`|`Y`|
|4|Verify the deepsleep wake up from wifi| Trigger deepsleep, and trigger wake up from wifi|`PLAT_DS_SetDeepSleep()`|`Y`|`Y`|
|5|Verify the deepsleep wake up from IR| Trigger deepsleep, and trigger wake up from IR|`PLAT_DS_SetDeepSleep()`|`Y`|`Y`|
|6|Verify the deepsleep wake up from Power Key| Trigger deepsleep, and trigger wake up from Power Key|`PLAT_DS_SetDeepSleep()`|`Y`|`Y`|
|7|Verify the deepsleep wake up from CEC| Trigger deepsleep, and trigger wake up from CEC|`PLAT_DS_SetDeepSleep()`|`Y`|`Y`|
|8|Verify the deepsleep wake up from LAN| Trigger deepsleep, and trigger wake up from LAN|`PLAT_DS_SetDeepSleep()`|`Y`|`Y`|

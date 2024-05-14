# Deepsleep Manager Test Specification Documentation

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Introduction](#introduction)
- [Module Description](#module-description)
- [Testing Scope](#testing-scope)
  - [Set DeepSleep with timeout](#set-deepsleep-with-timeout)
  - [Test with wake-up Source](#test-with-wake-up-source)

## Acronyms, Terms and Abbreviations

- `HAL`:    Hardware Abstraction Layer
- `API`:   Application Programming Interface
- `L2` - Level2 Testing
- `L3` - Level3 Testing
- `NA` : Not Applicable

## Introduction

This document provides an overview of the testing requirements for the Deep Sleep Manager module. It outlines the scope of testing, objectives, testing levels and approaches, specific test requirements, control plane emulator requirements and expected deliverables.

Interface of the test is available here: [DeepSleep Manager HAL header](https://github.com/rdkcentral/rdk-halif-deepsleep_manager/blob/main/include/deepSleepMgr.h)

## Module Description

The Deep Sleep Manger `HAL` provides a set of `APIs` to initialize, set the deep sleep state and wake-up from the deep sleep state with a list of wake-up source.

## Test Scenarios

The Deep-sleep Manager layer facilitates the deep-sleep sleep and wake up procedures.

|#|Test Functionality|Description|
|-|------------------|-----------|
|1|[Set deep sleep with timeout](#set-deep-sleep-with-timeout)|Set the deep sleep with timeout and verify the wake-up source |
|2|[Test with Wake-up Source](#test-with-wake-up-source)|Configure the deep sleep mode with no timeout, ensuring that the Deep Sleep Manager facilitates wake-up sources, allowing the device to awaken from deep sleep.|


### Set Deep Sleep with timeout
|S.No.|Test Functionality|Description|HAL APIs|L2|L3|Control plane requirements|
|-----|------------------|-----------|--------|--|--|--------------------------|
|1|[Set deep sleep with timeout](#set-deep-sleep-with-timeout)|Set the deep sleep with timeout and verify the wake-up source |PLAT_DS_SetDeepSleep|Y|`NA`|`NA`|

#### Test Startup Requirement

`NA`

#### Emulator Requirements

`NA`

#### Control Plane Requirements

`NA`

### Test with Wake-up Source
|S.No.|Test Functionality|Description|HAL APIs|L2|L3|Control plane requirements|
|-----|------------------|-----------|--------|--|--|--------------------------|
|2|[Test with Wake-up Source](#test-with-wake-up-source)|Configure the deep sleep mode with no timeout, ensuring that the Deep Sleep Manager facilitates wake-up sources, allowing the device to awaken from deep sleep.|PLAT_DS_SetDeepSleep|`NA`|Y|Control plane requirements to trigger non-timeout wake up source.|

#### Test Startup Requirement - Test with Wake-up Source

`NA`

#### Emulator Requirements - Test with Wake-up Source

- Boot configuration: Wake-up sources supported by the device

#### Control Plane Requirements - Test with Wake-up Source

- Control panel to trigger the wake-up source and supported wake-up sources are:

[DeepSleep_WakeupReason_t link](https://github.com/rdkcentral/rdk-halif-deepsleep_manager/blob/main/include/deepSleepMgr.h#L146)

-----------
-----------

## Boot configuartion

### Module Configuration Requirements

The module must be configured during the boot sequence in the case of emulation as if it were a real hardware device with access to multiple deep-sleep wake up sources.
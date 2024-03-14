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
- `IR`:     InfraRed
- `CEC`:    Consumer Electronic Control
- `LAN`:    Local Area Network
- `STB`:    Set-top Box
- `RCU`:    Remote Control Unit
- `STR`:    Suspend To RAM
- `HDMI`:   High-Definition Multimedia Interface
- `GPIO`:   General Purpose Input/OutputManufacturers
- `L2` - Level2 Testing
- `L3` - Level3 Testing
- `NA` : Not Applicable

## Introduction

This document provides an overview of the testing requirements for the Deep Sleep Manager module. It outlines the scope of testing, objectives, testing levels and approaches, specific test requirements, control plane emulator requirements and expected deliverables.

Interface of the test is available here: [DeepSleep Manager HAL header](https://github.com/rdkcentral/rdk-halif-deepsleep_manager/blob/main/include/deepSleepMgr.h)

## Module Description

The Deep Sleep Manger `HAL` provides a set of `APIs` to initialize, set the deep sleep state and wake-up from the deep sleep state with a list of wake-up source.

## Testing Scope

|#|Test Functionality|Description|L2|L3|
|-|------------------|-----------|--|--|
|1|[Set deep sleep with timeout](#set-deep-sleep-with-timeout)|Set the deep sleep with timeout and verify the wake-up source |Y|`NA`|
|2|[Test with Wake-up Source](#test-with-wake-up-source)|Configure the deep sleep mode with no timeout, ensuring that the Deep Sleep Manager facilitates wake-up sources, allowing the device to awaken from deep sleep.|`NA`|Y|

### Set Deep Sleep with timeout

|Description|
|-----------|
|Set the deep sleep with timeout and verify the wake-up source and timeout value|

#### Test Startup Requirement

`NA`

#### Emulator Requirements

`NA`

#### Control Plane Requirements

`NA`

### Test with Wake-up Source

|Description|
|-----------|
|Configure the deep sleep mode with no timeout, ensuring that the DeepSleep Manager facilitates wake-up sources, allowing the device to awaken from deep sleep.|

#### Test Startup Requirement - Test with Wake-up Source

`NA`

#### Emulator Requirements - Test with Wake-up Source

Boot configuration: Wake-up sources supported by the device

#### Control Plane Requirements - Test with Wake-up Source

Control panel to trigger the wake-up source and supported wake-up sources are:

[DeepSleep_WakeupReason_t link](https://github.com/rdkcentral/rdk-halif-deepsleep_manager/blob/main/include/deepSleepMgr.h#L146)
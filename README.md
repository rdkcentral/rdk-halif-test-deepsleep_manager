# Unit Testing Suite For Deep Sleep Manager HAL

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Reference Documents](#reference-documents)
- [Notes](#notes)

## Acronyms, Terms and Abbreviations

- `L1` - Functional Tests
- `HAL`- Hardware Abstraction Layer

## Description

This repository contains the Unit Test Suites (L1) for Deep Sleep Manager `HAL`.

## Reference Documents

<!-- Need to update links to rdkcentral and point to branch main-->
|SNo|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[deepsleep-manager_halSpec.md - v1.0.3 ](https://github.com/rdkcentral/rdk-halif-deepsleep_manager//blob/1.0.3/docs/pages/deepsleep-manager_halSpec.md "deepsleep-manager_halSpec.md")|
|2|`L1` Tests |`L1` Test Case File for this module |[test_l1_deepSleepMgr.c - v1.0.4](https://github.com/rdkcentral/rdk-halif-test-deepsleep_manager/blob/1.0.4/src/test_l1_deepSleepMgr.c "test_l1_deepSleepMgr.c")|

## Notes

- All APIs need to be implemented in this current version. If any API is not supported, please add stub implementation with return type DEEPSLEEPMGR_SUCCESS for the same.
- Building against the actual library may introduce SOC dependencies. Hence, a template SKELETON library is created without SOC dependencies. On the real platform (target), it can be mounted, copied and bound with the actual library.

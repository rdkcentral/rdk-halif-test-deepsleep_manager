# Unit Testing Suite For Deep Sleep Manager HAL

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Reference Documents](#reference-documents)
- [Notes](#notes)

## Acronyms, Terms and Abbreviations

- `HAL`- Hardware Abstraction Layer
- `L1` - Functional Tests
- `L2` - Module functional Testing

## Description

This repository contains the Unit Test Suites (L1 & L2) for Deep Sleep Manager `HAL`.

## Reference Documents

|SNo|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[deepsleep-manager_halSpec.md](https://github.com/rdkcentral/rdk-halif-deepsleep_manager/blob/main/docs/pages/deepsleep-manager_halSpec.md)|
|2|High Level Test Specification Document|High Level Test Specification Documentation this module|[deep-sleep-manager_High-Level_TestSpec.md](https://github.com/rdkcentral/rdk-halif-test-deepsleep_manager/blob/main/docs/pages/deep-sleep-manager_High-Level_TestSpec.md)|
|3|`L2` Low Level Test Specification Document|`L2`Low Level Test Specification Documentation this module|[deep-sleep-manager_L2-Low-Level_TestSpec.md](https://github.com/rdkcentral/rdk-halif-test-deepsleep_manager/blob/main/docs/pages/deep-sleep-manager_L2-Low-Level_TestSpec.md)|
|4|`L1` Tests |`L1` Test Case File for this module |[test_l1_deepSleepMgr.c](https://github.com/rdkcentral/rdk-halif-test-deepsleep_manager/blob/main/src/test_l1_deepSleepMgr.c)|
|5|`L2` Tests |`L2` Test Case File for this module |[test_l2_deepSleepMgr.c](https://github.com/rdkcentral/rdk-halif-test-deepsleep_manager/blob/main/src/test_l2_deepSleepMgr.c)|

## Notes

- All APIs need to be implemented in this current version. If any API is not supported, please add stub implementation with return type DEEPSLEEPMGR_SUCCESS for the same.
- Building against the actual library may introduce SOC dependencies. Hence, a template SKELETON library is created without SOC dependencies. On the real platform (target), it can be mounted, copied and bound with the actual library.
- When running the binary, remember to include a profile file as an argument for designated test cases. The following example illustrates this: `./hal_test -p deepsleepmanagerExtendedEnumsNotSupported.yaml`
- Profiles file available in [profile yaml file](./profiles/deepsleepmanagerExtendedEnumsNotSupported.yaml)

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
- `L3` - Module testing with External Stimulus is required to validate and control device
- `High-Level Test Specification` : These specification will provide a broad overview of the system's functionality from the callers' perspective. It focuses on major use cases, system behavior, and overall caller experience.
- `Low-Level Test Specification` : These specification will delve deeper into the technical details. They will define specific test cases with inputs, expected outputs, and pass/fail criteria for individual functionalities, modules, or APIs.

## Description

This repository contains the Unit Test Suites (L1, L2 & L3) for Deep Sleep Manager `HAL`.

## Reference Documents

|SNo|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[deepsleep-manager_halSpec.md](https://github.com/rdkcentral/rdk-halif-deepsleep_manager/blob/main/docs/pages/deepsleep-manager_halSpec.md)|
|2|High Level Test Specification Document|High Level Test Specification Documentation this module|[deep-sleep-manager_High-Level_TestSpec.md](docs/pages/deep-sleep-manager_High-Level_TestSpec.md)|
|3|`L2` Low Level Test Specification Document|`L2`Low Level Test Specification Documentation this module|[deep-sleep-manager_L2-Low-Level_TestSpec.md](docs/pages/deep-sleep-manager_L2-Low-Level_TestSpec.md)|
|4|`L3` Low Level Test Spec|`L3` Low Level Test Specification|[deep-sleep-manager_L3-Low-Level_TestSpec.md](docs/pages/deep-sleep-manager_L3-Low-Level_TestSpec.md)|
|5|`L3` Test Procedure Document|`L3` Test Procedure Document|[deep-sleep-manager_L3_TestProcedure.md](docs/pages/deep-sleep-manager_L3_TestProcedure.md)|

## Notes

- All APIs need to be implemented in this current version. If any API is not supported, please add stub implementation with return type DEEPSLEEPMGR_SUCCESS for the same.
- Building against the actual library may introduce `SOC` dependencies. Hence, a template SKELETON library is created without `SOC` dependencies. On the real platform (target), it can be mounted, copied and bound with the actual library.
- When executing the binary, ensure to include a platform-specific profile file as an argument for the designated test cases. The following example illustrates this:

```bash
./hal_test -p deepsleepmanagerExtendedEnumsNotSupported.yaml
 ```

Alternatively, use the run.sh script with the profile file:

```bash
./run.sh -p /absolute/path/to/profile/file
 ```

- Profiles file available in [here](./profiles/deepsleepmanagerWakeUpSources.yaml)

### Setting Python environment for running the `L1` `L2` and `L3` automation test cases

- For running the `L1` `L2` and `L3` test suite, a host PC or server with a Python environment is required.
- Install Python Environment and Activation Scripts as detailed in the [HPK Documentation](https://github.com/rdkcentral/rdk-hpk-documentation/blob/main/README.md)
- To run the `L1` `L2` test cases follow the [deep-sleep-manager_L1_L2_TestProcedure.md](docs/pages/deep-sleep-manager_L1_L2_TestProcedure.md)
- To run the `L3` test cases follow the [deep-sleep-manager_L3_TestProcedure.md](docs/pages/deep-sleep-manager_L3_TestProcedure.md)

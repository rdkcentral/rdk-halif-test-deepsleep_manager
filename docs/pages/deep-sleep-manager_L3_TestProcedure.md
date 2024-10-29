# dsHost HAL L3 Python Test Procedure

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Setting Up Test Environment](#setting-up-test-environment)
- [Run Test Cases](#run-test-cases)
- [Test Setup Connections](#test-setup-connections)
- [Test Cases](#test-cases)
  - [test1_TriggerDeepsleep.py](#test1_TriggerDeepsleeppy)
## Acronyms, Terms and Abbreviations

- `HAL`    - Hardware Abstraction Layer
- `L3`     - Level 3 Testing
- `DUT`    - Device Under Test
- `RAFT`   - Rapid Automation Framework for Testing
- `YAML`   - YAML Ain't Markup Language

## Setting Up Test Environment

To execute `HAL` `L3` Python test cases, need a Python environment. Follow these steps mentioned in [HPK Public Documentation](https://github.com/rdkcentral/rdk-hpk-documentation/blob/main/README.md)

### Update Configuration Files

#### Rack Configuration File

Example Rack configuration File: [example_rack_config.yml](../../../host/tests/configs/example_rack_config.yml)

For more details refer [RAFT](https://github.com/rdkcentral/python_raft/blob/1.0.0/README.md) and [example_rack_config.yml](https://github.com/rdkcentral/python_raft/blob/1.0.0/examples/configs/example_rack_config.yml)

In this file, update the configuration to define the console sessions for the `DUT` and the outbound settings:

|Console Session|Description|
|---------------|-----------|
|default|Downloads the streams required for test cases|
|ssh_player|Plays the stream required for test case|
|ssh_player_secondary|Plays a secondary stream, if required for test case|
|ssh_hal_test|Executes the `HAL` binary for the test case|

```yaml
rackConfig:
  - dut:
      ip: "XXX.XXX.XXX.XXX"  # IP Address of the device
      description: "stb device under test"
      platform: "stb"
      consoles:
        - default:
            type: "ssh"
            port: 10022
            username: "root"
            ip: "XXX.XXX.XXX" # IP address of the device
            password: ' '
        - ssh_player:
            type: "ssh"
            port: 10022
            username: "root"
            ip: "XXX.XXX.XXX" # IP address of the device
            password: ' '
        - ssh_player_secondary:
            type: "ssh"
            port: 10022
            username: "root"
            ip: "XXX.XXX.XXX" # IP address of the device
            password: ' '
        - ssh_hal_test:
            type: "ssh"
            port: 10022
            username: "root"
            ip: "XXX.XXX.XXX" # IP address of the device
            password: ' '
      outbound:
        download_url: "tftp://tftp-server.com/rack1/slot1/"    # Download location for the CPE device
        upload_url: "sftp://server-address/home/workspace/tftp/rack1/slot1/" # Upload location
        upload_url_base_dir: "sftp://server-address/home/workspace/tftp/rack1/slot1"
        httpProxy:   # Local proxy if required
        workspaceDirectory: './logs/workspace'   # Local working directory

```

#### Device Configuration File

Example Device configuration File: [deviceConfig.yml](../../../host/tests/configs/deviceConfig.yml)

For more details refer [RAFT](https://github.com/rdkcentral/python_raft/blob/1.0.0/README.md) and [example_device_config.yml](https://github.com/rdkcentral/python_raft/blob/1.0.0/examples/configs/example_device_config.yml)

Update the target directory where `HAL` binaries will be copied into the device. Also, map the profile to the source/sink settings `YAML` file path.

Ensure the platform should match with the `DUT` platform in [Rack Configuration](#rack-configuration-file)

```yaml
deviceConfig:
  cpe1:
    platform: "stb"    # Must match the platform in example_rack_config.yml
    model: "uk"
    target_directory: "/tmp"  # Path where HAL binaries are copied in device
    test:
      profile: "../../../../profiles/deepsleepmanagerExtendedEnumsNotSupported.yaml"
      player:
        tool: "gstreamer"
        prerequisites:
          - export xxxx    # Pre-commands required to play the stream

```

#### Test Setup Configuration File

Example Test Setup configuration File the deepsleep side: [deepsleep_L3_testSetup.yml](../../..//host/tests/deepsleep_L3_Tests/deepsleep_L3_testSetup.yml)

Example Test Setup configuration File the power manager side: [power_L3_testSetup.yml](../../..//host/tests/power_L3_Tests/deepsleep_L3_testSetup.yml)

Update the artifact paths from which the binaries should be copied to the device.

Set the execution paths for each test case.

```yaml
dsHost:
  description: "deepsleep manager Device Settings test setup"
  assets:
    device:
      defaults: &defaults
        artifacts:
          - "<path>/bin/deepsleepmanager/hal_test"
          - "<path>/bin/deepsleepmanager/libut_control.so"
          - "<path>/bin/deepsleepmanagerExtendedEnumsNotSupported.yaml"
          - "<path>/bin/deepsleepmanager/run.sh"
          - "<path>/bin/powermanager/hal_test"
          - "<path>/bin/powermanager/libut_control.so"
          - "<path>/bin/powermanager/run.sh"
        execute:
          - "chmod +x /opt/HAL/deepsleep_L3/hal_test"
          - "chmod +x /opt/HAL/deepsleep_L3/run.sh"
          - cp -rf /usr/lib/libiarmmgrs-deepsleep-hal.so /opt/HAL/deepsleep_L3/
          - "ln -s /usr/lib/libiarmmgrs-deepsleep-hal.so /opt/HAL/deepsleep_L3/libiarmmgrs-deepsleep-hal.so"
          - cp -rf /usr/lib/libiarmmgrs-power-hal.so /opt/HAL/power_L3/
          - "ln -s /usr/lib/libiarmmgrs-power-hal.so /opt/HAL/power_L3/libiarmmgrs-power-hal.so"
        streams:
        test1_TriggerDeepsleep:
          <<: *defaults
          streams:
```
#### Test Suite Configuration
Example Test Setup configuration File: [deepsleep_test_suite.yml](../../../host/tests/deepsleepClasses/deepsleep_test_suite.yml)
Example Test Setup configuration File: [power_test_suite.yml](../../../host/tests/deepsleepClasses/power_test_suite.yml)
Update the execute command according to the device path where `HAL` binaries are copied.

```yaml
deepsleep:
  description: "Deepsleep manager testing profile"
  test:
    execute: "/tmp/run.sh -p /tmp/deepsleepmanagerExtendedEnumsNotSupported.yaml"
    type: UT-C  # Cunit tests (UT-C)
```

```yaml
power:
  description: "Power manager testing profile"
  test:
    execute: "/tmp/run.sh -p /tmp/deepsleepmanagerExtendedEnumsNotSupported.yaml"
    type: UT-C  # Cunit tests (UT-C)
```

## Run Test Cases

Once the environment is set up, you can execute the test cases with the following command

```bash
python <TestCaseName.py> --config </PATH>/ut/host/tests/configs/example_rack_config.yml --deviceConfig </PATH>/ut/host/tests/configs/deviceConfig.yml
```

## Test Setup Connections

Verify that the enable deepsleep sources are working on the device
For Example:

- Set the deepsleep wake up source to on via power manager api, and then trigger deepsleep, and subsequent wakeup

## Test Cases
### test1_TriggerDeepsleep.py

#### Platform Support - test01

- Sink/Source

#### User Input Required - test01

**Yes**: User interaction is necessary to trigger deepsleep and trigger wake up (This will be automated later).

#### Acceptance Criteria - test01

No tests are skipped, and all wake up sources are being triggered properly

#### Expected Results - test01

All wake up sources should wake up properly

#### Test Steps - test01

- Initiate the Test:

  - Select and execute the Python file: **`test1_TriggerDeepsleep.py`**
  - The test will automatically download all required artifacts, copying them to the designated target directory before commencing execution.

- Trigger deepsleep prompt:

    Would you like to trigger WAKE-UP SOURCE test? Note, skipping the test is considered a fail condition. (Y/N):

    Please trigger wake up via [will be mention whatever wake up source is being tested]. Did the device wakeup as expected (Y/N):

- The above will loop through all wake up sources that acclicable for the specific device based on the .yaml file.

- Once in deepsleep the device will need to be manually awoken

    - When the device enters 'voice' test, to trigger the wake up manually the user will need speak to the device to trigger the wake up. If the device successfully wakes up from deepsleep via the specified method, it passes the test.

    - When the device enters 'presence detection' test, to trigger the wake up move in front of the tv, in front the presence detection (e.g. camera) to trigger the wake up. If the device successfully wakes up from deepsleep via the specified method, it passes the test.

    - When the device enters 'Bluetooth' test, to trigger the wake up use a bluetooth remove and press the power on botton on the remote. If the device successfully wakes up from deepsleep via the specified method, it passes the test.

    - When the device enters 'wifi' test, to trigger the wake up send a signal(e.g. Wake On Lan app will work for wifi) via the mac address over wifi connection. If the device successfully wakes up from deepsleep via the specified method, it passes the test.

    - When the device enters 'IR' test, to trigger the wake up use an IR remote pressing the power on key on the remote to wake up the device. If the device successfully wakes up from deepsleep via the specified method, it passes the test.

    - When the device enters 'power key' test, to trigger the wake up press the power key button on the device itself. If the device successfully wakes up from deepsleep via the specified method, it passes the test.

    - When the device enters 'CEC' test, to trigger connect a HDMI cable to the device and send an Image_View_On CEC message from the connected device to wake up the tv. If the device successfully wakes up from deepsleep via the specified method, it passes the test.

    - When the device enters 'LAN' test, to trigger the wake up send a signal while connected over ethernet via the mac address. If the device successfully wakes up from deepsleep via the specified method, it passes the test.


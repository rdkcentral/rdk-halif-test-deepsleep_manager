# DeepSleep HAL L3 Python Test Procedure

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
|ssh_hal_deepsleep_test|Executes the `HAL` binary for the deepsleep test case|
|ssh_hal_power_test|Executes the `HAL` binary for the power test case|

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
        - ssh_hal_deepsleep_test:
            type: "ssh"
            port: 10022
            username: "root"
            ip: "XXX.XXX.XXX" # IP address of the device
            password: ' '
        - ssh_hal_power_test:
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
      profile: "../../../profiles/deepsleepmanagerExtendedEnumsNotSupported.yaml"

```

#### Test Setup Configuration File

Example Test Setup configuration File the deepsleep side: [deepsleep_L3_testSetup.yml](../../..//host/tests/deepsleep_L3_Tests/deepsleep_L3_testSetup.yml)

Example Test Setup configuration File the power manager side: [power_L3_testSetup.yml](../../..//host/tests/power_L3_Tests/deepsleep_L3_testSetup.yml)

Streams required for each test case was provided in this file. Testing Deep sleep functionality doesn't require any streams.

```yaml
deepsleep:  # Prefix must always exist
  description: "deepsleep Manager test setup"
  assets:
    device:
      test1_TestWakeupSources:
        streams:

power:  # Prefix must always exist
  description: "power Manager test setup"
  assets:
    device:
      test1_TestWakeupSources:
        streams:
```
#### Test Configuration
Example Test configuration File: [deepsleep_testConfig.yml](../../../host/tests/deepsleepClasses/deepsleep_testConfig.yml)
Example Test Setup configuration File: [power_testConfig.yml](../../../host/tests/deepsleepClasses/power_testConfig.yml)

Execute command to run the HAL binary was provided in this file.

```yaml
deepsleep:
  description: "Deepsleep manager testing profile"
  test:
    execute: "run.sh"
    type: UT-C  # Cunit tests (UT-C)
```

```yaml
power:
  description: "Power manager testing profile"
  test:
    execute: "run.sh"
    type: UT-C  # Cunit tests (UT-C)
```

## Run Test Cases

Once the environment is set up, you can execute the test cases with the following command

```bash
python <TestCaseName.py> --config </PATH>/ut/host/tests/configs/example_rack_config.yml --deviceConfig </PATH>/ut/host/tests/configs/deviceConfig.yml
```

## Test Setup Connections

Make sure the device under test `DUT` is connected to wifi, LAN and a CEC supported device for waking up from deepsleep before starting the test case.

In order to connect to Wifi on vendor layer builds, use the below commands:

**Copy the routers SSID and key details:**

wpa_passphrase <"Router SSID"> <"Passsword" > /data/wpa-supplicant.conf

**Start the wpa_supplicant daemon:**
wpa_supplicant -dd -B -i wlan0 -c /data/wpa-supplicant.conf

If still not getting IP for wlan0 bridge interface try:

```
ifconfig wlan0 down
ifconfig wlan0 up
```

## Test Cases
### test1_TriggerDeepsleep.py

#### Platform Support - test01

- Sink/Source

#### User Input Required - test01

**Yes**: User interaction is required to manually trigger wake-up events from deep sleep for specific wake-up sources. (This will be automated later).

#### Acceptance Criteria - test01

All supported wake-up sources must be validated and properly trigger the system to wake up from deep sleep

#### Expected Results - test01

All tested wake-up sources must successfully trigger the system to exit deep sleep without errors or failures. Upon waking, the recorded wake-up reason must accurately correspond to the triggered event.

#### Test Steps - test01

- Initiate the Test:

  - Select and execute the Python file: **`test1_TriggerDeepsleep.py`**
  - The test will automatically download all required artifacts, copying them to the designated target directory before commencing execution.

- Trigger deepsleep prompt:

    The test will set the wake-up source and trigger a deepsleep.

    The above will loop through all supported wake up sources that applicable for the specific device based on the .yaml file.

- Once in deepsleep the device will need to be manually awoken for some sources like IR, CEC and Power_Key.

    - When the device enters 'IR' test, to trigger the wake up use an IR remote pressing the power key on the remote to wake up the device. If the device successfully wakes up from deepsleep via the specified method, User should enter the response it passes the test.

    - When the device enters 'power key' test, to trigger the wake up press the front panel power key button of the device itself. If the device successfully wakes up from deepsleep via the specified method, User should enter the response it passes the test.

    - When the device enters 'CEC' test, to trigger connect a HDMI cable to the device and send an Image_View_On CEC message from the connected device to wake up the `DUT`. If the device successfully wakes up from deepsleep via the specified method, User should enter the response it passes the test.

- The following tests should be done automaticaly.

    - When the device enters 'LAN' test, it should automatically trigger the wake up.

    - When the device enters 'wifi' test, it should automatically trigger the wake up.

    -  When the device enters 'Timer' test, it should automatically trigger the wake up after 60 seconds.

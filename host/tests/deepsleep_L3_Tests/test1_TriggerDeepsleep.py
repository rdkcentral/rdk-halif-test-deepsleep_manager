#!/usr/bin/env python3
#** *****************************************************************************
# *
# * If not stated otherwise in this file or this component's LICENSE file the
# * following copyright and licenses apply:
# *
# * Copyright 2024 RDK Management
# *
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# *
# http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# *
#* ******************************************************************************

import os
import sys
import bluetooth
import time
import struct
import subprocess

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(dir_path+"/../")

from deepsleepClasses.deepsleep import deepsleepClass
from deepsleepClasses.power import powerManagerClass
from deepsleepClasses.power import WakeupSources
from raft.framework.plugins.ut_raft import utHelperClass
from raft.framework.plugins.ut_raft.configRead import ConfigRead
from raft.framework.plugins.ut_raft.utUserResponse import utUserResponse
from raft.framework.core.logModule import logModule

class deepsleep_test1_TriggerDeepsleep(utHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the test1_TriggerDeepsleep test .

        Args:
            None.
        """

        self.testName  = "test1_TriggerDeepsleep"
        self.testSetupPathPower = dir_path + "/power_L3_testSetup.yml"
        self.testSetupPathDeepsleep = dir_path + "/deepsleep_L3_testSetup.yml"
        self.moduleNameDeepsleep = "deepsleep"
        self.moduleNamePower = "power"
        self.rackDevice = "dut"
        self.qcID = '1'

        super().__init__(self.testName, self.qcID, log)

        # Test Setup configuration file
        self.testSetupPower = ConfigRead(self.testSetupPathPower, self.moduleNamePower)
        self.testSetupDeepsleep = ConfigRead(self.testSetupPathDeepsleep, self.moduleNameDeepsleep)

         # Create user response Class
        self.testUserResponse = utUserResponse()

        # Open Session for hal test
        self.hal_session_deepsleep = self.dut.getConsoleSession("ssh_hal_deepsleep_test")
        self.hal_session_power = self.dut.getConsoleSession("ssh_hal_power_test")

        # Get path to device profile file
        deviceTestSetup = self.cpe.get("test")
        self.moduleConfigProfileFile = os.path.join(dir_path, deviceTestSetup.get("profile"))
        self.targetWorkspaceDeepsleep = self.cpe.get("target_directory")
        self.targetWorkspaceDeepsleep = os.path.join(self.targetWorkspaceDeepsleep, self.moduleNameDeepsleep)

        self.targetWorkspacePower = self.cpe.get("target_directory")
        self.targetWorkspacePower = os.path.join(self.targetWorkspacePower, self.moduleNamePower)

    def wake_on_lan(self, macaddress, manual=False):
        """
        Sends a Wake-on-LAN magic packet to the specified MAC address.

        Args:
          macaddress: The MAC address of the target device (e.g., '00:11:22:33:44:55').
        """
        # Check MAC address format
        if manual == True:
            return self.testUserResponse.getUserYN(f"Please trigger wake up via LAN. Did the device wakeup as expected (Y/N):")
            
        else:
            #TODO: Add automation wakeup and verification methods
            return False
            if len(macaddress.split(':')) != 6:
              raise ValueError('Incorrect MAC address format')

            # Convert MAC address to bytes
            mac_bytes = bytes.fromhex(macaddress.replace(':', ''))

            # Construct the magic packet
            packet = b'\xff' * 6 + mac_bytes * 16

            # Create a UDP socket
            sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

            # Send the magic packet to the broadcast address
            sock.sendto(packet, ('<broadcast>', 9))  # Port 9 is the standard WoL port
            sock.close()

    def wake_on_wifi(self, macaddress, manual=False):
        """
        Sends a Wake-on-LAN magic packet to the specified MAC address.

        Args:
          macaddress: The MAC address of the target device (e.g., '00:11:22:33:44:55').
        """

        if manual == True:
            return self.testUserResponse.getUserYN(f"Please trigger wake up via wifi. Did the device wakeup as expected (Y/N):")
            
        else:
            #TODO: Add automation wakeup and verification methods
            return False
            # Check MAC address format
            if len(macaddress.split(':')) != 6:
              raise ValueError('Incorrect MAC address format')

            # Convert MAC address to bytes
            mac_bytes = bytes.fromhex(macaddress.replace(':', ''))

            # Construct the magic packet
            packet = b'\xff' * 6 + mac_bytes * 16

            # Create a UDP socket
            sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

            # Send the magic packet to the broadcast address
            sock.sendto(packet, ('<broadcast>', 9))  # Port 9 is the standard WoL port
            sock.close()

    def wake_tv(self, hdmi_port=1, manual=False):
        """
        Wakes the TV using cec-client.

        Args:
          hdmi_port: The HDMI port number the TV is connected to.
        """
        if manual == True:
            return self.testUserResponse.getUserYN(f"Please trigger wake up via CEC. Did the device wakeup as expected (Y/N):")

        else:
            #TODO: Add automation wakeup and verification methods
            return False
            try:
              subprocess.run(["cec-client", "-s", "-p", str(hdmi_port), "on 0"], check=True)
              print(f"TV on HDMI port {hdmi_port} woken up.")
            except subprocess.CalledProcessError as e:
              print(f"Error waking up TV: {e}")

    def wake_on_voice(self, backend_url, audio_file, manual=False):
        """
        Sends audio data from a file to the microphone backend using GStreamer.

        Args:
          backend_url: The URL of the backend server (e.g., "rtmp://your-backend-server/live/stream").
          audio_file: The path to the audio file to be sent.
        """
        if manual == True:
            return self.testUserResponse.getUserYN(f"Please trigger wake up via voice command. Did the device wakeup as expected (Y/N):")

        else:
             #TODO: Add automation wakeup and verification methods
             return False
             try:
               # Construct the GStreamer pipeline
               pipeline = (
                   "filesrc location={} ! decodebin ! audioconvert ! audioresample ! "
                   "voaacenc bitrate=128000 ! aacparse ! "
                   "flvmux ! rtmpsink location='{}'".format(audio_file, backend_url)
               )
     
               # Run the GStreamer pipeline
               subprocess.run(["gst-launch-1.0", pipeline], check=True)
     
               print("Microphone backend test successful!")
     
             except subprocess.CalledProcessError as e:
               print(f"Error running GStreamer pipeline: {e}")

    def wake_on_bluetooth(self, macaddress, manual=False):
        """
        Sends a keypress event to a Bluetooth device.

        Args:
            macaddress: The MAC address of the Bluetooth device.
        """

        if manual == True:
            return self.testUserResponse.getUserYN(f"Please trigger wake up via bluetooth. Did the device wakeup as expected (Y/N):")
           
        else:
            #TODO: Add automation wakeup and verification methods
            return False
            # Replace with your device's MAC address and port
            device_mac = "XX:XX:XX:XX:XX:XX"
            port = 1  # RFCOMM port

            # Connect to the Bluetooth device
            sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
            sock.connect((device_mac, port))

            # Send keypress events
            sock.send("\t")  # Send a Tab keypress
            time.sleep(1)
            sock.send("Hello from Raspberry Pi!\n")  # Send some text
            time.sleep(1)
            sock.send("\r")  # Send an Enter keypress

            # Close the connection
            sock.close()

    def wake_on_presence_detection(self, manual=False):
        """
        Triggers a wake-up event based on presence detection.

        Args:
            None.
        """
        if manual == True:
            return self.testUserResponse.getUserYN(f"Please trigger wake up via presence detection. Did the device wakeup as expected (Y/N):")

        else:
            #TODO: Add automation wakeup and verification methods
            return False

    def wake_on_power_key(self, manual=False):
        """
        Triggers a wake-up event based on the power key.

        Args:
            None.
        """
        if manual == True:
            return self.testUserResponse.getUserYN(f"Please trigger wake up via power key. Did the device wakeup as expected (Y/N):")

        else:
            #TODO: Add automation wakeup and verification methods
            return False

    def wake_on_IR(self, manual=False):
        """
        Triggers a wake-up event based on IR signal.

        Args:
            None.
        """
        if manual == True:
            return self.testUserResponse.getUserYN(f"Please trigger wake up via IR. Did the device wakeup as expected (Y/N):")

        else:
            #TODO: Add automation wakeup and verification methods
            return False

    def testFunction(self):
        """This function will test the get cpu tempature functionality

        Returns:
            bool
        """

        # Create the deepsleep manager class
        self.testDeepsleep = deepsleepClass(self.moduleConfigProfileFile, self.hal_session_deepsleep, self.targetWorkspaceDeepsleep)
        # Create the Power Manager Class
        self.testPower = powerManagerClass(self.moduleConfigProfileFile, self.hal_session_power, self.targetWorkspacePower)

        self.wakeup_sources_map = WakeupSources.get_wakeup_sources_map()
        

        # Initialize the deepsleep manager and power manager
        self.testPower.initialise()
        self.testDeepsleep.initialise()

        self.wakeupsources = self.testPower.getSupportedWakeupSources()

        result = True

        finalResult = True

        for source in self.wakeupsources:
            source_enum = WakeupSources(int(source))
            source_name = self.wakeup_sources_map.get(source_enum, "Unknown source")
            self.log.stepStart(f"Triggering wake up test for {source_name}")

            self.log.step(f"Setting wakeup source to {source_name}")
            self.testPower.setWakeupSource(source, 1)

            self.log.step(f"Triggering deepsleep")
            if source == 0x06:
                self.testDeepsleep.triggerDeepsleep(60, 1)
            else:
                self.testDeepsleep.triggerDeepsleep(0, 1)

            if source == 0x00:
               # Wake on Voice
               result = self.wake_on_voice("rtmp://your-backend-server/live/stream", "audio.wav", True)
               pass
            elif source == 0x01:
                 # Wake on Presence Detection
                 result = self.wake_on_presence_detection(True)
                 pass
            elif source == 0x02:
                 # Wake on Bluetooth
                 result = self.wake_on_bluetooth("XX:XX:XX:XX:XX:XX", True)
                 pass
            elif source == 0x03:
                 # Wake on Wifi
                 result = self.wake_on_wifi(True)
                 pass
            elif source == 0x04:
                 # Wake on IR
                 result = self.wake_on_IR(True)
                 pass
            elif source == 0x05:
                 # Wake on Power key
                 #Send power key
                 result = self.wake_on_power_key(True)
                 pass
            elif source == 0x06:
                    # Wake on Timer
                    result = self.testUserResponse.getUserYN(f"Did the device wakeup as expected after sixty seconds? (Y/N):")
                    pass
            elif source == 0x07:
                 # Wake on CEC
                 result = self.wake_tv(1, True)
                 pass
            elif source == 0x08:
                 # Wake on LAN
                 #wake_on_lan("XX:XX:XX:XX:XX:XX")
                 result = self.wake_on_lan("XX:XX:XX:XX:XX:XX", True)
                 pass
            
            if result:
                   self.log.stepResult(result, f"{source_name} wakeup success")
            else:
                   self.log.stepResult(result, f"{source_name} wakeup failed")
                   finalResult = False

        return finalResult
    
    def testEndFunction(self, powerOff=True):
        # Delete the deepsleep class
        del self.testDeepsleep

        del self.testPower

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = deepsleep_test1_TriggerDeepsleep(summeryLog)
    test.run(False)

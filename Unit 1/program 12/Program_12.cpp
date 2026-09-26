#include <iostream>                  // Includes the iostream library for input and output operations
#include <string>                    // Includes the string library for using string data type

using namespace std;                 // Allows the use of standard C++ objects without std::

class SmartDevice {                  // Defines a class named SmartDevice

private:                             // Declares private data members of the class

    int deviceId;                    // Stores the unique ID of the smart device
    string deviceType;               // Stores the type of the device
    string location;                 // Stores the location of the device
    string status;                   // Stores the current status of the device
    string lastUpdated;              // Stores the time when the device was last updated

public:                              // Makes the following members publicly accessible

    // Constructor
    SmartDevice(int id, string type, string loc, string stat, string time)
        : deviceId(id), deviceType(type), location(loc),
          status(stat), lastUpdated(time) {
                                      // Constructor initializes all device details
    }

    // Switch device ON
    void switchOn(string time) {     // Defines a function to switch the device ON
        status = "ON";               // Changes the device status to ON
        lastUpdated = time;          // Updates the last updated time
    }

    // Switch device OFF
    void switchOff(string time) {    // Defines a function to switch the device OFF
        status = "OFF";              // Changes the device status to OFF
        lastUpdated = time;          // Updates the last updated time
    }

    // Change device status
    void changeStatus(string newStatus, string time) {
                                      // Defines a function to change the device status
        status = newStatus;           // Assigns the new status to the device
        lastUpdated = time;           // Updates the last updated time
    }

    // Display device details
    void display() const {            // Defines a function to display device information

        cout << "Device ID: " << deviceId << endl;
                                      // Displays the device ID

        cout << "Device Type: " << deviceType << endl;
                                      // Displays the device type

        cout << "Location: " << location << endl;
                                      // Displays the device location

        cout << "Status: " << status << endl;
                                      // Displays the current device status

        cout << "Last Updated: " << lastUpdated << endl;
                                      // Displays the last updated time

        cout << "-----------------------------" << endl;
                                      // Displays a separator between devices
    }
};                                  // Ends the SmartDevice class definition

int main() {                         // Main function where program execution begins

    // Create smart devices

    SmartDevice light(101, "Light", "Living Room", "OFF", "10:00 AM");
                                      // Creates a smart light object with initial details

    SmartDevice thermostat(102, "Thermostat", "Bedroom", "ON", "10:05 AM");
                                      // Creates a thermostat object with initial details

    SmartDevice camera(103, "Camera", "Main Door", "ON", "10:10 AM");
                                      // Creates a camera object with initial details

    SmartDevice doorLock(104, "Door Lock", "Main Door", "LOCKED", "10:15 AM");
                                      // Creates a door lock object with initial details

    // Perform operations

    light.switchOn("10:20 AM");      // Switches the light ON and updates its time

    thermostat.changeStatus("24 Degree C", "10:25 AM");
                                      // Changes the thermostat status and updates its time

    camera.switchOff("10:30 AM");    // Switches the camera OFF and updates its time

    doorLock.changeStatus("UNLOCKED", "10:35 AM");
                                      // Changes the door lock status to UNLOCKED and updates its time

    // Display overall home dashboard

    cout << "========== SMART HOME DASHBOARD ==========" << endl;
                                      // Displays the smart home dashboard heading

    cout << endl;                     // Prints a blank line for better formatting

    light.display();                  // Displays the current light details

    thermostat.display();             // Displays the current thermostat details

    camera.display();                 // Displays the current camera details

    doorLock.display();               // Displays the current door lock details

    return 0;                         // Returns 0 to indicate successful program execution
}

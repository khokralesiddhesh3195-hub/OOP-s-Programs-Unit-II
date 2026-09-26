#include <iostream>                  // Includes the iostream library for input and output operations
#include <string>                    // Includes the string library for using string data type
#include <vector>                    // Includes the vector library for using dynamic arrays

using namespace std;                 // Allows the use of standard C++ objects without std::

class SoilSensor {                   // Defines a class named SoilSensor

private:                             // Declares private data members of the class

    string sensorId;                 // Stores the unique ID of the soil sensor
    double moistureLevel;            // Stores the soil moisture level as a decimal value
    string timestamp;                // Stores the time of the sensor reading

public:                              // Makes the following members publicly accessible

    SoilSensor(string id, double moisture, string time)
        : sensorId(id), moistureLevel(moisture), timestamp(time) {}
                                      // Constructor initializes sensor ID, moisture level, and timestamp

    void readSensor(double newMoisture, string newTime) {
                                      // Defines a function to update the sensor reading

        moistureLevel = newMoisture; // Updates the moisture level with the new value
        timestamp = newTime;         // Updates the timestamp with the new time
    }

    void displayData() const {       // Defines a function to display sensor data without modifying the object

        cout << "Sensor: " << sensorId
             << " | Moisture: " << moistureLevel << "%"
             << " | Time: " << timestamp << endl;
                                      // Displays the sensor ID, moisture level, and timestamp
    }
};                                  // Ends the SoilSensor class definition

int main() {                         // Main function where program execution begins

    vector<SoilSensor> farmSensors;  // Creates a vector to store multiple SoilSensor objects

    farmSensors.emplace_back("S001", 45.2, "08:00");
                                      // Creates the first sensor with ID S001, moisture 45.2%, and time 08:00

    farmSensors.emplace_back("S002", 52.8, "08:00");
                                      // Creates the second sensor with ID S002, moisture 52.8%, and time 08:00

    farmSensors.emplace_back("S003", 38.5, "08:00");
                                      // Creates the third sensor with ID S003, moisture 38.5%, and time 08:00

    cout << "=== Morning Sensor Readings ===" << endl;
                                      // Displays the heading for morning sensor readings

    for (const auto& sensor : farmSensors) {
                                      // Iterates through each SoilSensor object in the vector

        sensor.displayData();         // Calls displayData() to display the current sensor information
    }

    farmSensors[0].readSensor(47.5, "09:00");
                                      // Updates the first sensor's moisture level to 47.5% at 09:00

    cout << "\n=== Updated Reading ===" << endl;
                                      // Displays a heading for the updated sensor reading

    farmSensors[0].displayData();     // Displays the updated information of the first sensor

    return 0;                         // Returns 0 to indicate successful program execution
}

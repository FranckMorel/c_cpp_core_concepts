/*
 * Topic: Nested Structs
 *
 * Demonstrates:
 * - Structs inside structs
 * - Grouping related data
 * - Accessing nested members
 *
 * Nested structs are useful in embedded systems
 * to organize complex system data.
 *
 * Note:
 * See extra notes at the buttom for detailed explanations
 */

#include <stdio.h>

struct SensorData
{
    char sensorName[30];
    float value;
    unsigned long timestamp;
};

struct GpsData
{
    float latitude;
    float longitude;
};

struct SystemData
{
    struct SensorData sensor;
    struct GpsData gps;
    int systemState;
};

int main(void)
{
    struct SystemData system = {{"Acceleration", 2.45f, 1000}, {51.1657f, 10.4515f}, 1};

    printf("System Data\n\n");

    printf("Sensor Name: %s\n", system.sensor.sensorName);
    printf("Sensor Value: %.2f\n", system.sensor.value);
    printf("Timestamp: %lu\n", system.sensor.timestamp);

    printf("Latitude: %.4f\n", system.gps.latitude);
    printf("Longitude: %.4f\n", system.gps.longitude);

    printf("System State: %d\n", system.systemState);

    return 0;
}

/*
===============================================================================
NOTES
===============================================================================

1. Nested Struct
----------------

A nested struct means that one struct
contains another struct.

Example:

struct SystemData
{
    struct SensorData sensor;
    struct GpsData gps;
};


2. Accessing Nested Members
---------------------------

Use the dot operator multiple times:

system.sensor.value

Meaning:

system
  -> sensor
      -> value


3. Why Nested Structs?
----------------------

Nested structs help organize related data.

Instead of many separate variables:

sensorName
sensorValue
timestamp
latitude
longitude
systemState

Use structured data:

SystemData
  ├── SensorData
  ├── GpsData
  └── systemState


4. Embedded Example
-------------------

Nested structs are commonly used for:

- system status
- sensor packages
- communication frames
- configuration data
- device state information

===============================================================================
*/

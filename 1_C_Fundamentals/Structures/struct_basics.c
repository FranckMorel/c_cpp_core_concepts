/*
 * Topic: Struct Basics
 *
 * A struct is a user-defined data type that groups
 * multiple related variables into one logical unit.
 *
 * In embedded systems, structs are commonly used for:
 * - sensor data
 * - configuration data
 * - system states
 * - communication frames
 *
 * Note:
 * See extra notes at the buttom for detailed explanations
 */

#include <stdio.h>

struct SensorData
{
    int sensorId;
    float value;
    unsigned long timestamp;
};

int main()
{
    /*
     * Create first struct object.
     */
    struct SensorData sensor1;

    sensor1.sensorId = 1;
    sensor1.value = 23.45f;
    sensor1.timestamp = 1000;

    /*
     * Create second struct object.
     *
     * Each object has its own copy
     * of all struct members.
     */
    struct SensorData sensor2;

    sensor2.sensorId = 2;
    sensor2.value = 18.75f;
    sensor2.timestamp = 1020;

    printf("Sensor 1\n ID: %d | Value: %f | Timestamp: %d\n\n",
            sensor1.sensorId,
            sensor1.value,
            sensor1.timestamp);

    printf("Sensor 2\n ID: %d | Value: %f | Timestamp: %d\n",
             sensor2.sensorId,
             sensor2.value,
             sensor2.timestamp);

    return 0;
}

/*
===============================================================================
NOTES
===============================================================================

1. What is a struct?
--------------------

A struct groups multiple related variables
into one user-defined type.

Example:

struct SensorData
{
    int sensorId;
    float value;
    unsigned long timestamp;
};


2. Creating a struct object
---------------------------

SensorData sensor1;

This creates one object of type SensorData.


3. Accessing members
--------------------

Use the dot operator:

sensor1.sensorId
sensor1.value
sensor1.timestamp


4. Multiple objects
-------------------

SensorData sensor1;
SensorData sensor2;

Each object has its own independent values.

===============================================================================
*/

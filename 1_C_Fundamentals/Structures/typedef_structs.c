/*
 * Topic: typedef Structs
 *
 * Demonstrates:
 * - typedef with structs
 * - Simplified type names
 * - Common embedded C style
 *
 * Note:
 * See extra notes at the buttom for detailed explanations
 */

#include <stdio.h>

/*
 * Without typedef:
 *
 * struct SensorData sensor;
 *
 * With typedef:
 *
 * SensorData sensor;
 */
typedef struct
{
    char sensorName[30];
    float value;
    unsigned long timestamp;
} SensorData;

int main(void)
{
    SensorData sensor1 = {"Temperature", 23.5f, 1000};

    SensorData sensor2 = {"Pressure", 101.3f, 2000};

    printf("Sensor 1\n");
    printf("Name: %s\n", sensor1.sensorName);
    printf("Value: %.2f\n", sensor1.value);
    printf("Timestamp: %lu\n\n", sensor1.timestamp);

    printf("Sensor 2\n");
    printf("Name: %s\n", sensor2.sensorName);
    printf("Value: %.2f\n", sensor2.value);
    printf("Timestamp: %lu\n", sensor2.timestamp);

    return 0;
}

/*
===============================================================================
NOTES
===============================================================================

1. Without typedef
------------------

struct SensorData
{
    ...
};

struct SensorData sensor1;


2. With typedef
---------------

typedef struct
{
    ...
} SensorData;

SensorData sensor1;


3. Why typedef?
---------------

Reduces code verbosity and improves readability.


4. Embedded Usage
-----------------

Very common in embedded C projects:

typedef struct
{
    uint32_t baudrate;
    uint8_t parity;
} UART_Config;

UART_Config uart1;


5. C vs C++
-----------

C:

struct SensorData sensor1;

or

typedef struct
{
    ...
} SensorData;

SensorData sensor1;


C++:

struct SensorData
{
    ...
};

SensorData sensor1;

No typedef required.

===============================================================================
*/

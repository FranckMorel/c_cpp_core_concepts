#include "stack_template.hpp"
#include <iostream>


struct sensorData
{
    int sensorId;
    float value;
    unsigned long timestamp;
};


int main()
{
    Stack<sensorData> sensorDataStack;
    sensorData s1;

    for (int i = 0; i < 5; i++)
    {
        s1.sensorId = i * 2;
        s1.value = (i + 0.345f);
        s1.timestamp = (i + 247637);

        sensorDataStack.push(s1);
    }

    int i = 5;

    while(sensorDataStack.pop(s1))
    {
        std::cout << "Sensor " << i << " : "
                                     "Id: "     << s1.sensorId <<
                               " | value: "     << s1.value <<
                               " | timestamp: " << s1.timestamp <<
                               "\n";
        i--;
    }

}

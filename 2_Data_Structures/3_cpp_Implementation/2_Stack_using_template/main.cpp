#include "stack_template.hpp"
#include <iostream>
#include <string>

using namespace std;

/*

* Example custom data type.
*
* Demonstrates that the template stack
* can store user-defined structures in
* addition to primitive data types.
  */
struct SensorData
{
    int sensorId;
    float value;
    unsigned long timestamp;
};

/*

* Reverse a string using a stack.
*
* Algorithm:
* 1. Push all characters onto the stack.
* 2. Pop them back into the string.
* 3. Due to the LIFO principle, the string
* is reconstructed in reverse order.
  */
string ReverseString(string s)
{
    Stack<char> charStack;


    /* Push every character onto the stack */


    for (size_t i = 0; i < s.length(); i++)
    {
        charStack.push(s[i]);
    }

    /* Pop characters back into the string */
    size_t i = 0;

    while (charStack.pop(s[i]))
    {
        i++;
    }

    return s;

}

int main()
{

/*************************************************
* Example 1:
* Store and retrieve custom SensorData objects
*************************************************/

    Stack<SensorData> sensorDataStack;
    SensorData s1;

    for (int i = 0; i < 5; i++)
    {
        s1.sensorId = i * 2;
        s1.value = i + 0.345f;
        s1.timestamp = i + 247637;

        sensorDataStack.push(s1);
    }

    int sensorNumber = 5;

    while (sensorDataStack.pop(s1))
    {
        cout << "Sensor " << sensorNumber << " : "
             << "Id: " << s1.sensorId << " | Value: " << s1.value << " | Timestamp: " << s1.timestamp << "\n";

        sensorNumber--;
    }

    cout << "\n";


/*************************************************
 * Example 2:
 * Reverse a string using Stack<char>
 *************************************************/

    string input;

    cout << "Enter a String:\n";
    getline(cin, input);

    input = ReverseString(input);

    cout << "Reversed String: " << input << "\n";

    return 0;

}


/*
Notes:
Bei string s;

sizeof(s) gibt größe des String Objekts zurück
je nach Compiler kann es 24, 32 oder 64 sein

und s.length() gibt Größe des Strings also Anzahl der Elemente
*/

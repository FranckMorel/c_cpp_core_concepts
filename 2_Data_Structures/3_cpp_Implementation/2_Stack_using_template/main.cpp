#include "stack_template.hpp"
#include <cstring>
#include <iostream>


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
void ReverseString(char* c, size_t len)
{
    Stack<char> charStack;

    /* Push every character onto the stack */
    for (size_t i = 0; i < len; i++)
    {
        charStack.push(c[i]);
    }

    /* Pop characters back into the string */
    size_t i = 0;

    while (charStack.pop(c[i]))
    {
        i++;
    }

}

/*
 * Reverse a string using recursion.
 *
 * Unlike the previous implementation,
 * this algorithm does not use an explicit
 * stack data structure.
 *
 * Instead, recursion uses the implicit
 * function call stack managed by the compiler
 * and CPU.
 */

 void swap(char *left, char *right)
{
    /* Exchange the characters */
    char temp = *left;
    *left = *right;
    *right = temp;
}

/*
 * Recursive helper function.
 *
 * Algorithm:
 * 1. Swap the left and right characters.
 * 2. Move both pointers toward the center.
 * 3. Repeat until both pointers meet or cross.
 */
void ReverseRecursive(char *left, char *right)
{
    /*
     * Base Case
     *
     * Stop recursion when the middle
     * of the string has been reached.
     *
     * left == right
     *     Odd number of characters
     *
     * left > right
     *     Even number of characters
     */
    if (left >= right)
    {
        return;
    }

    swap(left, right);

    /*
    * Recursive Call
    *
    * Solve a smaller subproblem by
    * moving both pointers toward
    * the center of the string.
    */
    ReverseRecursive(left + 1, right - 1);
}

/*
 * Wrapper Function
 *
 * Calculates the string boundaries and
 * starts the recursive algorithm.
 */
void ReverseStringRecursive(char *str)
{
    size_t len = strlen(str);

    if (len == 0)
    {
        return;
    }

    char *left = &str[0];
    char *right = &str[len - 1];

    ReverseRecursive(left, right);
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

    char input[50];

    cout << "Reverse using Stack\n";
    cout << "Enter a String: ";
    cin.getline(input,50);

    ReverseString(input,strlen(input));

    cout << "Reversed String: " << input << "\n";
    cout << "\n\n";


/*************************************************
 * Example 3:
 * Reverse a string using recursion
*************************************************/

    cout << "Reverse by Recursion\n";
    cout << "Enter a String: ";
    cin.getline(input, 50);

    ReverseStringRecursive(input);

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

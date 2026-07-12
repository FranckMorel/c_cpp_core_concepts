/*
 * Topic: Stack Applications
 *
 * Practical examples demonstrating how a stack
 * can be used to solve common programming problems.
 *
 * Applications:
 *
 * 1. Store custom data types
 * 2. Reverse a string
 * 3. Reverse a string using recursion
 * 4. Check balanced parentheses
 * 5. Evaluate postfix expressions
 */

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

/***********************************************************************************************************

* Reverse a string using a stack.
*
* Algorithm:
* 1. Push all characters onto the stack.
* 2. Pop them back into the string.
* 3. Due to the LIFO principle, the string
*    is reconstructed in reverse order.
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

/*******************************************************************************************************
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

/*********************************************************************************************************
 * Check balanced parentheses using a stack.
 *
 * Opening brackets are pushed onto the stack.
 * Closing brackets must match the latest
 * opening bracket on top of the stack.
 *
 * This demonstrates a typical real-world
 * application of the LIFO principle.
 */
bool checkBalancedParenthesis(char *str) {
    Stack<char> charStack;
    size_t len = strlen(str);
    char topChar;

    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            charStack.push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(!charStack.pop(topChar))
            {
                return false;
            }
            if((str[i] == ')' && topChar != '(') ||
               (str[i] == '}' && topChar != '{') ||
               (str[i] == ']' && topChar != '['))
            {
                return false;
            }
        }
    }

    return charStack.isEmpty();
}


/*******************************************************************************************************
 * Evaluate a postfix expression using a stack.
 *
 * Algorithm:
 * 1. Push every operand onto the stack.
 * 2. When an operator is encountered:
 *      - Pop the right operand.
 *      - Pop the left operand.
 *      - Perform the operation.
 *      - Push the result back onto the stack.
 * 3. The final value remaining on the stack
 *    is the result of the expression.
 */
int EvaluatePostfix(char *exp)
{
    Stack<int> intStack;

    size_t len = strlen(exp);

    int operandLeft;
    int operandRight;
    int result;

    for (size_t i = 0; i < len; i++)
    {
        /*
         * Operand
         *
         * Convert the ASCII digit into
         * an integer before pushing it
         * onto the stack.
         */
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            intStack.push(exp[i] - '0');
        }

        /*
         * Operator
         *
         * The top element represents
         * the right operand.
         */
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            /*
             * A valid operation requires
             * two operands.
             */
            if (intStack.pop(operandRight) && intStack.pop(operandLeft))
            {
                switch(exp[i]){
                case '+':
                    result = operandLeft + operandRight;
                    break;

                case '-':
                    result = operandLeft - operandRight;
                    break;

                case '*':
                    result = operandLeft * operandRight;
                    break;

                case '/':
                    if (operandRight == 0)
                    {
                        return 0;
                    }

                    result = operandLeft / operandRight;
                    break;
                }

                /*
                 * Store the intermediate
                 * result back on the stack.
                 */
                intStack.push(result);
            }

        }
    }

    /*
     * The remaining stack element
     * contains the final result.
     */
    if (intStack.pop(result))
    {
        return result;
    }

    return 0;
}


int EvaluatePrefix(char* exp)
{
    Stack<int> intStack;

    size_t len = strlen(exp);

    int operandLeft;
    int operandRight;
    int result;

    for (int i = static_cast<int>(len - 1); i >= 0; i--)
    {
        if(exp[i] >= '0' && exp[i] <= '9')
        {
            intStack.push(exp[i] - '0');
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            if (intStack.pop(operandLeft) && intStack.pop(operandRight))
            {
                switch (exp[i])
                {
                case '+':
                    result = operandLeft + operandRight;
                    break;

                case '-':
                    result = operandLeft - operandRight;
                    break;

                case '*':
                    result = operandLeft * operandRight;
                    break;

                case '/':
                    if (operandRight == 0)
                    {
                        return 0;
                    }

                    result = operandLeft / operandRight;
                    break;
                }

                intStack.push(result);
            }
        }
    }

    if (intStack.pop(result))
    {
        return result;
    }

    return 0;
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
    cout << "\n\n";

/*************************************************
 * Example 4:
 * Check balanced parentheses using a stack
*************************************************/

    char str1[] = "{[(())]}";
    char str2[] = "{[(])}";
    char str3[] = "((()))";
    char str4[] = "(()";
    char str5[] = "";

    cout << str1 << " : " << checkBalancedParenthesis(str1) << "\n";
    cout << str2 << " : " << checkBalancedParenthesis(str2) << "\n";
    cout << str3 << " : " << checkBalancedParenthesis(str3) << "\n";
    cout << str4 << " : " << checkBalancedParenthesis(str4) << "\n";
    cout << "\"" << str5 << "\"" << " : " << checkBalancedParenthesis(str5) << "\n";
    cout << "\n\n";

/************************************************
 * Example 5:
 * Evaluate postfix expressions
***********************************************/

    char exp1[] = "23+5*"; // (2 + 3) * 5 = 25
    char exp2[] = "82-";   // 8 - 2 = 6
    char exp3[] = "84/";   // 8 / 4 = 2
    char exp4[] = "234*+"; // 2 + (3 * 4) = 14

    cout << exp1 << " = " << EvaluatePostfix(exp1) << "\n";
    cout << exp2 << " = " << EvaluatePostfix(exp2) << "\n";
    cout << exp3 << " = " << EvaluatePostfix(exp3) << "\n";
    cout << exp4 << " = " << EvaluatePostfix(exp4) << "\n";

    return 0;
}


/*
Notes:
Bei string s;

sizeof(s) gibt größe des String Objekts zurück
je nach Compiler kann es 24, 32 oder 64 sein

und s.length() gibt Größe des Strings also Anzahl der Elemente
*/

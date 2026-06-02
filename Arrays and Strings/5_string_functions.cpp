/*
 * File: string_functions.cpp
 * Topic: Basic C-Style String Functions
 *
 * This example demonstrates:
 * - strlen()
 * - strcpy()
 * - strncpy()
 * - strcmp()
 * - strcat()
 * - common safety issues with C-style strings
 *
 * Embedded relevance:
 * C-style string handling is common in embedded systems for:
 * - UART commands
 * - debug messages
 * - protocol parsing
 * - AT commands
 * - fixed-size buffers
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
     * strlen()
     *
     * Returns the number of visible characters before '\0'.
     * It does NOT include the null terminator.
     */

    char name[] = "Morel";

    printf("String: %s\n", name);
    printf("strlen(name): %zu\n", strlen(name));
    printf("sizeof(name): %zu\n\n", sizeof(name));

    /*
     * strcpy()
     *
     * Copies a string into another character array.
     *
     * Important:
     * The destination buffer must be large enough.
     */

    char destination[16];

    strcpy(destination, name);

    printf("Copied string: %s\n\n", destination);

    /*
     * strcmp()
     *
     * Compares two strings.
     *
     * Returns:
     * 0  -> strings are equal
     * <0 -> first string is smaller
     * >0 -> first string is greater
     */

    char command[] = "START";

    if (strcmp(command, "START") == 0)
    {
        printf("Command detected: START\n\n");
    }

    /*
     * strcat()
     *
     * Appends one string to another.
     *
     * Important:
     * The destination buffer must have enough free space.
     */

    char message[32] = "Status: ";
    strcat(message, "OK");

    printf("Message: %s\n\n", message);

    /*
     * strncpy()
     *
     * Copies at most N characters.
     *
     * Important:
     * strncpy() does not always append '\0' automatically
     * if the source string is too long.
     */

    char small_buffer[6];

    strncpy(small_buffer, "HELLO", sizeof(small_buffer) - 1); // strncpy(destination, source, max);
    small_buffer[sizeof(small_buffer) - 1] = '\0';

    printf("Safe copied string: %s\n", small_buffer);

    /*
     * Dangerous example:
     *
     * char buffer[4];
     * strcpy(buffer, "John");
     *
     * This would overflow the buffer because:
     * "John" needs 5 bytes including '\0'.
     */

    return 0;
}

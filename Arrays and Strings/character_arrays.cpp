/*
 * Topic: Character Arrays
 *
 * This example demonstrates:
 * - how character arrays store text
 * - why strings need a null terminator '\0'
 * - different ways to initialize character arrays
 * - common mistakes when working with C-style strings
 *
 * Embedded relevance:
 * Character arrays are commonly used in embedded systems for:
 * - UART messages
 * - command parsing
 * - debug output
 * - communication protocols
 * - fixed-size text buffers
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
     * A C-style string is a character array terminated by '\0'.
     */

    char name1[5] = {'J', 'o', 'h', 'n', '\0'};

    printf("name1: %s\n", name1);
    printf("Length of name1: %zu\n\n", strlen(name1));

    /*
     * Easier initialization.
     * The compiler automatically adds the null terminator.
     */

    char name2[] = "John";

    printf("name2: %s\n", name2);
    printf("sizeof(name2): %zu bytes\n", sizeof(name2));
    printf("strlen(name2): %zu characters\n\n", strlen(name2));

    /*
     * Important:
     *
     * strlen() counts visible characters until '\0'.
     * sizeof() returns the full array size in bytes.
     *
     * For "John":
     *
     * strlen(name2) -> 4
     * sizeof(name2) -> 5
     *
     * because '\0' is stored as an additional character.
     */

    /*
     * Wrong example:
     *
     * char wrong[5] = {'M', 'o', 'r', 'e', 'l'};
     *
     * This is not a valid C-style string because there is no space
     * for the null terminator.
     */

    /*
     * Modifying a character array is allowed.
     */

    name2[0] = 'K';

    printf("Modified name2: %s\n", name2);


    return 0;
}

/*
 * Topic: Strings and Pointers
 *
 * This example demonstrates:
 * - relationship between strings and pointers
 * - how string literals are stored
 * - pointer arithmetic on strings
 * - dereferencing string pointers
 * - differences between character arrays and string pointers
 *
 * Embedded relevance:
 * Strings and pointers are commonly used in embedded systems for:
 * - UART communication
 * - command-line interfaces
 * - protocol parsing
 * - debug messages
 * - memory-efficient text handling
 */

#include <stdio.h>

int main(void)
{
    /*
     * A string literal is stored in memory and "text"
     * points to its first character.
     */

    const char *text = "Embedded";

    printf("Full string: %s\n\n", text);

    /*
     * Dereferencing:
     */

    printf("First character: %c\n", *text);

    /*
     * Pointer arithmetic:
     */

    printf("Second character: %c\n", *(text + 1));
    printf("Third character: %c\n\n", *(text + 2));

    /*
     * Array indexing is equivalent to pointer arithmetic:
     *
     * text[i] == *(text + i)
     */

    printf("Using array indexing:\n");

    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("text[%d] = %c\n", i, text[i]);
    }

    printf("\n");

    /*
     * Pointer traversal:
     */

    const char *ptr = text;

    printf("Traversing string using pointer:\n");

    while (*ptr != '\0')
    {
        printf("%c ", *ptr);
        ptr++;
    }

    printf("\n\n");

    /*
     * Important:
     *
     * text is a pointer variable.
     * Therefore:
     *
     * sizeof(text)
     * returns the size of a pointer,
     * NOT the size of the string.
     */

    printf("sizeof(text): %zu bytes\n\n", sizeof(text));

    /*
     * Character array vs pointer:
     */

    char name[] = "John";

    /*
     * Character arrays are modifiable.
     */

    name[0] = 'K';

    printf("Modified character array: %s\n", name);

    /*
     * Important:
     *
     * The following is NOT allowed:
     *
     * text[0] = 'X';
     *
     * because string literals are read-only in C++.
     */

    return 0;
}

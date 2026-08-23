#ifndef PDT_STRING
#define PDT_STRING

#include <stdlib.h>
#include <stdint.h>

#define MAX_STRING_LENGTH 16

typedef struct {
    char* bytes;
    uint32_t length;
} String;

/**
 * Creates a String from the given char buffer of the given length.
 */
uint32_t PDT_String_create(char* src, uint32_t length, String* dst);

/**
 * Creates a String from a given null-0terminated char buffer 
 */
uint32_t PDT_String_createFromNullTerminated(char* src, String* dst);

/**
 *
 */
uint32_t PDT_String_toNullTerminated(String* src, char** dst);

/**
 *
 */
uint32_t PDT_String_strlen(String* string, uint32_t* length);

/**
 *
 */
uint32_t PDT_String_strcpy(String* src, String* dst);

#endif

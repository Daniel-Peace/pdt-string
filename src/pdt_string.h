#ifndef PDT_STRING
#define PDT_STRING

#include <stdint.h>

/**
 * The maximum length, or number of characters, a that a 
 * string can be.
 */
#define MAX_STRING_LENGTH 16

/**
 * Represents a string by containing an array of "char" as 
 * well as that array's length. It should be noted that 
 * PDT_String treats everything.
 */
typedef struct {
    char* bytes;
    uint32_t length;
} PDT_String;

/**
 * Creates a PDT_String from the given char buffer of the given 
 * length.
 */
uint32_t PDT_String_create(char* src, uint32_t length, PDT_String* dst);

/**
 * Creates a PDT_String from a given null-terminated char 
 * buffer. 
 */
uint32_t PDT_String_createFromNullTerminated(char* src, PDT_String* dst);

/**
 * Converts the given "PDT_String" to null-terminated char
 * array.
 */
uint32_t PDT_String_toNullTerminated(PDT_String* src, char** dst);

/**
 * Checks the length of the "PDT_String" pointed to by 
 * `string` and stores it in the "uint32_t" pointed to by 
 * `length`.
 */
uint32_t PDT_String_strlen(PDT_String* string, uint32_t* length);

/**
 * Copies the PDT_String pinted to by `src` into the 
 * PDT_String pointed to by `dst`. Any existing data stored 
 * in `dst` will be overwritten.
 */
uint32_t PDT_String_strcpy(PDT_String* src, PDT_String* dst);

#endif

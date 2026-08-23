#include "pdt_string.h"
#include <stdint.h>
#include <stdlib.h>

uint32_t PDT_String_create(char* bytes, uint32_t length, String* string) 
{
    if (length > MAX_STRING_LENGTH)
    {
        return 1;
    }

    if (string == NULL)
    {
        return 1;
    }

    string->bytes = bytes;

    string->length = length;

    return 0;
}

uint32_t PDT_String_createFromNullTerminated(char* bytes, String* string) 
{
    if (string == NULL)
    {
        return 1;
    }

    uint32_t length = 0;

    char* currentbyte = bytes;

    while (*currentbyte != '\0')
    {
        length++;

        currentbyte += 1;
    }

    if (length > MAX_STRING_LENGTH)
    {
        return 1;
    }

    char* copyOfBytes = malloc(sizeof(char) * length);

    for (int i = 0; i < length; i++)
    {
        copyOfBytes[i] = bytes[i];
    }

    string->bytes = copyOfBytes;

    string->length = length;

    return 0;
}


uint32_t PDT_String_toNullTerminated(String* src, char** dst)
{
    (*dst) = malloc(sizeof(char) * src->length);

    for (int i = 0; i < src->length; i++)
    {
        (*dst)[i] = src->bytes[i];
    }

    (*dst)[src->length] = '\0';

    return 0;
}


uint32_t PDT_String_strlen(String* string, uint32_t* length)
{
    (*length) = string->length;

    return 0;
}

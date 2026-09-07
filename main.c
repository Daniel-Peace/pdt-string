#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "./src/pdt_string.h"
#include "./src/pdt_string.c"

uint32_t test_createFromNullTerminated();

uint32_t test_create();

int main() 
{
    uint32_t error = 0;

    error = test_createFromNullTerminated();

    error = test_create();

    PDT_String string3;

    char* myString3 = "My String";

    error = PDT_String_createFromNullTerminated(myString3, &string3);

    if (error != 0)
    {
        printf("[-] ERROR - Failed test 3");

        exit(1);
    }

    char* result;

    error = PDT_String_toNullTerminated(&string3, &result);

    printf("String: %s", result);
}

uint32_t test_createFromNullTerminated()
{
    printf("[-] ---\n");

    printf("[-] Testing \"createFromNullTerminated\"\n");

    char* srcChars = "Hello";

    PDT_String dstString;

    uint32_t error = PDT_String_createFromNullTerminated(srcChars, &dstString);

    if (error != 0)
    {
        return -1;
    }

    printf("[-] Length: %d\n", dstString.length);

    printf("[-] Bytes: %s\n", dstString.bytes);

    return 0;
}

uint32_t test_create()
{
    printf("[-] ---\n");

    printf("[-] Testing \"create\"\n");

    char* srcChars = "Hello";

    char* srcCharsNoNull = malloc(sizeof(char) * 5);

    for (int i = 0; i < 5; i++)
    {
        srcCharsNoNull[i] = srcChars[i];
    }

    PDT_String string2;

    uint32_t error = PDT_String_create(srcCharsNoNull, 5, &string2);

    if (error != 0)
    {
        return -1;
    }

    printf("[-] Length: %d\n", string2.length);

    printf("[-] Bytes: %s\n", string2.bytes);

    return 0;
}

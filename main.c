#include <stdio.h>
#include <stdlib.h>
#include "./src/pdt_string.h"
#include "./src/pdt_string.c"

int main() 
{
    char* myString1 = "Hello";

    String string1;

    uint32_t error = PDT_String_createFromNullTerminated(myString1, &string1);

    if (error != 0)
    {
        printf("[-] ERROR - Something went wrong while creating a string...");

        exit(1);
    }

    printf("String 1 Length: %d\n", string1.length);

    printf("String 1 bytes: %s\n", string1.bytes);

    char* myString2 = malloc(sizeof(char) * 5);

    for (int i = 0; i < 5; i++)
    {
        myString2[i] = myString1[i];
    }

    String string2;

    PDT_String_create(myString2, 5, &string2);

    printf("String 2 Length: %d\n", string2.length);

    printf("String 2 bytes: %s\n", string2.bytes);

    String string3;

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

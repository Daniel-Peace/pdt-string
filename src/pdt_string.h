/**
 * =========================================================
 * Copyright (c) 2026 Daniel Peace
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 * =========================================================
 */

#ifndef PDT_STRING_DEFINITION
#define PDT_STRING_DEFINITION

#include <stdint.h>

/**
 * The maximum length, or number of characters, a that a
 * string can be.
 */
#define MAX_STRING_LENGTH 255

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

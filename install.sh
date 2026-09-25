#!/bin/bash

echo "[-] Building library..."
clang -c ./src/pdt_string.c -o pdt_string.o
if [ $? -eq 0 ]; then
    echo "[-] Successfulling built library..."
else
    echo "[-] Failed to build library..."
    echo "[-] Exiting..."
    exit 1
fi

echo "[-] Copying header file to .local/include/pdt/"
cp ./src/pdt_string.h $HOME/.local/include/pdt/
if [ $? -eq 0 ]; then
    echo "[-] Successfully copied header file..."
else
    echo "[-] Failed to copy header file..."
    echo "[-] Exiting..."
    exit 1
fi

echo "[-] Moving object file to .local/lib"
mv pdt_string.o $HOME/.local/lib/
if [ $? -eq 0 ]; then
    echo "[-] Successfully moved pdt_error.o file to .local/lib/"
else
    echo "[-] Failed to move file..."
    echo "[-] exiting..."
    exit 1
fi

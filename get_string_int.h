#ifndef GET_H
#define GET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>  // INT_MIN, INT_MAX

int getSafeInt(int currentValue);

void getInputString( char* currentValue, size_t maxLength);

#endif
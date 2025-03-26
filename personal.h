/**
 * @file personal.h
 * @brief Header file for managing personal information.
 * @details Includes definitions, constants, and headers required for managing a personal info system such as adding, deleting, and modifying personal data.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */

#ifndef PERSONAL_H
#define PERSONAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGH 10
#define MAX_PHONE_LENGTH 20
#define FILE_NAME "data.bin"

#define FILE_NAME "data.bin"
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_CYAN    "\033[36m"

#include "node.h"
#include "personal_load.h"
#include "personal_add.h"
#include "personal_print.h"
#include "personal_delete.h"
#include "personal_modify.h"
#include "get_string_int.h"




#endif

#ifndef GET_STRING_INPUT_H
#define GET_STRING_INPUT_H

#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h> // size_t

/**
 * @brief Prompt user for an integer input (required).
 * @return Validated integer input.
 */
int inputIntRequired(void);

/**
 * @brief Prompt user for text input (no number allowed, empty input retains previous value).
 * @param currentValue Pointer to the buffer to store input.
 * @param maxLength Maximum length of input.
 */
void inputTextOrKeep(char *currentValue, size_t maxLength);

/**
 * @brief Prompt user for text input (no number allowed, required input).
 * @param currentValue Pointer to the buffer to store input.
 * @param maxLength Maximum length of input.
 */
void inputTextRequired(char *currentValue, size_t maxLength);

/**
 * @brief Prompt for phone number input (digits only, required).
 * @param output Buffer to store the validated phone number.
 * @param maxLength Maximum allowed length of the input.
 */
void inputPhoneDigitsOnly(char* output, size_t maxLength);

/**
 * @brief Prompt user for phone number (digits only, enter retains previous value).
 * @param currentValue Pointer to the buffer to store input.
 * @param maxLength Maximum length of input.
 */
void inputPhoneDigitsOnlyOrKeep(char *currentValue, size_t maxLength);


/**
 * @brief Prompt user for integer input. Enter retains previous value.
 * @param currentValue Integer to return if user enters nothing.
 * @return New or retained integer.
 */
int inputIntOrKeep(int currentValue);

/**
 * @brief Prompt user until 'yes' or 'no' is entered.
 * @param answer Buffer to store 'yes' or 'no'.
 * @param maxLength Maximum length of input.
 */
void inputYesOrNo(char *answer, size_t maxLength);

#endif // GET_STRING_INPUT_H

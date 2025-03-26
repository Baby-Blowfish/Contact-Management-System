
#include "personal_modify.h"

// 정수 입력: 반드시 입력해야 함
int inputIntRequired()
{
    char buffer[16] = {0};
    char *endptr = NULL;
    long result = 0;

    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf(COLOR_RED "\n[Error] Input failed. Try again.\n\n" COLOR_RESET);
            continue;
        }

        if (buffer[0] == '\n')
        {
            printf(COLOR_RED "\n[Error] Input required. Please enter a number.\n\n" COLOR_RESET);
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        errno = 0;
        result = strtol(buffer, &endptr, 10);

        if (errno == ERANGE || result < INT_MIN || result > INT_MAX)
        {
            printf(COLOR_RED "\n[Error] Number out of range.\n\n" COLOR_RESET);
            continue;
        }

        if (endptr == buffer || *endptr != '\0')
        {
            printf(COLOR_RED "\n[Error] Invalid number.\n\n" COLOR_RESET);
            continue;
        }

        return (int)result;
    }
}

// 전화번호 입력: 숫자만 허용 (필수 입력)
void inputPhoneDigitsOnly(char *output, size_t maxLength)
{
    char buffer[256] = {0};

    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf(COLOR_RED "\n[Error] Failed to read input.\n\n" COLOR_RESET);
            continue;
        }

        if (buffer[0] == '\n')
        {
            printf(COLOR_RED "\n[Error] Input required. Please enter digits.\n\n" COLOR_RESET);
            continue;
        }

        int isNumber = 1;
        for (size_t i = 0; buffer[i] != '\0' && buffer[i] != '\n'; ++i)
        {
            if (!isdigit((unsigned char)buffer[i]))
            {
                isNumber = 0;
                break;
            }
        }

        if (!isNumber)
        {
            printf(COLOR_RED "\n[Error] Phone number must contain digits only.\n\n" COLOR_RESET);
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(output, buffer, maxLength - 1);
        output[maxLength - 1] = '\0';
        return;
    }
}

// 전화번호 입력: 엔터 시 기존 값 유지, 숫자만 허용
void inputPhoneDigitsOnlyOrKeep(char *currentValue, size_t maxLength)
{
    char buffer[256] = {0};

    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf(COLOR_RED "\n[Error] Failed to read input.\n\n" COLOR_RESET);
            return;
        }

        if (buffer[0] == '\n')
        {
            return; // 기존 값 유지
        }

        int isNumber = 1;
        for (size_t i = 0; buffer[i] != '\0' && buffer[i] != '\n'; ++i)
        {
            if (!isdigit((unsigned char)buffer[i]))
            {
                isNumber = 0;
                break;
            }
        }

        if (!isNumber)
        {
            printf(COLOR_RED "\n[Error] Phone number must contain digits only.\n\n" COLOR_RESET);
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(currentValue, buffer, maxLength - 1);
        currentValue[maxLength - 1] = '\0';
        return;
    }
}

// 문자열 입력: 엔터 시 기존 값 유지, 숫자만 입력 불가
void inputTextOrKeep(char *currentValue, size_t maxLength)
{
    char buffer[256] = {0};

    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf(COLOR_RED "\n[Error] Failed to read input.\n\n" COLOR_RESET);
            return;
        }

        if (buffer[0] == '\n')
        {
            return; // 기존 값 유지
        }

        int isNumber = 1;
        for (size_t i = 0; buffer[i] != '\0' && buffer[i] != '\n'; ++i)
        {
            if (!isdigit((unsigned char)buffer[i]))
            {
                isNumber = 0;
                break;
            }
        }

        if (isNumber)
        {
            printf(COLOR_RED "\n[Error] Input must not be a number. Please enter valid text.\n\n" COLOR_RESET);
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(currentValue, buffer, maxLength - 1);
        currentValue[maxLength - 1] = '\0';
        return;
    }
}

// 문자열 입력: 반드시 입력해야 함, 숫자만 입력 불가
void inputTextRequired(char *currentValue, size_t maxLength)
{
    char buffer[256] = {0};

    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf(COLOR_RED "\n[Error] Failed to read input.\n\n" COLOR_RESET);
            continue;
        }

        int onlyWhitespace = 1;
        for (size_t i = 0; buffer[i] != '\0'; ++i)
        {
            if (!isspace((unsigned char)buffer[i]))
            {
                onlyWhitespace = 0;
                break;
            }
        }

        if (onlyWhitespace)
        {
            printf(COLOR_RED "\n[Error] Input required. Please try again.\n\n" COLOR_RESET);
            continue;
        }

        int isNumber = 1;
        for (size_t i = 0; buffer[i] != '\0' && buffer[i] != '\n'; ++i)
        {
            if (!isdigit((unsigned char)buffer[i]))
            {
                isNumber = 0;
                break;
            }
        }

        if (isNumber)
        {
            printf(COLOR_RED "\n[Error] Input must not be a number. Please enter valid text.\n\n" COLOR_RESET);
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(currentValue, buffer, maxLength - 1);
        currentValue[maxLength - 1] = '\0';
        return;
    }
}

// 정수 입력: 엔터 입력 시 기존 값 유지
int inputIntOrKeep(int currentValue)
{
    char buffer[16] = {0};
    char *endptr = NULL;
    long result = 0;

    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf(COLOR_RED "\n[Error] Input failed. Try again.\n\n" COLOR_RESET);
            continue;
        }

        if (buffer[0] == '\n')
        {
            return currentValue; // 현재 값 유지
        }

        buffer[strcspn(buffer, "\n")] = '\0';
        errno = 0;
        result = strtol(buffer, &endptr, 10);

        if (errno == ERANGE || result < INT_MIN || result > INT_MAX)
        {
            printf(COLOR_RED "\n[Error] Number out of range.\n\n" COLOR_RESET);
            continue;
        }

        if (endptr == buffer || *endptr != '\0')
        {
            printf(COLOR_RED "\n[Error] Invalid number.\n\n" COLOR_RESET);
            continue;
        }

        return (int)result;
    }
}

// yes 또는 no만 입력 허용
void inputYesOrNo(char *answer, size_t maxLength)
{
    while (1)
    {
        inputTextRequired(answer, maxLength);

        if (strcmp(answer, "yes") == 0 || strcmp(answer, "no") == 0)
        {
            return;
        }
        else
        {
            printf(COLOR_RED "\n[Error] Please enter 'yes' or 'no'.\n\n" COLOR_RESET);
        }
    }
}

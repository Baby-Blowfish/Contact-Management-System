#include "get_string_int.h"

// 정수 입력 받기
int getSafeInt(int currentValue) {
    char buffer[6] = {0};
    char* endptr = NULL;
    long result = 0.0;

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("[Error] Input failed. Please try again.\n");
            continue;
        }

        // 엔터 입력 시 현재 값 유지
        if (buffer[0] == '\n') {
            return currentValue;
        }

        // 공백 및 개행 문자 제거
        buffer[strcspn(buffer, "\n")] = '\0';

        // 문자열을 정수로 변환
        errno = 0;
        result = strtol(buffer, &endptr, 10);

        // 변환 오류 처리
        if (errno == ERANGE || result < INT_MIN || result > INT_MAX) {
            printf("[Error] Number out of range. Please enter a valid integer.\n");
            continue;
        }

        // 숫자가 아닌 문자가 포함된 경우 처리
        if (endptr == buffer || *endptr != '\0') {
            printf("[Error] Invalid input. Please enter a valid integer.\n");
            continue;
        }

        return (int)result;
    }
}

void getInputString( char* currentValue, size_t maxLength) {
    char buffer[maxLength];
    
    fgets(buffer, sizeof(maxLength), stdin);
    if (buffer[0] == '\n') return;  // 엔터 입력 시 기존 값 유지

    strtok(buffer, "\n");
    strncpy(currentValue, buffer, maxLength - 1);
}
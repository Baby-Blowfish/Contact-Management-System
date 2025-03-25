#include "personal_modify.h"
#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>  // INT_MIN, INT_MAX

// 정수 입력 받기
int getSafeInt(int currentValue) {
    char buffer[100];
    char* endptr;
    long result;

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


int Modify(Node* head, const char* keyword) {
    Node* cur = head;

    while (cur) {
        if (strcmp(cur->data.szName, keyword) == 0 ||
            strcmp(cur->data.szPhone, keyword) == 0 ||
            atoi(keyword) == cur->data.nAge) {

            printf("\n\033[1;34m[Found] Name: %s, Age: %d, Phone: %s\033[0m\n",
                   cur->data.szName, cur->data.nAge, cur->data.szPhone);

            printf("Enter New Name (leave empty to keep current): ");
            getInputString(cur->data.szName, MAX_NAME_LENGH);
            
            printf("Enter New Age (enter 0 to keep current): ");
            cur->data.nAge = getSafeInt(cur->data.nAge);

            printf("Enter New Phone (leave empty to keep current): ");
            getInputString(cur->data.szPhone, MAX_PHONE_LENGTH);


            printf("\n\033[1;35mModified successfully.\033[0m\n\n");
            return 1;
        }
        cur = cur->next;
    }

    return 0;
}

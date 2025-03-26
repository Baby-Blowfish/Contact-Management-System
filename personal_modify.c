#include "personal_modify.h"

// Modify(): 다중 검색 및 수정 기능
int Modify(Node *head)
{
    int mode = 0;
    char keyword[MAX_PHONE_LENGTH] = {0};
    int modified = 0;
    Node *cur = NULL;
    int match = 0;
    char confirm[MAX_NAME_LENGH] = {0};

    // 검색 기준 입력
    printf("\nChoose search field: 1) Name  2) Age  3) Phone\n> ");
    mode = inputIntRequired();

    // 키워드 입력
    printf("Enter keyword: ");
    inputTextRequired(keyword, MAX_PHONE_LENGTH);

    cur = head;
    while (cur)
    {
        match = 0;
        if (mode == 1 && strcmp(cur->data.szName, keyword) == 0)
            match = 1; // 이름 비교
        if (mode == 2 && atoi(keyword) == cur->data.nAge)
            match = 1; // 나이 비교
        if (mode == 3 && strcmp(cur->data.szPhone, keyword) == 0)
            match = 1; // 전화번호 비교

        if (match)
        {
            // 일치 항목 출력
            printf(COLOR_CYAN "\n[Match] Name: %s, Age: %d, Phone: %s\n\n" COLOR_RESET,
                   cur->data.szName, cur->data.nAge, cur->data.szPhone);

            // 사용자에게 수정 여부 확인
            printf("Modify this entry? (yes/no): ");
            inputYesOrNo(confirm, MAX_NAME_LENGH);

            if (strcmp(confirm, "yes") == 0)
            {
                // 이름 수정
                printf("Enter New Name (leave empty to keep current): ");
                inputTextOrKeep(cur->data.szName, MAX_NAME_LENGH);

                // 나이 수정
                printf("Enter New Age (enter 0 to keep current): ");
                cur->data.nAge = inputIntOrKeep(cur->data.nAge);

                // 전화번호 수정
                printf("Enter New Phone (leave empty to keep current): ");
                inputPhoneDigitsOnlyOrKeep(cur->data.szPhone, MAX_PHONE_LENGTH);

                printf(COLOR_CYAN "\n[Success] Entry modified.\n\n" COLOR_RESET);
                modified++;
            }
            else if (strcmp(confirm, "no") == 0)
            {
                cur = cur->next; // 다음 노드로 이동
                continue;
            }
        }

        cur = cur->next; // 다음 노드로 이동
    }

    return modified;
}

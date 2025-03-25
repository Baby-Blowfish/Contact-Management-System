#include "personal_delete.h"

// Delete(): 특정 이름의 데이터 삭제
int Delete(Node** head, Node** tail, const char* keyword) {
    Node* cur = *head;
    Node* prev = NULL;

    while (cur) {
        if (strcmp(cur->data.szName, keyword) == 0 ||
            strcmp(cur->data.szPhone, keyword) == 0 ||
            atoi(keyword) == cur->data.nAge) {
                
            printf("\n\033[1;34m[Found] Name: %s, Age: %d, Phone: %s\033[0m\n",
                   cur->data.szName, cur->data.nAge, cur->data.szPhone);

            // 첫번째 노드(head)가 삭제 대상인 경우우
            if(prev == NULL)
            {
                *head = cur->next;
            }else{
                prev->next = cur->next;
            }

            // 마지막 노드 삭제 시 tail 포인터 갱신
            if (cur == *tail) {
                *tail = prev;
            }

            free(cur);
            cur = NULL;  // dangling pointer 방지
            printf("\033[1;35mdeleted successfully.\033[0m\n\n");
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

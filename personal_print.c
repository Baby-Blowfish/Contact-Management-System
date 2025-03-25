#include <stdio.h>
#include "personal_print.h"
#include "personal.h"

// PrintInfo(): 모든 데이터 출력
void PrintInfo(Node* head) {
    if (!head) {
        printf("No data available.\n");
        return;
    }

    Node* cur = head;
    while (cur) {
        printf("Name: %s, Age: %d, Phone: %s\n",
               cur->data.szName, cur->data.nAge, cur->data.szPhone);
        cur = cur->next;
    }
}
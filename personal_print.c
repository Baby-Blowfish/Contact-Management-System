#include "personal_print.h"

// PrintInfo(): 모든 데이터 출력
void PrintInfo(Node *head)
{
    if (!head)
    {
        printf(COLOR_YELLOW "\nNo data available.\n\n" COLOR_RESET);
        return;
    }

    Node *cur = head;

    printf("\n................................... \n");
    while (cur)
    {
        printf("Name: %s, Age: %d, Phone: %s\n",
               cur->data.szName, cur->data.nAge, cur->data.szPhone);
        cur = cur->next;
    }
    printf("................................... \n\n");
}
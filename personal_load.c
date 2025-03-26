#include "personal_load.h"

// Load(): 데이터 불러오기
Node *Load(Node **tail, const char *filename)
{

    FILE *file = NULL;
    Node *head = NULL;
    PERSON_INFO temp = {0, "", ""};
    Node *newnode = NULL;

    file = fopen(filename, "rb");
    if (!file)
    {
        printf(COLOR_YELLOW "\n[Warning] No previous data found. Starting with an empty contact list.\n\n"COLOR_RESET);
        *tail = NULL;
        return NULL;
    }

    *tail = NULL;

    while (fread(&temp, sizeof(PERSON_INFO), 1, file))
    {
        newnode = (Node *)malloc(sizeof(Node));
        if (!newnode)
        {
            perror(COLOR_RED "\n[Error] Memory allocation failed\n\n"COLOR_RESET);
            fclose(file);
            return head;
        }

        newnode->data = temp;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            (*tail)->next = newnode;
        }

        *tail = newnode;
    }

    fclose(file);

    // 데이터가 없는 경우 tail을 명시적으로 NULL로 설정
    if (!head)
    {
        *tail = NULL;
    }

    printf(COLOR_CYAN "\nData loaded successfully.\n\n" COLOR_RESET);
    return head;
}

#include "personal.h"

void Close(Node *head, Node *tail);

/**
 * @brief Main function for the Contact Management Program.
 * @param None
 * @return int Exit status (0 for successful termination)
 * @details Provides a menu to add, delete, modify, print, and save contacts using a linked list.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */
int main(void)
{

    int choice = 0, age = 0;
    char name[MAX_NAME_LENGH] = {0};
    char phone[MAX_PHONE_LENGTH] = {0};
    char keyword[MAX_PHONE_LENGTH] = {0};

    Node *head = NULL;
    Node *tail = NULL;

    head = Load(&tail, FILE_NAME);

    while (1)
    {
        printf("===============================\n");
        printf("      Contact Management       \n");
        printf("===============================\n");
        printf("1. Add New Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Modify Contact\n");
        printf("4. Print All Contacts\n");
        printf("5. Save and Exit\n");
        printf("===============================\n");

        printf("Select Option  :  ");

        choice = inputIntRequired();

        // 데이터가 없을 경우 삭제 수정 프린트 x
        if ((choice == 2 || choice == 3 || choice == 4) && head == NULL)
        {
            printf("\n\033[1;31m[Error] No data available.\033[0m\n\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter Name: ");
            inputTextRequired(name, MAX_NAME_LENGH);

            printf("Enter Age:");
            age = inputIntRequired();

            printf("Enter Phone: ");
            inputPhoneDigitsOnly(phone, MAX_NAME_LENGH);

            head = Add(head, &tail, age, name, phone);
            break;
        case 2:
            if (Delete(&head, &tail) == 0)
            printf(COLOR_GREEN "\n[Not Found] %s is not in the contact list.\n\n" COLOR_RESET, keyword);
            break;
        case 3:
            if (Modify(head) == 0)
                printf(COLOR_GREEN "\n[Not Found] %s is not in the contact list.\n\n" COLOR_RESET, keyword);
            break;
        case 4:
            PrintInfo(head);
            break;
        case 5:
            Close(head, tail);
            return 0;
        default:
            printf("Invalid choice. Plesa try again.\n");
        }
    }

    return 0;
}

/**
 * @brief Saves contact data and releases memory.
 * @param head Pointer to the head of the linked list.
 * @param tail Pointer to the tail of the linked list.
 * @return None
 * @details Saves all contacts to a binary file and frees the allocated memory for each node.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */

// Close(): 데이터 저장 및 메모리 해제
void Close(Node *head, Node *tail)
{
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file)
    {
        perror(COLOR_RED "\n\nFile open error\n" COLOR_RESET);
        return;
    }

    Node *cur = head;
    while (cur)
    {
        if (fwrite(&(cur->data), sizeof(PERSON_INFO), 1, file) != 1)
        {
            perror(COLOR_RED "\n\n [Error] Data save failed\n" COLOR_RESET);
            fclose(file);
            return;
        }
        Node *temp = cur;
        cur = cur->next;
        free(temp);

        // Tail 활용: 마지막 노드라면 종료
        if (temp == tail)
        {
            break;
        }
    }

    fclose(file);
    printf("\n\033[1;36mData saved successfully.\033[0m\n\n");
}
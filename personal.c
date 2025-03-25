#include "personal.h"
#include "personal_load.h"
#include "personal_add.h"
#include "personal_print.h"
#include "personal_delete.h"
#include "personal_modify.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "data.bin"

void Close(Node* head, Node* tail);

int main(void)
{

    int choice, age;
    char name[MAX_NAME_LENGH];
    char phone[MAX_PHONE_LENGTH];
    char keyword[MAX_PHONE_LENGTH];
    
    Node* head = NULL;
    Node* tail = NULL;

    head = Load(&tail, FILE_NAME);

    
    while(1)
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

        scanf("%d", &choice);
        getchar();

        // 데이터가 없을 경우 삭제 수정 프린트 x
        if ((choice == 2 || choice == 3 || choice == 4) && head == NULL) {
            printf("\n\033[1;31m[Error] No data available.\033[0m\n\n");
            continue;
        }

        switch(choice)
        {
            case 1:
                printf("Enter Name: ");
                fgets(name, MAX_NAME_LENGH, stdin);
                strtok(name,"\n");

                printf("Enter Age:");
                scanf("%d",&age);
                getchar();

                printf("Enter Phone: ");
                fgets(phone, MAX_PHONE_LENGTH, stdin);
                strtok(phone,"\n");

                head = Add(head, &tail, age, name, phone);
                break;
            case 2:
                printf("Enter Name, Age, or Phone to Delete: ");
                fgets(keyword, MAX_NAME_LENGH, stdin);
                strtok(keyword, "\n");
                if( Delete(&head, &tail, keyword) == 0) printf("\n\033[1;31m[Not Found] %s is not in the contact list.\033[0m\n\n", keyword);
                break;
            case 3:
                printf("Enter Name, Age, or Phone to Modify: ");
                fgets(keyword, MAX_NAME_LENGH, stdin);
                strtok(keyword, "\n");
                if( Modify(head, keyword) == 0 ) printf("\n\033[1;31m[Not Found] %s is not in the contact list.\033[0m\n\n", keyword);

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


// Close(): 데이터 저장 및 메모리 해제
void Close(Node* head, Node* tail) {
    FILE* file = fopen(FILE_NAME, "wb");
    if (!file) {
        perror("File open error");
        return;
    }

    Node* cur = head;
    while (cur) {
        if (fwrite(&(cur->data), sizeof(PERSON_INFO), 1, file) != 1) {
            perror("[Error] Data save failed");
            fclose(file);
            return;
        }
        Node* temp = cur;
        cur = cur->next;
        free(temp);

        // Tail 활용: 마지막 노드라면 종료
        if (temp == tail) {
            break;
        }
    }

    fclose(file);
    printf("\n\033[1;35mData saved successfully.\033[0m\n\n");
}
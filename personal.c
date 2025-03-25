#include "personal.h"
#include "personal_load.h"
#include "personal_add.h"
#include "personal_print.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "data.bin"

int main(void)
{

    int choice, age;
    char name[MAX_NAME_LENGH];
    char phone[MAX_PHONE_LENGTH];
    
    Node* head = NULL;
    Node* tail = NULL;
    
    head = Load(&tail);

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

        printf("Select Option");

        scanf("%d", &choice);
        getchar();

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
                break;
            case 3:
                break;
            case 4:
                PrintInfo(head);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Plesa try again.\n");
        }
    }

    return 0;
}

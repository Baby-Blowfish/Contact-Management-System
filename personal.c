#include "personal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{

    int choice;

    PPERSON_INFO head = NULL;
    PPERSON_INFO tail = NULL;

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
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Plesa try again.\n");
        }
    }

    return 0;
}

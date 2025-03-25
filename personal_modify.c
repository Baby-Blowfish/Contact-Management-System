#include "personal_modify.h"


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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    StrList *list = StrList_alloc();
    int size = 0,index = 0, ascii_code = 0;
    char choice[3] = {'1','0','0'};
    char temp[10000]; // Assuming maximum 10000 chars in a word
    // Display menu
    printf("\nMenu:\n");
    printf("1. Add strings to list\n");
    printf("2. Insert string at index\n");
    printf("3. Print list\n");
    printf("4. Print list length\n");
    printf("5. Print string at index\n");
    printf("6. Print number of characters appearing in the list\n");
    printf("7. Print number of occurrences of a string\n");
    printf("8. Remove all occurrences of a string\n");
    printf("9. Remove string at index\n");
    printf("10. Reverse list\n");
    printf("11. Clear list\n");
    printf("12. Sort list\n");
    printf("13. Check if list is sorted\n");
    printf("0. Exit\n");
    
    while(choice[0] != '0'){
        printf("Enter your choice: ");
        scanf(" %2s", choice);
        // Check if the length of the choice is valid
        if (choice[1] == '\0') {
            // Calculate the ASCII code based on the first character of the choice
            ascii_code = (int)choice[0];
        }
        else if (strlen(choice) == 2) {
            // Calculate the ASCII code if two characters were entered
            ascii_code = (int)choice[1] + 10;
        }else{
            // Invalid choice length
            printf("Invalid choice 1. Please try again.\n");
            break;
        }
        // Check if the ASCII code is within the valid range
        if (ascii_code < 48 && ascii_code > 61) {
            printf("Invalid choice from Menu. Please try again.\n");
            break;
        }
        // Perform action based on user choice
        switch(ascii_code) {
            case 49:
                scanf(" %d",&size);
                getchar();
                fgets(temp, sizeof(temp), stdin);
                char *token = strtok(temp, " \n");
                while (token != NULL && size > 0) {
                    // Insert each word into the list
                    StrList_insertLast(list,token);
                    token = strtok(NULL, " \n");
                    size--;
                }
                break;
            case 50:
                // Insert string at index
                scanf(" %d", &index);
                getchar();
                scanf("%[^\n]", temp);
                StrList_insertAt(list,temp,index);
                break;
            case 51:
                // Print List
                StrList_print(list);
                break;
            case 52:
                // Print size of List
                size = StrList_size(list);
                printf("The size of List is %d\n",size);
                break;
            case 53:
                // Print string at index
                scanf(" %d", &index);
                StrList_printAt(list,index);
                break;
            case 54:
                // Print occurrences of chars
                size = StrList_printLen(list);
                printf("The size of char in the List is %d\n",size);
                break;
            case 55:
                // Print occurrences of string
                scanf(" %[^\n]", temp);
                size = StrList_count(list,temp);
                printf("The size of the occurrences of string is %d\n",size);
                break;
            case 56:
                // Remove occurrences of string
                scanf(" %[^\n]", temp);
                StrList_remove(list,temp);
                break;
            case 57:
                // Remove string at index
                scanf(" %d", &index);
                StrList_removeAt(list,index);
                break;
            case 58:
                // Reverse list
                StrList_reverse(list);
                break;
            case 59:
                // Clear list
                StrList_free(list);
                break;
            case 60:
                // Sort list
                StrList_sort(list);
                break;
            case 61:
                // Check if list is sorted
                int b = StrList_isSorted(list);
                if(b) printf("The List is sorted\n");
                else printf("The List is not sorted\n");
                break;
            case 48:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice Menu. Please try again.\n");
        }
    }
    return 0;
}

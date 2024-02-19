#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"
#include <string.h>

int main() {
    StrList* list = StrList_alloc(); // Allocate a new StrList
    int size = 0, index = 0;
    char choice;
    char temp[1000]; // Assuming maximum 1000 characters for string input

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

    printf("Enter your choice: ");

    while (scanf(" %c", &choice) == 1 && choice != '0') {
        // Perform action based on user choice
        switch (choice) {
            case '1':
                printf("Enter number of strings to add: ");
                scanf("%d", &size);
                for (int i = 0; i < size; i++) {
                    printf("Enter string %d: ", i + 1);
                    scanf("%s", temp);
                    StrList_insertLast(list, temp);
                }
                break;
            case '2':
                // Insert string at index
                printf("Enter index and string to insert: ");
                scanf("%d %s", &index, temp);
                StrList_insertAt(list, temp, index);
                break;
            case '3':
                StrList_print(list);
                break;
            case '4':
                size = StrList_size(list);
                printf("The size of List is %d\n", size);
                break;
            case '5':
                // Print string at index
                printf("Enter index: ");
                scanf("%d", &index);
                StrList_printAt(list, index);
                break;
            case '6':
                // Print occurrences of chars
                size = StrList_printLen(list);
                printf("The size of char in the List is %d\n", size);
                break;
            case '7':
                // Print occurrences of string
                printf("Enter string to count occurrences: ");
                scanf("%s", temp);
                printf("Occurrences of %s: %d\n", temp, StrList_count(list, temp));
                break;
            case '8':
                // Remove occurrences of string
                printf("Enter string to remove: ");
                scanf("%s", temp);
                StrList_remove(list, temp);
                break;
            case '9':
                // Remove string at index
                printf("Enter index: ");
                scanf("%d", &index);
                StrList_removeAt(list, index);
                break;
            case '0'+10:
                // Reverse list
                StrList_reverse(list);
                break;
            case '0'+11:
                // Clear list
                StrList_free(list);
                list = StrList_alloc(); // Reallocate an empty list
                break;
            case '0'+12:
                // Sort list
                StrList_sort(list);
                break;
            case '0'+13:
                // Check if list is sorted
                if (StrList_isSorted(list))
                    printf("List is sorted.\n");
                else
                    printf("List is not sorted.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("Enter your choice: ");
    }
    
    printf("Exiting program.\n");
    StrList_free(list); // Free the list before exiting
    return 0;
}

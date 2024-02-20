#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node
typedef struct _Node {
    char* data;
    struct _Node* next;
} Node;

// Define the structure of the linked list
struct _StrList {
    Node* head;
    size_t size;
};

// Function to allocate a new empty StrList
StrList* StrList_alloc() {
    StrList* list = (StrList*)malloc(sizeof(StrList));
    if (list) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

// Function to free memory allocated for StrList
void StrList_free(StrList* list) {
    if (list) {
        Node* current = list->head;
        while (current) {
            Node* next = current->next;
            free(current->data); // Free the string data
            free(current);       // Free the node
            current = next;
        }
    }
}

// Function to insert an element at the end of the StrList
void StrList_insertLast(StrList* list, const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = strdup(data); // Duplicate the string to store in the node
        newNode->next = NULL;

        if (list->head == NULL) {
            list->head = newNode;
        } else {
            Node* current = list->head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        list->size++;
    }
}

// Function to insert an element at a given index
void StrList_insertAt(StrList* list, const char* data, int index) {
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
        return;
    }

    if (index == 0) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = strdup(data);
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = strdup(data);

    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
}

// Function to return the first data
char* StrList_firstData(const StrList* list) {
    if (list->head) {
        return list->head->data;
    }
    return NULL;
}

// Function to print the StrList
void StrList_print(const StrList* list) {
    if (list == NULL || list->head == NULL) {
        printf("\n");
    }
    else {
        Node* current = list->head;
        while (current) {
            printf("%s ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to print the word at a given index
void StrList_printAt(const StrList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return;
    }

    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    printf("%s\n", current->data);
}

// Function to return the amount of characters in the list
int StrList_printLen(const StrList* list) {
    int totalLen = 0;
    Node* current = list->head;
    while (current) {
        totalLen += strlen(current->data);
        current = current->next;
    }
    return totalLen;
}

// Function to count occurrences of a string in the list
int StrList_count(StrList* list, const char* data) {
    int count = 0;
    Node* current = list->head;
    while (current) {
        if (strcmp(current->data, data) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Function to remove all occurrences of a string from the list
void StrList_remove(StrList* list, const char* data) {
    Node* current = list->head;
    Node* prev = NULL;

    while (current) {
        if (strcmp(current->data, data) == 0) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            free(temp->data);
            free(temp);
            list->size--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Function to remove an element at a given index
void StrList_removeAt(StrList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return;
    }

    Node* current = list->head;
    Node* prev = NULL;

    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current->data);
    free(current);
    list->size--;
}

// Function to check if two lists have the same elements
int StrList_isEqual(const StrList* list1, const StrList* list2) {
    if (list1->size != list2->size) {
        return 0;
    }

    Node* current1 = list1->head;
    Node* current2 = list2->head;

    while (current1 && current2) {
        if (strcmp(current1->data, current2->data) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return 1;
}

// Function to clone a list
StrList* StrList_clone(const StrList* list) {
    StrList* newList = StrList_alloc();
    if (!newList) {
        return NULL;
    }

    Node* current = list->head;
    while (current) {
        StrList_insertLast(newList, current->data);
        current = current->next;
    }

    return newList;
}

// Function to reverse the list
void StrList_reverse(StrList* list) {
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
}

// Function to sort the list in lexicographical order
void StrList_sort(StrList* list) {
    // Bubble sort
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    /* Checking for empty list */
    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = list->head;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->data, ptr1->next->data) > 0) {
                char* temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to check if the list is sorted in lexicographical order
int StrList_isSorted(StrList* list) {
    Node* current = list->head;
    while (current && current->next) {
        if (strcmp(current->data, current->next->data) > 0) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

size_t StrList_size(const StrList* list) {
    return list->size;
}

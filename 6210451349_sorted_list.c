//Pitchpa Photharajareon 6210451349

#include <stdio.h>
#include <stdlib.h>
struct Node { 
    int data; 
    struct Node* next; 
}; 

struct Node *newNode(int new_data) { 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next =  NULL; 
    return new_node; 
} 

void addLinklist(struct Node** head_ref, struct Node* new_node) { 
    struct Node* current; 
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else { 
        current = *head_ref; 
        while (current->next!=NULL && current->next->data < new_node->data) { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 

void outputLinklist(struct Node *head) { 
    struct Node *temp = head; 
    while(temp != NULL) { 
        printf("%d\n", temp->data); 
        temp = temp->next; 
    } 
} 

int main() {
    int number;
    struct Node* head = NULL; 
    while(1) {
        printf("enter number 0-1: ");
        scanf("%d", &number); 
        if(number < 0) {
            break;
        }
        struct Node *new_node = newNode(number); 
        addLinklist(&head, new_node); 
    }
    printf("output\n");
    outputLinklist(head); 
}

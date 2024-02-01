#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
} Node;


void insertAtBeginning(Node **head, int new_data);
void deleteAtBeginning(Node **head);
void deleteAtEnd(Node **head);
void delete(Node **previous_node, int position);
void printList(Node *next);


void insertAtBeginning(Node **head, int new_data){
    Node *new_node = (struct Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}


void deleteAtBeginning(Node **head){
    Node *ptr;
    if (head == NULL){
        printf("\nList is empty");
    }
    else{
        ptr = *head;
        *head = ptr->next;
        free(ptr);
        printf("\n Node deleted from the beginning ...");
    }
}


void deleteAtEnd(Node **head){
    Node *ptr, *ptr1;
    if (*head == NULL){
        printf("\nlist is empty");
    }
    else if ((*head)->next == NULL){
            free(*head);
            *head = NULL;
            printf("\nOnly node of the list deleted ...");
        }
    else{
        ptr = *head;
        while (ptr->next != NULL){
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\n deleted Node from the last ...");
    }
}


void delete(Node **head, int position){
    Node *temp = *head, *previous;
    if (temp == NULL){
        printf("\nList is empty");
        return;
    }
    if (position == 1){
        *head = temp->next;
        free(temp);
        printf("\ndeleted node with position %d", position);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++){
        previous = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("\nposition out of range");
        return;
    }
    previous->next = temp->next;
    free(temp);
    printf("\ndeleted node with position %d", position);
}


void PrintList(Node *node){
    while (node != NULL){
        printf("%d\n", node->data);
        node = node->next;
    }
}


int main(){
    int ch, new, position;
    Node *head = NULL;
    while (ch != 6){
        printf("Menu\n");
        printf("1.Insert into linked list\n");
        printf("2.Delete at beginning\n");
        printf("3.Delete at a specific position\n");
        printf("4.Delete at end\n");
        printf("5.Display linked list\n");
        printf("6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch){
        
            case 1:{
                printf("Enter the data you want to insert at beginning\n");
                scanf("%d", &new);
                insertAtBeginning(&head, new);
                break;
            }
            
            case 2:{
                deleteAtBeginning(&head);
                break;
            }

            case 3:{
                    printf("Enter the position at which you want to delete \n");
                    scanf("%d", &position);
                    delete (&head, position);
                    break;
                }

            case 4:{
                deleteAtEnd(&head);
                break;
            }

            case 5:{
                printf("Created linked list is:\n");
                PrintList(head);
                break;
            }

            case 6:{
                return 0;
                break;
            }

            default:{
                printf("Invalid data!");
                break;
            }
        }
    }
    return 0;
}
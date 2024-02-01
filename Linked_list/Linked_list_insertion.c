#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
} Node;


void insertAtBeginning(Node **head, int data_data);
void insertAtEnd(Node **head, int data_data);
void insert(Node **prev_node, int data_data, int pos);
void PrintList(Node *next);


void insertAtBeginning(Node **head, int data_data){
    Node *data_node = (struct Node *)malloc(sizeof(Node));
    data_node->data = data_data;
    data_node->next = *head;
    *head = data_node;
}


void insertAtEnd(Node **head, int data_data){
    Node *data_node = (struct Node *)malloc(sizeof(Node));
    Node *last = *head;
    data_node->data = data_data;
    data_node->next = NULL;

    if (*head == NULL){
        *head = data_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = data_node;
}


void insert(Node **head, int data_data, int pos){
    if (*head == NULL){
        printf("Cannot be NULL\n");
        return;
    }
    Node *temp = *head;
    Node *dataNode = (Node *)malloc(sizeof(Node));
    dataNode->data = data_data;
    dataNode->next = NULL;
    while (--pos > 0){
        temp = temp->next;
    }
    dataNode->next = temp->next;
    temp->next = dataNode;
}


void PrintList(Node *node){
    while (node != NULL){
        printf("%d\n", node->data);
        node = node->next;
    }
}


int main(){
    int ch, data, pos;
    Node *head = NULL;
    while (ch != 5){
        printf("Menu\n");
        printf("1.insert at beginning\n");
        printf("2.insert at a specific position\n");
        printf("3.insert at end\n");
        printf("4.Display linked list\n");
        printf("5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch){

            case 1:{
                printf("Enter the data you want to insert at beginning\n");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            }

            case 2:{
                printf("Enter the data and position at which you want to insert \n");
                scanf("%d%d", &data, &pos);
                insert(&head, data, pos);
                break;
            }

            case 3:{
                    printf("Enter the data you want to insert at end\n");
                    scanf("%d", &data);
                    insertAtEnd(&head, data);
                    break;
                }

            case 4:{
                printf("Created linked list is:\n");
                PrintList(head);
                break;
            }

            case 5:{
                return 0;
                break;
            }

            case 6:{
                printf("Invalid data!");
                break;
            }
        }
    }
    return 0;
}
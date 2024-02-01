#include <stdio.h>
#define N 5

int queue[N];
int front = -1, rear = -1;

void insert(int);
int delete();
void display();


void main(){
    int num, choice;
    do{
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your option : \n");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter the number to be inserted in the queue : \n");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            num = delete ();
            if (num != -1)
                printf("\n The number deleted is : %d\n", num);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
            exit(0);
            break;
        }
    } while (choice != 4);
}


void insert(int num){
    if (rear == N - 1)
        printf("\n OVERFLOW");
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else rear++;
    queue[rear] = num;
}


int delete(){
    int val;
    if (front == -1 || front > rear){
        printf("\n UNDERFLOW");
        return -1;
    }
    else{
        val = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return val;
    }
}


void display(){
    int i;
    printf("\n");
    if (front == -1 || front > rear)
        printf("\n QUEUE IS EMPTY");
    else
    {
        for (i = front; i <= rear; i++)
            printf("\t %d", queue[i]);
    }
}
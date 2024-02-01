#include <stdio.h>

int s[10], top = -1;


void push(){
    if (top == (10 - 1)){
        printf("Stack is full. Stack overflow\n");
    }
    else{
        int item;
        printf("Enter the element:\n");
        scanf("%d", &item);
        top++;
        s[top] = item;
    }
}


void pop(){
    if (top == -1){
        printf("Stack is empty . Stack underflow\n");
    }
    else{
        printf("Popped element is :%d\n", s[top]);
        top--;
    }
}


void display(){
    int i;
    if (top >= 0){
        for (i = 0; i <= top; i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
    else{
        printf("Stack is empty\n");
    }
}


void main(){
    int choice;
    do{
        printf("\n1.Push\n2.Pop\n3.Display\n4.Quit\n");
        printf("Enter the option:\n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a valid option\n");
            }
    } while (choice != 4);
}
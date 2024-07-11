#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Stack_type{
    int a[MAX];
    int top;
} Stack;

void init(Stack *s){
    s->top = -1;
}

int isEmpty(Stack* s){
    return s->top==-1;
}
int isFull(Stack* s){
    return s->top==MAX-1;
}
void push(Stack* s, int value){
    s->a[++(s->top)]=value;
}
int pop(Stack* s){
    return s->a[(s->top)--];
}
void displayStack(Stack* s){
    for(int i=0; i<=s->top;i++){
        printf("%d ", s->a[i]);
    }
}

void main() {
    Stack s;
    init(&s);
    int num[6] = {1,-2,3,-4,5,-6};
    // push
    printf("MAX = %d\n\n", MAX);
printf("PUSH\n");
    for (int i = 0; i < 6; i++){
        printf("push %d: \n",num[i]);
        if(!isFull(&s)){
            push(&s,num[i]);
            displayStack(&s);
            printf("\n");
        }
        else
            printf("Stack is full. \n\n");
    }
    // pop
    printf("POP\n");
    int i = 0;
    while (!isEmpty(&s)) {
        printf("pop %d: %d\n",i, pop(&s));
        displayStack(&s);
        i++;
        printf("\n");
     }
}

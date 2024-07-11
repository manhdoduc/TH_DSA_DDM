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
void findGreaterRight(int arr[], int n){
    Stack s;
    init(&s);
    int result[n];
    for(int i=n-1;i>=0;i--){
        while(!isEmpty(&s) && s.a[s.top]<=arr[i]){
            pop(&s);
        }
        if(isEmpty(&s)){
            result[i]=-1;
        }
        else{
            result[i]=s.a[s.top];
        }
        push(&s,arr[i]);
    }
    printf("Result: ");
    for(int i=0;i<n;i++){
        printf("%d ",result[i]);
    }
}

int main(){
    int a[]={1,4,3,1,2,5,6,5,7,8};
    int n=10;
    findGreaterRight(a, n);
    return 0;
}
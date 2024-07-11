#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Khai báo cấu trúc ngăn xếp
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Hàm khởi tạo ngăn xếp
void init(Stack *s) {
    s->top = -1;
}

// Ham kt stack trong
int isEmpty(Stack* s){
    return s->top==-1;
}
// Ham kt stack day chua
int isFull(Stack* s){
    return s->top==MAX_SIZE-1;
}

// Ham them  ptu vao STack
void push(Stack* s, char key){
    s->data[++s->top]= key;
}

// Ham xoa phan tu top cua Stack
int pop(Stack* s){
    return s->data[--s->top];
}

// Ham in ra Stack
void displayStack(Stack* s){
    for(int i=0; i< s->top;i++){
        printf("%c", s->data[i]);
    }
}

// Ham kt dau ngoac hop le
int isValid(char* s){
    Stack stack;
    init(&stack);
    for(int i=0 ; i<strlen(s); i++){
        char c=s[i];
        if((c=='(')||(c=='[')||(c=='{')){
            push(&stack, c);
        } else {
            if((c=')')||(c==']')||(c=='}')){
                if(isEmpty(&stack)){
                return -1;
                }
            }
            char p = pop(&stack);
            if(((c=='(') && (p!=')')) || ((c=='[') && (p!=']')) || ((c=='{') && (p!='}'))){
                return -1;
            }
        }
    }
    return isEmpty(&stack);
}
int main(){
    char test;
    printf("Nhap vao vi du can kiem tra\n");
    printf("Test = "); 
    scanf("%c ", &test);
    if(isValid(&test)){
        printf("Hop le\n");
    } else printf("Ko hop le");
}
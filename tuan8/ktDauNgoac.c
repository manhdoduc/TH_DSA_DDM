#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

// Hàm kiểm tra ngăn xếp rỗng
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Hàm kiểm tra ngăn xếp đầy
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Hàm thêm phần tử vào đỉnh ngăn xếp
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        exit(1);
    }
    s->data[++s->top] = c;
}

// Hàm lấy phần tử ở đỉnh ngăn xếp
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->data[s->top--];
}

// Hàm kiểm tra dấu ngoặc hợp lệ
bool isValid(char *s) {
    Stack stack;
    init(&stack);
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&stack, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&stack)) {
                return false;
            }
            char top = pop(&stack);
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return isEmpty(&stack);
}

// Hàm main
int main() {
    char s[MAX_SIZE];
    printf("Nhap day ngoac: ");
    scanf("%s", s);
    if (isValid(s)) {
        printf("Day ngoac hop le!\n");
    } else {
        printf("Day ngoac khong hop le!\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//Định nghĩa node
typedef struct NodeType {
    int data;
    struct NodeType* next;
}Node;

//Định nghĩa Linked list
typedef struct LinkedListType{
    Node* head;
}LinkedList;

//Khởi tạo linked list
void init(LinkedList* list) {
    list->head = NULL;
}
//Size cua list
int size(struct NodeType* list) {
    int count = 0;
    struct NodeType* h = list;
    while (h != NULL) {
        count++;
        h = h->next;
    }
    return count;
}
//Hàm tạo node mới
Node* makeNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
//Hàm chèn node mới vào đầu danh sách
void PushPush(int data, LinkedList* list){
    Node* newNode=makeNode(data);
    newNode->next=list->head;
    list->head=newNode;
}
void Pop(LinkedList* list) {
    int n = size(list->head);
    if (n == 0) {
        // Queue is empty, do nothing
        return;
    }

    if (n == 1) {
        // Queue has only one element, pop it
        free(list->head);
        list->head = NULL;
        return;
    }

    Node* tmp = list->head;
    for (int i = 0; i < n - 2; i++) {
        tmp = tmp->next;
    }

    free(tmp->next);
    tmp->next = NULL;
}

void Top(LinkedList* list) {
    int n = size(list->head);
    if (n == 0) {
        printf("Queue is empty\n");
        return;
    }

    Node* tmp = list->head;
    for (int i = 0; i < n - 1; i++) {
        tmp = tmp->next;
    }

    int value = tmp->data;
    printf("Top of Queue: %d\n", value);
}

//Hàm in linked list
void printQueue(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        //printf("Node address: %p | ", &(node->data));
        printf("%d ", node->data);
        //printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}
//Hàm main
int main(){
    LinkedList list;
    init(&list);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        PushPush(tmp, &list); 
    }
    Top(&list);
    printQueue(&list);
    Pop(&list);
    printQueue(&list);
    return 0;
}

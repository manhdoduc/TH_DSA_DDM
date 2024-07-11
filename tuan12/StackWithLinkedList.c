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
void Push(int data, LinkedList* list){
    Node* newNode=makeNode(data);
    newNode->next=list->head;
    list->head=newNode;
}

void Pop(LinkedList* list){
    if(list->head==NULL) return;
    Node* newHead = list->head->next;
    free(list->head);  
    list->head = newHead;  
}
void Top(LinkedList* list){
    if(list->head==NULL) return;
    int valueTop=list->head->data;
    printf("Top of Stack : %d\n", valueTop);
}
//Hàm in Stack
void printStack(LinkedList* list){
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
        Push(tmp, &list); 
    }
    Top(&list);
    printStack(&list);
    Pop(&list);
    printStack(&list);

    return 0;
}

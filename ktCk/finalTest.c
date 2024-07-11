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
void insertHead(int data, LinkedList* list){
    Node* newNode=makeNode(data);
    newNode->next=list->head;
    list->head=newNode;
}
void insertBack(int data, LinkedList* list){
    Node * newNode=makeNode(data);
    if(list->head==NULL){ 
        insertHead(data, list);
        return;
    }
    Node * last= list->head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newNode;
}
void insertK(int data, LinkedList* list, int k){
    int n=size(list->head);
    if(k<1||k>n+1) return;
    if(k==1) insertHead(data, list);
    Node* node=list->head;
    for(int i=0;i<k-2;i++){
        node=node->next;
    }
    Node* newNode=makeNode(data);
    newNode->next=node->next;
    node->next=newNode;
}
void deleteHead(LinkedList* list){
    if(list->head==NULL) return;
    Node* newHead = list->head->next;
        free(list->head);  
        list->head = newHead;  
}
void deleteBack(LinkedList* list){
   int n=size(list->head);
   Node * tmp;
   for(int i=0;i<n-2;i++){
    tmp=tmp->next;
   }
   free(tmp->next);
   tmp->next=NULL;
}
void deleteK(LinkedList* list, int k){
    int n = size(list->head);
    if(k < 1 || k > n) {
        
        return;
    }

    if(k == 1) {
        
        deleteHead(list);
        return;
    }

    Node* current = list->head;
    Node* previous = NULL;

    for(int i = 0; i < k - 1; i++) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;

    free(current);
}

//Hàm in linked list
void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

Node* getTail(Node* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }
    return getTail(head->next);
}

//Hàm main
int main() {
    LinkedList list;
    init(&list);
    int n = 10;
    for (int i = 0; i < n; i++) {
        int tmp = rand() % (10 - 0 + 1) + 0;
        insertHead(tmp, &list);
    }
    Node* tail = getTail(list.head);
    if (tail != NULL) {
        printf("Dia chi con tro nut cuoi danh sach : %d\n", &tail);
    } else {
        printf("Danh sach trong \n");
    }

    printList(&list);

    return 0;
}


// B1: Base case là head == NULL || head->next == NULL
// B2: Kết quả base case là con trỏ đến nút cuối danh sách liên kết
// B3: Trước Base case là con trỏ đến nút trước nút cuối danh sách liên kết 
// B4: Trước B3 là con trỏ thứ 2 trước con trỏ mà con trỏ đó trỏ đến nút cuối
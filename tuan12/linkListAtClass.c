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
        // Invalid position, do nothing
        return;
    }

    if(k == 1) {
        // Delete the head node
        deleteHead(list);
        return;
    }

    Node* current = list->head;
    Node* previous = NULL;

    // Move to the node just before the one to be deleted
    for(int i = 0; i < k - 1; i++) {
        previous = current;
        current = current->next;
    }

    // Adjust pointers to skip the node at position k
    previous->next = current->next;

    // Free the memory of the deleted node
    free(current);
}

//Hàm in linked list
void printList(LinkedList* list){
    Node* node = list->head;
    while (node != NULL) {
        //printf("Node address: %p | ", &(node->data));
        printf("%d ", node->data);
        //printf("next node address = %p\n ", node->next);
        node = node->next;
    }
    printf("\n");
}

//Hàm tính tổng LinkList
int sumRecursive(Node* node) {
    if (node == NULL) {
        return 0; // Trường hợp cơ sở: danh sách rỗng, tổng là 0
    }

    // Gọi đệ quy cho danh sách con bắt đầu từ nút tiếp theo
    return node->data + sumRecursive(node->next);
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
        insertHead(tmp, &list); 
    }
    printList(&list);
    int k;
    scanf("%d", &k);
    deleteK(&list, k);
    printList(&list);
    return 0;
}

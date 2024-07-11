#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node* makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

void duyet(node * head){
    while(head != NULL){
        printf("%d ", head->data);
        head=head->next;
    }
}

int count(node * head){
    int dem=0;
    while(head!=NULL){
        dem++;
        head=head->next;
    }
    return dem;
}

void pushFront(node **head, int x){
    node* newNode = makeNode(x);
    // B1: next cua newnode => head
    newNode->next=(*head);  // *head => dia chi cua node head trong dslk
    (*head)=newNode;
    // B2: cap nhap node head => newNode
}

void pushBack(node **head, int x) {
    node *newNode = makeNode(x);
    
    if (*head == NULL) {
        // Nếu danh sách rỗng, nút mới trở thành nút đầu danh sách
        *head = newNode;
        return;
    }

    // Tìm nút cuối cùng trong danh sách
    node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Nối nút mới vào cuối danh sách
    last->next = newNode;
}

void insert(node **head, int k, int x){
	int n = size(*head);
	if(k < 1 || k > n + 1) return;
	if(k == 1){
		pushFront(head, x); return;
	}
	node *temp = *head;
	for(int i = 1; i <= k - 2; i++){
		temp = temp->next;
	}
	//temp : k - 1
	node *newNode = makeNode(x);
	newNode->next = temp->next;
	temp->next = newNode;
}
int main(){
    node *head=NULL;
    for(int i=1;i<6;i++){
        pushBack(&head,i);
    }
    duyet(head);
}

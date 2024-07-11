#include <stdio.h>
#define MAX 50

typedef struct {
    int head, tail;
    int a[MAX];
} Queue;

void init(Queue* q) {
    q->head = 0;
    q->tail = -1;
}

int isFull(Queue *q){
    return q->tail==MAX-1;
}
int isEmpty(Queue *q){
    return q->head==q->tail+1;
}
void put(Queue* q, int value) {
    q->a[++(q->tail)] = value;
}
int get(Queue* q){
    return q->a[++(q->head)-1];
}
int top(Queue* q){
    return q->a[q->head];
}
void displayQueue(Queue*q){
    for(int i=q->head;i<=q->tail;i++){
        printf("%d ", q->a[i]);
    }
    printf("\n");
}
void cancelRegistration(Queue* q, int element) {
    // Tìm vị trí của phần tử cần xóa
    int i;
    for (i = q->head; i <= q->tail; i++) {
        if (q->a[i] == element) {
            break;
        }
    }

    // Nếu phần tử không được tìm thấy
    if (i > q->tail) {
        printf("Element not found in the queue.\n");
        return;
    }

    // Dịch chuyển các phần tử phía sau về phía trước
    for (int j = i; j < q->tail; j++) {
        q->a[j] = q->a[j + 1];
    }

    // Giảm giá trị của tail
    q->tail--;

    printf("Element %d removed from the queue.\n", element);
}

int main() {
    Queue L;
    init(&L);
    int list[1000];
    int tt;
    printf("Chon thao tac muon thuc hien\n"); 
    printf("1 de them nguoi moi\n");
    printf("2 de xoa 1 khach hang\n");
    printf("3 de in ra nguoi dau danh sach\n");
    printf("4 hien toan bo danh sach\n");
    printf("Chon thao tac :\n");
    do {
    scanf("%d", &tt);
    } while (tt != 1 && tt != 2 && tt != 3 && tt != 4);

    while(tt==1||tt==2||tt==3||tt==4){
        if(tt==1){
            if(isFull(&L)){
                printf("Danh sach dang day\n");
            } else {
                printf("So dai dien nguoi moi\n");
                int p;
                scanf("%d", &p);
                put(&L, p);
            }
        } else if(tt==2){
            if(isEmpty(&L)){
                printf("Danh sach dang trong\n");
            } else {
                printf("Chon so dai dien can xoa\n");
                int d;
                scanf("%d", &d); 
                cancelRegistration(&L, d);
            }
        } else if(tt==3){
            if(isEmpty(&L)){
                printf("Danh sach dang trong\n");
            } else {
            int h=top(&L);
            printf("Nguoi o dau danh sach : %d\n", h);
            }
        } else {
            displayQueue(&L);
        }
        printf("Chon thao tac : \n");
        scanf("%d", &tt);
    }
    return 0;
}



#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int*a, int *b);
void bubbleSort(int array[], int n){
    for(int i=0;i<n;i++){
        for(int j=0; j<n-1-i;j++){
            if(array[j]>array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }
}
void initializeArray(int arr[], int n, int min, int max){
    for(int i=0; i<n;i++){
        arr[i]=min+ rand()%(max-min+1);
        //sinh ngau nhien gia tri trong [min,max]
    }
}

int main(){
    int a[1000];
    int n;
    scanf("%d", &n);
    time_t t;
    srand((unsigned)time(&t));
    initializeArray(a, n, -100, 100);
    bubbleSort(a, n);
    for( int j=0; j<n;j++){
        printf("%d ", a[j]);
    }
}
void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
#include<stdio.h>
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

int main(){
    int a[1000];
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
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


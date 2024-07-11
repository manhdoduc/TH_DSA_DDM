#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertionSort(int a[],int N, int *comps, int *shifts){
    for(int i=1; i<N;i++){
        int comp=0;
        int shift=0;
        int x=a[i],pos=i-1;
        comp++;
        while(pos>=0&&x<a[pos]){
            a[pos+1]=a[pos];
            shift++;
            --pos;
        }
        a[pos+1]=x;
        printf("\nBuoc %d : ", i);
        for( int j=0;j<N;j++){
            printf("%4d ", a[j]);
        }
        printf("\nComps buoc %d : %d", i, comp);
        printf("\nShift buoc %d : %d", i, shift);
        (*comps)+=comp;
        (*shifts)+=shift;
    }
}
void initializeArray(int arr[], int N, int min, int max){
    for(int i=0; i<N;i++){
        arr[i]=min+ rand()%(max-min+1);
    }
}
void main(){
    time_t t;
    srand((unsigned)time(&t));
    int n[100];
    int N=5;
    int comps=0;
    int shifts=0;
    initializeArray(n, N, -20, 20);
    printf("Mang ban dau :");
    for(int i=0;i<N;i++){
        printf("%4d ",n[i]);
    }
    insertionSort(n, N, &comps, &shifts);
    printf("\nMang sau khi sap xep :");
    for(int i=0;i<N;i++){
        printf("%4d ", n[i]);
    }
    printf("\nTong so Comps = : %4d ", comps);
    printf("\nTong so Shift = : %4d ", shifts);
}
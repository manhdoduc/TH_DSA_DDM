#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void selectionSort(int arr[], int n, int* comps, int* swaps){
    for(int i=0;i<n-1;i++){
        int min_post=i;
        for(int j=i+1;j<n;j++){
            (*comps)++;
            if(arr[min_post]>arr[j]){
                min_post=j;
            }
        }
        (*swaps)++;
        int tmp=arr[i];
        arr[i]=arr[min_post];
        arr[min_post]=tmp;
    }
}
void initializeArray(int arr[], int n, int min, int max){
    for(int i=0; i<n;i++){
        arr[i]=min+ rand()%(max-min+1);
        //sinh ngau nhien gia tri trong [min,max]
    }
}
int main(){
    int arr[10];
    int n=10; 
    time_t t;
    srand((unsigned)time(&t));
    initializeArray(arr, n, -10, 10);
    int comps=0;
    int swaps=0;
    selectionSort(arr, n, &comps, &swaps);
    for( int i=0; i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\nComps = %d", comps);
    printf("\nSwaps = %d", swaps);
}
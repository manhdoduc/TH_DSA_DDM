#include<stdio.h>
void swap(int*a, int *b);
void bubbleSort(int array[], int n, int *comps, int * swaps){
    for(int i=0;i<n;i++){
        for(int j=0; j<n-1-i;j++){
            (*comps)++;
            if(array[j]>array[j+1]){
                swap(&array[j],&array[j+1]);
                (*swaps)++;
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
    int swaps=0;
    int comps=0;
    bubbleSort(a, n,&comps, &swaps);
    for( int j=0; j<n;j++){
        printf("%d ", a[j]);
    }
    printf("\nComps= %d",comps);
    printf("\nSwaps= %d",swaps);
}

void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}


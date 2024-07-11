#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void selectionSort(int arr[], int n, int* comps, int* swaps, int* steps, int count[]){
    for(int i=0;i<n-1;i++){
        int min_post=i;
        for(int j=i+1;j<n;j++){
            (*comps)++;
            if(arr[min_post]>arr[j]){
                min_post=j;
            }
        }
        if(min_post!=i){
        (*swaps)++;
        int tmp=arr[i];
        arr[i]=arr[min_post];
        arr[min_post]=tmp;
        }
        count[*swaps]++;
    }
    (*steps)=(*comps)+(*swaps);
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
    int K[]={20, 30, 50,100};
    int compS[4]={0};
    int swapS[4]={0};
    int stepS[4]={0};
    time_t t;
    srand((unsigned)time(&t));
    printf("THONG KE KET QUA TAN SUAT CHAY\n");
    for(int i=0;i<4;i++){
        int comp=0;
        int swap=0;
        int step=0;
        int count[20]={};
        for(int j=1;j<=K[i];j++){
            initializeArray(arr, n, -20, 20);
            int comps=0;
            int swaps=0;
            int steps=0;
            selectionSort(arr, n, &comps, &swaps, &steps, count);
            comp+=comps;
            swap+=swaps;
            step+=steps;
        }
        printf("\nK = %4d | ", K[i]);
        for(int i=0;i<10;i++){
            printf("%8d ", count[i]);
        }
        compS[i]=comp/K[i];
        swapS[i]=swap/K[i];
        stepS[i]=step/K[i];
    }
    printf("\n\nBANG THONG KE\n");
    printf("\n%-8s","K");
    for(int i=0;i<4;i++){
        printf("%8d", K[i]);       
    }
    printf("\n%-8s","Comps");
    for(int j=0;j<4;j++){
        printf("%8d", compS[j]);
    }
    printf("\n%-8s","Swap");
    for(int k=0;k<4;k++){
        printf("%8d", swapS[k]);
    }
    printf("\n%-8s","Step");
    for(int h=0;h<4;h++){
        printf("%8d", stepS[h]);
    }
}
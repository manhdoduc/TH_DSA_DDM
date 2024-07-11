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
        if(min_post!=i){
        (*swaps)++;
        int tmp=arr[i];
        arr[i]=arr[min_post];
        arr[min_post]=tmp;
        }
    }    
}
void insertionSort(int a[],int N, int *comps, int *shifts){
    for(int i=1; i<N;i++){
        int x=a[i],pos=i-1;
        (*comps)++;
        while(pos>=0&&x<a[pos]){
            a[pos+1]=a[pos];
            (*shifts)++;
            --pos;
        }
        a[pos+1]=x;
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
    int N=20;
    int compSeAve[2]={0};
    int compIn[2]={0};
    int shiftS[2]={0};
    int swapS[2]={0};
    int numK[2]={1000,10000};
    for(int k=0; k<2; k++){
        int compSelec=0;
        int compInser=0;
        int totalShifts=0;
        int totalSwaps=0;
        int countSwap[10000]={};
        int countShift[10000]={};
        for(int index=0;index<=numK[k];index++){
            int compSe=0;
            int compIn=0;
            int shift=0;
            int swap=0;
            initializeArray(n, N, -20, 20);
            insertionSort(n, N, &compIn, &shift);
            selectionSort(n, N, &compSe, &swap);
            countShift[index]=shift;
            countSwap[index]=swap;
            compSelec+=compSe;
            compInser+=compIn;
            totalShifts+=shift;
            totalSwaps+=swap;
        }
        compSeAve[k]=compSelec/numK[k];
        compIn[k]=compInser/numK[k];
        shiftS[k]=totalShifts/numK[k];
        swapS[k]=totalSwaps/numK[k];
        printf("\nK= %6d", numK[k]);
        printf("\nBANG THONG KE SO LAN SHIFT\n");
        for(int h=0;h<20;h++){
            printf("%d ", countShift[h]);
        }
        printf("\nBANG THONG KE SO LAN SWAP\n");
        for(int h=0;h<20;h++){
            printf("%d ", countSwap[h]);
        }
    }
    printf("\nBANG TRUNG BINH");
    printf("\n%-8s:","K");
    for(int i=0;i<2;i++){
        printf("%15d ", numK[i]);
    }
    printf("\n%-8s:","Comp Slection");
    for(int i=0;i<2;i++){
        printf("%10d ", compSeAve[i]);
    }
    printf("\n%-8s:","Swap");
    for(int j=0;j<2;j++){
        printf("%8d ", swapS[j]);
    }
    printf("\n%-8s:","Comp Insertion");
    for(int i=0;i<2;i++){
        printf("%8d ", compIn[i]);
    }
    printf("\n%-8s:","Shift");
    for(int j=0;j<2;j++){
        printf("%8d ", shiftS[j]);
    }
}
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int*a, int *b);
void bubbleSort(int array[], int n, double *aver, int freq[],int *index){
    int comps=0;
    for(int i=0;i<n;i++){
        for(int j=0; j<n-1-i;j++){
            if(array[j]>array[j+1]){
                swap(&array[j],&array[j+1]);
                comps++;
            }
        }
    }
    *aver+=comps;
    if((*index)<21){
    freq[(*index)]=comps;
    }
}
void initializeArray(int arr[], int n, int min, int max){
    for(int i=0; i<n;i++){
        arr[i]=min+ rand()%(max-min+1);
        //sinh ngau nhien gia tri trong [min,max]
    }
}
int main(){
    int arr[50];
    int max=100;
    int min=-100;
    int n=20;
    time_t t;
    int arrK[]={10, 20, 100, 1000};
    srand((unsigned)time(&t));
    for(int i=0;i <sizeof(arrK)/sizeof(arrK[0]);i++){
        double aver = 0;
        printf("\nK = %d\n", arrK[i]);
        int freq[100]={0};
        int index=0;
        for(int j=0;j<arrK[i];j++){
            initializeArray(arr, n, min, max);
            bubbleSort(arr, n, &aver, freq, &index);
            index++;
        } 
        aver=aver/arrK[i];
        printf("Average =  %5.2f\n", aver);
        for(int h=0;h<20;h++){
            printf("%4d ",freq[h]);
        }
    }
}
void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void linerSearch(int arr[], int n, int x, int *comps){
    for(int i=0;i<n;i++){
        (*comps)++;
        if(arr[i]==x){
            break;
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
    int arr[50];
    int max=100;
    int min=-100;
    int n=20;
    time_t t;
    int arrK[]={10, 20, 100, 1000};
    srand((unsigned)time(&t));

    initializeArray(arr, n, min, max);
    for(int i=0;i<sizeof(arrK)/sizeof(arrK[0]);i++){
        double aver = 0;
        printf("k = %d\n", arrK[i]);
        for(int j=0;j<arrK[i];j++){
            int x=arr[rand()%n];
            int comps=0;
            linerSearch(arr,n,x, &comps);
            aver+=comps;
        } 
        aver=aver/arrK[i];
        printf("average =  %.2f\n", aver);
    }
}
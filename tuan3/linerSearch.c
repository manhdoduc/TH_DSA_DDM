#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void linerSearch(int arr[], int n, int x, int *comps, int freq[]){
    for(int i=0;i<n;i++){
        (*comps)++;
        if(arr[i]==x){
            break;
        }
    }
    freq[*comps]++;
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
        printf("K = %d\n", arrK[i]);
        int freq[20]={0};
        for(int j=0;j<arrK[i];j++){
            int x=arr[rand()%n];
            int comps=0;
            linerSearch(arr,n,x, &comps, freq);
            aver+=comps;
        } 
        aver=aver/arrK[i];
        for (int h = 0; h < 20; h++) {
            printf("%4d : %4d\n", h, freq[h]);
        }
        printf("Average =  %.2f\n", aver);
    }
}
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void binarySearch(int a[], int n, int value, int * comps, int freq[]){
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid = l + (r - l) / 2;
        if(a[mid]==value){
            break;
        } 
        else if(a[mid]<value){
            l=mid+1;
            (*comps)++;
        }
        else {
            r=mid-1;
            (*comps)++;
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
    int arr[20];
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
        int freq[100]={0};
        for(int j=0;j<arrK[i];j++){
            int x=arr[rand()%n];
            int comps=0;
            binarySearch(arr, n, x, &comps, freq);
            aver+=comps;
        } 
        aver=aver/arrK[i];
        for (int h = 0; h < 20; h++) {
                printf("%4d : %4d\n", h, freq[h]);
        }
        printf("Average =  %.2f\n", aver);
    }
}
#include<stdio.h>
void swap(int* a, int* b){
    int tmp= (*a);
    (*a)=(*b);
    (*b)=tmp; 
}
// phan hoach Hoare
int partition(int arr[], int l, int r){
    int pivot=arr[l];
    int i=l-1;
    int j=r+1;
    while(1){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
        else return j;
    }
}
void quickSort(int arr[],int l,int r){
    if(l>=r) return;
    int p=partition(arr, l, r);
    quickSort(arr, l, p);
    quickSort(arr, p+1, r);
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[100];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
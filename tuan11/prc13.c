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
        for(int i=0 ;i<=r;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
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
int quickSort(int arr[],int l,int r,int * count){
    if(l>=r) return -1;
    int p=partition(arr, l, r);
    (*count)++;
    quickSort(arr, l, p, count);
    quickSort(arr, p+1, r, count);
    
}

int main(){
    int n=8;
    int arr[]={8,7,6,5,4,3,2,1};
    int count=0;
    quickSort(arr,0,n-1, &count);
    printf("Array : ");
    for(int i=0;i<8;i++){
        printf("%d ", arr[i]);
    }
    printf("\nThe number of count is : %d", count);
    return 0;
}
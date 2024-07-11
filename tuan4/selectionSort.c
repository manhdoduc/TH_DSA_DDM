# include<stdio.h>
void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min_post=i;
        for(int j=i+1;j<n;j++){
            if(arr[min_post]>arr[j]){
                min_post=j;
            }
        }
        int tmp=arr[i];
        arr[i]=arr[min_post];
        arr[min_post]=tmp;
    }
}
void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
}
void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int x=a[i],pos=i-1;
        while(pos>=0&&x<a[pos]){
            a[pos+1]=a[pos];
            --pos;
        }
        a[pos+1]=x;
    }
}
int main(){
    int arr[100];
    int n;
    scanf("%d", &n);
    for( int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    for(int k=0;k<n;k++){
        printf("%d ", arr[k]);
    }
}
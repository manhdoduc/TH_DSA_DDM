#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertionSort(int a[],int N, int *comps, int *shifts){
    for(int i=1; i<N;i++){
        int comp=0;
        int shift=0;
        int x=a[i],pos=i-1;
        comp++;
        while(pos>=0&&x<a[pos]){
            a[pos+1]=a[pos];
            shift++;
            --pos;
        }
        a[pos+1]=x;
        (*comps)+=comp;
        (*shifts)+=shift;
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
    int N=10;
    int compS[4]={0};
    int shiftS[4]={0};
    int numK[4]={10,20,50,100};
    printf("BANG THONG KE SO LAN SHIFT");
    for(int k=0; k<4; k++){
        int comps=0;
        int shifts=0;
        int count[100]={0};
        for(int index=0;index<=numK[k];index++){
            int comp=0;
            int shift=0;
            initializeArray(n, N, -20, 20);
            insertionSort(n, N, &comp, &shift);
            count[index]=shift;
            comps+=comp;
            shifts+=shift;
        }
        compS[k]=comps/numK[k];
        shiftS[k]=shifts/numK[k];
        printf("\nK= %6d |", numK[k]);
        for(int h=0;h<10;h++){
            printf("%4d ", count[h]);
        }
    }
    printf("\nBANG TRUNG BINH");
    printf("\n%-8s:","K");
    for(int i=0;i<4;i++){
        printf("%8d ", numK[i]);
    }
    printf("\n%-8s:","Comps");
    for(int i=0;i<4;i++){
        printf("%8d ", compS[i]);
    }
    printf("\n%-8s:","Shift");
    for(int j=0;j<4;j++){
        printf("%8d ", shiftS[j]);
    }
}
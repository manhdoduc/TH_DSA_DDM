#include <stdio.h>
void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertZero(int a[], int *n, int position){
    (*n)++;
    for(int i = (*n) - 1; i > position; i--)
        a[i] = a[i-1];
    a[position] = 0;
}
void f(int a[], int *n,int *cnt,int *ins){
    int min = 0;
    int j;
    for (int i = 0; i<(*n); i++){
        printf("i = %d\n",i);
        if(i%2 == 0){
            for(j = i; j<(*n); j++)
                if(a[j]%2==0)
                    if (a[min]%2 != 0)
                        min = j;
                    else 
                        if(a[min] > a[j] || min<i)
                            min = j;
            if (a[min]%2 == 0){
                swap(&a[i],&a[min]);
                (*cnt)++;
            } else{
                (*ins)++;
                insertZero(a, n, i);
            }
        }
        else
            {
                for(j = i; j<(*n); j++)
                {
                    if(a[j]%2!=0)
                        if (a[min]%2 == 0)
                            min = j;
                        else 
                            if(a[min] > a[j] || min < i)
                                min = j;
                }
                if (a[min]%2 != 0){
                        swap(&a[i],&a[min]);
                        (*cnt)++;
                } else{
                    (*ins)++;
                    insertZero(a, n, i);
                }
                
            }
            printArray(a,*n);
    }
}

void printArray(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%5d",a[i]);
    printf("\n");
}

int main() {
    int a[] = {1,9,7,5,2,4};
    int n = 6;
    int cnt=0;
    int ins=0;
    printf("Before: ");
    printArray(a,n);
    f(a,&n,&cnt,&ins);
    printf("After: ");
    printArray(a,n);
    printf("%d\n",cnt);
    printf("%d\n",ins);
    return 0;
}

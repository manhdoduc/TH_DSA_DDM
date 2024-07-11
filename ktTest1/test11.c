#include<stdio.h>
void f(int a[], int n, int *comp, int *swap)
{
    int i, j;
    *comp=0;
    *swap=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 1; j < n; j++)
        {   
            (*comp)++;
            if (a[j - 1] >= a[j])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                (*swap)++;
            }
        }
    }
}
int main(){
    int a[]={8, 6, 4, 8, 8, 12, 10};
    int n=7;
    int comp;
    int swap;
    f(a, n, &comp, &swap);
    printf("Compare = %d", comp);
    printf("\nSwap = %d", swap);
}
#include<stdio.h>
void f(int a[], int n, int b[], int *comp, int *assign)
	{
        *comp=0;
        *assign=0;
	    for (int i = 0; i < n; i++)
	    {
	        for (int j = 0; j < n; j++)
	        {
                (*comp)++;
	            if (a[i] == a[j])
	            {
	            	b[a[i]]++;
                    (*assign)++;
	            }
	        }
	    }
	}
int main(){
    int a[]={0,4,1,3,1,3};
    int b[10]={};
    int n=6;
    int comp;
    int assign=0;
    f(a, n, b, &comp, &assign);
    printf("Comp = %d", comp);
    printf("\nAssign = %d", assign);
}
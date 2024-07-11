#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void f(int a[], int n, int *co, int *ass) {
    int even = 0;
    int odd = 1;
    for (int i = 0; i < n; i++) {
        (*co)++;
        if (a[i] % 2 == 0) {

            int temp = a[even];

            a[even] = a[i];

            a[i] = temp;

            even += 2;
            (*ass)+=3;

        }

    }


    for (int i = 0; i < n; i++) {
        (*co)++;
        if (a[i] % 2 != 0) {

            int temp = a[odd];

            a[odd] = a[i];

            a[i] = temp;

            odd += 2;
            (*ass)+=3;

        }

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
    int compS[3]={0};
    int assignS[3]={0};
    int numK[3]={100,1000,10000};
    printf("BANG THONG KE SO LAN COMP");
    for(int k=0; k<3; k++){
        int comps=0;
        int assigns=0;
        int count[10000]={0};
        for(int index=0;index<=numK[k];index++){
            int comp=0;
            int assign=0;
            initializeArray(n, N, -20, 20);
            f(n, N, &comp, &assign);
            count[index]=assign;
            comps+=comp;
            assigns+=assign;
        }
        compS[k]=comps/numK[k];
        assignS[k]=assigns/numK[k];
        printf("\nK= %6d |", numK[k]);
        for(int h=0;h<10;h++){
            printf("%4d ", count[h]);
        }
    }
    printf("\nBANG TRUNG BINH");
    printf("\n%-8s:","K");
    for(int i=0;i<3;i++){
        printf("%8d ", numK[i]);
    }
    printf("\n%-8s:","Comps");
    for(int i=0;i<3;i++){
        printf("%8d ", compS[i]);
    }
    printf("\n%-8s:","Shift");
    for(int j=0;j<3;j++){
        printf("%8d ", assignS[j]);
    }
}
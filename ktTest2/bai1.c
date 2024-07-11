#include<stdio.h>
void f(int a[], int n, int *comp, int *gan) {
    int even = 0;
    int odd = 1;
    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (a[i] % 2 == 0) {

            int temp = a[even];

            a[even] = a[i];

            a[i] = temp;

            even += 2;
            (*gan)+=3;

        }

    }


    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (a[i] % 2 != 0) {

            int temp = a[odd];

            a[odd] = a[i];

            a[i] = temp;

            odd += 2;
            (*gan)+=3;

        }

    }

}


int main() {

    int n = 10;

    int a[10] = {2, 5, 3, 7, 4, 1, 6, 9, 8, 6};
    int comp=0;
    int gan=0;

    f(a, n, &comp, &gan);
    printf("so buoc so sanh la: %d \n", comp);
    printf("so buoc gan la :%d ", gan);
    return 0;

}
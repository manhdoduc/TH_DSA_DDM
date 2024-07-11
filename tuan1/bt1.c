#include<stdio.h>
#include<stdlib.h>
int main(){
    //khai bao so phan tu nhap vao 
    int n;
    scanf("%d", &n);
    float arrA[100], arrB[100];
    //nhap cac phan tu vao mang 
    for(int i=0;i<n;i++){
        scanf("%f", &arrA[i]);
    }
    //gia tri can so sanh
    int m;
    scanf("%d",&m);
    //dung ham abs() tinh khoang cach tung gia tri cua mang so voi m
    //gia tri j dung de luu tru gia tri gan nhat
    int j=abs(arrA[0]-m);
    //k luu vi tri gia tri gan nhat
    int k=0;
    for(int i=0;i<n;i++){
        //gan tung gia tri arrB[i] bang khoang cach arrA[i] den m
        arrB[i]=abs(arrA[i]-m);
        if(arrB[i]<j){
            j=arrB[i];
            k=i;
        }
    }
    printf("%f at index %d nearest to %d", arrA[k], k, m);
}
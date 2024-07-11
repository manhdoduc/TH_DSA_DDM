#include<stdio.h>
// Bai 2 a

float dq1(int n){
    if(n==1) return 1;
    return 1.0/n + dq1(n-1);
}
// /*
//  buoc 1: BC xay ra khi n=1 return 1
//  buoc 2: kq cua BC la dq1(1)=1
//  buoc 3: truoc BC la n=2, kq la dq1(2)=dq(1)+ 1/2
//  buoc 4: truoc th buoc 3 la n=3, kq la dq1(3)=dq1(2)+dq1(1)+1/3
// */
// 2b
float dq2(int n) {
    if (n == 1) 
        return 0.5;
    return 1.0 / (2 * n) + dq2(n - 1);
}
// /*
// buoc 1: BC xay ra khi n=1 return 0.5
// buoc 2: kq cua BC la dq2(1)= 0.5
// buoc 3: truoc BC la n=2, kq la dq2(2)=dq2(1)+ 1/4
// buoc 4: truoc th buoc 3 la n=3, kq la dq2(3)=dq2(2)+dq2(1)+1/6
// */
// 2c
float dq3(int n){
    if(n==1) return 0.5;
    return 1.0*n/(n+1)+ dq3(n-1);
}
// /*
// buoc 1: BC xay ra khi n=1 return 0.5
// buoc 2: kq cua BC la dq2(1)= 0.5
// buoc 3: truoc BC la n=2, kq la dq2(2)=dq2(1)+ 2/3
// buoc 4: truoc th buoc 3 la n=3, kq la dq2(3)=dq2(2)+dq2(1)+3/4
// */
// 2d
float dq4(int n){
    if(n==0) return 2;
    if(n==1) return 3;
    return 6*dq4(n-1)+9*dq4(n-2);
}
// /*
// buoc 1: BC xay ra khi n=0 return 2 va n=1 return 3 
// buoc 2: kq cua BC la dq3(0)= 2, dq3(1)=3
// buoc 3: truoc BC la n=2, kq la dq2(2)=6*dq4(1)+8*dq4(0) 
// buoc 4: truoc th buoc 3 la n=3, kq la dq4(3)=6*dq2(2)+8*dq2(1)
// */
void main(){
    int n;
    scanf("%d", &n);
    float r1=dq1(n);
    float r2=dq2(n);
    float r3=dq3(n);
    float r4=dq4(n);
    printf("%0.3f", r1);
} 



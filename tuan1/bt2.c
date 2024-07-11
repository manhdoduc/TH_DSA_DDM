#include<stdio.h>
#include<string.h>
int main(){
    //khai bao mang luu chuoi nhap vao
    char strA[1000];
    scanf("%s\n", &strA);
    //bien crt luu gia tri can tim
    char crt;
    scanf("%c",&crt);
    //k de so sanh co tim thay ky tu crt
    int k=0;
    for(int i=0;i<strlen(strA);i++){
        //so sanh tung vi tri co bang crt (ko quan tam in hoa hay thuong) 
        if(strA[i]==crt||strA[i]+32==crt||strA[i]-32==crt){
            printf("Found %c at %d\n", crt, i);
            k++; // k tang gia tri khi co ky tu giong crt
        } 
    } 
    //so sanh k=0 thi ko tim thay
    if(k==0) printf("Not found!");
}
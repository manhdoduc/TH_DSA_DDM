#include<stdio.h>
#include<string.h>
//ham so sanh 2 chuoi co giong nhau tra ve 1, khac nhau tra ve 0
int searchStr(char *a,char *b){
    int i=0;
    while(a[i]!='\0'&&b[i]!='\0'){
        if(a[i]!=b[i]){
            return 0;
        } i++;
    } return 1;
}
int main(){
    //nhap gia tri dau vao 
    int n,k;
    scanf("%d",&n);
    scanf("%d\n",&k);
    char str[n][k+1];
    for(int i=0;i<n;i++){
        scanf("%s\n", &str[i]);
    }
    //chuoi can so sanh
    char strC[k+1];
    scanf("%s", &strC);
    strC[k]='\0';
    //gia tri found dung de biet co tim thay chuoi strC
    int found=0;
    for(int i=0;i<n;i++){
        //so sanh tung chuoi con cua str xem co tim thay strC khong        
            if(searchStr(str[i], strC)==1){
                printf("Found %s at %d", strC, i);
                found=1;// found =1 khi tim thay chuoi strC
                break;
            }
    }
    //khong tim thay in ra Not found
    if(found==0) printf("Not found");
}
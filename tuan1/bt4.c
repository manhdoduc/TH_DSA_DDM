#include<stdio.h>
#include<string.h>
void insertChar(char str[], int* n, char key, int index) {
    (*n)++;
    for (int i = *(n)-1; i > index; i--) {
        str[i] = str[i - 1];
    } 
    str[index] = key;
}
int main(){
    char strA[1000];
    scanf("%s\n",&strA);
    char crt;
    scanf("%c",&crt);
    int k;
    scanf("%d",&k);
    int n=strlen(strA);
    insertChar(strA, &n, crt, k);
    for(int i=0;i<n;i++){
        printf("%c",strA[i]);
    }
}
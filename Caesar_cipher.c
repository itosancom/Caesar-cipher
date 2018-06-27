#include<stdio.h>
#include<string.h>
#include<ctype.h>

int key;
char enc(char text,int key),dec(char text,int key);
char str[100],strP[100];
void input(),output();

int main(){
    char tmp;
    int d='a'-'A';

    printf("Select Mode--\n");
    printf("[a]Encription\n");
    printf("[b]Decryption\n");
    printf("[e]Exit\n");
    printf("Mode Select>");
    scanf("%c",&tmp);

    if(tmp=='a'){
        input();
        for(int i=0;i<strlen(str);i++){
            strP[i]=enc(str[i],key);
        }
        output();
    }
    else if(tmp=='b'){
        input();
        for(int i=0;i<strlen(str);i++){
            strP[i]=dec(str[i],key);
        }
        output();
    }
    else if(tmp=='e'){
        return 0;
    }
    else{
        printf("Error\n");
    }
}

void input(){
    printf("Input Text>");
    scanf("%s",str);
    printf("Input key>");
    scanf("%d",&key);
    for(int i=0;i<strlen(str);i++){
        str[i]=tolower(str[i]);
    }
}

void output(){
    printf("OK！\n");
    printf(">>>%s\n",strP);
}

char enc(char text,int key){
    text+=key;
    return text;
}

char dec(char text,int key){
    text-=key;
    return text;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* getIp(char* ip);
void whichClasses(char* ip);
int dotNumber(const char *str, char ch);

int main(){
    char* ip=getIp(ip);
    int number=dotNumber(ip,'.');
    
    if(number==3)
        whichClasses(ip);
    else{
        printf("It's not an IPv4 adress!!\n");
        exit(1);
    } 
    return(0);
}

void whichClasses(char* ip){
    char* firstBytes=strtok(ip,".");
    char* secondtBytes=strtok(NULL,".");
    char* thirdBytes=strtok(NULL,".");
    char* fourthBytes=strtok(NULL,".");

    int firstByte=0;
    int secondtByte=0;
    int thirdByte=0;
    int fourthByte=0;


    firstByte=atoi(firstBytes);
    secondtByte=atoi(secondtBytes);
    thirdByte=atoi(thirdBytes);
    fourthByte=atoi(fourthBytes);

    if((firstByte>=0 && firstByte<=255) && (secondtByte>=0 && secondtByte<=255) && (thirdByte>=0 && thirdByte<=255) && (fourthByte>=0 && fourthByte<=255)){
        if(firstByte >= 0 && firstByte <= 127)
            printf("It's a A classe\n");
        if(firstByte > 127 && firstByte <= 191)
            printf("It's a B classe\n");
        if(firstByte > 191 && firstByte <= 223)
            printf("It's a C classe\n");
        if(firstByte > 223 && firstByte <= 239)
            printf("It's a D classe\n");
    }    
    else
        printf("This ip that you enter is not an ip adress!!\n");
}

int dotNumber(const char *str, char ch){
    int count = 0;
    while(*str){
        if(*str == ch) {
            count++;
        }
        str++;
    }
    return(count);
}

char* getIp(char* ip){
    ip=malloc(255*sizeof(char*));
    ask:
    printf("Enter an IPv4 adress:");
    scanf("%s",ip);
    for(int i=0 ; i<strlen(ip) ; i++){
        if(ip[i]!='.'&&strchr("0123456789",ip[i])==NULL)
            goto ask;
    }
    return(ip);
}

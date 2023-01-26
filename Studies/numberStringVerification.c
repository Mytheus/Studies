#include <stdio.h>
#include <string.h>

/*
    NUMBER TYPE VERIFICATION PROGRAM
    Must recieve a number and tell what is the the type of the given number.
    Made entirely based on the ascii table.
*/

int isItANumber(char number[]){
    int afterDot = 0;
    for (int i = 0; i < strlen(number); i++){
        if (number[i]<47 || number[i]>57){
            if (number[i]!='.' && number[i]!=','){
                if(number[i]=='-' && i!=0){
                    return 0;
                }
            }
            else{
                if (afterDot){
                    return 0;
                }
                afterDot = !afterDot;
            }
        }
    }
    return 1;
}
int isItRational(char number[]){
    for (int i = 0; i < strlen(number); i++)
    {
        if (number[i]=='.' || number[i]==','){
            return 1;
        }
    }
    return 0;
}

int isItInteger(char number[]){
    if(!isItRational(number)){
        return 1;
    }
    return 0;
}

int isItNatural(char number[]){
    if(!isItRational(number) && number[0]!='-'){
        return 1;
    }
    return 0;
}

void numberType(char number[]){
    if (isItNatural(number)){
        printf("It is a natural number.\n");
    }

    if (isItInteger(number)){
        printf("It is a integer number.\n");
    }

    if (isItRational(number)){
        printf("It is a rational number.\n");
    }
}


int main(){
    char number[100];
    printf("Enter a number: ");
    scanf("%s",number);
    if (!isItANumber(number)){
        printf("The input you gave is not a number.\n");
    }
    else{
        numberType(number);
    }
    return 0;
}
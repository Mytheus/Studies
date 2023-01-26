#include <stdio.h>
#include <string.h>

/*
    NAME VERIFICATION PROGRAM
    RULES:
        - Must be letters and spaces only
        - Must have at least one character
        - Must not begin with space or a lowercased letter
    Made entirely based on the ascii table.
*/


int isThisCharALetter(char target){
    if (target<65 || (target>90 && target<97) || target>122){
        return 0;
    }
    return 1;
}

int isThisCharASpace(char target){
    if (target==32) return 1;
    return 0;
}

int isThisLetterUppercased(char target){
    if (isThisCharALetter(target)){
        if (target>64 && target<91){return 1;}
    }
    return 0;
}

int isEmpty(char string[]){
    return (strlen(string)>0?0:1);
}
int isThisNameValid(char name[]){
    //if (isEmpty(name)) return 0; //C will not capture empty strings
    //if (isThisCharASpace(name[0])) return 2; //C does not capture the space if a String starts with it.
    if (!isThisLetterUppercased(name[0])) return 3;
    for (int i = 0; i < strlen(name); i++){
        if (!isThisCharALetter(name[i]) && !isThisCharASpace(name[i])){
            return 4;
        }
    }
    return 1;
}

void getFirstName(char fullName[], char firstName[]){
    for (int i = 0; i <= strlen(fullName); i++)
    {
        if (isThisCharASpace(fullName[i])){
            firstName[i] = '\0';
            return;
        }
        else{
            firstName[i] = fullName[i];
        }
    }
    
}
int main(){
    int loop = 1;
    while(loop)
    {
        char name[50];
        char firstName[30];
        printf("Enter a valid name: ");
        scanf(" %[^\n]s", name);
        switch (isThisNameValid(name))
        {
        case 0:
            printf("Error: the name must not be empty.\n");
            break;
        case 2:
            printf("Error: the name must not begin with space.\n");
            break;
        case 3:
            printf("Error: the name must begin with an uppercased letter.\n");
            break;
        case 4:
            printf("Error: the name must have only letters and spaces.\n");
            break;
        default:
            getFirstName(name, firstName);
            printf("Hello, %s!\n", firstName);
            loop=!loop;
            break;
        }
    }
    
    
    
    return 0;
}
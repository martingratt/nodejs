#include <stdio.h>
#include <string.h>

main(){
    char satz[100];
    gets(satz);
    for (int i = 0; i < strlen(satz); i++){
        if (satz[i] == ' '){
            printf("\n");
        } else
        {
            printf("%c", satz[i]);
        }
        
    }
}
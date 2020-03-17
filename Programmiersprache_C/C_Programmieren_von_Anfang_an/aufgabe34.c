#include <stdio.h>
#include <string.h>

main(){

char satz[80];
printf("Bitte einen Satz eingeben!: ");
gets(satz);
int count = 0;
for (int i = 0; i < strlen(satz); i++){

if (satz[i] == 'e'){

count++;

}
}
printf("%i", count);
}
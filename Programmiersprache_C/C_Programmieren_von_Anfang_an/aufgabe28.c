#include <stdio.h>

void beep(int);



main(){

    int eingabe;
    printf("\n Bitte geben Sie die Anzahl der Töne ein: ");
    scanf("%i", &eingabe);
    beep(eingabe);
    
}

void beep (int eingabe){
    printf("\n Eingabe: %i", eingabe);
    int a;
    for (a = 1; a<=eingabe; a++){
        printf("\a");
        printf("\n %i. Ton", a);
    }
}

/*
double d_abs(double a){

if (a < 0) {
    a = a * -1;
}

return a;

}*/
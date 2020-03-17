#include <stdio.h>

double d_abs(double);



main(){
    double eingabe, rueckgabe;
    printf("\n Bitte geben Sie eine Zahl ein: ");
    scanf("%lf", &eingabe);
    rueckgabe = d_abs(eingabe);
    printf("\n Zahl ohne Vorzeichen: %lf", rueckgabe);

}

double d_abs(double a){

if (a < 0) {
    a = a * -1;
}

return a;

}
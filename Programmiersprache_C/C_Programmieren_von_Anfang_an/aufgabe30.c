#include <stdio.h>
#include <math.h>

double hoch (double, int);

main(){

    double a = 2;
    int b = 4;

    double ergebnis = hoch(a, b);

    printf("\n Ergebnis: %lf", ergebnis);

}

double hoch (double wert, int potenz){

    printf("\n Potenz: %i, Wert: %lf", potenz, wert);

    if (potenz == 0 || wert == 1 || potenz <= 0) {
        return -1.0;
    }
    else
    {
        return pow(wert, potenz);
    }
    
}
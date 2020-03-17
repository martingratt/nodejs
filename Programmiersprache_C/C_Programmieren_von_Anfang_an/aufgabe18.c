#include <stdio.h>

main(){
    int zeile,spalte;
    for (zeile = 20; zeile >=1; zeile = zeile - 1) {
        for (spalte = 1; spalte <= zeile; spalte++)
            printf("*");
        printf("\n");
    }
}
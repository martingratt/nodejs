#include <stdio.h>
main(){
    int a,b,ergebnis;
    printf("\nWahreheitstabllen\n");
    printf("\nA \tB \tErgebnis");
    a=0;b=0;ergebnis=!(a&&!b);
    printf("\n%i \t%i \t%i", a,b,ergebnis);
    a=0;b=1;ergebnis=!(a&&!b);
    printf("\n%i \t%i \t%i", a,b,ergebnis);
    a=1;b=0;ergebnis=!(a&&!b);
    printf("\n%i \t%i \t%i", a,b,ergebnis);
    a=1;b=1;ergebnis=!(a&&!b);
    printf("\n%i \t%i \t%i", a,b,ergebnis);

}
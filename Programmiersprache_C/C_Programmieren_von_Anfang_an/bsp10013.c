#include <stdio.h>

main(){
    float temperatur;
    printf("\nTemperaturrechner");
    printf("\nBitte Grad Celsius eingeben: ");
    scanf("%f", &temperatur);
    if (temperatur >= 273.15){
        printf("\n%.2f Grad Celsius sind %.2f K", temperatur, temperatur + 273.15);
    }
    else
    {
        printf("\nDiese Temperatur gibt es nicht!");
    }
    
    
}
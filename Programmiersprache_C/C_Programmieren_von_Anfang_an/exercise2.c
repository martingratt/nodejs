#include <stdio.h>

int computerid = 0;
int modulo = 0;
char key [11];
int value1 = 0;
int value2 = 0;
int value3 = 0;


int calcModulo (int computerid);
int calcValue1(int modulo);
int calcValue2(int value1, int modulo);
int calcValue3(int value2, int modulo);


main() {

    printf("\nPlease provide a unique computer id with 10 digits: ");
    scanf("%i", &computerid);
    modulo = calcModulo(computerid);

    value1 = calcValue1(modulo);
    value2 = calcValue2(value1, modulo);
    value3 = calcValue3(value2, modulo);

    printf("\n---------------");
    printf("\nYour ComputerID: %i", computerid);
    printf("\nIhr Key ist: %i-%i-%i", value1,value2,value3);

}

int calcModulo (int computerid){

    int sub = 10.0;
    int addedModulo = 0;
    int modulo = 0;

    while (computerid >= 1)

    {
        computerid = computerid / sub;

        modulo = computerid % sub;

        addedModulo = addedModulo + modulo;
    
    }

    printf("\nAddedmodulo: %i ", addedModulo);

    return addedModulo;
}

int calcValue1(int value1){

int oldmodulo = value1;

while (value1 < 101)
{
    value1 = value1 + (oldmodulo * 2);
}

return value1;

}

int calcValue2(int value1, int modulo){

    int value2 = value1 + modulo;

    return value2;

}

int calcValue3(int value2, int modulo){

    int value3 =  value2 + modulo - 1;

    return value3;

}


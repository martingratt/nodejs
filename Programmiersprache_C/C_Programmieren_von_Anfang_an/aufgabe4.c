#include <stdio.h>
#include <string.h>
#include <stdint.h>

int userlaenge;
char password[9];
char lastGeneratedCharacter = 0;
char username[100];
int passwordLetterCounter = 0;

uint32_t multiply(uint32_t a, uint32_t b);
uint32_t hi(uint32_t x);
uint32_t lo(uint32_t x);
  
int firstCharacterOfPassword(char *username){
	printf("\nUsername1: %s", username);

	int n1 = username[0];
	int n2 = username[1];
	printf("\nN 1: %x", n1);
	printf("\nN 2: %x", n2);
	
	int c1 = n1 + n2;

	printf("\nChar 1: %x", c1);

	//int c2 = c1 * 0x2c0b02c1;
	//printf("\nChar 2: %x", c2);

	uint32_t c2 = multiply(c1, 0x2c0b02c1);
	printf("\nChar 2: %x", c2);

	//hier das erste byte vier Stellennach rechts verschieben

	int c3 = c2 >>4;
	printf("\nChar 3: %x", c3);

	//int c3 = 2;
	

	int c4 = c3 * 0x5d;
	printf("\nChar 4: %x", c4);

	int c5 = c1 - c4;
	printf("\nChar 5: %x", c5);

	int c6 = c5 + 0x21;
	char c7 = c6;
	printf("\nChar 6: %x", c6);

	lastGeneratedCharacter = c2;
	
	passwordLetterCounter++;

	return c6;

	
	

}

int nCharacterOfPassword(int stelle, const char *username, int lastGenerated){
	printf("\nUsername: %s", username);

	printf("\nStelle: %i", stelle);

	printf("\nLast Generated: %x", lastGenerated);

	uint32_t n1 = username[stelle];

	//int n1 = username[stelle];
	printf("\nN 1: %c", n1);

	int c1 = n1 * 4;
	printf("\nC1: %x", c1);
	printf("\nLastGenerated: %x", lastGenerated);
	int c2 = c1 + lastGenerated;
	printf("\nC2: %x", c2);
	/*int c3 = c2 * 0x2c0b02c1;
	printf("\nC3: %x", c3);
	*/

	uint32_t c3 = multiply(c2, 0x2c0b02c1);
	printf("\nC3: %x", c3);

	//hier das erste byte vier Stellennach rechts verschieben

	int c4 = c3 >>4;
	printf("\nC4: %x", c4);
	//hier das erste byte vier Stellen nach rechts verschieben

	/*int c4 = 4;
	printf("\nC4: %x", c4);
	*/

	int c5 = c4 * 0x5d;

	printf("\nC5: %x", c5);

	int c6 = c2 - c5;

	printf("\nC6: %x", c6);

	int c7 = c6 + 0x21;

	printf("\nC7: %x", c7);
	
	return c7;

	lastGeneratedCharacter = c7;
}

int lastCharacterOfPassword(int lastGenerated, uint32_t temp){
	
	uint32_t c1 = multiply(temp, 0x2c0b02c1);

	int c2 = c1 >>4;

	int c3 = c2 * 0x5d;

	int c4 = temp - c3;

	int c5 = c4 + 0x21;

	return c5;

}





main() {

	

	printf("\nBitte Usernamen eingeben: ");
	scanf("%s", &username);
	printf("\nUsername: %s", username);
	userlaenge = strlen(username);
	printf("\nLaenge Username: %d ", userlaenge);

	int n1 = firstCharacterOfPassword(username);
	printf("\nUsername3: %s", username);
	lastGeneratedCharacter = n1;
	printf("\nUsername4: %s", username);
	password[0] = n1;
	printf("\nErster Buchstabe: %c", password[0]);
	printf("\nUsername5: %s", username);

	/*

	for (int i = 1; i<=userlaenge; i++) {
		printf("\nNumber: %i", i);
		int nCharacter = nCharacterOfPassword(i, username, lastGeneratedCharacter);
		password[i] = nCharacterOfPassword;
		printf("\nNächster Buchstabe: %c", password[i]);

	}
	*/

	//for (int i = 1; i<=10; i++) {

	

	for (int i = 1; i<=userlaenge-1; i++) {
		printf("\n---------------------");
		printf("\nNummer: %i", i+1);
		printf("\nBuchstabe im Username: %c", username[i]);
		printf("\n---------------------");
		int nCharacter = nCharacterOfPassword(i, username, lastGeneratedCharacter);
		password[i] = nCharacter;
		lastGeneratedCharacter = nCharacter;
		printf("\nNaechster Buchstabe: %c", password[i]);
		passwordLetterCounter++;

	}

	if (userlaenge < 10){

		printf("\nIch bin hier");


		for (int i = userlaenge; i < 10; i++){

			//Addition des Counters mit dem Counter
			//Subtraktion des Counters von 10
			//Left shift der Addition um den Wert der Subtraktion
			uint32_t temp1 = ((i+0x41)<<(10-i));
			
			//
			uint32_t temp2 = password[i-1];
			uint32_t temp3 = temp1 + temp2;

			printf("\nTemp3: %i", temp3);

			int nCharacter = lastCharacterOfPassword(lastGeneratedCharacter, temp3);
			password[i] = nCharacter;
			lastGeneratedCharacter = nCharacter;
			passwordLetterCounter++;
			printf("\nNaechster Buchstabe: %c", password[i]);
				
			printf("\n Passwort: %c", password[i]);

			printf("\n Passwort: %s", password);

			printf("\nIch bin dort2");

		}


		

	}
	
	printf("\n-----------------------------------");
	printf("\nCredentials: ");
	printf("\n Username: %s", username);

	printf("\n Passwort: %s", password);


	/*
	int n2 = nCharacterOfPassword(1, username, n1);
	password[1] = n2;
	printf("\nZweiter Buchstabe: %c", password[1]);
	
*/



}

uint32_t multiply(uint32_t a, uint32_t b) {
    
    uint32_t s0, s1, s2, s3; 

    uint32_t x = lo(a) * lo(b);
    s0 = lo(x);

    x = hi(a) * lo(b) + hi(x);
    s1 = lo(x);
    s2 = hi(x);

    x = s1 + lo(a) * hi(b);
    s1 = lo(x);

    x = s2 + hi(a) * hi(b) + hi(x);
    s2 = lo(x);
    s3 = hi(x);

    uint32_t result = s1 << 16 | s0;
    uint32_t carry = s3 << 16 | s2;
    return carry;
}

/*Split the number into half and return the higher 16bits*/
uint32_t hi(uint32_t x) {
    return x >> 16;
}
/*Return the second half, also the lower 16bits*/
uint32_t lo(uint32_t x) {
    return ((1L << 16) - 1) & x;
}



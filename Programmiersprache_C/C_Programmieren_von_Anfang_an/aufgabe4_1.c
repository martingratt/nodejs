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
  
//Dieser Funktion wird nur für die Erstellung des ersten Buchstaben des Passworts aufgerufen
int firstCharacterOfPassword(char *username){

	//Erste Stelle Usernamen
	int n1 = username[0];
	//Zweite Stelle Usernamen
	int n2 = username[1];
	//Addidtion der beiden Hexwerte
	int c1 = n1 + n2;

	//Multiplikation mit 0x2c0b02c1
	uint32_t c2 = multiply(c1, 0x2c0b02c1);

	//Verschiebung um 4 Stellen nach rechts (right shift) 
	int c3 = c2 >>4;

	//Multiplikation mit 0x5d
	int c4 = c3 * 0x5d;

	//Ergebnis wird von der Addition der ersten beiden Buchstaben subtrahiert
	int c5 = c1 - c4;

	//Addition mit 0x21
	int c6 = c5 + 0x21;
	
	char c7 = c6;

	//Ändern des letzten gespeicheten Buchstabens
	lastGeneratedCharacter = c2;
	
	passwordLetterCounter++;

	return c6;

}

//Dieser Funktion wird für die Anzahl der Buchstaben des Usernamens aufgerufen
int nCharacterOfPassword(int stelle, const char *username, int lastGenerated){

	//Ermittlung des nächsten Buchstabens
	uint32_t n1 = username[stelle];

	//Multiplikation des Hexwertes des Buchstabens mit 4
	int c1 = n1 * 4;
	
	//Addition des Ergebnisses mit dem letzten generierten Buchstaben
	int c2 = c1 + lastGenerated;

	//Multiplikation des Ergebnisses mit 0x2c0b02c1
	uint32_t c3 = multiply(c2, 0x2c0b02c1);

	//Höhere 16 bit des Ergebnisses werden wird 4 bits nach rechts geshiftet
	int c4 = c3 >>4;

	//Multiplikation des Ergebnisses mit 0x5d
	int c5 = c4 * 0x5d;

	//Subtraktion des vorherigen Ergebnisses von Ergebnis von C2
	int c6 = c2 - c5;

	//Addition mit 0x21
	int c7 = c6 + 0x21;

	//Rückgabe des generierten Charackters	
	return c7;

	//Ändern des letzten gespeicheten Buchstabens
	lastGeneratedCharacter = c7;
}

int lastCharacterOfPassword(int lastGenerated, uint32_t temp){

	//Multiplikation des übergebenen Betrages mit 0x2c0b02c1	
	uint32_t c1 = multiply(temp, 0x2c0b02c1);
	
	//Höhere 16 bit des Ergebnisses werden wird 4 bits nach rechts geshiftet
	int c2 = c1 >>4;

	//Multipliktion mit 0x5d
	int c3 = c2 * 0x5d;

	//Subratkion des letzten Ergebnisses mit an die Funtion übergebenen Wert
	int c4 = temp - c3;

	//Addition des letzten Ergebnis mit 0x21
	int c5 = c4 + 0x21;

	//Rückgabe des hexwert generierten Charackters
	return c5;

}

main() {

	printf("\nBitte Usernamen eingeben: ");
	scanf("%s", &username);
	userlaenge = strlen(username);

	//Generierung des ersten Charackters des Passworts
	int n1 = firstCharacterOfPassword(username);
	
	lastGeneratedCharacter = n1;
	
	password[0] = n1;	

	//Generierung des zweiten Charackters des Passworts bis zur länge des Usernamens
	for (int i = 1; i<userlaenge; i++) {
		
		//Erzeugung des Charackters durch Methodenaufruf
		int nCharacter = nCharacterOfPassword(i, username, lastGeneratedCharacter);

		//Speichern des Charackters in das Passwort
		password[i] = nCharacter;

		//Speichern als letzten generierten Wert
		lastGeneratedCharacter = nCharacter;

		passwordLetterCounter++;

	}

	if (userlaenge < 10){

		for (int i = userlaenge; i < 10; i++){

			printf("\nFuntkion 3");

			//Addition des Counters mit dem Counter
			//Subtraktion des Counters von 10
			//Left shift der Addition um den Wert der Subtraktion
			uint32_t temp1 = ((i+0x41)<<(10-i));
			
			//hohlen des letzten generierten Charackter des Passworts
			uint32_t temp2 = password[i-1];
			
			//Addition des Ergebnis des left shifts mit dem Charackters
			uint32_t temp3 = temp1 + temp2;

			//Übergabe in die Funktion der Characktergenerierung
			int nCharacter = lastCharacterOfPassword(lastGeneratedCharacter, temp3);
			
			//Speichern des generierten Charackters 
			password[i] = nCharacter;

			lastGeneratedCharacter = nCharacter;

			passwordLetterCounter++;

		}

	}

	//Ausgabe des Usernamens und Passworts
	printf("\n-----------------------------------");
	printf("\nCredentials: ");
	printf("\n Username: %s", username);
	printf("\n Passwort: %s", password);
	printf("\n-----------------------------------");

}

uint32_t multiply(uint32_t a, uint32_t b) {
	
	//https://stackoverflow.com/questions/1815367/catch-and-compute-overflow-during-multiplication-of-two-large-integers
    
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
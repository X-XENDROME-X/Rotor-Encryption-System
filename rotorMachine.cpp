#include  <fstream>
#include  <iostream>
#include  <ctype.h>
#include  "rotorMachine.h"
#include  <stdio.h>

// Below uses the standard namespace
using namespace  std;

// Below reads a file and write its contents with XOR 42 to "rotors.ini"
void  buildIni(char* filename) {

	// Below is the input file stream to read the provided file.
	ifstream ReadFile;
	// Below opens the input file. 
	ReadFile.open(filename);

	// Below opens the output file stream to write to "rotors.ini".
	ofstream WriteFile;
	// Below creates or overwrite "rotors.ini".
	WriteFile.open("rotors.ini");


	int IntVal;
	//Below XORs each integer read from the input file with 42 and write to "rotors.ini". 
	while (ReadFile >> IntVal) { 
	        WriteFile<<(IntVal^42)<<endl;
	}  

	//Below closes the input file.
	ReadFile.close();
	//Below closes the output file.
    	WriteFile.close();

}


// Below builds rotor configurations from "rotors.ini"
void  buildRotors(int rotor1[28] , int rotor2[28]) {
	
	//Below inputs file stream to read "rotors.ini".
	ifstream ReadRotor;
        ReadRotor.open("rotors.ini");

	// Below gives an error if it is not opened
	if (!ReadRotor.is_open()) {
		cout << "Error: Rotor machine not initialized. Run with -i option and provide an appropriate configuration file." << endl;
	}

	int IntVal;
	int x =0;

	while (ReadRotor>>IntVal) {
		//Below XORs the value with 42 to recover the original value.
		IntVal = IntVal ^ 42;
        	
		//Below fills the first rotor's configuration.
		if (x < 28) {

            		rotor1[x] = IntVal;

		//Below fills the second rotor's configuration.
        	}  else if (x < 56) {

            		rotor2[x - 28] = IntVal;

        	}	
        	++x;
	}
}

// Below is used to rotate the rotor to the right
void  rotateRotorRight(int rotor[28]) {

	// Below stores the last element of the rotor	
	int Element = rotor[27];
	int x =27;

	while (x>=0){
		// Below shifts each element to the right.
		rotor[x] = rotor[x-1];
		--x;
	}
	// Below places the last element at the beginning.
	rotor[0] = Element;
}

// Below is used to rotate the rotor to the left
void  rotateRotorLeft(int rotor[28]) {

	// Below stores the first element of the rotor 
	int Element = rotor[0];
        int x =0;

        while (x<28) {
		// Below shifts each element to the left
                rotor[x] = rotor[x+1];
                ++x;
        }
	 // Below places the first element at the end.
        rotor[27] = Element;
}

// Below sets rotor 1 to a specified position
void  setRotor1(int rotor[28], int rotations) {
	
	int x=0;
	
	// Below rotates the rotor to the right by the specified number of positions.
	while (x < rotations) {
	
		rotateRotorRight(rotor);
		++x;
	}
}

// Below sets rotor 2 to a specified position
void  setRotor2(int rotor[28], int rotations) {
        
	int x=0;
        
	// Below rotates the rotor to the right by the specified number of positions.
	while (x < rotations) {
	     
	        rotateRotorLeft(rotor);
                ++x;
        }
}


// Below converta a character to an index for rotor mapping
int  charToIndex(char convert) {

	//Below converts the character to uppercase.
	convert = toupper(convert);
	
	//Below  checks if the character is a letter.
	if (convert <= 'Z' && convert >= 'A') {	
		// Returns the index of the character.
		return convert - 'A';
	
	//Below checks if the character is a period.
	}  else if (convert == '.') {		
		// Returns the index for a period.
		return 27;
	
	//Below checks if the character is a space.
	}  else if (convert == ' ') {
		// Returns the index for a space.
		return 26;
	}
       	return -1;	
}

// Below converts an index to a character for rotor mapping
char  indexToChar(int convert) {

	// Below checks if the index represents a letter.
	if (convert < 26 && convert >= 0) {
		// Below converts the index to the corresponding letter.
		return convert + 'A';

	//Below checks if the index represents a period.
	} else if (convert == 27) {
		// Returns a period.
		return '.';	

	//Below checks if the index represents a space.
	} else if (convert == 26) {
		// Returns a space.
		return ' ';
        }
	return ' ';
}

// Below is a function that encrypts a file using the rotor machine
void  encryptFile(ifstream &infile, ofstream &outfile, int rotor1[28], int rotor2[28]) {
	
	//Below  creates a character array to store lines read from the input file.
	char buffer[256];
	
	//Below loops through each line of the input file.
        while(infile.getline(buffer , sizeof(buffer))){		
		// Below loops through each character in the current line.
		for (int x = 0 ; buffer[x] != '\0'; ++x){
		
			//Below gets the current character from the input line.
			char Input = buffer[x];
			//Below converts the character to an index using rotor mapping.
			int Index = charToIndex(Input);
	                   
			 //below loops through the rotor configurations to find the matching character.
			 for(int y = 0 ; y < 28 ; y++){
			
		                //Below converts the character in rotor1 at the calculated index matches rotor2 at position y.
        		         if(rotor1[Index] == rotor2[y]){
					//Below converts the rotor2 position (y) back to a character.
                	         	char Encrypted = indexToChar(y);
                        		//Below writes the encrypted character to the output file.
				        outfile<<Encrypted;

					//Below rotates rotor1 to the right for the next character.
                                        rotateRotorRight(rotor1);
					//Below rotates rotor2 to the left for the next character.
                                        rotateRotorLeft(rotor2);

					//Below exits the inner loop once the character is found in rotor configurations.
                                      	break;
                                }
                        }
        	}
	
                if(!infile.eof()){
			// If there are more lines in the input file, then below  adds a newline character to separate lines in the output file.
                        outfile << '\n';
                }
        }
}

// Below defines a function to decrypt a file using the rotor machine
void  decryptFile(ifstream &infile, ofstream &outfile, int rotor1[28], int rotor2[28]) {
	
	//Below defines a character buffer to store lines from the input file.
	char buffer[256];

	// Below loops through each line in the input file.
	while (infile.getline(buffer , sizeof(buffer))){

		// Below loops through each character in the current line.
		for (int x = 0; buffer[x] != '\0'; ++x){
	
			//Below gets the current character from the buffer.
			char Input = buffer[x];
			//Below converts the character to an index.
			int Index = charToIndex(Input);
			
			//Below loops through the rotor configurations.
			for(int y = 0 ; y < 28 ; y++){

                        	 //Below checks if the rotor configuration of rotor2 at the given index matches rotor1 at position 'y'.
				if(rotor2[Index] == rotor1[y]){
                         		
					//Below converts the rotor mapping index back to a character.
				       	char Decrypted = indexToChar(y);
                                	//Below  writes the decrypted character to the output file.
					outfile<<Decrypted;

					//Below rotates rotor1 to the right.
                                	rotateRotorRight(rotor1);
                                	//Below rotates rotor2 to the left.
					rotateRotorLeft(rotor2);

                                	break;
                        	}
                	}
		}
		//Below checks if we haven't reached the end of the input file.
		if(!infile.eof()){
			// Below writes a newline character to separate lines in the output file.
                        outfile << '\n';

                }
	}
}


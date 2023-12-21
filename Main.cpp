#include  <sstream>
#include  <iostream>
#include  <stdlib.h>
#include  <cstdlib>
#include  <cstring>

//Below includes the custom rotor machine header file
#include  "rotorMachine.h"


using namespace std;

int main(int argc , char** argv)  {

        int rotor1[28];
        int rotor2[28];
	
	//Below checks if the program was run with the "-i" option and a configuration file	
	if (argc == 3 && strcmp(argv[1] , "-i") == 0) {
		//Below initializes the rotor machine based on the configuration file
		buildIni(argv[2]);
	
	//Below checks if the program was run with the "-d" option, rotor configuration, and input/output files
	} else if (strcmp(argv[4] , "-r") == 0  && strcmp(argv[1] , "-d") == 0  &&  argc == 7) {
		
		//Below builds the rotor configurations
		buildRotors(rotor1 , rotor2);
        	
		//Below gets the starting position for rotor 1 and rotor 2 respectively
		int StartPos1 = atoi(argv[5]);
        	int StartPos2 = atoi(argv[6]);
        	
		//Below sets rotor 1 and rotor2 to their specified starting positions respectively
		setRotor1(rotor1 , StartPos1);
        	setRotor2(rotor2 , StartPos2);

		//Below opens an input file
		ifstream  infile(argv[2]);
        	
		//Below opens an output file
		ofstream  outfile(argv[3]);

		//Below decrypts the file using the rotor machine
		decryptFile(infile , outfile , rotor1 , rotor2);

	//Below checks if the program was run with the "-e" option, rotor configuration, and input/output files
	} else if (strcmp(argv[4] , "-r") == 0  && strcmp(argv[1] , "-e") == 0  &&  argc == 7) {

		//Below builds the rotor configurations
		buildRotors(rotor1 , rotor2);
		
		//Below gets the starting position for rotor 1 and rotor 2 respectively
		int StartPos1 = atoi(argv[5]);
		int StartPos2 = atoi(argv[6]);

		//Below sets rotor 1 and rotor2 to their specified starting positions respectively
		setRotor1(rotor1 , StartPos1);
		setRotor2(rotor2 , StartPos2);
			
		//Below opens an input file
		ifstream infile(argv[2]);

		//Below opens an output file
		ofstream outfile(argv[3]);

		//Below encrypts the file using the rotor machine
		encryptFile(infile , outfile , rotor1 , rotor2);
	
	//Below checks if the program was run with the "-d" option, rotor configuration, input/output files, and an initialization file
	} else if (strcmp(argv[4] , "-r") == 0  && strcmp(argv[1] , "-d") == 0  &&  strcmp(argv[7] , "-i") == 0  &&  argc == 9) {

		//below initializes the rotor machine based on the configuration file.
		buildIni(argv[8]);

		//Below builds the rotor configurations
		buildRotors(rotor1 , rotor2);

		//Below gets the starting position for rotor 1 and rotor 2 respectively
                int StartPos1 = atoi(argv[5]);
                int StartPos2 = atoi(argv[6]);

		//Below sets rotor 1 and rotor2 to their specified starting positions respectively
                setRotor1(rotor1 , StartPos1);
                setRotor2(rotor2 , StartPos2);

		//Below opens an input file
                ifstream  infile(argv[2]);

		//Below opens an output file
                ofstream  outfile(argv[3]);

		//Below decrypts the file using the rotor machine
		decryptFile(infile , outfile , rotor1 , rotor2);
		

	//Below checks if the program was run with the "-e" option, rotor configuration, input/output files, and an initialization file
	} else if (strcmp(argv[4] , "-r") == 0  && strcmp(argv[1] , "-e") == 0  &&  strcmp(argv[7] , "-i") == 0  &&  argc == 9) {

		//below initializes the rotor machine based on the configuration file.
		buildIni(argv[8]);
 		
		//Below builds the rotor configurations
                buildRotors(rotor1 , rotor2);

		//Below gets the starting position for rotor 1 and rotor 2 respectively
                int StartPos1 = atoi(argv[5]);
                int StartPos2 = atoi(argv[6]);

		//Below sets rotor 1 and rotor2 to their specified starting positions respectively
                setRotor1(rotor1 , StartPos1);
                setRotor2(rotor2 , StartPos2);

		//Below opens an input file
                ifstream  infile(argv[2]);
 
		//Below opens an output file
                ofstream  outfile(argv[3]);

		//Below encrypts the file using the rotor machine
       		encryptFile(infile , outfile , rotor1 , rotor2);
		 
	// If none of the above conditions are met, below displays an error message.
        } else  {

		cout << "Error: Rotor machine not initialized. Run with -i option and provide an appropriate configuration file." << endl;
		
	} 
        return 0;
}
                  

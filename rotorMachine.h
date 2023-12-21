#ifndef ROTORMACHINE_H
#define ROTORMACHINE_H

//Below includes the standard C++ file input/output library
#include  <fstream>

//below  uses the standard namespace
using namespace std;

//Below is the function to build the initial configuration of rotors based on a file
void buildIni(char *);

//Below is the function to set up the rotor wiring for encryption
void buildRotors(int[28] , int[28]);

// Below is the function to rotate the rotor to the right
void rotateRotorRight(int[28]);

// Below is the function to rotate the rotor to the left
void rotateRotorLeft(int[28]);

// Below is the function to configure the first rotor
void setRotor1(int[28], int);

// Below is the function to configure the second rotor
void setRotor2(int[28] , int);

// Below is the function to convert a character to an index
int charToIndex(char);

// Below is the function to convert an index to a character
char indexToChar(int);

// Below is function to encrypt a file using the rotor machine
void encryptFile(ifstream &, ofstream &, int[28], int[28]);

// Below is function to decrypt a file using the rotor machine
void decryptFile(ifstream &, ofstream &, int[28], int[28]);

#endif

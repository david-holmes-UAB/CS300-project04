/*
* File: main.cpp
* ------------------------------------
* Testing and run file for utilizing the Hamming Code functions.
*/

#include "hamming.h"
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // Array to hold inndividual bits
    int bits[7];

    // The current line in the file
    std::string currentLine = "";

    // File to be read in by the program
    std::ifstream file("hamwords.txt");
    std::string line; 
    while (getline(file,line)){
    for (int i = 0; i < 7; i++){
        
        bits[i] = atoi(&line[i])%2;

    }
    decodeHamming(bits);
    
}



    return 0;
}
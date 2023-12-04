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

    while (getline(file,currentLine)){
        int i = 0;
        for (char c : currentLine){
        
            bits[i] = (int) c - '0';
            i++;
        }
        decodeHamming(bits);
    
    }



    return 0;
}
/*
* File: hamming.cpp
* --------------------------------------
* File containing the implementation of the necessary Hamming code functions.
*/

#include "hamming.h"
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <algorithm>

// Variables

/* 
* The parity matrix for decoding Hamming words. 
* Courtesy of: https://en.wikipedia.org/wiki/Hamming(7,4)
*/
Eigen::MatrixXi parityMatrix {
    {1, 0, 1, 0, 1, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {0, 0, 0, 1, 1, 1, 1}
};

/* Matrix to decode the Hamming word. */
Eigen::MatrixXi decodingMatrix {
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1}
};

/* To0000000
1110000
1001100
0111100
0101010decodeHamming(bits)
1011010
1100110
0010110
1101001
0011001
0100101
1010101
1000011
0110011
0001111
1111111 store the matrix to do matrix multiplication */
Eigen::MatrixXi hammingCode(1, 7);

/* To store the final returned data */
int data[4];


// Functions

/* Attempt to decode and print results. */
void decodeHamming(const int (&bits)[7]) {
    hammingCode = fillMatrix(bits);

    /* local copy of the array */
    int bitCopy[7];
    std::copy (bits, bits + 7, bitCopy);
    /* 
    * Get locataion of a prospective error in the code.
    * If there is no error, this is -1
    */
    int errorLocation = hasError(hammingCode) - 1;

    if (errorLocation == -1) {
        /* TODO: hamming decoding */
    }
    else {
        hammingCode = fixHammingWord(hammingCode, errorLocation);
        bitCopy[errorLocation] = (bitCopy[errorLocation] == 0) ? 1 : 0;

        /* Check for if there is another error */
        errorLocation = hasError(hammingCode) - 1;
        if (errorLocation != -1) {
            std::cout << "Multiple error detected with input: ";
            for (int i : bitCopy) {
                std::cout << i;
            }
            std::cout << std::endl;
        } 
        else {
            /* TODO: hamming decoding */
        }
    }

    std::cout << "Temporary message. (Debug)" << std::endl;
}

/* Fill matrix with the data from the array. */
Eigen::MatrixXi fillMatrix(const int (&bits)[7]) {
    Eigen::MatrixXi newMatrix {
        {bits[0]},
        {bits[1]},
        {bits[2]},
        {bits[3]},
        {bits[4]},
        {bits[5]},
        {bits[6]}
    };

    return newMatrix;
}

/* Check to see if matrix has errors */
int hasError(const Eigen::MatrixXi &hamMatrix) {
    
}

/* Fixes an error at a given location in the hamming word matrix */
Eigen::MatrixXi fixHammingWord(Eigen::MatrixXi hamMatrix, int location) {

}

void printHamming(int bits[7]){
    for (int i = 0; i < 7; i++){
        std::cout<<bits[i];
    }
    std::cout << std::endl;
}
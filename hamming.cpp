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

/* To store the matrix to do matrix multiplication */
Eigen::MatrixXi hammingCode(7, 1);

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
        Eigen::MatrixXi decoded = decodingMatrix * hammingCode;
        data[0] = decoded(0, 0);
        data[1] = decoded(0, 1);
        data[2] = decoded(0, 2);
        data[3] = decoded(0, 3);

        for (int i : bitCopy) { std::cout << i; }
        std::cout << " decoded is: ";
        for (int i : data) { std::cout << i; }
        std::cout << std::endl;

    }
    else {
        hammingCode = fixHammingWord(hammingCode, errorLocation);
        bitCopy[errorLocation] = (bitCopy[errorLocation] == 0) ? 1 : 0;

        /* Check for if there is another error */
        errorLocation = hasError(hammingCode) - 1;
        if (errorLocation != -1) {
            std::cout << "Multiple errors detected with input: ";
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
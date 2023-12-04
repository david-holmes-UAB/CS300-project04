/*
* File: hamming.cpp
* --------------------------------------
* File containing the implementation of the necessary Hamming code functions.
*/

#include "hamming.h"
#include <eigen3/Eigen/Dense>
#include <iostream>

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
Eigen::MatrixXi hammingCode(1, 7);

/* To store the final returned data */
int data[4];


// Functions

/* Attempt to decode and print results */
void decodeHamming(const int (&bits)[7]) {

}
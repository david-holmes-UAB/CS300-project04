/*
* File: hamming.h
* ------------------------------------
* Outline/Declaration of functions used in implementing a Hamming(7, 4) code.
* Utilizes the Eigen library for multiple matrix operations.
*
* A Hamming word is a 7-bit data package, where three bits are parity bits, and the remaining 4 are data to be sent.
*/

#ifndef _hamming_h
#define _hamming_h

#include <eigen3/Eigen/Dense>

//! Decodes a Hamming word.
/*! Goes through the process of decoding a Hamming word defined by the contents of @param bits.
* @param bits An int array containing the seven individual bits of the word.
*/
void decodeHamming(const int (&bits)[7]);

//! Checks if an error is in the Hamming word.
/*! Checks the matrix representation of a Hamming word to see if an error is found in the bits.
* @param hamMatrix An Eigen 1 x 7 int matrix containing the bits of the word.
* @return The position in the matrix the error is at, if any. Returns 0 if there is no error.
*/
int hasError(const Eigen::MatrixXi &hamMatrix);

//! Corrects errors in a Hamming word.
/*! Fixes the error within the bits of the Hamming word if needed by changing the bits to maintain intended parity.
* @param hamMatrix An Eigen 1 x 7 int matrix containing the bits of the word.
* @param location The location of the error within the matrix.
* @return The fixed version of the input matrix.
*/
Eigen::MatrixXi fixHammingWord(Eigen::MatrixXi hamMatrix, int location);

//! Converts a Hamming word into a matrix.
/*! Fills an Eigen 1 x 7 matrix to represent the Hamming word.
* @param bits An int array containing the seven individual bits of the word.
* @return An Eigen 1 x 7 matrix filled using the contents of the array.
*/
Eigen::MatrixXi fillMatrix(const int (&bits)[7]);

/*! Prints out a 4 bit value using the digits from a dedicated internal array.
* @param bitData A 4 length integer array that together forms a represenation of a 4 bit value.
*/
void printData(const int (&bitData)[4]);

/*! \mainpage notitle
*
*   \section intro_sec Introduction
*   
*   This documentation details the usage of the Hamming class, which can be used to decode a pre-encoded
* Hamming(7, 4) word and correct any incorrect bits found within it. A Hamming word as defined by this class
* has 3 parity bits - one in the first and second digit places respectively, and one in the fourth digit place.
* The remaining four bits are the data to be transmitted.
* 
*   \section req_sec Requirements
*   
*   This library requires the Eigen library to be installed to utilize.
*
*   \section install_sec Installation
*   
*   Simply download the hamming.h and hamming.cpp files from the repository, and specify hamming.h in your include directives.
*
*   The repository can be found on GitHub \link https://github.com/david-holmes-UAB/CS300-project05/tree/main here.
*/



#endif
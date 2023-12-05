#include <iostream>
#include <assert.h>
#include <eigen3/Eigen/Dense>
#include <string>
#include "hamming.h"

int main(){
    /* Assorted test variables */
    int binarySix[7] {1, 1, 0, 0, 1, 1, 0};           // encoded 0110 as 1100110

    /* FillMatrix tests */
    // test 1
    int bits[7]{0,1,1,0,1,1,0};
    Eigen::MatrixXi fillTest {
        {0},
        {1},
        {1},
        {0},
        {1},
        {1},
        {0}
    };
    assert(("fillMatrix 1", fillMatrix(bits) == fillTest ));

    // test 2
    Eigen::MatrixXi binarySixMatrix {
        {1},
        {1},
        {0},
        {0},
        {1},
        {1},
        {0}
    };
    assert(("fillMatrix test 2; Input: 1100110", fillMatrix(binarySix) == binarySixMatrix));    


    /* hasError tests */

    // test 1
    assert(("hasError 1 error test", hasError(fillTest) != 0));

    // test 2
    int bits1[7]{1,1,1,0,0,0,0};
    auto errmatx = fillMatrix(bits1);
    assert(("hasError 0 errors", hasError(errmatx)==0));

    // test 3
    int errorInput[7] = {1, 1, 1, 0, 1, 0, 1};                  // encoded 1101 as 1010101; with error on 2nd bit
    Eigen::MatrixXi errorMatrix = fillMatrix(errorInput);
    assert(("hasError test 3; Input: 1110101; error on 2nd bit", hasError(errorMatrix)  == 2));

    // test 4  
    int errorInput2[7] = {0, 0, 1, 1, 1, 0, 1};                  // encoded 1001 as 0011001; with error on 5th bit
    errorMatrix = fillMatrix(errorInput2);
    assert(("hasError test 3; Input: 1110101; error on 2nd bit", hasError(errorMatrix) == 5));

    /* fixHamming tests */

    //test 1
    fillTest = fillMatrix({0,1,0,1,1,1,1});
    auto fix = fixHammingWord(fillTest,hasError(fillTest)-1);
    int bits3[7]{0,0,0,1,1,1,1};
    auto ans = fillMatrix(bits3);
    
    assert(("fixHamming 1 error >> output: ",(fix ==ans)));

    // test 2
    Eigen::MatrixXi sendData = fillMatrix({0, 1, 1, 0, 1, 1, 1});                    // 1011 encoded as 0110011, but with an error at bit 5.
    Eigen::MatrixXi correctData = fillMatrix({0, 1, 1, 0, 0, 1, 1});
    int location = hasError(sendData) - 1;
    assert(("fixHamming test 2; check if an error on 5th bit is corrected", fixHammingWord(sendData, location) == correctData));

    /* getData tests */
    
    // test 1; mimics a normal program run
    std::cout << "starting full simulation runs\n";
    Eigen::MatrixXi sixMatrix = fillMatrix(binarySix);
    Eigen::MatrixXi decoder {
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1}
    };
    if (hasError(sixMatrix) == 0) {
        decoder *= sixMatrix;
    }
    int testData[4] = {decoder(0, 0), decoder(1, 0), decoder(2, 0), decoder(3, 0)};
    assert(("getData test 1; Input: 1100110; Expected output: 0110", getData(testData) == std::string("0110")));


    std::cout << "all tests successful\n";


}
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
    assert(("hasError test 3; Input: 1110101; error on 2nd bit", hasError(errorMatrix) == 2));

    // test 4  
    int errorInput2[7] = {0, 0, 1, 1, 1, 0, 1};                  // encoded 1001 as 0011001; with error on 5th bit
    Eigen::MatrixXi errorMatrix2 = fillMatrix(errorInput2);
    assert(("hasError test 3; Input: 1110101; error on 2nd bit", hasError(errorMatrix2) == 5));

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
   
    Eigen::MatrixXi prodMatrix;

    if (hasError(sixMatrix) == 0) {
        prodMatrix = decoder * sixMatrix;
    }
    
    int testData[4] = {prodMatrix(0, 0), prodMatrix(1, 0), prodMatrix(2, 0), prodMatrix(3, 0)};
    assert(("getData test 1; Input: 1100110; Expected output: 0110", getData(testData) == std::string("0110")));

    // test 2
    Eigen::MatrixXi fulltest2 = fillMatrix({0,0,0,0,1,1,1});

    if (hasError(fulltest2) == 0){
        prodMatrix = decoder * fulltest2;
        std::cout << "this shouldn't be here\n";
    }else{
    
        prodMatrix = decoder * fixHammingWord(fulltest2,hasError(fulltest2)-1);
        
    }

    int testData2[4] ={prodMatrix(0, 0), prodMatrix(1, 0), prodMatrix(2, 0), prodMatrix(3, 0)};

    assert(("getData test 2; Input: 0000111; Expected output: 0111", getData(testData2) == std::string("0111")));
    std::cout << "all tests successful\n";


}
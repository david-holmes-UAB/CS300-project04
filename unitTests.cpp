#include<iostream>
#include<assert.h>
#include <eigen3/Eigen/Dense>
#include "hamming.h"
int main(){
    // FillMatrix test
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
    assert(("hasError 1 error test", hasError(fillTest) == 2));
    int bits1[7]{1,1,1,0,0,0,0};
    
    assert(("hasError 0 errors", hasError(fillMatrix(bits1))==0));

    assert(("fixHamming 1 error",(fixHammingWord(fillTest,hasError(fillTest))==fillMatrix({0,0,1,0,1,1,0}))));
    std::cout << "all tests successful\n";
}
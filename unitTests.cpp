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
    assert(("hasError 1 error test", hasError(fillTest) != 0));
    int bits1[7]{1,1,1,0,0,0,0};
    auto errmatx = fillMatrix(bits1);
    assert(("hasError 0 errors", hasError(errmatx)==0));
    auto fix = fixHammingWord(fillTest,hasError(fillTest));
    int bits3[7]{0,0,1,0,1,1,0};
    auto ans = fillMatrix(bits3);
    
    std::cout<< fix <<std::endl;
    assert(("fixHamming 1 error >> output: ",(fix ==ans)));
    std::cout << "all tests successful\n";
}
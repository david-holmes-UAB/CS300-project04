#include<iostream>
#include<assert.h>
#include <eigen3/Eigen/Dense>
#include <hamming.h>
int main(){
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
}
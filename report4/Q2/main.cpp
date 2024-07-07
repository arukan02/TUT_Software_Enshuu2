#include <iostream>
#include <Eigen/Dense>
#include <math.h>


int main (int argc, char *argv[]){
    Eigen::VectorXd a = Eigen::VectorXd::Zero(10);

    for(int i = 0; i < 10; i++)
        a(i) = i;
    
    for (int val : a){
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
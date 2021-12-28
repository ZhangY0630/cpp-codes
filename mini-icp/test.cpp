#include <iostream>
#include <numeric>
#include <eigen3/Eigen/Core>       

int main(int argc, char* argv[]){
    Eigen::Matrix4d m = Eigen::MatrixXd::Random(4,4);
    std::cout << m << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << m.block<1,3>(0,0).transpose() <<std::endl;
    std::cout << "--------------------------" << std::endl;
    // std::cout << m+ m.block<1,3>(0,0).transpose() <<std::endl;
}

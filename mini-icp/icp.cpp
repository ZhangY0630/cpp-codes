#include <iostream>
#include <numeric>
#include "icp.h"
#include <eigen3/Eigen/Core>                

using namespace std;
using namespace Eigen;

Matrix4d best_fit_transform(const Eigen::MatrixXd &A,const Eigen::MatrixXd &B){
    Matrix4d T = MatrixXd::Identity(4,4);
    Vector3d centroid_A(0,0,0);
    Vector3d centroid_B(0,0,0);
    MatrixXd AA = A;
    MatrixXd BB = B;

    int row = A.rows();

    for (int i = 0;i < row;i++){
        centroid_A += A.block<1,3>(i,0).transpose();
        centroid_B += B.block<1,3>(i,0).transpose();
        
    }

    centroid_A /=row;
    centroid_B /=row;

    for (int i=0;i < row;i++){
        AA.block<1,3>(i,0) = A.block<1,3>(i,0) - centroid_A.transpose();
        BB.block<1,3>(i,0) = B.block<1,3>(i,0) - centroid_B.transpose();
    }

    MatrixXd H = AA.transpose()*BB;




}

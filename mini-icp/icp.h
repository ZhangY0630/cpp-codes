#include <eigen3/Eigen/Core>
#include <vector>

#ifndef ICP_H
#define ICP_H

#define N_pts 30
#define N_tests 10000 //# of test iteration
#define noise_sigma 0.01
#define translation 0.1 // max translation of the test set
#define rotaion 0.01 // max

typedef struct ICP_OUT
{
    Eigen::Matrix4d trans;
    std::vector<float> distances;
    int itr;
};

typedef struct{
    std::vector<float> distances;
    std::vector<int> indices;
} NEIGHBOUR;

Eigen::Matrix4d best_fit_transform(const Eigen::MatrixXd &A,const Eigen::MatrixXd &B);
ICP_OUT icp(const Eigen::MatrixXd &A,const Eigen::MatrixXd &B,int max_iteration=20,int tolerance=0.001);

NEIGHBOUR nearest_neighbour(const Eigen::MatrixXd &src,const Eigen::MatrixXd &dst);
float dist(const Eigen::Vector3d &pta,const Eigen::Vector3d &ptb);

#endif

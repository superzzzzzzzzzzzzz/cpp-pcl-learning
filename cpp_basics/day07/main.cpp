#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main()
{
    Eigen::Vector3f p;
    p << 1.0f, 0.0f, 0.0f;

    Eigen::Matrix3f R;
    R << 0.0f, -1.0f, 0.0f,
        1.0f,  0.0f, 0.0f,
        0.0f,  0.0f, 1.0f;
    Eigen::Vector3f t;
    t << 1.0f,2.0f,3.0f;

    Eigen::Matrix4f T = Eigen::Matrix4f::Identity();
    T.block<3, 3>(0, 0) = R;
    T.block<3, 1>(0, 3) = t;

    Eigen::Vector3f transformed = R * p + t;

    cout<< "Transformed point: " << endl;
    cout<< T << endl;


    return 0;
}
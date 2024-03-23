#ifndef RWFUNCTIONS_H
#define RWFUNCTIONS_H
#include "D:\\Eigen\\eigen-3.4.0\\Eigen\\Eigen"
#include <string>

using namespace std;
using namespace Eigen;

MatrixXf readObsCoord(string file);
VectorXf readDist(string file);

#endif // RWFUNCTIONS_H
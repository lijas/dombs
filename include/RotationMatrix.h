#ifndef ROTATIONMATRIX_H
#define ROTATIONMATRIX_H

#include <armadillo>

namespace dombs{
    arma::mat getA(arma::vec EulerParameters); // regular rotation matrix
    arma::mat getA(arma::vec EulerParameters, int derivative); // derivative of the rotation matrix
    arma::mat getG(arma::vec EulerParameters);
};

#endif // ROTATIONMATRIX_H

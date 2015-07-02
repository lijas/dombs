#ifndef DOMBS_H
#define DOMBS_H
#include <armadillo>
#include <vector>
#include "Body.h"

namespace dombs
{
    int const DOFS_PER_BODY = 7;
    arma::mat getA(arma::vec EulerParameters); // regular rotation matrix
    arma::mat getA(arma::vec EulerParameters, int derivative); // derivative of the rotation matrix
    arma::mat getG(arma::vec EulerParameters);

    arma::mat getMassMatrix(std::vector<Body> *bodies);
};

#endif // DOMBS_H

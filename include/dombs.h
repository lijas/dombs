#ifndef DOMBS_H
#define DOMBS_H
#include <armadillo>
#include <vector>
#include "Body.h"
#include <Constraint.h>

namespace dombs
{
    int const DOFS_PER_BODY = 7;
    arma::mat getA(arma::vec EulerParameters); // regular rotation matrix
    arma::mat getA(arma::vec EulerParameters, int derivative); // derivative of the rotation matrix
    arma::mat getG(arma::vec EulerParameters);

    arma::mat assembleBodyMassMatrix(std::vector<Body*> *bodies);
    arma::mat assembleCqMatrix(std::vector<Constraint*> *constraints, int ndofs);
    arma::vec assembleCMatrix(std::vector<Constraint*> *constraints);

    //---Help functions
    //Returns the element-positions specified by v1 and v2 in a columnvector. Used for assembling
    arma::uvec getElemVec(arma::vec v1, arma::vec v2);
    arma::uvec colon(int i1, int i2);
    arma::uvec permutation2vec(arma::mat *p);
    int totnConstEq(std::vector<Constraint*> *c);


};

#endif // DOMBS_H

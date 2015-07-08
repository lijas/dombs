#ifndef DOMBS_H
#define DOMBS_H

#include <armadillo>
#include <vector>
#include <Body.h>
#include <Constraint.h>

namespace dombs{

    int const DOFS_PER_BODY = 7;

    //Self explanitory
    arma::mat assembleBodyMassMatrix(std::vector<Body*> *bodies);
    arma::mat assembleCqMatrix(std::vector<Constraint*> *constraints, int ndofs);
    arma::vec assembleCMatrix(std::vector<Constraint*> *constraints);

    //---Help functions
    //Returns the element-positions specified by v1 and v2 in a columnvector. Used for assembling
    arma::uvec getElemVec(arma::vec v1, arma::vec v2);
    //the colon operator in matlab
    arma::uvec colon(int i1, int i2);
    //Makes the permuation matrix from lu-factorisation in to a vector
    arma::uvec permutation2vec(arma::mat p);
    //Calculates the total number of constraints equaitons
    arma::vec getqq(std::vector<Body*> *bodies);

    int totnConstEq(std::vector<Constraint*> *c);

};

#endif // DOMBS_H

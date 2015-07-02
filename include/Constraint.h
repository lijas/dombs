#ifndef CONSTRAINT_H_INCLUDED
#define CONSTRAINT_H_INCLUDED

#include "Body.h"

class Constraint {

public:

    virtual arma::mat getCq() = 0;
    virtual arma::mat getCt() = 0;
    virtual arma::mat getC()  = 0;
    virtual arma::mat getQc() = 0;

    arma::uvec getAssemDofs();

    Body* getBody1(){return b1;};
    Body* getBody2(){return b2;};

protected:
    int cqrows, cqcols;
    Body *b1, *b2;
};

#endif // CONSTRAINT_H_INCLUDED

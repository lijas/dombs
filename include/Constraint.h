#ifndef CONSTRAINT_H_INCLUDED
#define CONSTRAINT_H_INCLUDED

#include <Body.h>

class Constraint {

public:
    virtual arma::mat getCq() = 0;
    virtual arma::mat getCt() = 0;
    virtual arma::mat getC()  = 0;
    virtual arma::mat getQc() = 0;

    virtual arma::uvec getAssemDofs() = 0;

    int getnCqRows(){return cqrows;};
    int getnCqCols(){return cqcols;};

    int getnCRows(){return crows;};
    int getnCCols(){return ccols;};

    int getnCtRows(){return ctrows;};
    int getnCtCols(){return ctcols;};

    int getnQcRows(){return qcrows;};
    int getnQcCols(){return qccols;};
protected:
    int cqrows, cqcols;
    int ctrows, ctcols;
    int crows, ccols;
    int qcrows, qccols;

};

#endif // CONSTRAINT_H_INCLUDED

#ifndef CONSTRAINT_H_INCLUDED
#define CONSTRAINT_H_INCLUDED

#include <armadillo>

class Constraint {

public:
    //All relevant matrices for a constraint. Must be implements by subclasses
    virtual arma::mat getCq() = 0;
    virtual arma::mat getCt() = 0;
    virtual arma::mat getC()  = 0;
    virtual arma::mat getQc() = 0;

    //The dofs that the Cq and Ct should be assebled in to the "Big" matrices
    virtual arma::uvec getAssemDofs() = 0;

    //returns the number of rows and columns in the matrices
    virtual int getnCqRows(){return cqrows;};
    virtual int getnCqCols(){return cqcols;};

    virtual int getnCRows(){return crows;};
    virtual int getnCCols(){return ccols;};

    virtual int getnCtRows(){return ctrows;};
    virtual int getnCtCols(){return ctcols;};

    virtual int getnQcRows(){return qcrows;};
    virtual int getnQcCols(){return qccols;};
protected:
    //Number of rows and columns in the matrices
    int cqrows, cqcols;
    int ctrows, ctcols;
    int crows, ccols;
    int qcrows, qccols;

};

#endif // CONSTRAINT_H_INCLUDED

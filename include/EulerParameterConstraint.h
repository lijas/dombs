#ifndef EULERPARAMETERCONSTRAINT_H
#define EULERPARAMETERCONSTRAINT_H

#include <Constraint.h>
#include <armadillo>

class EulerParameterConstraint : public Constraint
{
    public:
        EulerParameterConstraint();
        ~EulerParameterConstraint();

        arma::mat getCq();
        arma::mat getCt();
        arma::mat getC();
        arma::mat getQc();

        arma::uvec getAssemDofs();

        void setBody(Body *b){body = b;};

    protected:
    private:
        Body *body;
};

#endif // EULERPARAMETERCONSTRAINT_H

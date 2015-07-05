#ifndef BALLJOINT_H_INCLUDED
#define BALLJOINT_H_INCLUDED

#include <armadillo>
#include <Constraint.h>
#include <Body.h>
class BallJoint : public Constraint{

public:
    BallJoint();

    arma::mat getCq();
    arma::mat getCt();
    arma::mat getC();
    arma::mat getQc();

    void setBody1(Body *b){b1 = b;};
    void setBody2(Body *b){b2 = b;};

    void setU1(arma::vec u){u1 = u;};
    void setU2(arma::vec u){u2 = u;};

    arma::uvec getAssemDofs();
private:
    Body *b1, *b2;
    arma::vec u1, u2;
};


#endif // BALLJOINT_H_INCLUDED

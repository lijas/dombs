#ifndef FIXBALLJOINT_H
#define FIXBALLJOINT_H

#include <Constraint.h>
#include <armadillo>
#include <Body.h>

class FixBallJoint : public Constraint
{
    public:
        FixBallJoint();
        ~FixBallJoint();

        arma::mat getCq();
        arma::mat getCt();
        arma::mat getC();
        arma::mat getQc();

        arma::uvec getAssemDofs();

        void setJointPos(arma::vec inp){pos = inp;};
        void setBody(Body *inb){body = inb;};
        void setU(arma::vec iu){u = iu;};
    protected:
    private:
        Body *body;
        arma::vec pos, u;
};

#endif // FIXBALLJOINT_H

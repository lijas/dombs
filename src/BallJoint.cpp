#include <BallJoint.h>
#include <RotationMatrix.h>

using namespace std;
using namespace arma;

BallJoint::BallJoint(){
    u1 = zeros<vec>(3);
    u2 = u1;
    b1 = 0; b2 = 0;
    cqrows = 3; cqcols = 14;
    ctrows = 3, ctcols = 14;
    crows = 3, ccols = 1;
    qcrows = 7, qccols = 1;
}

uvec BallJoint::getAssemDofs(){
    return join_vert(b1->getdofs(), b2->getdofs());
}

mat BallJoint::getCq(){

    mat cqe1 = eye<mat>(3,7);
    mat cqe2 = -1*eye<mat>(3,7);

    cqe1.col(3) = dombs::getA(b1->getep(),0)*u1;
    cqe1.col(4) = dombs::getA(b1->getep(),1)*u1;
    cqe1.col(5) = dombs::getA(b1->getep(),2)*u1;
    cqe1.col(6) = dombs::getA(b1->getep(),3)*u1;

    cqe2.col(3) = -1*dombs::getA(b2->getep(),0)*u2;
    cqe2.col(4) = -1*dombs::getA(b2->getep(),1)*u2;
    cqe2.col(5) = -1*dombs::getA(b2->getep(),2)*u2;
    cqe2.col(6) = -1*dombs::getA(b2->getep(),3)*u2;

    return join_horiz(cqe1,cqe2);
}

mat BallJoint::getCt(){

}

mat BallJoint::getC(){
    return b1->getPos() + dombs::getA(b1->getep())*u1 - (b2->getPos() + dombs::getA(b2->getep())*u2);
}

mat BallJoint::getQc(){

}

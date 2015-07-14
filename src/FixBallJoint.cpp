#include <FixBallJoint.h>
#include <dombs.h>
#include <RotationMatrix.h>

using namespace std;
using namespace arma;

FixBallJoint::FixBallJoint(){
    pos = zeros<vec>(3);
    u = pos;
    body = 0;

    cqrows = 3; cqcols = 7;
    ctrows = 3, ctcols = 7;
    crows = 3, ccols = 1;
    qcrows = 7, qccols = 1;
}

FixBallJoint::~FixBallJoint(){
    //dtor
}

uvec FixBallJoint::getAssemDofs(){
    return body->getdofs();
}

mat FixBallJoint::getCq(){
    mat cqe = eye(cqrows, cqcols);
    cqe.col(3) = dombs::getA(body->getep(),0)*u;
    cqe.col(4) = dombs::getA(body->getep(),1)*u;
    cqe.col(5) = dombs::getA(body->getep(),2)*u;
    cqe.col(6) = dombs::getA(body->getep(),3)*u;
    return cqe;
}

mat FixBallJoint::getCt(){

}

mat FixBallJoint::getC(){
    return body->getPos() + dombs::getA(body->getep())*u; //-pos;
}

mat FixBallJoint::getQc(){

}

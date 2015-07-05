#include <BallJoint.h>


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
    return ones<mat>(cqrows, cqcols);
}

mat BallJoint::getCt(){

}

mat BallJoint::getC(){

}

mat BallJoint::getQc(){

}

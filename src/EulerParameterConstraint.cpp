#include "EulerParameterConstraint.h"


using namespace std;
using namespace arma;


EulerParameterConstraint::EulerParameterConstraint()
{
    body = null;

    cqrows = 1; cqcols = 4;
    ctrows = 1, ctcols = 4;
    crows = 1, ccols = 1;
    qcrows = 1, qccols = 1;
}

EulerParameterConstraint::~EulerParameterConstraint()
{
    //dtor
}

uvec EulerParameterConstraint::getAssemDofs(){
    return body->getEpdofs();
}

mat EulerParameterConstraint::getCq(){
    return ones<mat>(cqrows, cqcols);
}

mat EulerParameterConstraint::getCt(){

}

mat EulerParameterConstraint::getC(){
    return body->getep().t() * body->getep();
}

mat EulerParameterConstraint::getQc(){

}

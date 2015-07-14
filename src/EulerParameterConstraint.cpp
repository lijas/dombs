#include "EulerParameterConstraint.h"
#include <RotationMatrix.h>

using namespace std;
using namespace arma;


EulerParameterConstraint::EulerParameterConstraint()
{
    body = 0;

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
    return body->getep().t()*2;
}

mat EulerParameterConstraint::getCt(){

}

mat EulerParameterConstraint::getC(){
    return (body->getep().t() * body->getep()) - 1;
}

mat EulerParameterConstraint::getQc(){

}

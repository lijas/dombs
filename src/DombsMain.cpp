#include "DombsMain.h"
#include <Ode4.h>
#include <FixBallJoint.h>
#include <BallJoint.h>
#include <Body.h>
#include <EulerParameterConstraint.h>
#include <dombs.h>

using namespace std;
using namespace arma;

vec funkk(vec q, double t);

void DombsMain::initilize(string infileName){

    fileName = infileName;

    readInputFile(); //set solver, init bodies and constraints
    runner();
}

void DombsMain::readInputFile(){

    //TILL EXEMPEL
    Body b1(0);
    Body b2(1);
    bodies.push_back(&b1);
//    bodies.push_back(&b2);

    FixBallJoint fbj;
    vec v(3); v << 0 << 1 << 0;
    fbj.setU(v);
    fbj.setBody(&b1);

    BallJoint bj1;
    bj1.setBody1(&b1);
    bj1.setBody2(&b2);
    bj1.setU1(v);
    bj1.setU2(v*-1);


    constraints.push_back(&bj1);
//    constraints.push_back(&fbj);

    EulerParameterConstraint epc1, epc2;
    epc1.setBody(&b1);
    epc2.setBody(&b2);

    constraints.push_back(&epc1);
//constraints.push_back(epc2);

    solver = new Ode4;
    solver->setTimeSpan(0,1);
    solver->setnsteps(1000);
    //solver->setInitialCondition(ic);
}

void DombsMain::runner(){
    solver->runSolver(dombsfunk);
}

vec DombsMain::dombsfunk(vec q, double t){

    mat Cq = dombs::assembleCqMatrix(constraints, ndofs);
    mat C = dombs::assembleCMatrix(constraints);
    mat Mb = dombs::assembleBodyMassMatrix(bodies);

    double normC = norm(C);

    mat L, U, P;
    lu(L, U, P, Cq.t());
    uvec P = arma::permutation2vec(P);

    ndepC = P(span(0,ndepC-1));
    nindepC = P(span(ndepC, ndofs-1));

    double tol = 0.00001;
    while(normc > normC){
        Cq = dombs::assembleCqMatrix(constraints, ndofs);
        C = dombs::assembleCMatrix(contraints);

    }



    return q;
}







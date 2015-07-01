#include "DombsMain.h"
#include <Ode4.h>

using namespace std;
using namespace arma;

void DombsMain::initilize(string infileName){

    fileName = infileName;

    readInputFile(); //set solver, init bodies and constraints
    runner();
}

void DombsMain::readInputFile(){

    //TILL EXEMPEL

//    Body b1();
//    Body b2();
//
//    bodies.push_back(b1);
//    bodies.push_back(b2);
//
//    BallJoint c1();
//    c1.b1 = &b1;
//    c2.b2 = &b2;
//
//    constraints.push_back(c1);
//
//    vec ic = zeros<vec>(10);

    Ode4 apa();
    solver = new Ode4();
    solver->setTimeSpan(0,1);
    solver->setnsteps(1000);
    //solver->setInitialCondition(ic);
}

void DombsMain::runner(){

    solver->runSolver(dombsfunk);

}

void DombsMain::(*dombsfunk)(vec q, double t){

    mat Cq = zeros<mat>(nconstraints, ndof);
    int cConstRow = 0;
    for(int i=0; i<constraints.size(); i++){
        Constraint *cconst = constraints.at(i);
        mat c = cconst->getCq();

        uvec assemCols = cconst->b1->getAssemDofs();

        //Number of constraint equation for current constratnt
        int nConstEq = constraints.at(i).cqrows;
        Cq.elem(,assemCols)
        Cq(span(cConstRow, cConstRow+nConstEq), s)
    }

    mat M = getMassMatrix();
}







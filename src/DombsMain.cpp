#include "DombsMain.h"
#include <Ode4.h>

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
    Body *b1 = new Body;
    bodies.push_back(b1);

    solver = new Ode4;
    solver->setTimeSpan(0,1);
    solver->setnsteps(1000);
    //solver->setInitialCondition(ic);
}

vec funkk(vec q, double t){
    t = 1;
    vec v;
    return v;
}

void DombsMain::runner(){
    typedef vec (*funk)(vec, double);
    funk tempfunkapa = funkk;
    solver->runSolver(tempfunkapa);

}

vec DombsMain::dombsfunk(vec q, double t){
    cout<<"i am here"<<endl;
//    mat Cq = zeros<mat>(nconstraints, ndof);
//    int cConstRow = 0;
//    for(int i=0; i<constraints.size(); i++){
//        Constraint *cconst = constraints.at(i);
//        mat c = cconst->getCq();
//
//        uvec assemCols = cconst->getBody1()->getAssemDofs();
//
//        //Number of constraint equation for current constratnt
//        int nConstEq = constraints.at(i).cqrows;
//        Cq.elem(,assemCols)
//        Cq(span(cConstRow, cConstRow+nConstEq), s)
//    }
//
//    mat M = getMassMatrix();
    return q;
}







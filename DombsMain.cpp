#include "DombsMain.h"
#include <Solver.h>

DombsMain::initilize(string infileName){

    fileName = infileName;

    readInputFile(); //set solver, init bodies and constraints
    runner();
}

DombsMain::readInputFile(string fileName){

    this->fileName = fileName;

    //TILL EXEMPEL

    Body b1();
    Body b2();

    bodies.push_back(b1);
    bodies.push_back(b2);

    BallJoint c1();
    c1.b1 = &b1;
    c2.b2 = &b2;

    constraints.push_back(c1);

    vec ic = zeros<vec>(10);

    solver = new Ode4();
    solver->setTimeSpan(0,1);
    solver->setnsteps(1000);
    solver->setInitialCondition(ic);
}

DombsMain::runner(){

    solver.run(dombsfunk);

}

void DombsMain::dombsfunk(mat q, double t){

    for(int i=0; i<constraints.length(); i++){
        mat c = constraints.at(i).getCq();

    }

}

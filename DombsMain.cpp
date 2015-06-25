#include "DombsMain.h"
#include <Solver.h>

DombsMain::initilize(string infileName){

    fileName = infileName;

    readInputFile(); //set solver, init bodies and constraints

    runner();
}

DombsMain::runner(){

    solver.run(dombsfunk);

}

void DombsMain::dombsfunk(mat q, double t){





}

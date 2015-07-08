#ifndef DOMBSMAIN_H_INCLUDED
#define DOMBSMAIN_H_INCLUDED

#include <string>
#include <vector>
#include <Body.h>
#include <Constraint.h>
#include <Solver.h>

namespace dombsmain {

    //Store the inputfile name
    extern std::string inputfileName;
    //A vector containing that points to all bodies
    extern std::vector<Body*> bodies;
    //A vector containing that points to all constraints
    extern std::vector<Constraint*> constraints;
    //A solver that points to the current solver that is used, ode4, ode3 etc
    extern Solver *solver;
    //Some variables that I think we can init when reading the input file. They will probobly not change
    extern unsigned int nbodies, nconstraints, ndofs, nindepC, ndepC;
    //
    extern arma::vec all_qq;

    //The main functions that is called from main.cpp
    void initilize(std::string fileName);
    //Reads the input file
    void readInputFile();
    //Calls the solver to start running (Överflöding funtion kanske)
    void runner();
    //Oklart om vi behöver ddenna
    void postProcess();

    //Ultimate dombs function of doom
    arma::vec dombsfunk(arma::vec q, double d);
}
#endif // DOMBSMAIN_H_INCLUDED

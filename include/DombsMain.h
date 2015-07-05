#ifndef DOMBSMAIN_H_INCLUDED
#define DOMBSMAIN_H_INCLUDED

#include <string>
#include <vector>
#include "Body.h"
#include "Constraint.h"
#include <Solver.h>

class DombsMain {

public:
    void initilize(std::string fileName);

private:

    std::string fileName;

    std::vector<Body*> bodies;
    std::vector<Constraint*> constraints;

    Solver *solver;

    int nbodies, nconstraints, ndofs, nindepC, ndepC;

    void readInputFile();
    void runner();
    void postProcess();

    static arma::vec dombsfunk(arma::vec q, double d);
};

#endif // DOMBSMAIN_H_INCLUDED

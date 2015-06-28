#ifndef DOMBSMAIN_H_INCLUDED
#define DOMBSMAIN_H_INCLUDED

#include <string>
#include <vector>

class DombsMain {

public:
    void initilize(string fileName);

private:

    string fileName;
    vector<Body> bodies;
    vector<Constraint> constraints;

    Solver *solver;

    int nbodies, nconstraints, ndof;

    void readInputFile();
    void runner();
    void postProcess();

    void dombsfunk(mat q, double d);
};

#endif // DOMBSMAIN_H_INCLUDED

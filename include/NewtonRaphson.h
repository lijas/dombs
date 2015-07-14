#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

#include <armadillo>

namespace dombs{

class NewtonRaphson {
public:
    NewtonRaphson(){tol = 0.0000001; maxItr = 100;};
    NewtonRaphson(double tolin){tol = tolin; maxItr = 100;};
    NewtonRaphson(int maxin){tol = 0.0000001; maxItr = maxin;};
    NewtonRaphson(int maxin,double tolin){tol = tolin; maxItr = maxin;};


    arma::vec solve(arma::vec (*Objective)(arma::vec q), arma::mat (*Tangent)(arma::vec q), arma::vec xx);

    int setMaxItr(int in){maxItr = in;};
    int setTol(double in){tol = in;};
private:
    int maxItr;
    double tol;
};

}

#endif // NEWTONRAPHSON_H

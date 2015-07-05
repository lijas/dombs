#ifndef SOLVER_H
#define SOLVER_H

#include <armadillo>

class Solver{

    public:
        Solver();
        ~Solver();

        virtual void runSolver(arma::vec (*f)(arma::vec, double)) = 0;

        void setTimeSpan(double st, double et){startTime = st; endTime = et;};
        void setnsteps(double ns){nsteps = ns;};
        void setInitialCondition(arma::vec ic){initialCondition = ic;};
    protected:
        double startTime, endTime, nsteps;
        arma::vec initialCondition;
};

#endif // SOLVER_H

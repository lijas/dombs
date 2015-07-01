#ifndef SOLVER_H
#define SOLVER_H


class Solver
{
    public:
        virtual void runSolver(void (*f)(arma::vec, double)) = 0;

        void setTimeSpan(double st, double et){startTime = st; endTime = et;};
        void setnsteps(double ns){nsteps = ns;};
        void setInitialCondition(arma::vec ic){initialCondition = ic;};
    private:
        double startTime, endTime, nsteps;
        arma::vec initialCondition;
};

#endif // SOLVER_H

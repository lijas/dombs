#ifndef SOLVER_H
#define SOLVER_H


class Solver
{
    public:
        Solver();
        virtual void runSolver(void (*f)(vec, double)) = 0;

        void setTimeSpan(double st, double et){startTime = st; endTime = et;};
        void setnsteps(double ns){nsteps = ns;};
        void setInitialCondition(vec ic){initialCondition = ic;};
    private:
        double startTime, endTime, nsteps;
        vec initialCondition;
};

#endif // SOLVER_H

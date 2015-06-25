#ifndef SOLVER_H
#define SOLVER_H


class Solver
{
    public:
        Solver();
        virtual void runSolver(void (*f)(mat, double)) = 0;
    protected:
    private:
};

#endif // SOLVER_H

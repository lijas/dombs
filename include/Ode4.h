#ifndef ODE4_H
#define ODE4_H

#include <Solver.h>


class Ode4 : public Solver
{
    public:
        Ode4();
        ~Ode4();

        void runSolver(void (*f)(arma::vec, double));
    protected:
    private:
};

#endif // ODE4_H

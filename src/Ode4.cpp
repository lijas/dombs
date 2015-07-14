#include <Ode4.h>

using namespace std;
using namespace arma;

Ode4::Ode4()
{

}

Ode4::~Ode4()
{
    //dtor
}


void Ode4::runSolver(vec (*f)(vec q, double t)){

    //Check endtime smaller then start time
    //ERROR HANDLING STUFF
    vec tspan = linspace<vec>(startTime,endTime,nsteps);

    int neq = initialCondition.n_rows;

    mat Y = zeros<mat>(neq,nsteps);
    mat F = zeros<mat>(neq,4);

    Y.col(0) = initialCondition;
    for(int i=1; i<=nsteps-1; i++){ //ska det vara minus 1? annars blir det fel p� raden: double hi = tspan(i)...
      double ti = tspan(i-1);
      double hi = tspan(i) - tspan(i-1);
      vec yi = Y.col(i-1);

      F.col(0) = f(yi, ti);
      F.col(1) = f(yi + 0.5*hi*F.col(0), ti + 0.5*hi);
      F.col(2) = f(yi + 0.5*hi*F.col(1), ti + 0.5*hi);
      F.col(3) = f(yi + hi*F.col(2), ti + hi);

      Y.col(i) = yi + (hi/6)*(F.col(0) + 2*F.col(1) + 2*F.col(2) + F.col(3));
      cout<<"Step: "<< i << "/"<< nsteps <<endl;
    }
    cout<<"exit ode4"<<endl;
    Y.save("Y.txt",raw_ascii);
}

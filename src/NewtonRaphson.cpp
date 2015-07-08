#include <NewtonRaphson.h>

using namespace std;
using namespace arma;

namespace dombs{

    vec NewtonRaphson(vec (*C)(vec q), mat (*Cq)(vec q), *q){
        double tol = 0.0001;
        while (norm(C) > tol){
            vec dq = -solve(Cq(q),C);
            *q = *q + &dq;
        }

    }

}








#include "dombs.h"

namespace dombs
{
    DOFS_PER_BODY = 7;

    mat getA(vec EulerParameters){
        mat E = zeros<mat>(3,4);
        mat Ebar = zeros<mat>(3,4);

        E << -EulerParameters(1) << EulerParameters(0) << -EulerParameters(3) << EulerParameters(2) << endr
          << -EulerParameters(2) << EulerParameters(3) << EulerParameters(0) << -EulerParameters(1) << endr
          << -EulerParameters(3) << -EulerParameters(2) << EulerParameters(1) << EulerParameters(0) << endr;

        Ebar << -EulerParameters(1) << EulerParameters(0) << EulerParameters(3) << -EulerParameters(2) << endr
             << -EulerParameters(2) << -EulerParameters(3) << EulerParameters(0) << EulerParameters(1) << endr
             << -EulerParameters(3) << EulerParameters(2) << -EulerParameters(1) << EulerParameters(0) << endr;

        A = E*Ebar.t;
        return A;
    };

}

#include <RotationMatrix.h>

using namespace arma;

namespace dombs{

mat getA(vec EulerParameters){
        mat E = zeros<mat>(3,4);
        mat Ebar = zeros<mat>(3,4);

        E << -EulerParameters(1) << EulerParameters(0) << -EulerParameters(3) << EulerParameters(2) << endr
          << -EulerParameters(2) << EulerParameters(3) << EulerParameters(0) << -EulerParameters(1) << endr
          << -EulerParameters(3) << -EulerParameters(2) << EulerParameters(1) << EulerParameters(0) << endr;

        Ebar << -EulerParameters(1) << EulerParameters(0) << EulerParameters(3) << -EulerParameters(2) << endr
             << -EulerParameters(2) << -EulerParameters(3) << EulerParameters(0) << EulerParameters(1) << endr
             << -EulerParameters(3) << EulerParameters(2) << -EulerParameters(1) << EulerParameters(0) << endr;

        mat A = E*Ebar.t();
        return A;
    };

    mat getA(vec EulerParameters, int derivative){
        mat E = zeros<mat>(3,4);
        mat Ebar = zeros<mat>(3,4);

        E << -EulerParameters(1) << EulerParameters(0) << -EulerParameters(3) << EulerParameters(2) << endr
          << -EulerParameters(2) << EulerParameters(3) << EulerParameters(0) << -EulerParameters(1) << endr
          << -EulerParameters(3) << -EulerParameters(2) << EulerParameters(1) << EulerParameters(0) << endr;

        Ebar << -EulerParameters(1) << EulerParameters(0) << EulerParameters(3) << -EulerParameters(2) << endr
             << -EulerParameters(2) << -EulerParameters(3) << EulerParameters(0) << EulerParameters(1) << endr
             << -EulerParameters(3) << EulerParameters(2) << -EulerParameters(1) << EulerParameters(0) << endr;

        if (derivative == 0){
            mat E0 = zeros<mat>(3,4);
            mat Ebar0 = zeros<mat>(3,4);

            E0(0,1) = 1; E0(1,2) = 1; E0(2,3) = 1;
            Ebar0(0,1) = 1; Ebar0(1,2) = 1; Ebar0(2,3) = 1;

            mat Ader0 = E0*Ebar.t() + E*Ebar0.t();
            return Ader0;
        }
        else if (derivative == 1){
            mat E1 = zeros<mat>(3,4);
            mat Ebar1 = zeros<mat>(3,4);

            E1(0,0) = -1; E1(2,2) = 1; E1(1,3) = -1;
            Ebar1(0,0) = -1; Ebar1(2,2) = -1; Ebar1(1,3) = 1;

            mat Ader1 = E1*Ebar.t() + E*Ebar1.t();
            return Ader1;
        }
        else if (derivative == 2){
            mat E2 = zeros<mat>(3,4);
            mat Ebar2 = zeros<mat>(3,4);

            E2(1,0) = -1; E2(2,1) = -1; E2(0,3) = 1;
            Ebar2(1,0) = -1; Ebar2(2,1) = 1; Ebar2(0,3) = -1;

            mat Ader2 = E2*Ebar.t() + E*Ebar2.t();
            return Ader2;
        }
        else if (derivative == 3){
            mat E3 = zeros<mat>(3,4);
            mat Ebar3 = zeros<mat>(3,4);

            E3(2,0) = -1; E3(1,1) = 1; E3(0,2) = -1;
            Ebar3(2,0) = -1; Ebar3(1,1) = -1; Ebar3(0,2) = 1;

            mat Ader3 = E3*Ebar.t() + E*Ebar3.t();
            return Ader3;
        }
    };

    mat getG(vec EulerParameters){
        mat E = zeros<mat>(3,4);

        E << -EulerParameters(1) << EulerParameters(0) << -EulerParameters(3) << EulerParameters(2) << endr
          << -EulerParameters(2) << EulerParameters(3) << EulerParameters(0) << -EulerParameters(1) << endr
          << -EulerParameters(3) << -EulerParameters(2) << EulerParameters(1) << EulerParameters(0) << endr;

        mat G = 2*E;
        return G;

    };
}

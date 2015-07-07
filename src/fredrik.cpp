#include <armadillo>

using namespace arma;

int main(){

    vec EulerParameters;
    EulerParameters << 1 << 1 << 1 << 1 << endr;


        mat E = zeros<mat>(3,4);
        mat Ebar = zeros<mat>(3,4);

        E << -EulerParameters(1) << EulerParameters(0) << -EulerParameters(3) << EulerParameters(2) << endr
          << -EulerParameters(2) << EulerParameters(3) << EulerParameters(0) << -EulerParameters(1) << endr
          << -EulerParameters(3) << -EulerParameters(2) << EulerParameters(1) << EulerParameters(0) << endr;

        Ebar << -EulerParameters(1) << EulerParameters(0) << EulerParameters(3) << -EulerParameters(2) << endr
             << -EulerParameters(2) << -EulerParameters(3) << EulerParameters(0) << EulerParameters(1) << endr
             << -EulerParameters(3) << EulerParameters(2) << -EulerParameters(1) << EulerParameters(0) << endr;

        mat A = E*Ebar.t();

            mat E0 = zeros<mat>(3,4);
            mat Ebar0 = zeros<mat>(3,4);

            E0(0,1) = 1; E0(1,2) = 1; E0(2,3) = 1;
            Ebar0(0,1) = 1; Ebar0(1,2) = 1; Ebar0(2,3) = 1;

            mat Ader0 = E0*Ebar.t() + E*Ebar0.t();

        //Ader0.print();

        Ader0.print();


}

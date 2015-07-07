#include <armadillo>
#include <iostream>

using namespace arma;

//vec NewtonRaphson(vec (*C)(vec q), mat (*Cq)(vec q), vec q){
//    double tol = 0.0001;
//    while (norm(C) > tol){
//        vec dq = -solve(Cq(q),C);
//        q = *q + dq;
//    }
//
//}
//
//vec C(vec q){
//    return vec A << 1 << 2 << 3 << 4 << endr;
//}


int main(){

    vec q(2);

    q << 1 << 6 << endr;

    double *hej = q.memptr();

    vec qq(4);

    qq << *hej << *(hej+1) << *hej << *(hej+1) << endr;

    qq.print();

    int *hejsan;

    hejsan = 1;

    hej = hejsan;

    cout << endl;

    qq.print();


}

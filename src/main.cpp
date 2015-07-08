#include <iostream>
#include <armadillo>
#include <string>
#include <DombsMain.h>

using namespace std;
using namespace arma;

int main(){

    cout << "Armadillo version: " << arma_version::as_string() << endl;

    vec v1(3); v1<<1<<2<<3;
    vec v2(v1.memptr(), 3, false);
    vec v3(3); v3<<4<<5<<6;

//    v1(2) = 100;
//    v2.print("v2");
//    v2(2) = 1000;
//    v1.print("v1");
//    v2.print("v2");

    v2 = v3;
    v2.print("v2");
    v1.print("v1");
    //dombsmain::initilize("test");

	return 0;
}

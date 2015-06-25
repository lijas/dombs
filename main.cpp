#include <iostream>
#include <armadillo>
#include <vector>
#include "Body.h"
#include <string>

using namespace std;
using namespace arma;

int main(){

    cout << "Armadillo version: " << arma_version::as_string() << endl;
// hejs
	mat m1(7, 1);
	m1.zeros();
	mat m2(7, 1);
    m2.zeros();

    Body b1(m1,m2);

    vector<Body> bodies;
    bodies.push_back(b1);

	return 0;
}

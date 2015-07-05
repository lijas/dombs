#include <iostream>
#include <armadillo>
#include <vector>
#include <Body.h>
#include <string>
#include <BallJoint.h>
#define <FixBallJoint.h>
#include <dombs.h>

using namespace std;
using namespace arma;

int main(){

    cout << "Armadillo version: " << arma_version::as_string() << endl;

    DombsMain dm;
    dm.initilize("test");

	return 0;
}

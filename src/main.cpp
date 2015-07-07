#include <iostream>
#include <armadillo>
#include <string>
#include <DombsMain.h>

using namespace std;
using namespace arma;

int main(){

    cout << "Armadillo version: " << arma_version::as_string() << endl;

    dombsmain::initilize("test");

	return 0;
}

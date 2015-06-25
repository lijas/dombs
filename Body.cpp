#include <armadillo>
#include "Body.h"

using namespace std;
using namespace arma;

Body::Body(){
	q = mat(7, 1);
	dq = mat(7, 1);
	q.zeros(); dq.zeros();
}

Body::Body(mat iq, mat idq){
	q = iq;
	dq = idq;
}

void Body::setCoords(mat iq){
    if(iq.rows() == 7 && iq.cols() == 1)
        q = iq;
    else
        return;
}

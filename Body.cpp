#include "Body.h"

using namespace arma;

Body::Body(){
	q = vec(7, 1);
	dq = vec(7, 1);
	q.zeros(); dq.zeros();
}

Body::Body(vec iq, vec idq){
	q = iq;
	dq = idq;
}

void Body::setCoords(vec iq){

    if(iq.n_rows == 7 && iq.n_cols == 1)
        q = iq;
    else
        return;
}

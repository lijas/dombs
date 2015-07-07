#include <Body.h>
#include <dombs.h>

using namespace arma;

Body::Body(){
	q = vec(7);
	dq = vec(7);
	q.zeros();
	dq.zeros();

	density = 1;
	calculateMass();

	id = -1; //need to set id afterwards
}

Body::Body(int iid){
    q = vec(7);
	dq = vec(7);
	q.zeros();
	dq.zeros();

    density = 1;
	calculateMass();

	id = iid; //need to set id afterwards
	evalDofs();
}

Body::Body(int iid, vec iq, vec idq){
	q = iq;
	dq = idq;

    density = 1;
	calculateMass();

    density = 1;
	calculateMass();

	id = iid;
	evalDofs();
}
void Body::evalMassAndMomentInertia(){
    //Calculate momentinerta and mass using the density and shape
    //Set to 1 for now
    mass = 1;
    momentInertia = eye<mat>(3,3);
}

void Body::setCoords(vec iq){
    this->q = iq;
}

void Body::setDensity(double d){
    density = d;
    calculateMass();
}

void Body::evalDofs(){
    dofs = uvec((dombs::colon(id*7,id*7+6)));   //all dofs span
    posdofs = dombs::colon(id*7,id*7+2);   //pos dofs span
    epdofs = dombs::colon(id*7+3,id*7+6); //ep ofs span
}

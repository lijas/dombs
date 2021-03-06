#include <Body.h>
#include <dombs.h>

using namespace arma;

Body::Body(){
	q = new vec(7);
	dq = new vec(7);
	q->zeros();
	dq->zeros();

	density = 1;
	evalMassAndMomentInertia();

	id = -1; //need to set id afterwards
}

Body::Body(int iid){
	q = new vec(7);
	dq = new vec(7);
	q->zeros();
	dq->zeros();

    density = 1;
	evalMassAndMomentInertia();

	id = iid; //need to set id afterwards
	evalDofs();
}

Body::Body(int iid, vec *iq, vec *idq){
	q = iq;
	dq = idq;

    density = 1;
	evalMassAndMomentInertia();

    density = 1;
	evalMassAndMomentInertia();

	id = iid;
	evalDofs();
}
void Body::evalMassAndMomentInertia(){
    //Calculate momentinerta and mass using the density and shape
    //Set to 1 for now
    mass = 0.1;
    momentInertia = eye<mat>(3,3) * 1/12*mass*0.01*0.01;
}

void Body::setDensity(double d){
    density = d;
    evalMassAndMomentInertia();
}

void Body::evalDofs(){
    dofs = uvec((dombs::colon(id*7,id*7+6)));   //all dofs span
    posdofs = dombs::colon(id*7,id*7+2);   //pos dofs span
    epdofs = dombs::colon(id*7+3,id*7+6); //ep ofs span
}

#ifndef BODY_H
#define BODY_H
#include <armadillo>

class Body{

public:
	Body();
	Body(arma::vec iq, arma::vec idq);

	void setCoords(arma::vec iq);

    double getMass();
    arma::mat getMomentInertia();

    arma::vec getq(){return q;};
    arma::vec getdq(){return dq;};
    arma::vec getPos(){return q.rows(0,2);};
    arma::vec getep(){return q.rows(3,6);};

    //Get the span for all dofs for this body
    arma::span getDofsSpan(){return arma::span(id*7,id*7+6);};
    //Get the span for the pos dofs for this body
    arma::span getDofsSpanPos(){return arma::span(id*7,id*7+2);};
    //Get the span for the euler parameters dofs for this body
    arma::span getDofsSpanEp(){return arma::span(id*7+3,id*7+6);};

    int getid(){return id;};
private:

    int id;

    arma::vec q;
	arma::vec dq;

    double calculateMass();

    double density, mass;
    arma::mat momentInertia;

    bool deformable;
    //Simple shape;
};
#endif // BODY_H

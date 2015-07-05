#ifndef BODY_H
#define BODY_H
#include <armadillo>

class Body{

public:
	Body();
	Body(int iid);
	Body(arma::vec iq, arma::vec idq);
	Body(int iid, arma::vec iq, arma::vec idq);

	void setCoords(arma::vec iq);
    void setId(int ii){id = ii; evalDofs();};
    void setDensity(double);

    double getMass();
    int getId(){return id;};


    arma::mat getMomentInertia();

    arma::vec getq(){return q;};
    arma::vec getdq(){return dq;};
    arma::vec getPos(){return q.rows(0,2);};
    arma::vec getep(){return q.rows(3,6);};

    arma::uvec getdofs(){return dofs;};
    arma::uvec getPosdofs(){return posdofs;};
    arma::uvec getEpdofs(){return epdofs;};

    //Get the span for all dofs for this body
    arma::span getDofsSpan(){return arma::span(id*7,id*7+6);};
    //Get the span for the pos dofs for this body
    arma::span getDofsSpanPos(){return arma::span(id*7,id*7+2);};
    //Get the span for the euler parameters dofs for this body
    arma::span getDofsSpanEp(){return arma::span(id*7+3,id*7+6);};
private:

    int id;

    arma::vec q;
	arma::vec dq;

	arma::uvec dofs;
	arma::uvec posdofs;
	arma::uvec epdofs;

    void calculateMass();
    void evalDofs();

    double density, mass;
    arma::mat momentInertia;

    bool deformable;
    //Simple shape;
};
#endif // BODY_H

#ifndef BODY_H
#define BODY_H
#include <armadillo>

class Body{

public:
    //This constructor should not be used, because it does not set the id of the body
	Body();
	//Assigns a id to the body
	Body(int iid);
	//Should not be used because does not set id
	Body(arma::vec iq, arma::vec idq);
	Body(int iid, arma::vec iq, arma::vec idq);

    //Sets the coords of the body, assumably the initial conditions
	void setCoords(arma::vec iq);
	//Sets the id of the body, should be done when reading the input
    void setId(int ii){id = ii; evalDofs();};

    //Sets the density and recalculates the mass and inertia matrix
    void setDensity(double);

    double getMass(){return mass;};
    int getId(){return id;};
    arma::mat getMomentInertia(){return momentInertia;};

    //Returns pos and ep etc
    arma::vec getq(){return q;};
    arma::vec getdq(){return dq;};
    arma::vec getPos(){return q.rows(0,2);};
    arma::vec getep(){return q.rows(3,6);};

    //Returns the dofs for ep and pos etc
    arma::uvec getdofs(){return dofs;};
    arma::uvec getPosdofs(){return posdofs;};
    arma::uvec getEpdofs(){return epdofs;};

    //----Get dofs in form of span
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

    //These are called if id or density variable is set
    void evalMassAndMomentInertia();
    void evalDofs();

    double density, mass;
    arma::mat momentInertia;

    bool deformable;
    //Simple shape;
};
#endif // BODY_H

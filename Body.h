using namespace arma;

class Body{

public:
	Body();
	Body(mat iq, mat idq);

	void setCoords(mat iq);

    double getMass();
    mat getMomentInertia();

    mat getq(){return q;};
    mat getdq(){return dq;};
    mat getPos(){return q.rows(1,3);};

private:

    mat q;
	mat dq;

    double calculateMass();

    double density, mass;
    mat momentInertia;

    bool deformable;
    //Simple shape;
};

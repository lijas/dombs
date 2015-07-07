#include <DombsMain.h>
#include <Ode4.h>
#include <FixBallJoint.h>
#include <BallJoint.h>
#include <Body.h>
#include <Constraint.h>
#include <EulerParameterConstraint.h>
#include <dombs.h>

using namespace std;
using namespace arma;

namespace dombsmain{

     std::string inputfileName;

     std::vector<Body*> bodies;
     std::vector<Constraint*> constraints;

     Solver *solver;

     unsigned int nbodies, nconstraints, ndofs, nindepC, ndepC;


    void initilize(string infileName){

        inputfileName = infileName;

        readInputFile(); //set solver, init bodies and constraints
        runner();
    }

    void readInputFile(){

        //TILL EXEMPEL
        Body *b1 = new Body(0);
        vec b1pos(7); b1pos << 0.00191341716182545 << -0.00461939766255643 << 0 << 0.980785280403230 << 0 << 0 << 0.195090322016128;
        b1->setCoords(b1pos);

        Body *b2 = new Body(1);
        bodies.push_back(b1);
    //    bodies.push_back(&b2);


        FixBallJoint *fbj = new FixBallJoint;
        vec v(3); v << 0 << 1 << 0;
        fbj->setU(v);
        fbj->setBody(b1);

        BallJoint *bj1 = new BallJoint;
        bj1->setBody1(b1);
        bj1->setBody2(b2);
        bj1->setU1(v);
        bj1->setU2(v*-1);

        constraints.push_back(fbj);
         //constraints.push_back(bj1);

        EulerParameterConstraint *epc1 = new EulerParameterConstraint;
        EulerParameterConstraint *epc2 = new EulerParameterConstraint;
        epc1->setBody(b1);
        epc2->setBody(b2);

        constraints.push_back(epc1);
        //constraints.push_back(epc2);

        nbodies = 1;
        nconstraints = 2;
        ndofs = 7;
        nindepC = 3;
        ndepC = 4;

        solver = new Ode4;
        solver->setTimeSpan(0,1);
        solver->setnsteps(1000);
        //solver->setInitialCondition(ic);
    }

    void runner(){
        solver->runSolver(dombsfunk);
    }

    vec dombsfunk(vec q, double t){
        Constraint *ccc = constraints.at(0);

        mat Cq = dombs::assembleCqMatrix(&constraints, ndofs);
        Cq.print("Cq");
        mat C = dombs::assembleCMatrix(&constraints);
        C.print("C");
        mat Mb = dombs::assembleBodyMassMatrix(&bodies);

        mat L, U, P;
        lu(L, U, P, Cq.t());
        uvec p = dombs::permutation2vec(P);

        uvec depC = p.head(ndepC-1);
        uvec indepC = p.tail(ndepC - ndofs-1);

        double tol = 0.00001;
        double normC = norm(C);
        while(normC > tol){
            Cq = dombs::assembleCqMatrix(&constraints, ndofs);
            C = dombs::assembleCMatrix(&constraints);

        }

        return q;
    }

}






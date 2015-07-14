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

namespace dombs{

     std::string inputfileName;

     std::vector<Body*> bodies;
     std::vector<Constraint*> constraints;

     Solver *solver;

     unsigned int nbodies, nconstraints, nconsteq, ndofs, nindepC, ndepC;

     arma::vec all_qq;
     arma::vec all_dqq;
     arma::vec gravityDir;

    void initilize(string infileName){

        inputfileName = infileName;

        readInputFile(); //set solver, init bodies and constraints
        runner();
    }

    void readInputFile(){

        //TILL EXEMPEL
        Body *b1 = new Body(0);
        Body *b2 = new Body(1);

        bodies.push_back(b1);
        bodies.push_back(b2);

        FixBallJoint *fbj = new FixBallJoint;
        vec v(3); v << 0 << 0.005 << 0;
        fbj->setU(v);
        fbj->setBody(b1);

        BallJoint *bj1 = new BallJoint;
        bj1->setBody1(b1);
        bj1->setBody2(b2);
        bj1->setU1(v*-1);
        bj1->setU2(v);

        constraints.push_back(fbj);
        constraints.push_back(bj1);

        EulerParameterConstraint *epc1 = new EulerParameterConstraint;
        EulerParameterConstraint *epc2 = new EulerParameterConstraint;
        epc1->setBody(b1);
        epc2->setBody(b2);

        constraints.push_back(epc1);
        constraints.push_back(epc2);

        nbodies = 2;
        nconstraints = 3;
        nconsteq = 8;
        ndofs = 14;
        nindepC = 6;
        ndepC = 8;

        all_qq.set_size(DOFS_PER_BODY*nbodies);
        all_qq << 0.00191341716182545 << -0.00461939766255643 << 0 << 0.980785280403230 << 0 << 0 << 0.195090322016128 << 0.00574025148547635 << -0.0138581929876693 << 0 << 0.980785280403230	<< 0 << 0 << 0.195090322016128;

        all_dqq.set_size(DOFS_PER_BODY*nbodies);
        all_dqq.zeros();

        vec *b1p = new vec(vec(all_qq.memptr(), 7, false));
        vec *b1v = new vec(vec(all_dqq.memptr(), 7, false));

        vec *b2p = new vec(vec(all_qq.memptr()+7, 7, false));
        vec *b2v = new vec(vec(all_dqq.memptr()+7, 7, false));

        b1->setq(b1p);
        b1->setdq(b1v);

        b2->setq(b2p);
        b2->setdq(b2v);

        vec gtemp(3); gtemp <<0<<-9.82<<0;
        gravityDir = gtemp;

        solver = new Ode4;
        solver->setTimeSpan(0,1);
        solver->setnsteps(1000);
        solver->setInitialCondition(join_vert(all_qq, all_dqq));
    }
    void runner(){
        solver->runSolver(dombsfunk);
    }

    vec dombsfunk(vec qin, double t){

        all_qq = qin.head(ndofs);
        all_dqq = qin.tail(ndofs);

        mat Cq = dombs::assembleCqMatrix(&constraints, ndofs);
        //Cq.print("Cq");
        mat C = dombs::assembleCMatrix(&constraints);
        //C.print("C");
        mat Mb = dombs::assembleBodyMassMatrix(&bodies);

        mat L, U, P;
        lu(L, U, P, Cq.t());
        uvec p = dombs::permutation2vec(P);

        uvec depC = p.head(ndepC);
        uvec indepC = p.tail(nindepC);

        double tol = 0.00001;
        double normC = norm(C);
        while(normC > tol){

            Cq = dombs::assembleCqMatrix(&constraints, ndofs);
            C = dombs::assembleCMatrix(&constraints);
            //C.print("C");

            mat Cqd = Cq.cols(depC);

            vec dq = -solve(Cqd,C);
            //dq.print("dq");

            all_qq(depC) += dq;

            normC = norm(C);
        }
        //cout<<"Exited the newton iteration loop"<<endl;

        //cout<<normC<<" normc"<<endl;

        mat Cqd = Cq.cols(depC);
        mat Cqi = Cq.cols(indepC);

        all_dqq(depC) = -inv(Cqd)*Cqi*all_dqq(indepC);

        vec Qv = dombs::assembleQv();
        vec Qg = dombs::assembleQg();
        vec Qc = zeros<vec>(nconsteq);

        mat QQ = join_vert( all_dqq , join_vert( Qv+Qg , Qc) );

        mat mmt1 = join_horiz(eye<mat>(ndofs,ndofs), join_horiz(zeros<mat>(ndofs,ndofs), zeros<mat>(ndofs, nconsteq)));
        mat mmt2 = join_horiz(zeros<mat>(ndofs,ndofs), join_horiz(Mb, Cq.t()));
        mat mmt3 = join_horiz(zeros<mat>(nconsteq,ndofs), join_horiz(Cq, zeros<mat>(nconsteq, nconsteq)));
        mat MM   = join_vert(join_vert(mmt1, mmt2), mmt3);

        vec qout = solve(MM,QQ);

        qout = qout(span(0,ndofs*2 - 1));
        return qout;
    }

}






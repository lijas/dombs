#include <dombs.h>
#include <Body.h>

using namespace std;
using namespace arma;

namespace dombs
{
//    DOFS_PER_BODY = 7;

    mat getA(vec EulerParameters){
        mat E = zeros<mat>(3,4);
        mat Ebar = zeros<mat>(3,4);

        E << -EulerParameters(1) << EulerParameters(0) << -EulerParameters(3) << EulerParameters(2) << endr
          << -EulerParameters(2) << EulerParameters(3) << EulerParameters(0) << -EulerParameters(1) << endr
          << -EulerParameters(3) << -EulerParameters(2) << EulerParameters(1) << EulerParameters(0) << endr;

        Ebar << -EulerParameters(1) << EulerParameters(0) << EulerParameters(3) << -EulerParameters(2) << endr
             << -EulerParameters(2) << -EulerParameters(3) << EulerParameters(0) << EulerParameters(1) << endr
             << -EulerParameters(3) << EulerParameters(2) << -EulerParameters(1) << EulerParameters(0) << endr;

        mat A = E*Ebar.t();
        return A;
    };

    mat getA(vec EulerParameters, int derivative){
        mat E = zeros<mat>(3,4);
        mat Ebar = zeros<mat>(3,4);

        E << -EulerParameters(1) << EulerParameters(0) << -EulerParameters(3) << EulerParameters(2) << endr
          << -EulerParameters(2) << EulerParameters(3) << EulerParameters(0) << -EulerParameters(1) << endr
          << -EulerParameters(3) << -EulerParameters(2) << EulerParameters(1) << EulerParameters(0) << endr;

        Ebar << -EulerParameters(1) << EulerParameters(0) << EulerParameters(3) << -EulerParameters(2) << endr
             << -EulerParameters(2) << -EulerParameters(3) << EulerParameters(0) << EulerParameters(1) << endr
             << -EulerParameters(3) << EulerParameters(2) << -EulerParameters(1) << EulerParameters(0) << endr;

        if (derivative == 0){
            mat E0 = zeros<mat>(3,4);
            mat Ebar0 = zeros<mat>(3,4);

            E0(0,1) = 1; E0(1,2) = 1; E0(2,3) = 1;
            Ebar0(0,1) = 1; Ebar0(1,2) = 1; Ebar0(2,3) = 1;

            mat Ader0 = E0*Ebar.t() + E*Ebar0.t();
            return Ader0;
        }
        else if (derivative == 1){
            mat E1 = zeros<mat>(3,4);
            mat Ebar1 = zeros<mat>(3,4);

            E1(0,0) = -1; E1(2,2) = 1; E1(1,3) = -1;
            Ebar1(0,0) = -1; Ebar1(2,2) = -1; Ebar1(1,3) = 1;

            mat Ader1 = E1*Ebar.t() + E*Ebar1.t();
            return Ader1;
        }
        else if (derivative == 2){
            mat E2 = zeros<mat>(3,4);
            mat Ebar2 = zeros<mat>(3,4);

            E2(1,0) = -1; E2(2,1) = -1; E2(0,3) = 1;
            Ebar2(1,0) = -1; Ebar2(2,1) = 1; Ebar2(0,3) = -1;

            mat Ader2 = E2*Ebar.t() + E*Ebar2.t();
            return Ader2;
        }
        else if (derivative == 3){
            mat E3 = zeros<mat>(3,4);
            mat Ebar3 = zeros<mat>(3,4);

            E3(2,0) = -1; E3(1,1) = 1; E3(0,2) = -1;
            Ebar3(2,0) = -1; Ebar3(1,1) = -1; Ebar3(0,2) = 1;

            mat Ader3 = E3*Ebar.t() + E*Ebar3.t();
            return Ader3;
        }
    };

    mat getG(vec EulerParameters){
        mat E = zeros<mat>(3,4);

        E << -EulerParameters(1) << EulerParameters(0) << -EulerParameters(3) << EulerParameters(2) << endr
          << -EulerParameters(2) << EulerParameters(3) << EulerParameters(0) << -EulerParameters(1) << endr
          << -EulerParameters(3) << -EulerParameters(2) << EulerParameters(1) << EulerParameters(0) << endr;

        mat G = 2*E;
        return G;

    };

    mat assembleCqMatrix(vector<Constraint*> *constraints, int ndofs){

        int nconstraints = constraints->size();
        int cCqRow = 0;

        mat Cq = zeros<mat>(totnConstEq(constraints), ndofs);

        for(int i=0; i<nconstraints; i++){
            Constraint *cconst = constraints->at(i);
            mat cq = cconst->getCq();
            cq.print("cq:");

            uvec assemCols = cconst->getAssemDofs();
            uvec assemRows = colon(cCqRow, cCqRow + cconst->getnCqRows() - 1);

            Cq(assemRows, assemCols) = cq;

            cCqRow += cconst->getnCqRows();
        }
        return Cq;

    }

    vec assembleCMatrix(vector<Constraint*> *constraints){
        int nconstraints = constraints->size();
        int cCRow = 0;

        vec C = zeros<mat>(totnConstEq(constraints));

        for(int i=0; i<nconstraints; i++){
            Constraint *cconst = constraints->at(i);
            mat c = cconst->getC();

            uvec assemRows = colon(cCRow, cCRow + cconst->getnCRows() - 1);

            C(assemRows) = c;

            cCRow += cconst->getnCqRows();
        }

        return C;
    }

    mat assembleBodyMassMatrix(std::vector<Body*> *bodies){

        int nbodies = bodies->size();
        mat bodiesMassMatrix = zeros<mat>(nbodies*DOFS_PER_BODY, nbodies*DOFS_PER_BODY);
        for(int i=0; i<nbodies; i++){
            Body *cb = bodies->at(i);
            mat mrr = eye<mat>(3,3)*cb->getMass();
            mat mtt = getG(cb->getep()).t() * cb->getMomentInertia() * getG(cb->getep());

            bodiesMassMatrix(cb->getDofsSpanPos(),cb->getDofsSpanPos()) = mrr;
            bodiesMassMatrix(cb->getDofsSpanEp(),cb->getDofsSpanEp()) = mtt;
        }
        return bodiesMassMatrix;
    }

    uvec getElemVec(vec v1, vec v2, int nmatrows){

        uvec indices(v1.n_elem*v2.n_elem);

        int counter = 0;
        for(int i=0; i<v1.n_elem; i++)
            for(int j=0; j<v2.n_elem; j++)
                indices(counter++) = v1(i) + nmatrows*v2(j);

        return indices;
    }

    uvec colon(int i1, int i2){
        uvec u1(i2-i1 + 1);
        for(int i=i1; i<=i2; i++)
            u1(i-i1) = i;

        return u1;
    }

    int totnConstEq(vector<Constraint*> *c){
        int toteq = 0;
        for(int i=0; i<c->size(); i++){
            toteq += c->at(i)->getnCqRows();
        }
        return toteq;
    }

    uvec permutation2vec(mat p){
        uvec pv(p.n_rows);
        for(int i=0; i<p.n_rows; i++){
            for(int j=0; j<p.n_cols; j++){
                if(p(i, j) != 0){
                    pv(i) = j;
                }
            }
        }
        return pv;
    }

    vec getqq(vector<Body*> *bodies){
//        nbdoies*DOFS_PER_BODY kanske kan bytas ut mot ndofs för ndofs är global
        int nbodies = bodies->size();
        double *qqdouble = new double[nbodies*DOFS_PER_BODY];
        for(int i=0; i<bodies->size(); i++){
            double *dd = bodies->at(i)->getq().memptr();
            std::copy(dd,dd+DOFS_PER_BODY,qqdouble +(i*DOFS_PER_BODY));
        }
        vec finalqq(qqdouble,nbodies*DOFS_PER_BODY, false);
        return finalqq;
    }

}








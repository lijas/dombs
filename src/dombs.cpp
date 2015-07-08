#include <dombs.h>
#include <Body.h>

using namespace std;
using namespace arma;

namespace dombs{

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








#include "Constraint.h"
#include "Body.h"

using namespace std;
using namespace arma;

uvec Constraint::getAssemDofs(){

    uvec dofs;

    for(int i=b1->getid()*7; i<b1->getid()*7 + 7; i++)
        dofs << i;

    for(int i=b2->getid()*7; i<b2->getid()*7 + 7; i++)
        dofs << i;

    return dofs;
}

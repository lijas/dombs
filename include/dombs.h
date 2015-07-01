#ifndef DOMBS_H
#define DOMBS_H

#include <vector>

namespace dombs
{
    int const DOFS_PER_BODY;
    mat getA(vec EulerParameters); // regular rotation matrix
    mat getA(vec EulerParameters, int derivative); // derivative of the rotation matrix
    mat getG(vec EulerParameters);

    mat getMassMatrix(vector<Body> *bodies);
};

#endif // DOMBS_H

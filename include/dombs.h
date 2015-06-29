#ifndef DOMBS_H
#define DOMBS_H


namespace dombs
{
    int const DOFS_PER_BODY;
    mat getA(vec EulerParameters); // regular rotation matrix
    mat getA(vec EulerParameters, int derivative); // derivative of the rotation matrix
    mat getG(vec EulerParameters);
};

#endif // DOMBS_H

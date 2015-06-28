#ifndef DOMBS_H
#define DOMBS_H


namespace dombs
{
    int const DOFS_PER_BODY;
    mat getA(vec EulerParameters);
    mat getG(vec EulerParameters);
};

#endif // DOMBS_H

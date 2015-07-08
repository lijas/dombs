#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

namespace dombs{

    vec NewtonRaphson(vec (*C)(vec q), mat (*Cq)(vec q), *q);

}

#endif // NEWTONRAPHSON_H

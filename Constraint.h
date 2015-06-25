#ifndef CONSTRAINT_H_INCLUDED
#define CONSTRAINT_H_INCLUDED

class Constraint {

public:

    virtual void getCq() = 0;
    virtual void getCt() = 0;
    virtual void getC()  = 0;
    virtual void getQc() = 0;

private:

    Body *b1, *b2;
};

#endif // CONSTRAINT_H_INCLUDED

#include "cutsphere.h"
#include "figurageometrica.h"
#include "sculptor.h"


cutSphere::cutSphere(int _xc, int _yc, int _zc, int _r){
    xc = _xc;
    yc = _yc;
    zc = _zc;
    r = _r;

}

cutSphere::~cutSphere(){}

void cutSphere::draw(Sculptor &fout){
    fout.cutSphere(xc, yc, zc, r);

}

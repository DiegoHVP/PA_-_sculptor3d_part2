#include "putsphere.h"
#include "sculptor.h"
#include "figurageometrica.h"


putSphere::putSphere(int xc, int yc, int zc, int _radius, float _r, float _g, float _b, float _a){
    xcenter = xc;
    ycenter = yc;
    zcenter = zc;
    radius = _radius;
    r = _r*255;
    g = _g*255;
    b = _b*255;
    a = _a*255;
}

putSphere::~putSphere(){}

void putSphere::draw(Sculptor &fout){
    fout.setColor(r,g,b,a);
    fout.putSphere(xcenter, ycenter, zcenter, radius);
}


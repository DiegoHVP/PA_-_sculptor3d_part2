#include "putellipsoid.h"
#include "putvoxel.h"
#include "sculptor.h"
#include "figurageometrica.h"

putEllipsoid::putEllipsoid(int xc, int yc, int zc, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a){
    xcenter = xc;
    ycenter = yc;
    zcenter = zc;
    rx = _rx;
    ry = _ry;
    rz = _rz;
    r = _r*255;
    g = _g*255;
    b = _b*255;
    a = _a*255;
}
putEllipsoid::~putEllipsoid(){}

void putEllipsoid::draw(Sculptor &fout){
    fout.setColor(r,g,b,a);
    fout.putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz);
}

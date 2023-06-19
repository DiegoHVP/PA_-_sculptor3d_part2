#include "putbox.h"
#include "putvoxel.h"
#include "figurageometrica.h"
#include "sculptor.h"

putBox::putBox(int _x0,int _x1,int _y0,int _y1,int _z0,int _z1, float _r, float _g, float _b, float _a){
    x0 = _x0;
    x1 = _x1;
    y0 = _y0;
    y1 = _y1;
    z0 = _z0;
    z1 = _z1;
    r = _r*255;
    g = _g*255;
    b = _b*255;
    a = _a*255;
}

putBox::~putBox(){}

void putBox::draw(Sculptor &fout){
    fout.setColor(r, g, b, a);
    fout.putBox(x0, x1, y0, y1, z0, z1);
}

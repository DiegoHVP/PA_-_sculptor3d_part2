#include "putvoxel.h"
#include "sculptor.h"

putVoxel::putVoxel(int _x0, int _y0, int _z0, float _r, float _g, float _b, float _a){
    x0 = _x0;
    y0 = _y0;
    z0 = _z0;
    r = _r*255;
    g = _g*255;
    b = _b*255;
    a = _a*255;
}

putVoxel::~putVoxel(){}

void putVoxel::draw(Sculptor &fout){
    fout.setColor(r,g,b,a);
    fout.putVoxel(x0,y0,z0);
}

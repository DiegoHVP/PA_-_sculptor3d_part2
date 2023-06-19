#include "cutellipsoid.h"
#include "cutvoxel.h"
#include "sculptor.h"
#include "figurageometrica.h"

cutEllipsoid::cutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz){
    xc = _xc;
    yc = _yc;
    zc = _zc;
    rx =_rx;
    ry =_ry;
    rz =_rz;
}

cutEllipsoid::~cutEllipsoid(){}

void cutEllipsoid::draw(Sculptor &fout){
    fout.cutEllipsoid(xc, yc, zc, rx, ry, rz);

}

#include "cutvoxel.h"
#include "figurageometrica.h"
#include "sculptor.h"


cutVoxel::cutVoxel(int _x0, int _y0, int _z0){
        x0 = _x0;
        y0 = _y0;
        z0 = _z0;
 }

cutVoxel::~cutVoxel(){}

void cutVoxel::draw(Sculptor &fout){
    fout.putVoxel(x0,y0,z0);
}

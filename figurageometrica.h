#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Voxel.h"
#include "sculptor.h"


/**
 * @struct FiguraGeometrica
 * @brief Estrutura que representa as Figuras Geometricas.
 *
 * Todas as figuras possuem posição(x, y, z), transparencia(a), alem de ter uma função desenho.
 */
class FiguraGeometrica
{
protected:
    int x,y,z; /**< Posição (x, y, z) de cada figura*/
    float r, g, b, a; /**< Componentes cor(R,G,B) e transparecia(a)*/
public:
    FiguraGeometrica(); /**< Construtor de FiguraGeometrica*/

    virtual ~FiguraGeometrica(); /**< Destrutor apenas de FiguraGeometrica*/
    virtual void draw(Sculptor &fout)=0; /**< função abstrata Draw de Sculptor*/
};

#endif // FIGURAGEOMETRICA_H


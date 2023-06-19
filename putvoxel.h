#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"


/**
 * @brief A classe putVoxel é uma classe derivada de FiguraGeometrica que representa um voxel a inserida usando Sculptor.
 */

class putVoxel : public FiguraGeometrica
{
    int x0, y0, z0; /**< Coordenadas do voxel */

public:
    /**
    * @brief putVoxel é o construtor da classe
    * @param _x0 coordenada x do voxel
    * @param _y0 coordenada y do voxel
    * @param _z0 coordenada z do voxel
    * @param _r componente da cor vermelha
    * @param _g componente da cor verde
    * @param _b componente da cor azul
    * @param _a componente da transparencia
    */
    putVoxel(int _x0, int _y0, int _z0, float _r, float _g, float _b, float _a);

    /**
     * @brief ~putVoxel é o destrutor da classe cutEllipsoid.
     */
    ~putVoxel();

    /**
     * @brief draw é um método virtual da classe FiguraGeometrica que insere um voxel usando Sculptor.
     * @param fout referência para o objeto Sculptor onde o voxel sera inserido
     */
    void draw(Sculptor &fout);
};

#endif // PUTVOXEL_H

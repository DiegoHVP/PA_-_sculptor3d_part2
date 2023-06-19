#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe cutVoxel é uma classe derivada de FiguraGeometrica que representa voxel a ser removido usando o Sculptor.
 */
class cutVoxel : public FiguraGeometrica
{
private:
    int x0, y0, z0;  /**< Coordenadas do voxel a ser removido */

public:

    /**
         * @brief cutVoxel é o construtor da classe
         * @param _xc coordenada x do voxel a ser removido
         * @param _yc coordenada y do voxel a ser removido
         * @param _zc coordenada z do voxel a ser removido
         */
    cutVoxel(int _x0, int _y0, int _z0);
    /**
     * @brief ~cutVoxel é o destrutor da classe
     */
    ~cutVoxel();
    /**
     * @brief draw é um método virtual da classe FiguraGeometrica que remove um voxel usando o Sculptor.
     * @param fout referência para o objeto Sculptor onde o voxel será removido
     */
    void draw(Sculptor &fout);
};

#endif // CUTVOXEL_H

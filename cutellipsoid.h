#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe cutEllipsoid é uma classe derivada de FiguraGeometrica que representa um elipsóide a ser removido usando o Sculptor.
 */

class cutEllipsoid : public FiguraGeometrica
{
private:
    int xc, yc, zc, rx, ry, rz; /**< Coordenadas e dimensões do elipsóide a ser removido */
public:
    /**
     * @brief cutEllipsoid e o construtor da classe
     * @param _xc coordenada x do centro do elipsoide
     * @param _yc coordenada y do centro do elipsoide
     * @param _zc coordenada z do centro do elipsoide
     * @param _rx raio do elipsoide no eixo x
     * @param _ry raio do elipsoide no eixo y
     * @param _rz raio do elipsoide no eixo z
     */
    cutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz);

    /**
     * @brief ~cutEllipsoid é o destrutor da classe
     */
    ~cutEllipsoid();

    /**
     * @brief draw é um método virtual da classe FiguraGeometrica que remove o elipsoide usando Sculptor.
     * @param fout referência para o objeto Sculptor onde o elipsóide será removido
     */
    void draw(Sculptor &fout);
};

#endif // CUTELLIPSOID_H

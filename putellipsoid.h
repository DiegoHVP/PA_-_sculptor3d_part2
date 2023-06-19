#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"


/**
 * @brief A classe putEllipsoid é uma classe derivada de FiguraGeometrica que representa uma Elipse a ser inserida usando Sculptor.
 */

class putEllipsoid : public FiguraGeometrica
{
private:
    int xcenter, ycenter, zcenter, rx, ry, rz; /**< Coordenadas e raios do elipsóide a ser inserida */

public:
    /**
         * @brief putEllipsoid é o construtor da classe.
         * @param _xc coordenada x do centro do elipsóide
         * @param _yc coordenada y do centro do elipsóide
         * @param _zc coordenada z do centro do elipsóide
         * @param _rx raio do elipsóide no eixo x
         * @param _ry raio do elipsóide no eixo y
         * @param _rz raio do elipsóide no eixo z
         * @param _r componente da cor vermelha
         * @param _g componente da cor verde
         * @param _b componente da cor azul
         * @param _a componente da transparencia
         */
    putEllipsoid(int xc, int yc, int zc, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
    /**
     * @brief ~putEllipsoid é o destrutor da classe
     */
    ~putEllipsoid();

    /**
     * @brief draw é um método virtual da classe FiguraGeometrica que insere um elipsóide usando o Sculptor.
     * @param fout referência para o objeto Sculptor onde o elipsóide sera inserido
     */
    void draw(Sculptor &fout);
};

#endif // PUTELLIPSOID_H

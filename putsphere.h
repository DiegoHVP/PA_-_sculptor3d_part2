#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"


/**
 * @brief A classe putSphere é uma classe derivada de FiguraGeometrica que representa uma esfera a ser inserida usando Sculptor.
 */

class putSphere : public FiguraGeometrica
{
private:
    int xcenter, ycenter, zcenter, radius; /**< Coordenadas e raio da esfera a ser inserida */

public:
    /**
     * @brief putSphere é o construtor da classe
     * @param xc coordenada x do centro do elipsóide
     * @param yc coordenada y do centro do elipsóide
     * @param zc coordenada z do centro do elipsóide
     * @param _rx raio do elipsóide no eixo x
     * @param _ry raio do elipsóide no eixo y
     * @param _rz raio do elipsóide no eixo z
     * @param _r componente da cor vermelha
     * @param _g componente da cor verde
     * @param _b componente da cor azul
     * @param _a componente da transparencia
     */
    putSphere(int xc, int yc, int zc, int _radius, float _r, float _g, float _b, float _a);

    /**
    * @brief ~putSphere é o destrutor da classe
    */
    ~putSphere();

    /**
    * @brief draw é um método virtual da classe FiguraGeometrica que desenha uma esfera usando o Sculptor.
    * @param fout referência para o objeto Sculptor onde a esfera sera inserida
    */
    void draw(Sculptor &fout);
};

#endif // PUTSPHERE_H

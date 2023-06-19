#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe cutSphere é uma classe derivada de FiguraGeometrica que representa um esfera a ser removido usando o Sculptor.
 */

class cutSphere : public FiguraGeometrica
{
private:
    int xc, yc, zc, r; /**< Coordenadas e raio d esfera a ser removido */

public:
    /**
     * @brief cutSphere é o construtor da classe
     * @param _xc coordenada x do centro do esfera
     * @param _yc coordenada y do centro do esfera
     * @param _zc coordenada z do centro do esfera
     * @param _r raio da esfera
     */
    cutSphere(int _xc, int _yc, int _zc, int _r);
    /**
     * @brief ~cutSphere é o destrutor da classe
     */
    ~cutSphere();

    /**
     * @brief draw é um método virtual da classe FiguraGeometrica que remove uma esfera usando o Sculptor.
     * @param fout referência para o objeto Sculptor onde a esfera será removido
     */
    void draw(Sculptor &fout);

};

#endif // CUTSPHERE_H

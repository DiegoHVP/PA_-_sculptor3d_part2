#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe putBox é uma classe derivada de FiguraGeometrica que representa uma a inserida usando Sculptor.
 */

class putBox : public FiguraGeometrica
{
private:
    int x0, x1, y0, y1, z0, z1; /**< Coordenadas da caixa a ser inserida*/

public:
    /**
     * @brief putBox é o construtor da classe
     * @param _x0 coordenada x a esquerda da caixa
     * @param _x1 coordenada x a direita da caixa
     * @param _y0 coordenada y a esquerda da caixa
     * @param _y1 coordenada y a direita da caixa
     * @param _z0 coordenada z abaixo da caixa
     * @param _z1 coordenada z acima da caixa
     * @param _r componente da cor vermelha
     * @param _g componente da cor verde
     * @param _b componente da cor azul
     * @param _a componente da transparencia
     */
    putBox(int _x0,int _x1,int _y0,int _y1,int _z0,int _z1, float _r, float _g, float _b, float _a);

    /**
     * @brief ~putBox é o destrutor da classe
     */
    ~putBox();


    /**
     * @brief draw é um método virtual da classe FiguraGeometrica que adiciona uma caixa usando o Sculptor.
     * @param fout referência para o objeto Sculptor onde a caixa será inserida
     */
    void draw(Sculptor &fout);
};

#endif // PUTBOX_H

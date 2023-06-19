#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief A classe cutBox é uma classe derivada de FiguraGeometrica que representa uma caixa a ser removida usando o Sculptor.
 */

class cutBox : public FiguraGeometrica
{
private:
    int x0, x1, y0, y1, z0, z1; /**< Coordenadas da caixa a ser removida */
public:
    /**
   * @brief cutBox é o construtor da classe cutBox.
   * @param _x0 coordenada x do canto superior esquerdo da caixa
   * @param _x1 coordenada x do canto inferior direito da caixa
   * @param _y0 coordenada y do canto superior esquerdo da caixa
   * @param _y1 coordenada y do canto inferior direito da caixa
   * @param _z0 coordenada z do canto superior esquerdo da caixa
   * @param _z1 coordenada z do canto inferior direito da caixa
   */
    cutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);

    /**
   * @brief ~cutBox é o destrutor da classe cutBox.
   */

    ~cutBox();

    /**
   * @brief draw é um método virtual da classe FiguraGeometrica que desenha a caixa a ser removida usando o Sculptor.
   * @param fout referência para o objeto Sculptor onde a caixa será removida
   */
    void draw(Sculptor &fout);

};

#endif // CUTBOX_H

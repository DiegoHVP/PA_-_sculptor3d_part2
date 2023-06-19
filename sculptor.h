#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "Voxel.h"

/**
 * @class Sculptor
 * @brief Classe que representa um escultor 3D.
 *
 * O escultor é responsável por criar e manipular uma matriz tridimensional de voxels.
 * Ele oferece métodos para realizar operações como colocar e remover voxels, criar caixas,
 * esferas e elipsoides, definir cores e transparências, e salvar a escultura em um arquivo OFF.
 */
class Sculptor {
private:
  Voxel ***v; // Matriz 3D
  int nx,ny,nz; // Dimensoes
  float r,g,b,a; // Cores e transparencia
public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  void setColor(float _r, float _g, float _b, float _a);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(const char* filename);
};
#endif // SCULPTOR_H



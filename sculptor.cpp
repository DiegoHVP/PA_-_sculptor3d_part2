#include <iostream>
#include <iomanip>
#include <fstream>
#include "Voxel.h"
#include "sculptor.h"


/**
 * @brief Construtor da classe Sculptor.
 *
 * @param _nx Dimensão em X do escultor.
 * @param _ny Dimensão em Y do escultor.
 * @param _nz Dimensão em Z do escultor.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 */
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
        }
    }
    for(int i = 0; i<nx;i++) for(int j = 0;j<ny;j++) for (int k = 0; k<nz;k++)
        v[i][j][k].show = false;

};
/**
 * @brief Destrutor da classe Sculptor.
 * Liberar a memoria reservada.
 */
Sculptor::~Sculptor(){
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
};
/**
 * @brief Define a cor atual utilizada para desenhar.
 *
 * @param _r Componente vermelho da cor (entre 0 e 255).
 * @param _g Componente verde da cor (entre 0 e 255).
 * @param _b Componente azul da cor (entre 0 e 255).
 * @param _a Transparência da cor (entre 0 e 255).
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * v.setColor(255, 0, 0, 255); // Define a cor vermelha com transparência total
 */
void Sculptor::setColor(float _r, float _g, float _b, float _a){
    r = _r/255.0;
    g = _g/255.0;
    b = _b/255.0;
    a = _a/255.0;

};
/**
 * @brief Ativa o voxel na posição (x, y, z) e atribui a ele a cor atual.
 *
 * @param x Posição do voxel no eixo X.
 * @param y Posição do voxel no eixo Y.
 * @param z Posição do voxel no eixo Z.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * v.setColor(255, 0, 0, 255); // Define a cor vermelha com transparência total
 *
 * v.putVoxel(5, 5, 5); // Ativa o voxel na posição (5, 5, 5) e atribui a ele a cor vermelha
 */
void Sculptor::putVoxel(int x, int y, int z){
    if( x>=0 && x<=(nx-1) && y>0 && y<=(ny-1) && z>=0 && z<=(nz-1)){
        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}
/**
 * @brief Desativa o voxel na posição (x, y, z).
 *
 * @param x Posição do voxel no eixo X.
 * @param y Posição do voxel no eixo Y.
 * @param z Posição do voxel no eixo Z.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * v.putVoxel(5, 5, 5); // Ativa o voxel na posição (5, 5, 5)
 *
 * v.cutVoxel(5, 5, 5); // Desativa o voxel na posição (5, 5, 5)
 */
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false;
}
/**
 * @brief Ativa uma caixa de voxels delimitada pelas coordenadas dos pontos (x0, y0, z0) e (x1, y1, z1) e atribui a eles a cor atual.
 *
 * @param x0 Coordenada X do canto superior esquerdo da caixa.
 * @param x1 Coordenada X do canto inferior direito da caixa.
 * @param y0 Coordenada Y do canto superior esquerdo da caixa.
 * @param y1 Coordenada Y do canto inferior direito da caixa.
 * @param z0 Coordenada Z do canto superior esquerdo da caixa.
 * @param z1 Coordenada Z do canto inferior direito da caixa.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * v.setColor(0, 0, 255, 255); // Define a cor azul com transparência total
 *
 * v.putBox(2, 7, 2, 7, 2, 7); // Ativa uma caixa delimitada pelos pontos (2, 2, 2) e (7, 7, 7) e atribui a ela a cor azul
 */
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i<x1;i++) for(int j = y0;j<y1;j++) for (int k = z0; k<z1;k++)
        putVoxel(i,j,k);
}
/**
 * @brief Desativa uma caixa de voxels delimitada pelas coordenadas dos pontos (x0, y0, z0) e (x1, y1, z1).
 *
 * @param x0 Coordenada X do canto superior esquerdo da caixa.
 * @param x1 Coordenada X do canto inferior direito da caixa.
 * @param y0 Coordenada Y do canto superior esquerdo da caixa.
 * @param y1 Coordenada Y do canto inferior direito da caixa.
 * @param z0 Coordenada Z do canto superior esquerdo da caixa.
 * @param z1 Coordenada Z do canto inferior direito da caixa.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * v.putBox(2, 7, 2, 7, 2, 7); // Ativa uma caixa delimitada pelos pontos (2, 2, 2) e (7, 7, 7)
 *
 * v.cutBox(3, 6, 3, 6, 3, 6); // Desativa uma caixa delimitada pelos pontos (3, 3, 3) e (6, 6, 6)
 */
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i<x1;i++) for(int j = y0;j<y1;j++) for (int k = z0; k<z1;k++)
        v[i][j][k].show = false;
}
/**
 * @brief Ativa uma esfera de voxels com centro em (xcenter, ycenter, zcenter) e raio "radius", atribuindo a eles a cor atual.
 *
 * @param xcenter Coordenada X do centro da esfera.
 * @param ycenter Coordenada Y do centro da esfera.
 * @param zcenter Coordenada Z do centro da esfera.
 * @param radius Raio da esfera.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * v.setColor(255, 255, 0, 255); // Define a cor amarela com transparência total
 *
 * v.putSphere(5, 5, 5, 3); // Ativa uma esfera com centro em (5, 5, 5) e raio 3, atribuindo a ela a cor amarela
 */
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i = -radius; i<radius;i++) for(int j = -radius;j<radius;j++) for (int k = -radius; k<radius;k++){
        if( (i*i + j*j +k*k) <= (radius*radius) )
            putVoxel( xcenter + i, ycenter + j , zcenter + k);
    }
}
/**
 * @brief Desativa uma esfera de voxels com centro em (xcenter, ycenter, zcenter) e raio "radius".
 *
 * @param xcenter Coordenada X do centro da esfera.
 * @param ycenter Coordenada Y do centro da esfera.
 * @param zcenter Coordenada Z do centro da esfera.
 * @param radius Raio da esfera.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * v.putSphere(5, 5, 5, 3); // Ativa uma esfera com centro em (5, 5, 5) e raio 3
 *
 * v.cutSphere(5, 5, 5, 2); // Desativa uma esfera com centro em (5, 5, 5) e raio 2
 */
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i = -radius; i<radius;i++) for(int j = -radius;j<radius;j++) for (int k = -radius; k<radius;k++){
        if( (i*i + j*j +k*k) <= (radius*radius) )
            cutVoxel( xcenter + i, ycenter + j , zcenter + k);
    }
}
/**
 * @brief Ativa um elipsoide de voxels com centro em (xcenter, ycenter, zcenter), raios "rx", "ry" e "rz", atribuindo a eles a cor atual.
 *
 * @param xcenter Coordenada X do centro do elipsoide.
 * @param ycenter Coordenada Y do centro do elipsoide.
 * @param zcenter Coordenada Z do centro do elipsoide.
 * @param rx Raio em X do elipsoide.
 * @param ry Raio em Y do elipsoide.
 * @param rz Raio em Z do elipsoide.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * v.setColor(0, 255, 0, 255); // Define a cor verde com transparência total
 *
 * v.putEllipsoid(5, 5, 5, 3, 4, 2); // Ativa um elipsoide com centro em (5, 5, 5), raios 3, 4 e 2, atribuindo a ele a cor verde
 */
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    for (int i = 0; i<nx ; i++) for (int j = 0; j < ny; j++) for (int k = 0; k < nz; k++) {
        if( ((i*i)/(float)(rx*rx) + (j*j)/(float)(ry*ry) + (k*k)/(float)(rz*rz)) <= 1 )
            putVoxel(xcenter + i, ycenter + j, zcenter + k);
    }
}
/**
 * @brief Desativa um elipsoide de voxels com centro em (xcenter, ycenter, zcenter), raios "rx", "ry" e "rz".
 *
 * @param xcenter Coordenada X do centro do elipsoide.
 * @param ycenter Coordenada Y do centro do elipsoide.
 * @param zcenter Coordenada Z do centro do elipsoide.
 * @param rx Raio em X do elipsoide.
 * @param ry Raio em Y do elipsoide.
 * @param rz Raio em Z do elipsoide.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * v.putEllipsoid(5, 5, 5, 3, 4, 2); // Ativa um elipsoide com centro em (5, 5, 5), raios 3, 4 e 2
 *
 * v.cutEllipsoid(5, 5, 5, 2, 3, 1); // Desativa um elipsoide com centro em (5, 5, 5), raios 2, 3 e 1
 */
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float tx,ty,tz;
    for(int i = -rx; i<rx;i++) for(int j = -ry;j<ry;j++) for (int k = -rz; k<rz;k++){
        tx = ((i - xcenter) * (i - xcenter)) / (float)(rx * rx);
        ty = ((j - ycenter) * (j - ycenter)) / (float)(ry * ry);
        tz = ((k - zcenter) * (k - zcenter)) / (float)(rz * rz);

        if ((tx + ty + tz) <= 1) {
            cutVoxel(i+xcenter, j+ycenter, k+zcenter);
        }
    }
}
/**
 * @brief Escreve a estrutura do objeto em um arquivo no formato OFF.
 *
 * @param filename Nome do arquivo a ser salvo.
 *
 * Exemplo de uso:
 *
 * Sculptor v(10, 10, 10);
 *
 * // ... Código para ativar ou desativar voxels ...
 *
 * v.writeOFF("sculpture.off"); // Salva a escultura no arquivo sculpture.off
 */
void Sculptor::writeOFF(const char* filename){
    std::ofstream file;
    std::cout<<"Salvando..."<<std::endl;
    file.open(filename);
    if(!file.is_open()){
        std::cout<<"ERRO AO CRIAR ARQUIVO"<<std::endl;
        exit(1);
    }
    int cont = 0;
    for(int i = 0; i<nx;i++) for(int j = 0;j<ny;j++) for (int k = 0; k<nz;k++)
        if(v[i][j][k].show)
            cont++;
    file<<"OFF\n"<<cont*8<<" "<<cont*6<<" "<<0<<std::endl;
    for(int i = 0; i<nx;i++) for(int j = 0;j<ny;j++) for (int k = 0; k<nz;k++)
        if(v[i][j][k].show){
            file << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
            file << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
            file << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
            file << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
            file << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
            file << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
            file << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
            file << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
        }

    int vertice = 0;
   file << std::fixed<<std::setprecision(2); // Fixa em decimal float <iomanip>

    for (int i = 0; i < nx; i++) for (int j = 0; j < ny; j++) for (int k = 0; k < nz; k++)
        if (v[i][j][k].show) {
            file << 4 << " " << vertice + 0 << " " << vertice + 3 << " " << vertice + 2 << " " << vertice + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
            file << 4 << " " << vertice + 4 << " " << vertice + 5 << " " << vertice + 6 << " " << vertice + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
            file << 4 << " " << vertice + 0 << " " << vertice + 1 << " " << vertice + 5 << " " << vertice + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
            file << 4 << " " << vertice + 0 << " " << vertice + 4 << " " << vertice + 7 << " " << vertice + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
            file << 4 << " " << vertice + 3 << " " << vertice + 7 << " " << vertice + 6 << " " << vertice + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
            file << 4 << " " << vertice + 1 << " " << vertice + 2 << " " << vertice + 6 << " " << vertice + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
            vertice += 8;
        }
    file.close();
    std::cout<<"ARQUIVO SALVO COM SUCESSO"<<std::endl;

}



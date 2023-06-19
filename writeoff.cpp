#include "writeoff.h"
#include "fstream"
#include "iostream"
#include "iomanip"

writeOFF::writeOFF(const char* filename){
    std::ofstream file;
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

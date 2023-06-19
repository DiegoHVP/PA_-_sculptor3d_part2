#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "sculptor.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"

int main(){

    std::vector<FiguraGeometrica*> figs;
    std::vector<FiguraGeometrica*>::iterator it;

    std::ifstream fin;

    int nx=0, ny=0, nz=0;

    fin.open("c:\\roteiro.txt");

    if(!fin.is_open()){
      std::cout << "Erro: não foi possivel ler o arquivo\n";
      exit(EXIT_FAILURE);
    }

    std::string s;
    float r, g, b, a; //PARA CASO NÃO DECLARE COR, ADCIONAR COR ANTERIOR

    while(fin.good()){
      if(!fin.good())
          break;
      fin >> s;

      if(s.compare("dim")==0){
        fin >> nx >> ny >> nz;
        std::cout<<"Dimensoes definidas em:"<<std::endl;
        std::cout<<"x: "<<nx<<"  y: "<<ny<<"  z: "<<nz<<std::endl;
      }
      if(s.compare("putvoxel")==0){
        int x, y, z;
        fin >> x >> y >> z;
        fin >> r >> g >> b >> a;
        figs.push_back(new putVoxel(x,y,z,r,g,b,a));
        std::cout<<"executando putvoxel..."<<std::endl;
      }
      if(s.compare("cutvoxel")==0){
        int x, y, z;
        fin >> x >> y >> z;
        figs.push_back(new cutVoxel(x,y,z));
        std::cout<<"executando cutVoxel..."<<std::endl;
      }
      if(s.compare("putbox")==0){
        int x0, x1, y0, y1, z0, z1;
        fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
        fin >> r >> g >> b >> a;
        figs.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        std::cout<<"executando putBox..."<<std::endl;
      }
      if(s.compare("cutbox")==0){
        int x0, x1, y0, y1, z0, z1;
        fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
        figs.push_back(new cutBox(x0,x1,y0,y1,z0,z1) );
        std::cout<<"executando cutBox..."<<std::endl;
      }
      if(s.compare("putsphere")==0){
        int x0, y0, z0, raio;
        fin >> x0 >> y0 >> z0 >> raio;
        fin >> r >> g >> b >> a;
        figs.push_back(new putSphere(x0,y0,z0,raio,r,g,b,a));
        std::cout<<"executando putSphere..."<<std::endl;
      }
      if(s.compare("cutsphere")==0){
        int x0, y0, z0, raio;
        fin >> x0 >> y0 >> z0 >> raio;
        figs.push_back(new cutSphere(x0,y0,z0,raio));
        std::cout<<"executando cutSphere..."<<std::endl;
      }
      if(s.compare("putellipsoid")==0){
        int x0, y0, z0, rx, ry, rz;
        fin >> x0 >> y0 >> z0 >> rx >> ry >> rz;
        fin >> r >> g >> b >> a;
        figs.push_back(new putEllipsoid(x0,y0,z0,rx,ry,rz,r,g,b,a));
        std::cout<<"executando putEllipsoid..."<<std::endl;
      }
      if(s.compare("cutellipsoid")==0){
        int x0, y0, z0, rx, ry, rz;
        fin >> x0 >> y0 >> z0 >> rx >> ry >> rz;
        figs.push_back(new cutEllipsoid(x0,y0,z0,rx,ry,rz));
        std::cout<<"executando cutEllipsoid..."<<std::endl;
      }
    }

    Sculptor fout(nx,ny,nz);

    std::cout<<"executando o draw do vetor..."<<std::endl;
    for(auto it: figs){
      it->draw(fout);
    }

    for(it = figs.begin(); it!=figs.end(); it++){
      delete *it;
    }

    fout.writeOFF("desenho.off");

    return 0;
}

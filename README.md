# Projeto parte 2 - Sculptor3D
## Introdução

Este projeto faz o uso do projeto [Sculptor3D](https://github.com/DiegoHVP/sculptor3d). O objetivo é aprender conceitos de herança, permitindo a criação de diferentes figuras geométricas.

## Funcionamento

O programa utiliza o conceito de herança para criar diferentes tipos de figuras geométricas a partir da classe base abstrata `FiguraGeometrica`. Cada figura geométrica herda da classe base e implementa o método virtual puro `draw`, que é responsável por desenhar a figura em um objeto `Sculptor`.

## Classe Base: `FiguraGeometrica`

### `FiguraGeometrica` (arquivo "FiguraGeometrica.h")

Essa é a classe base abstrata que define a interface para todas as figuras geométricas suportadas. Ela contém as coordenadas (x, y, z) que representam a posição da figura, bem como as componentes de cor (r, g, b) e transparência (a). Esses atributos são protegidos para que possam ser acessados pelas classes derivadas.

A classe possui um construtor padrão e um destrutor virtual, mas seu uso é feito apenas para fins de herança, e não deve ser instanciada diretamente. Além disso, a classe define o método virtual puro `draw`, que será implementado nas classes derivadas para desenhar a figura no objeto `Sculptor`.

## Classes Derivadas

As classes que herdam da `FiguraGeometrica` representam os diferentes tipos de figuras geométricas suportadas pelo programa.

### `putBox` (arquivo "putbox.h")

Essa classe representa uma caixa (ou cubo) que é inserida no espaço tridimensional. Ela herda da classe `FiguraGeometrica` e implementa o método `draw`, que desenha a caixa no objeto `Sculptor`.

### `cutBox` (arquivo "cutbox.h")

Essa classe representa uma operação de corte de uma caixa no espaço tridimensional. Ela herda da classe `FiguraGeometrica` e implementa o método `draw`, que realiza o corte no objeto `Sculptor`.

### `putSphere` (arquivo "putsphere.h")

Essa classe representa uma esfera que é inserida no espaço tridimensional. Ela herda da classe `FiguraGeometrica` e implementa o método `draw`, que desenha a esfera no objeto `Sculptor`.

### `cutSphere` (arquivo "cutsphere.h")

Essa classe representa uma operação de corte de uma esfera no espaço tridimensional. Ela herda da classe `FiguraGeometrica` e implementa o método `draw`, que realiza o corte no objeto `Sculptor`.

### `putEllipsoid` (arquivo "putellipsoid.h")

Essa classe representa um elipsoide que é inserido no espaço tridimensional. Ela herda da classe `FiguraGeometrica` e implementa o método `draw`, que desenha o elipsoide no objeto `Sculptor`.

### `cutEllipsoid` (arquivo "cutellipsoid.h")

Essa classe representa uma operação de corte de um elipsoide no espaço tridimensional. Ela herda da classe `FiguraGeometrica` e implementa o método `draw`, que realiza o corte no objeto `Sculptor`.

## Funcionamento do Programa

O programa lê o arquivo **"roteiro.txt"** para identificar as figuras a serem criadas e operações a serem realizadas. As dimensões do espaço tridimensional são definidas a partir das informações lidas no arquivo. Em seguida, cada figura geométrica é criada de acordo com os comandos fornecidos e armazenada no vetor `figs`, que contém ponteiros para objetos da classe `FiguraGeometrica`.
Exemplo do roteiro.txt

```
dim 100 100 100 // dimensões x, y e z

putbox 0 10 0 20 0 10 0.6 0.6 0.6 1 // caixa (x0,x1,y0,y1,z0,z1, r, g, b, transparência)
putbox 20 30 0 30 0 15 0.7 0.7 0.7 1
putbox 40 50 0 25 0 12 0.8 0.8 0.8 1
putbox 60 80 0 35 0 20 0.9 0.9 0.9 1
putbox 80 90 0 20 0 10 0.6 0.6 0.6 1 

putsphere 90 90 90 6 1 1 0.2 1 // esfera (xcentro, ycentro, zcentro, raio, r, g, b, transparência)
```

Após a criação das figuras, o programa itera sobre o vetor `figs` e chama o método `draw` para cada figura. Esse método desenha no objeto `Sculptor`. Por fim, o resultado é escrito em um arquivo no formato OFF chamado **"desenho.off"**.

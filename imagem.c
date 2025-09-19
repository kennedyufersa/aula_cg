//https://github.com/kennedyufersa/aula_cg/
#include <stdio.h>
#include <stdlib.h>
#define width 400
#define height 300
#define MAX_COLOR 256

typedef struct Pixel{
    int r;
    int g;
    int b;
}pixel, cor;

pixel imagem[width][height];

void criarTela(cor background);
void criarPonto(int x, int y, cor corPonto);

void show();

cor corTela =  (cor){100,100,200};
cor preto = (cor) {0,0,0};

int main(int argc, char *argv[]){

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    criarTela(corTela);
    criarPonto(x,y, preto);
    
    show();
}

void criarTela(cor background){
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < width; j++){
            imagem[i][j] = background;
        }
    }
}

void show(){
    //Cabeçalho
    printf("P3\n");
    printf("%d %d\n", width, height);
    printf("%d\n", MAX_COLOR);
    cor aux;
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < width; j++){
            aux = imagem[i][j];
            printf("%d %d %d\n", aux.r, aux.g, aux.b);
        }
    }
}
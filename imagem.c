//https://github.com/kennedyufersa/aula_cg/
#include <stdio.h>
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
void show();

int main(){
    criarTela((cor){100, 100, 200});
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
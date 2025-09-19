//https://github.com/kennedyufersa/aula_cg/
#include <stdio.h>
#include <stdlib.h>
#define width 40
#define height 30
#define MAX_COLOR 256

typedef struct Pixel{
    int r;
    int g;
    int b;
}pixel, cor;

pixel imagem[height][width];

void criarTela(cor background);
void criarPonto(int x, int y, cor corPonto);

// void show();
void criarArquivo();

cor corTela =  (cor){100,100,200};
cor preto = (cor) {0,0,0};

int main(int argc, char *argv[]){

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    criarTela(corTela);
    criarPonto(x,y, preto);

    criarArquivo();
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
            printf(" %d %d %d", aux.r, aux.g, aux.b);
        }
        printf("\n");
    }
}

void criarPonto(int x, int y, cor c){
    imagem[x][y] = c;
}

void criarArquivo(){
     //Cabeçalho
    FILE *f = fopen("imagem.ppm", "w");
    fprintf(f, "P3\n");
    fprintf(f, "%d %d\n", width, height);
    fprintf(f, "%d\n", MAX_COLOR);
    cor aux;
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < width; j++){
            aux = imagem[i][j];
            fprintf(f, " %d %d %d", aux.r, aux.g, aux.b);
        }
        fprintf(f, "\n");
    }   
}
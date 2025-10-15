#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define WIDTH 800
#define HEIGHT 800
#define MAX_COLOR 255
#define pi 3.141592653589793

typedef struct Pixel {
  int r;
  int g;
  int b;
} pixel, cor;

typedef struct Ponto {
  int x;
  int y;
} ponto;

pixel imagem[HEIGHT][WIDTH];

void criarTela(cor);
void criarPonto(ponto, cor);
void criarLinha(ponto, ponto, cor);
void criarRetangulo(ponto, ponto, cor);
void criarTriangulo(ponto, ponto, ponto, cor);
ponto
    imgObj(ponto,
           ponto); // Converter coordenadas do mundo para coordenadas da imagem

void criarFigura();
void printImagem();
void salvarImagem();

cor background = (cor){155,155,155};
cor azulClaro = (cor){100, 149, 237};

int main() {
  criarTela(background);
  criarFigura();
  salvarImagem();
}
cor azul = (cor){0,0,200};

void criarFigura() {
  int L = 50;
  criarRetangulo((Ponto){10,10}, (Ponto){10+L, 10+L}, azul);
}

ponto imgObj(ponto pMundo, ponto origem) {
  ponto pImg;
  pImg.x = pMundo.x + origem.x;
  pImg.y = pMundo.y + origem.y;
  return pImg;
}
void criarTriangulo(ponto p1, ponto p2, ponto p3, cor corTriangulo) {
  criarLinha(p1, p2, corTriangulo);
  criarLinha(p2, p3, corTriangulo);
  criarLinha(p1, p3, corTriangulo);
}

void criarTela(cor background) {
  for (size_t i = 0; i < HEIGHT; i++) {
    for (size_t j = 0; j < WIDTH; j++) {
      imagem[i][j] = background;
    }
  }
}

void criarPonto(ponto p, cor corPonto) {
  if (p.x >= 0 && p.x < WIDTH && p.y > 0 && p.y < HEIGHT) {
    imagem[HEIGHT - p.y - 1][p.x] = corPonto;
  }
}

void printImagem() {
  // Cabeçalho
  printf("P3\n");
  printf("%d %d\n", WIDTH, HEIGHT);
  printf("%d\n", MAX_COLOR);
  for (size_t i = 0; i < HEIGHT; i++) {
    for (size_t j = 0; j < WIDTH; j++) {
      printf("%d %d %d\n", imagem[i][j].r, imagem[i][j].g, imagem[i][j].b);
    }
  }
}

void criarLinha(ponto p1, ponto p2, cor corLinha) {
  int dx = p2.x - p1.x;
  int dy = p2.y - p1.y;
  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
  float xIncrement = dx / (float)steps;
  float yIncrement = dy / (float)steps;
  float x = p1.x;
  float y = p1.y;
  for (int i = 0; i < steps; i++) {
    criarPonto((ponto){(int)(x + 0.5), (int)(y + 0.5)}, corLinha);
    x += xIncrement;
    y += yIncrement;
  }
}

void criarRetangulo(ponto p1, ponto p2, cor corRetangulo) {
  ponto pa = (ponto){p2.x, p1.y};
  ponto pb = (ponto){p1.x, p2.y};
  criarLinha(p1, pa, corRetangulo);
  criarLinha(p2, pa, corRetangulo);
  criarLinha(p2, pb, corRetangulo);
  criarLinha(p1, pb, corRetangulo);
}

void salvarImagem() {
  FILE *f = fopen("linha.ppm", "w");
  if (f == NULL) {
    perror("Arquivo não foi criado");
  }
  fprintf(f, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR);
  for (size_t i = 0; i < HEIGHT; i++) {
    for (size_t j = 0; j < WIDTH; j++) {
      fprintf(f, "%d %d %d\n", imagem[i][j].r, imagem[i][j].g, imagem[i][j].b);
    }
    fprintf(f, "\n");
  }
  fclose(f);
}
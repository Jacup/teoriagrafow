#include <stdio.h>
int main () {
  int v, e, j, i, x, y;
  int v1 = 0, v2 = 0, l = 0;
  int memory[y];
  printf("Podaj liczbę wierzchołków: ");
  scanf("%d", &v);
  if (v == 0) {
    printf("ERROR\n");
    return 0; }
  printf("Podaj liczbę krawędzi: ");
  scanf("%d", &e);
  int graph[v][e];
  int visited[y];
  for (i = 0; i < v; i++) {
    for (j = 0; j < v; j++) {
      graph[i][j] = 0;
      visited[i] = 0;
      memory[i] = 0;
    }
  }
//INPUT
  for (x = 0; x < e; x++) {
    do {
      l = 1;
      printf("Podaj pierwszy i drugi wierzchołek %d krawędzi: ", x+1);
      scanf("%d %d", &v1, &v2);
      memory[y] = v1;
      memory[y+1] = v2;
      // printf("%d\n", memory[y]);
      // printf("%d\n", memory[y+1]);
      y +=2;
      if (v1 < 1 || v2 < 1) {
        printf("\tERROR! \nPodano wierzchołek mniejszy niż 1! \n");
        l=0;
      }
      if (v1 > v || v2 > v) {
        printf("\tERROR! \nWierzcholek nie moze byc wiekszy niz: '%d' !\n", v);
        l=0; }
      }
      while (!l);
      graph[v1-1][v2-1] += 1;
      graph[v2-1][v1-1] += 1;
      }
//OUTPUT
    int vmax = 0, deg = 0;
    for(x = 0; x < v; x++) {
      for(y = 0; y <= v - 1; y++) {
        deg += graph[x][y]; }
      printf("Wierzcholek %d ma stopień %d. \n", x+1, deg);
      if (deg <= 0){
        printf("Graf jest niespójny \n");
        return 0; }
      if ( deg > vmax ) {
        vmax = deg; }
        deg=0; }
      printf(" \n");
      printf("Stopien grafu wynosi: %d\n", vmax);
}

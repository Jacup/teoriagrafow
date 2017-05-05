#include <stdio.h>
int main() {
  int v,e,x,y,max=0,v1=0,v2=0,deg=0;

  printf("Podaj ilość wierzchołków: ");
  scanf("%d",&v);
  printf("Podaj ilość krawędzi: ");
  scanf("%d",&e);


  int tablica[v][v];

  for(x=0; x<v; x++){
    for(y=0; y<v; y++){
      tablica[x][y] = 0;
    }
  }

  for(x=0; x<e; x++){
    int warn=0;
    do {
      warn=1;
      printf("Podaj pierwszy i drugi wierzchołek %d krawędzi: ", x+1);
      scanf("%d %d", &v1, &v2);

      //wykluczenia
      if (v1==v2) {
        printf("\n\tERROR! \nKrawedz musi posiadac 2 rozne wierzcholki.\n");
        warn=0;
      }
      if ( v1 < 1 || v2 < 1) {
        printf("\n\tERROR! \nPodano wierzchołek mniejszy niż 1! \n");
        warn=0;
      }
      if (v1 > v || v2 > v) {
        printf("\n\tERROR! \nWierzcholek nie moze byc wiekszy niz: '%d' !\n", v);
        warn=0;
      }
    }
    while (!warn);

    tablica[v1-1][v2-1]=1;
    tablica[v2-1][v1-1]=1;
  }
  printf("\n\nWYNIK:\n");
  for( x=0; x<v; x++ ) {
    for(y=0; y<=v-1; y++) {
      deg += tablica[x][y];
    }
    printf("Wierzchołek %d ma stopień %d\n",x+1, deg);
    if ( deg > max )
      max = deg;
    deg=0;
  }
  printf("\nGraf jest %d stopnia. \n", max);
}

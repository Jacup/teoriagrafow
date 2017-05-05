#include <stdio.h>
int main() {
  int v,e,x,y,min,max=0,v1=0,v2=0,deg=0, sp=0;
  int wiersz = 0, kolumna = 0;
  int xx=0, yy=0;
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
    for(y=0; y<=v-1; y++){
      deg += tablica[x][y]; }
      if(deg%2==0){
        xx+=1; }
        else {
          yy=1; }
          printf("Wierzchołek %d ma stopień %d\n",x+1, deg);
          if ( deg > max )
          max = deg;
          if (deg == 0) {
            sp = 1;
            min = sp;
          }
          else
          sp = 0;
          deg=0;
        }
        printf("\nGraf jest %d stopnia. \n", max);
        if ( min == 0 ) {
          for(x=0;x<v;x++){
            for(y=0;y<=v-1;y++){
              if(v%2==0){
                if(tablica[y][x]==1){
                  wiersz=1;
                }
                if(tablica[y][x]==0){
                  kolumna=1;
                }
              }
              else{
                if(tablica[y][x]==1){
                  wiersz=1; }
                  if(tablica[y][x]==0){
                    kolumna=1; }
                  }
                }
              }
              if(v>e)
              printf("Podany graf jest spójny ale nie jest eulerowski.\n");
              else {
                if((xx>=1) & (max%2==0) & (wiersz==kolumna) & (yy==0))
                printf("Podany graf jest spójny i eulerowski.\n");
                else
                printf("Podany graf jest spójny ale nie jest eulerowski.\n");
              }
            }
            else
            printf("Graf jest niespójny.\n");
            return 0;
          }

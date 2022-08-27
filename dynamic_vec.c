#include <stdio.h>
#include <stdlib.h> 

//3.1.2
int *pvect = NULL;
int ncount = 0;
int maximo = 0;

void Resize()
{
  const int tam = 10; // Used to increase the vector size
  pvect = realloc(pvect, sizeof(int) * (maximo + tam));
  maximo += tam;
}

void d_insert(int elem)
{
  if( ncount == maximo )
  {
    Resize();
  }
  pvect[ncount++] = elem;
}

void print ()
{
  for (int i = 0; i<ncount; i++)
    {
      printf( "%d ", pvect[i]);
    }
}

int main(void) {
  d_insert(12);
  d_insert(5);
  print();
}
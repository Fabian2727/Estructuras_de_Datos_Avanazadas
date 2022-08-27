#include <stdio.h>
#include <stdlib.h> 

//3.1.2
int *pvect = NULL;
int count = 0;
int maximo = 0;

void Resize()
{
  const int tam = 10; // Used to increase the vector size
  pvect = realloc(pvect, sizeof(int) * (maximo + tam));
  maximo += tam;
}

void insert(int elem)
{
  if( count == maximo )
  {
    Resize();
  }
  pvect[count++] = elem;
}

void print ()
{
  for (int i = 0; i<count; i++)
    {
      printf( "%d ", pvect[i]);
    }
}

int main(void) {
  insert(12);
  insert(5);
  print();
}

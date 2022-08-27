#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
//3.2
struct Vector
{
  int*m_pvect;
  int count = 0;
  int maximo = 0; 
  int tam;
};

void Resize(struct Vector *pThis)
  {
    pThis->tam = 20; 
    int *pTemp = new int[pThis->maximo + pThis->tam];
    for(int i = 0 ; i < pThis->maximo ; i++) 
    {
      pTemp[i] = pThis->m_pvect[i]; 
    }
    pThis->m_pvect = pTemp;
  }

void insert(struct Vector *pThis, int elem)
  {
    if( pThis->count == pThis->maximo )
    {
      Resize(pThis);
    }
    pThis->m_pvect[pThis->count++] = elem;
  }

void print (struct Vector *pThis)
{
  for (int i = 0; i<pThis->count; i++)
    {
      cout << pThis->m_pvect[i]<<"  ";
    }
}

int main(void) {
  struct Vector vect;

  insert(&vect, 5);
  insert(&vect, 8);
  print(&vect);
}
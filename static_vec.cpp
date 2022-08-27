#include <iostream>
#include <stdlib.h> 
using namespace std;

//3.1.1
int vect[100];
int count = 0;

void insert(int elem)
{
  if( count < 100 )
  {
    vect[count++] = elem;
  }
}

void print ()
{
  for (int i = 0; i<count; i++)
    {
      cout<<vect[i]<<"  ";
    }
  cout<<endl;
}

int main() {
  insert(10);
  insert(25);
  print();
}
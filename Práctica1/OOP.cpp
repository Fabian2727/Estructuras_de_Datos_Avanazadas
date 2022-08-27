#include <iostream>
using namespace std;

class CVector
{
  private:
    int *pVect, count = 0, maximo = 0, tam; 
    void Init(int tam); 
    void Resize(); 
  public:
    CVector(int ntam = 10) // Constructor
    {
      this->tam = ntam;
    }
    void Insert(int elem);
    void print(); 
};

void CVector::Resize()
  {
    int *pTemp = new int[maximo + tam];
    for(int i = 0 ; i < maximo ; i++) 
    {
      pTemp[i] = pVect[i]; 
    }
    pVect = pTemp;
  }

void CVector::Insert(int elem)
{
  if( count == maximo ) 
  {
    Resize();
  }
  pVect[count++] = elem; 
}
void CVector::print()
{
  for (int i = 0; i<count; i++)
    {
      cout << pVect[i] << "  ";
    }
}

int main() {
  CVector vect;
  vect.Insert(5);
  vect.Insert(10);
  vect.Insert(8);
  vect.print();
  
}

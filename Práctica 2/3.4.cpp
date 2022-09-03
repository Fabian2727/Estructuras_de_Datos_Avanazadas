#include <iostream>
using namespace std;

//3.4

template <typename Type> class CVector
{
  private:
    Type* pVect; // Pointer to the buffer
    int count = 0, // Control how many elements are actually used
    maximo = 0, // Control the number of allocated elements
    tam; // To control the growing
    void Resize()
    {
      Type *pTemp = new Type[maximo + tam]; // Alloc a new vector
      for(int i = 0 ; i < maximo ; i++) // Transfer the elements
      {
        pTemp[i] = pVect[i]; // we can also use the function memcpy
      }
      pVect = pTemp;  
    }
  public:
    CVector(int ntam = 10) // Constructor
    {
      this->tam = ntam;
      pVect = new Type[maximo + tam];
    } // Constructor
    void Insert(Type elem) // Insert a new element
    {
      if( count == maximo ) // Verify the overflow
      {
        Resize(); // Resize the vector before inserting elem
      }
      pVect[count++] = elem; // Insert the element at the end
    }
    void print()
    {
      for (int i = 0; i<count; i++)
      {
        cout << pVect[i] << "  ";
      }
    }
};

int main(){
  CVector<int> vect;
  vect.Insert(5);
  vect.Insert(10);
  vect.Insert(8);
  vect.print();
}
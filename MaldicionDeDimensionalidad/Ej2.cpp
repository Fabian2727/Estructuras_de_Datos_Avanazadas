#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <chrono>>
#include <vector>
using namespace std;

int main() {
  

  // Ejercicio 2

  auto start4 = std::chrono::system_clock::now();
  long long mat4 [100][1000] = {0};
  
  for (int i = 0; i< 100; i++)
  {
    for (int j = 0; j<1000; j++)
    {
      mat4[i][j] = rand()%500;
    }
  }
  
  for (int i = 1; i< 100; i++)
  {
    long long aux = 0;
    for (int j = 0; j<1000; j++)
    {
      aux += pow(mat4[i][j]-mat4[0][j],2);
    }
    aux = sqrt(aux);
  }
  auto end4 = std::chrono::system_clock::now();
  std::chrono::duration<float,std::milli> duration4 = end4 - start4;
  cout << "Matriz[100][1000]: " << duration4.count() << " sec. " << endl;
}

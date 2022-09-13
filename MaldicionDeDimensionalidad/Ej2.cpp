#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <chrono>
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
  cout << "Ptro[100][1000]: " << duration4.count() << " sec. " << endl;
  
  auto start5 = std::chrono::system_clock::now();
  long long mat5 [100][10000] = {0};
  
  for (long long i = 0; i< 100; i++)
  {
    for (long long j = 0; j<10000; j++)
    {
      mat5[i][j] = rand()%500;
    }
  }
  
  for (long long i = 1; i< 100; i++)
  {
    long long aux = 0;
    for (long long j = 0; j<10000; j++)
    {
      aux += pow(mat5[i][j]-mat5[0][j],2);
    }
    aux = sqrt(aux);
  }
  auto end5 = std::chrono::system_clock::now();
  std::chrono::duration<float,std::milli> duration5 = end5 - start5;
  cout << "Ptro[10 000]: " << duration5.count() << " sec. " << endl;

  auto start6 = std::chrono::system_clock::now();
  long long mat6 [100][50000] = {0};
  
  for (long long i = 0; i< 100; i++)
  {
    for (long long j = 0; j<50000; j++)
    {
      mat6[i][j] = rand()%500;
    }
  }
  
  for (long long i = 1; i< 100; i++)
  {
    long long aux = 0;
    for (long long j = 0; j<50000; j++)
    {
      aux += pow(mat6[i][j]-mat6[0][j],2);
    }
    aux = sqrt(aux);
  }
  auto end6 = std::chrono::system_clock::now();
  std::chrono::duration<float,std::milli> duration6 = end6 - start6;
  cout << "Ptro[50 000]: " << duration6.count() << " sec. " << endl;
}

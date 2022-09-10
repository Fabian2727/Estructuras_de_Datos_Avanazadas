#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <chrono>>
#include <vector>
using namespace std;

long long pot (int a, int b)
{
  if (b == 0) return 1;
    int x = pot(a, b/2);
    if (b % 2 == 0) return x*x;
    return x*x*a;
}

long long dist (int x1,int y1,int z1,int x,int y,int z)
{
  long long dis = sqrt(pot(x-x1,2) + pot(y-y1,2) + pot(z-z1,2));
  return dis;
}

int main() {
  const long long n = 10;

  auto start = std::chrono::system_clock::now();

  long long mat [n][n] = {0};
  
  for (int i = 0; i< n; i++)
  {
    for (int j = 0; j<3; j++)
    {
      mat[i][j] = rand()%500;
    }
  }
  
  for (int i = 1; i< n; i++)
  {
    long long aux = 0;
    for (int j = 0; j<3; j++)
    {
      aux += pow(mat[i][j]-mat[0][j],2);
    }
    aux = sqrt(aux);
  }
  

  auto end = std::chrono::system_clock::now();
  
  std::chrono::duration<float,std::milli> duration = end - start;
  
  cout << duration.count() << "s " << endl;
  
}
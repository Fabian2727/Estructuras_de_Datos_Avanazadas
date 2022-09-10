#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <chrono>>
#include <vector>
using namespace std;

int main() {
  const long long n1 = 1000;
  const long long n2 = 10000;
  const long long n3 = 50000;

  auto start1 = std::chrono::system_clock::now();

  long long mat1 [n1][3] = {0};
  
  for (int i = 0; i< n1; i++)
  {
    for (int j = 0; j<3; j++)
    {
      mat1[i][j] = rand()%500;
    }
  }
  
  for (int i = 1; i< n1; i++)
  {
    long long aux = 0;
    for (int j = 0; j<3; j++)
    {
      aux += pow(mat1[i][j]-mat1[0][j],2);
    }
    aux = sqrt(aux);
  }

  auto end1 = std::chrono::system_clock::now();
  std::chrono::duration<float,std::milli> duration1 = end1 - start1;
  cout << "1000: " << duration1.count() << " sec. " << endl;

  // 10 000

  auto start2 = std::chrono::system_clock::now();

  long long mat2 [n2][3] = {0};
  
  for (int i = 0; i< n2; i++)
  {
    for (int j = 0; j<3; j++)
    {
      mat2[i][j] = rand()%500;
    }
  }
  
  for (int i = 1; i< n2; i++)
  {
    long long aux = 0;
    for (int j = 0; j<3; j++)
    {
      aux += pow(mat2[i][j]-mat2[0][j],2);
    }
    aux = sqrt(aux);
  }

  auto end2 = std::chrono::system_clock::now();
  std::chrono::duration<float,std::milli> duration2 = end2 - start2;
  cout << "10 000: " << duration2.count() << " sec. " << endl;
  
  // 50 000

  auto start3 = std::chrono::system_clock::now();

  long long mat3 [n3][3] = {0};
  
  for (int i = 0; i< n3; i++)
  {
    for (int j = 0; j<3; j++)
    {
      mat3[i][j] = rand()%500;
    }
  }
  
  for (int i = 1; i< n3; i++)
  {
    long long aux = 0;
    for (int j = 0; j<3; j++)
    {
      aux += pow(mat3[i][j]-mat3[0][j],2);
    }
    aux = sqrt(aux);
  }

  auto end3 = std::chrono::system_clock::now();
  std::chrono::duration<float,std::milli> duration3 = end3 - start3;
  cout << "50 000: " << duration3.count() << " sec. " << endl;
  
}

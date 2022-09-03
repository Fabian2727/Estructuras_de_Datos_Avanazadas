#include <iostream>
using namespace std;

//3.7

namespace MyNS
{
  float gnCount = 2.70902; // Unique value
  double Addition(double a, double b) // Global function
  { 
    return a+b; 
  }
  long factorial(int n) // Global function
  {
    long factorial=1;
     for(int i = 1; i <= n; i++)
      {
          factorial = factorial * i;
      }
      return factorial;
  }
};



int main() {
  cout << MyNS::gnCount << endl;
  cout << MyNS::factorial(8) << endl;
}
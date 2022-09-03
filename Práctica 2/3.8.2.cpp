#include <iostream>
#include <vector>
using namespace std;

//3.8.2

float Addition (float a,float b){return a + b;}
float Subtraction (float a,float b) {return a - b;}
float Multiplication (float a, float b) {return a * b;}
float Division (float a, float b) {return a / b;}

int main() {

  //Code A

  float a, b, c; int opt;
  cin >> a >> b;
  // OPT-> 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
  cin >> opt;
  switch( opt )
  {
    case 0: c = Addition(a, b); break;
    case 1: c = Subtraction(a, b); break;
    case 2: c = Multiplication(a, b); break;
    case 3: c = Division(a, b); break;
  }
  cout << "Solution by Swtich Case: " << c << endl;
  
  //Code B
  typedef float (*lpfnOperation)(float, float);
  // CVector of pointer to functions
  lpfnOperation vpf[4] = {&::Addition,         &::Subtraction,
                          &::Multiplication,   &::Division};
  float d, e, f; int opc;
  cin >> d >> e;
  //enter the operation 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division
  cin >> opc;
  // The next line replaces the switch and replaces the whole switch
  f = (*vpf[opc])(d, e);  
  cout << "Solution by pointers: " << f << endl;
}
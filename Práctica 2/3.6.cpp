#include <iostream>
#include <vector>
using namespace std;

//3.6 - Figura 20

class CMyComplexDataStructure
{
  vector<float> m_container;
  public:
    void Insert(float fVal) 
    { 
      m_container.push_back(fVal); 
    }
    template <typename objclass>
    void sumone(objclass funobj)
    {
      vector<float>::iterator iter = m_container.begin();
      for (; iter != m_container.end() ; iter++)
      {
        funobj(*iter);
      }
    }
  void print()
  {
    vector<float>::iterator iter = m_container.begin();
    for (; iter != m_container.end() ; iter++)
      {
        cout << *iter << "  ";
      }
    cout << endl;
  }
};
template <typename objclass>
class funcobjclass
{
  public:
    void operator ()(objclass& objinstance)
    {
      objinstance++;
    }
};
int main()
{
  CMyComplexDataStructure ds;
  ds.Insert(3.5);
  ds.Insert(4.5);
  ds.Insert(6.5);
  ds.Insert(3.9);
  funcobjclass<float> x;
  ds.sumone(x);
  ds.print();
}
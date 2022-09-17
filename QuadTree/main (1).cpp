#include <iostream>
using namespace std;

unsigned char* ReadBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");

    if(f == NULL)
        cout << "Argument Exception" << endl;

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // lee la cabecera

    // Extrae el alto y ancho de la imagen desde su cabecera
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    cout << endl;
    cout << "File Name: " << filename << endl;
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;

    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

    for(int i = 0; i < height; i++)
    {
      fread(data, sizeof(unsigned char), row_padded, f);
      for(int j = 0; j < width*3; j += 3)
      {
        // Invertir valores --> (B, G, R) a (R, G, B)
        tmp = data[j];
        data[j] = data[j+2];
        data[j+2] = tmp;
        cout<<"R:  "<<(int)data[j]<<"  G:  "<<(int)data[j+1]<<"  B:  "<<(int)data[j+2]<<endl;
      }
    }
    fclose(f);
    return data;
}

int main() {
  
  char* name = "test.bmp";
  ReadBMP(name);
  return 0;
}
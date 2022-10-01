#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 50;
int R[N][N];
int G[N][N];
int B[N][N];

void Print( int tam){
  cout<<"R:"<<endl;
  cout<<"============================================================================================"<<endl;
  for(int i=0;i<tam;i++)
  {
    for(int j=0;j<tam;j++)
    {
      cout<<R[i][j]<<"\t";
    }
    cout<<endl;
  }
cout<<"G:"<<endl; cout<<"============================================================================================"<<endl;
  for(int i=0;i<tam;i++)
  {
    for(int j=0;j<tam;j++)
    {
      cout<<G[i][j]<<"\t";
    }
    cout<<endl;
  }

cout<<"B:"<<endl;
cout<<"============================================================================================"<<endl;
  for(int i=0;i<tam;i++)
  {
    for(int j=0;j<tam;j++)
    {
      cout<<B[i][j]<<"\t";
    }
    cout<<endl;
  }
}

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

        R[i][j] = (int)data[j];
        G[i][j] = (int)data[j+1];
        B[i][j] = (int)data[j+2];
        
//cout<<"R:  "<<(int)data[j]<<"  G:  "<<(int)data[j+1]<<"  B:  <<(int)data[j+2]<<endl;
      }
    }
    fclose(f);
    return data;
}

void Update(int x, int y, int x_fin, int y_fin, int *matR, int *matG, int *matB, int avgR, int avgG, int avgB){
  int factor=20;
  if(*matR>factor)
  {
    for(int i=x;i<x_fin;i++)
    {
      for(int j=y;j<y_fin;j++)
      {
        R[i][j]=avgR;
      }
    }
  }
  if(*matG>factor) 
  {
    for(int i=x;i<x_fin;i++)
    {
      for(int j=y;j<y_fin;j++)
      {
        G[i][j]=avgG;
      }
    }
  }
  if(*matB>factor)
  {
    for(int i=x;i<x_fin;i++)
    {
      for(int j=y;j<y_fin;j++)
      {
        B[i][j]=avgB;
      }
    }
  }
}

void Avarage(int x, int y, int x_fin, int y_fin, int *matR, int *matG, int *matB)
{
  int sumR=0,sumG=0,sumB=0; //acumulado de valores
  int n=pow((x_fin-x),2); //cantidad de valores
  
  for(int i=x;i<x_fin;i++)
  {
    for(int j=y;j<y_fin;j++)
    {
      sumR = sumR + R[i][j];
      sumG = sumG + G[i][j];
      sumB = sumB + B[i][j];
    }
  }
  *matR = sumR/n;
  *matG= sumG/n;
  *matB= sumB/n;
}

void Dest(int x, int y, int x_fin, int y_fin, int *matR, int *matG, int *matB)
{
  int X = pow((x_fin-x),2);
  int totalR=0,totalG=0,totalB=0;
  
  for(int i=x;i<x_fin;i++)
  {
    for(int j=y;j<y_fin;j++)
    {
      totalR = totalR + pow(R[i][j] - *matR,2);
      totalG = totalG + pow(G[i][j] - *matG,2);
      totalB = totalB + pow(B[i][j] - *matB,2);
    }
  }
  *matR = sqrt(totalR / X);
  *matG = sqrt(totalG / X);
  *matB = sqrt(totalB / X);
}

void Agrupar(int tam){
  int quad1x=0,quad1y=0,
  quad2x=0,quad2y=tam/2,
  quad3x=tam/2,quad3y=0,
  quad4x=tam/2,quad4y=tam/2;
  
  int Rquad1,Gquad1,Bquad1;
  int Rquad2,Gquad2,Bquad2;
  int Rquad3,Gquad3,Bquad3;
  int Rquad4,Gquad4,Bquad4;

  //1er cuadrante
  Avarage(quad1x,quad1y,quad3x,quad2y,&Rquad1,&Gquad1,&Bquad1);
  //2do cuadrante
  Avarage(quad2x,quad2y,quad4x,tam,&Rquad2,&Gquad2,&Bquad2);
  //3er cuadrante
  Avarage(quad3x,quad3y,tam,quad4y,&Rquad3,&Gquad3,&Bquad3);
  //4to cuadrante
  Avarage(quad4x,quad4y,tam,tam,&Rquad4,&Gquad4,&Bquad4);

  int Rp1 = Rquad1,  Gp1 = Gquad1,  Bp1 = Bquad1;
  int Rp2 = Rquad2,  Gp2 = Gquad2,  Bp2 = Bquad2;
  int Rp3 = Rquad3,  Gp3 = Gquad3,  Bp3 = Bquad3;
  int Rp4 = Rquad4,  Gp4 = Gquad4,  Bp4 = Bquad4;

  //1er cuadrante
  Dest(quad1x,quad1y,quad3x,quad2y,&Rquad1,&Gquad1,&Bquad1);
  //2do cuadrante
  Dest(quad2x,quad2y,quad4x,tam,&Rquad2,&Gquad2,&Bquad2);
  //3er cuadrante
  Dest(quad3x,quad3y,tam,quad4y,&Rquad3,&Gquad3,&Bquad3);
  //4to cuadrante
  Dest(quad4x,quad4y,tam,tam,&Rquad4,&Gquad4,&Bquad4);

  cout<<"\nDesviacion Estandar: "<<endl;
  cout<<"Cuadrante 1:  "<<Rquad1<<", "<<Gquad1<<", "<<Bquad1<<endl;
  cout<<"Cuadrante 2:  "<<Rquad2<<", "<<Gquad2<<", "<<Bquad2<<endl;
  cout<<"Cuadrante 3:  "<<Rquad3<<", "<<Gquad3<<", "<<Bquad3<<endl;
  cout<<"Cuadrante 4:  "<<Rquad4<<", "<<Gquad4<<", "<<Bquad4<<endl;
  cout<<endl;

  //1er cuadrante
  Update(quad1x,quad1y,quad3x,quad2y,&Rquad1,&Gquad1,&Bquad1,Rp1,Gp1,Bp1);
  //2do cuadrante
  Update(quad2x,quad2y,quad4x,tam,&Rquad2,&Gquad2,&Bquad2,Rp2,Gp2,Bp2);
  //3er cuadrante
  Update(quad3x,quad3y,tam,quad4y,&Rquad3,&Gquad3,&Bquad3,Rp3,Gp3,Bp3);
   //4to cuadrante
  Update(quad4x,quad4y,tam,tam,&Rquad4,&Gquad4,&Bquad4,Rp4,Gp4,Bp4);  
}

int main(){

char* name = "t2.bmp";
ReadBMP(name);
Print(N);
Agrupar(N);
Print(N);

}

/*
   Analisis Númerico 1
   Autor: José Juan Gurrola Cota
   Programa: Programa que implementa el método de Regresión Polinomial de orden m, para ajustar un conjunto de n puntos dados. 
   13/06/2014
*/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <fstream>
#define MAXREN 10
#define MAXCOL 10
#define VALOR 30

using namespace std;
float sumatoriaxy(float x[MAXREN],float y[MAXREN],int l,int n);
float sumatoriax(float x[MAXREN],int k,int n);
 
int main(){
char nom_archivo[VALOR];
    ifstream entrada;
    int n,grado;
    
    for(int i =0;i<80;i++){   cout<<char(205);}
    cout<<"\t\tPrograma que implementa el método de Regresion Polinomial \n\t\t de orden m, para ajustar un conjunto de n puntos dados. "<<endl<<endl;    
    for(int i =0;i<80;i++){  cout<<char(205);}
    
    cout<<"\n\tIngrese el Nombre del Archivo : ";
    cin>>nom_archivo;

    entrada.open(nom_archivo,ifstream::in);

    if(!entrada.good()){
       cout<<"\n\tNo se pudo abrir el archivo ingresado."<<endl;
       system("pause");
       exit(0);
    }

    entrada>>n;
  
    float M[n][n+1],X[n],fx[n];
                           
    for(int i=0;i<n;i++){
       for(int j=0;j<2;j++){
          entrada>>M[i][j];   //matriz aumentada
       }
    }
    entrada.close();

    cout<<"Ingrese el grado del polinomio: ";
    cin>>grado;
    cout<<endl;
    
    int m=((grado*2)+grado-1);
    float x[n],y[n],xi[n][m],sumatorias[m],sumatoriasxy[grado];

    for(int i=0;i<n;i++)
         x[i]=M[i][0];
    for(int i=0;i<n;i++)
         y[i]=M[i][1];
    
    for(int i=0;i<n;i++){
        for(int k=2;k<=grado*2;k++){
            sumatorias[i]=sumatoriax(x,k,n);
        }
    }
    for(int i=0;i<n;i++){
        for(int l=1;l<=grado;l++){
            sumatoriasxy[i]=sumatoriaxy(x,y,l,n);
        }          
    }
        
    cout<<"sumatorias[i]"<<endl;     
    for(int i=0;i<grado;i++)
        cout<<sumatoriasxy[i]<<endl; 
    
    system("pause");
        
} 
float sumatoriax(float x[MAXREN],int k,int n)
{ 
    float resultado=0;
    for(int i=0;i<n;i++)   resultado=resultado+pow(x[i],k);
    return resultado;   
}
 
float sumatoriaxy(float x[MAXREN],float y[MAXREN],int l,int n)
{
  float resultado=0;
  for(int j=1;j<=l;j++){
      for(int i=0;i<n;i++)
          resultado=resultado+(pow(x[i],j))*(y[i]);
}
  return resultado;      
}

 

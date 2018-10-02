/*
   Analisis Númerico 1
   Autor: José Juan Gurrola Cota
   Programa: Programa que genera el polinomio interpolante de Lagrange de orden n, dados n+1 puntos. 
   30/11/2014
*/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#define MAXREN 10
#define MAXCOL 10

using namespace std;

float termino(float X[MAXREN],float fx[MAXREN],int,float,int);
 
void Lagrange(){
    char nom_archivo[30];
    ifstream entrada;
    int n;
    float resultado,x;
    
    for(int i =0;i<80;i++)    cout<<char(205);
    cout<<"\n\t\t\t Interpolacion Lagrange"<<endl<<endl;
    for(int i =0;i<80;i++)cout<<char(205);
    
    
    cout<<"\n\tIngrese el Nombre del Archivo: ";
    cin>>nom_archivo;

    entrada.open(nom_archivo,ifstream::in);

    if(!entrada.good()){
       cout<<"\n\tNo se pudo abrir el archivo ingresado."<<endl<<endl;
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
    
    cout<<"\n\tEscribe el valor de x: ";
    cin>>x;
    
    for(int i=0;i<n;i++){
        X[i]=M[i][0];
        fx[i]=M[i][1];
        }
           
    resultado=0;
    for(int i=0;i<n;i++)    resultado=resultado+termino(X,fx,n,x,i);
    
    cout<<"\n\tf"<<n-1<<"("<<x<<") = ";
    printf("%10.10f",resultado);   
    cout<<endl<<endl;

}
     
float termino(float X[MAXREN],float fx[MAXREN],int n,float x,int y)
{      
    float termino=0,numerador=1,denominador=1;     
        for(int i=0;i<n;i++){
            if(i!=y){
                numerador=numerador*(x-(X[i]));
                denominador=denominador*(X[y]-X[i]);
            }
        }
    termino=(numerador*fx[y])/denominador;
    return termino;    
}
     

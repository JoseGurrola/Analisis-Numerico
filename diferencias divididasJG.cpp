/*
   Analisis Númerico 1
   Autor: María Adriana Ochoa
   Programa: Programa que genera el polinomio interpolante con diferencias divididas de Newton de orden n, dados n+1 puntos. 
   27/11/2014
*/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

using namespace std;

 
int main()
{
    int n;
    char nom_archivo[30];
    ifstream entrada;
    float x=0.35,resultado=1,respuesta=0;

    for(int i =0;i<80;i++){
            cout<<char(205);
    }
    
    cout<<"    Programa que genera el polinomio interpolante con diferencias divididas\n\t\t\tde Newton de orden n, dados n+1 puntos. "<<endl<<endl;
    
     for(int i =0;i<80;i++){
            cout<<char(205);
    }
    
    cout<<"\n\tIngrese el Nombre del Archivo : ";
    cin>>nom_archivo;

    entrada.open(nom_archivo,ifstream::in);

    if(!entrada.good()){
       cout<<"\nNo se pudo abrir el archivo ingresado."<<endl;
       system("pause");
       exit(0);
    }

    entrada>>n;
    cout<<"El numero de puntos es: "<<n<<endl;
    
    float M[n][n+1],A[n][n],X[n];
                           
    for(int i=0;i<n;i++){
       for(int j=0;j<2;j++){
          entrada>>M[i][j];   //<---matriz aumentada
       }
    }
    entrada.close();
//separando matriz y mostrando la tabla de puntos:
    for(int i=0;i<n;i++)
        X[i]=M[i][0];
        cout<<"xi      f(xi)\n";

       for(int i=0;i<n;i++){
           A[i][0]=M[i][1];
           cout<<M[i][0]<<"\t"<<A[i][0]<<endl;
       }    
//obteniendo coeficientes
    for(int i=1;i<n;i++)
        for(int j=i;j<n;j++)
            A[j][i]=(A[j][i-1]-A[j-1][i-1])/(X[j]-X[j-i]);

        cout<<"\nCoeficientes:"<<endl;
    for(int i=0;i<n;i++)    cout<<A[i][i]<<endl;
        
   for(int i=0;i<n;i++){
       respuesta=respuesta+A[i][i]*(resultado);
         if(i!=0){
                  for(int j=0;j<i;j++)  
                      resultado*=(x-X[j]);
        }        
     }
     cout<<"\nEl valor aproximado es: "<<respuesta<<endl;    
     cout<<endl;
    system("pause"); 
}

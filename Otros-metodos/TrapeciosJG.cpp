/*
   Analisis Númerico 1
   Autor: José Juan Gurrola Cota
   Programa: Programa que Implementa la regla trapezoidal para integrar numéricamente una función f(x) en un intervalo [a,b].
   07/12/2014
*/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <fstream>


using namespace std;

float funcion_trapecios(float);
 
int main(){
    for(int i =0;i<80;i++){    cout<<char(205);    } 
    cout<<"                Integracion por Trapecios"<<endl<<endl<<endl;
     for(int i =0;i<80;i++){   cout<<char(205);    }
      
    int n;//Número de partes en que se va a dividir
    float a,b,fx[n],x[n],sumatoria=0,area,h;
    
    cout<<"Introduce el valor de a (inicio del intervalo)"<<endl;
    cin>>a;
    cout<<"Introduce el valor de b (fin del intervalo)"<<endl;
    cin>>b;
    
    cout<<"Introduce el valor de n(el numero de divisiones)"<<endl;
    cin>>n;
    
    h=(b-a)/n;
    
    cout<<"h="<<h<<endl;
    
    for(int i=0;i<=n;i++)
        x[i]=a+(h*i);
             
    for(int i=0;i<=n;i++)
        fx[i]=funcion_trapecios(x[i]);
        
    for(int i=1;i<n;i++)
        sumatoria=sumatoria+fx[i];  
 
    cout<<"sumatoria:"<<sumatoria<<endl;   
    area=(h/2)*(fx[0]+(2*sumatoria)+fx[n]);
    cout<<"Area= "<<area<<endl;
    
    system("pause");
           
}


float funcion_trapecios(float x){
      float resultado;
      resultado=pow(x,7)+(8*(pow(x,3)))+pow(x,-2);

      return resultado;     
}
 


 

/*
   Analisis N�merico 1
   Autor: Jos� Juan Gurrola Cota
   Programa: Programa que Implementa la regla de simpson 1/3 y 3/8 para una funci�n f(x) en un intervalo [a,b].
   11/12/2014
*/
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;

double funcionsimpson(double x);

void Simpson()
{
   float n, a, b;
   float area, S1, S2, x;
   float h;
    for(int i =0;i<80;i++){    cout<<char(205);    } 
    cout<<"\n\t\t\t Metodo Simpson 1/3 y 3/8"<<endl<<endl;
    for(int i =0;i<80;i++){    cout<<char(205);    } 
   cout<<"\n\n Ingrese el n: ";
   cin>>n;
   cout<<"\n Ingrese el limite inferior: ";
   cin>>a;
   cout<<"\n Ingrese el limite superior ";
   cin>>b;

   S1=S2=0;
   x=a;
   h=(b-a)/n;

    cout<<endl<<"\n H = "<<h;

    if(n==2){
       x = x+h;
       S1 = S1+funcionsimpson(x);
       area = (h/3)*(funcionsimpson(a)+ funcionsimpson(b)+4*S1+2*S2);
       cout<<"\n\t EL area es : "<<area;
    }
    else{
       for(int i=1; i<=((n/2)-1); i++){
          x=x+h;
          S1=S1+funcionsimpson(x);
          x=x+h;
          S2=S2+funcionsimpson(x);                                                 
       }
                
       x=x+h;
       S1=S1+funcionsimpson(x);
                  
       area=((funcionsimpson(a)+funcionsimpson(b)+4*S1+2*S2)*(h/3));
       cout<<"\n EL area es : "<<area<<endl;    
    }      
}

double funcionsimpson(double x)
{ 
       double F;
       F=3*(pow(x,2))+(1/x);
       return F;
}

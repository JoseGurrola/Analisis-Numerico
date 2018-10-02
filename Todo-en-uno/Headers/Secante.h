/*
   Analisis Númerico 1
   Autor: José Juan Gurrola Cota
   Programa: programa que encuentra una aproximacion a la raiz positiva de una funcion por el metodo de la secante
   08/10/2014
*/

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

double FxS(double);
double ErrorS(double, double);


void Secante(){
    double x,xa,xaa,p,tol;
    int Nmax;    //numero maximo de iteraciones.

        system("cls");
        for(int i =0;i<80;i++)  cout<<char(205);
        cout<<"\t\t\t\tSecante\nPrograma que encuentra una aproximacion a la raiz positiva de la funcion\nf(x) = arcsen x - e^-2x\n\n";  
        for(int i =0;i<80;i++)  cout<<char(205);
    do{//Pedimos al usuario el numero de iteraciones y evaluamos a que sea positivo
       cout<<"Ingresa el numero maximo de iteraciones: ";
       cin>>Nmax;
       if(Nmax<=0) cout<<"El numero maximo de iteraciones tiene que ser mayor a 0\n\n";
    }while(Nmax<=0);
    
    do{ 
        cout<<"Ingresa el numero de cifras significativas para la tolerancia: ";
        cin>>tol;
        if(tol<=0) cout<<"Error numero de cifras significativas incorrecto";                
    }while(tol<=0);
    
    tol=pow(10,-tol);
    
    int i=1; 
    double error=100; 
    xa=0.4f;
    xaa=0.6f;
    
    cout<<"n.........xn-1.........xn..........f(xn-1)......f(xn).......error\n"; 
    while(i<=Nmax){
        
        x=xa-((FxS(xa)*(xa-xaa))/(FxS(xa)-FxS(xaa)));
        
        error=ErrorS(x,xa);

        printf("%d   %10.10f  %10.10f  %10.10f  %10.10f %10.10f \n",i,xa,x,FxS(xa),FxS(x),error);
        
        if(error<tol){
            printf("\n\nEl valor aproximado es: %10.15f\n\n",x);
            i=Nmax+1;
        }
 
        i++;
        xa=x;          
    };
    if(error>tol)    cout<<"Error, no se encontro una aproximacion\n\n";  
}

//----------------------------------------------------------------------
/*
   SALIDA: 
   ENTRADA: el numero a evaluar(x)
*/
double FxS(double x)
{
    return asin(x)-exp(-2*x);
}
//----------------------------------------------------------------------
/*
   SALIDA: el valor del error  relativo aproximado
   ENTRADA: el valor de la aproximacion y el valor de la aproximacion anterior
*/
double ErrorS(double x, double x_ant)
{
    return fabs((x-x_ant)/x); 
}

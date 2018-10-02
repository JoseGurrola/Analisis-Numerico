/*
   Analisis Númerico 1
   Autor: José Juan Gurrola Cota
   Programa que calcula aproximaciones de Sen(x) capturando x y el numero de cifras significativas, CON Sen(x)REAL
   31/08/2014
*/

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

void Seno(double, int);
double Factorial(int);
double Erreal(double, double);
double Eraprox(double, double);
void Imprimir(int, double, double, double);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
     double x;
    int n;       
    cout<<"\n "<<char(175)<<char(175)<<" Programa que calcula una aproximacion del valor Sen(x) en n iteraciones "<<char(174)<<char(174)<<endl<<endl<<endl;
    cout<<"Ingresa x: ";
    cin>>x;
    
    do{
    cout<<"Ingresa el numero de cifras significativas para la aproximacion: ";
    cin>>n;
    if(n<0) cout<<"Error, n tiene que ser un numero positivo\n";
    }while(n<0);
    
    Seno(x,n);
    cout<<endl<<endl;
    system("pause");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Calcula la aproximacion al seno de x y llama a la función imprimir para la tabla
void Seno(double x, int n)
{
    double aprox, aprox_ant=0,ErReal, ErAprox;
    int i=0;
    double cifras=((pow(10,-n))*5);
    
    cout<<"Seno("<<x<<")= ";
    printf("%10.18f\n\n",sin(x));
    cout<<"n         Sen(x)         Error relativo real  Error relativo aproximado"<<endl;
    do{
        aprox+=pow(-1,i)* (pow(x,(2*i)+1)/Factorial((2*i)+1));
        ErReal=Erreal(x, aprox);
        ErAprox=Eraprox(aprox, aprox_ant);
        Imprimir(i+1,aprox,ErReal,ErAprox);
        aprox_ant=aprox;
        i++;
    }while(Erreal(x, aprox)>cifras);
    
    
}
//------------------------------------------------------------------------------
//Función que calcula el factorial de un número
 double Factorial(int num)
{
    if(num<2)
       return 1;
    else
       return num * Factorial(num-1);
}
//------------------------------------------------------------------------------
//Funcion que calcula el Error Relativo Real
double Erreal(double x, double aprox)
{
    double Error=100;
    return Error=fabs((sin (x) - aprox)/sin (x) );
}
//------------------------------------------------------------------------------
//Funcion que calcula el Error Relativo Aproximado
double Eraprox(double aprox, double aprox_ant)
{
    double Error=100;
    return Error=fabs((aprox-aprox_ant)/aprox);
}
//------------------------------------------------------------------------------
void Imprimir(int i, double aprox, double ErReal, double ErAprox)
{
    printf("%d   %10.17f  %10.17f  %10.17f\n",i,aprox, ErReal,ErAprox);
}

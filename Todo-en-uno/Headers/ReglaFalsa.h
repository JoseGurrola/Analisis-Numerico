/*
   Analisis Númerico 1
   Autor: José Juan Gurrola Cota
   Programa 3: programa que encuentra una aproximacion a la raiz positiva de una funcion por el metodo de REGLA FALSA
   21/09/2014
*/

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

double funcion(double);
double ErrorRF(double, double);

void ReglaFalsa(){
    double a,b,c, tolerancia=0.001;
    int Nmax;    //numero maximo de iteraciones.
    do{    //Pedimos el interbalo [a,b] y evaluamos que f(a) y f(b) tengan signos opuestos y su evaluacion correspondiente.
        system("cls");
        for(int i =0;i<80;i++)  cout<<char(205);
        cout<<"\t\t\t\tRegla Falsa\nPrograma que encuentra una aproximacion a la raiz positiva de la funcion f(x) = e^x-x^3 (tolerancia de 10^-3)\n\n";  
        for(int i =0;i<80;i++)  cout<<char(205);
        cout<<"Ingresa el punto 'a' del intervalo: ";
        cin>>a;    
        cout<<"Ingresa el punto 'b' del intervalo: ";
        cin>>b;
        if(funcion(a) < 0 && funcion(b) < 0){ 
            cout<<"No es posible encontrar raiz con el intervalo ["<<a<<", "<<b<<"]\n\n\n\n\n\n";
            system("pause");
        }
        if(funcion(a) > 0 && funcion(b) > 0){ 
            cout<<"No es posible encontrar raiz con el intervalo ["<<a<<", "<<b<<"]\n\n\n\n\n\n"; 
            system("pause");
        }  
    }while((funcion(a) < 0 && funcion(b) < 0) || (funcion(a) > 0 && funcion(b) > 0));
    
    do{//Pedimos al usuario el numero de iteraciones y evaluamos a que sea positivo
       cout<<"Ingresa el numero maximo de iteraciones: ";
       cin>>Nmax;
       if(Nmax<=0) cout<<"El numero maximo de iteraciones tiene que ser mayor a 0\n\n";
    }while(Nmax<=0);
    
    
    int i=1;
    
    double valor_real=1.85718386f; //Para calcular el error utilizamos el valor real que conozco gracias a fooplot
    cout<<"\nn       an          bn          Cn          f(an)       f(Cn)      error"<<endl<<endl; //Encabezado de la tabla
    while(i<=Nmax){
        
        c=a-((funcion(a)*(b-a))/(funcion(b)-funcion(a)));  
        
        printf("%d   %10.7f  %10.7f  %10.7f  %10.7f  %10.7f  %10.7f\n",i,a,b,c,funcion(a),funcion(c), ErrorRF(valor_real,c));  //Se imprime la linea de la tabla respectiva a cada iteración
        
        if(funcion(c)==0 || ErrorRF(valor_real,c)<=tolerancia){ //Revisamos a que lleguemos a una aproximacion apropiada entorno a la tolerancia
            printf("\n\nEl valor aproximado es: %10.7f\n\n",c);
            i=Nmax+1;
        }
        if((signo(funcion(a))*signo(funcion(b)))<0){ //Hacemos el intervalo mas pequeño, para esto se verifica si a o b tomaran el valor de p
            b=c;   
        }else a=c;
        
        i+=1; 
        
    };
    /*
    if(ErrorRF(a,c)>tolerancia){  //Si despues de que el numero de iteraciones no se encuentra un valor menor a la tolerancia, mandamos mensaje de error
            cout<<"\n\n\n\nNo se encontro un numero aproximado con el numero de iteraciones dadas\n\n\n";
        }*/
}
//----------------------------------------------------------------------
/*
   SALIDA: el valor de la funcion f(x) = (e^-x)+(4x^3)-5  evaluado en x
   ENTRADA: el numero a evaluar(x)
*/
double funcion(double x){
    return exp(x)-pow(x,3);
}
//----------------------------------------------------------------------
/*
   SALIDA: el valor calculado del error
   ENTRADA: el valor exacto y el valor aproximado
*/
double ErrorRF(double valor_real, double c){
    return fabs((valor_real-c)/valor_real); 
}
//-----------------------------------------------------------------------

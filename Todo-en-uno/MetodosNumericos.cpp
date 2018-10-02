#include <iostream>
#include <cstdlib>
#include<math.h>
#include <fstream>
#include <time.h>
#include <windows.h>
//------------------------------------------------------------------------------
#include "Headers/Biseccion.h"
#include "Headers/ReglaFalsa.h"
#include "Headers/PuntoFijo.h"
#include "Headers/NewtonRaphson.h"
#include "Headers/Secante.h"
#include "Headers/EliminacionGS.h"
#include "Headers/EliminacionGPP.h"
#include "Headers/GaussSeidel.h"
#include "Headers/FactorizacionLU.h"
#include "Headers/DiferenciasDivididas.h"
#include "Headers/Lagrange.h"
#include "Headers/Regresion.h"
#include "Headers/Trapecios.h"
#include "Headers/Simpson.h"

using namespace std;

void submenu1(int);
void menu();
void Encabezado(string);
void Presentacion(int x);
void coords(int,int);

//******************************************************************************
int main()
{
    Sleep(1000);
    Beep(2000,100);
   for(int i=1;i<=3;++i){
      system("cls");
      Presentacion(i);
      Beep((i*150),200);
      Sleep(3000);
   }
   menu();
   system("pause");
}
//******************************************************************************
void menu()
{
   int opcion,opcion3;
   do{
   system("cls");
   Encabezado("        METODOS NUMERICOS");

   cout<<"Selecciona una opcion: \n";

   cout<<"0) Salir\n";
   cout<<"1) Solucion de funciones no lineales\n";
   cout<<"2) Solucion de SEL\n";
   cout<<"3) Ajuste de curvas\n";
   cout<<"4) Integracion numerica\n";

   do{
      cout<<"opcion: ";
      cin>>opcion;
      if(opcion<0 || opcion>4) cout<<"Error: Opcion incorrecta\n";
   }while(opcion<0 || opcion>4);

   if(opcion==0) exit(0);
   else submenu1(opcion);

   cout<<"\n\n\n0) Salir\n";
   cout<<"1) Volver a menu principal\n";

   do{
       cout<<"opcion: ";
       cin>>opcion3;
       if(opcion3<0 || opcion3>1) cout<<"Error: Opcion incorrecta\n";
   }while(opcion3<0 || opcion3>1);
   if(opcion3==0) exit(0);

   }while(opcion3!=0);

}
//******************************************************************************
void submenu1(int opcion)
{
   int opcion2;
    switch(opcion){
       case 1:
            system("cls");
            Encabezado("SOLUCION DE ECUACIONES NO LINEALES");
            cout<<"Selecciona una opcion: \n";

            cout<<"0) Volver\n";
            cout<<"1) Biseccion\n";
            cout<<"2) Regla Falsa\n";
            cout<<"3) Punto Fijo\n";
            cout<<"4) Newton-Raphson\n";
            cout<<"5) Secante\n";
            do{
               cout<<"opcion: ";
               cin>>opcion2;
               if(opcion2<0 || opcion2>5) cout<<"Error: Opcion incorrecta\n";
            }while(opcion2<0 || opcion2>5);

            system("cls");
            switch(opcion2){
               case 0: menu();
               break;
               case 1: Biseccion();
               break;
               case 2: ReglaFalsa();
               break;
               case 3: PuntoFijo();
               break;
               case 4: NewtonRaphson();
               break;
               case 5: Secante();
               break;
            }
    break;
   //-----------------------------------------
       case 2:
            system("cls");
            Encabezado("SOLUCION DE SEL");
            cout<<"Selecciona una opcion: \n";

            cout<<"0) Volver\n";
            cout<<"1) Eliminacion Gaussiana Simple\n";
            cout<<"2) Eliminacion Gaussiana con pivoteo parcial\n";
            cout<<"3) Gauss-Jordan\n";
            cout<<"4) Jacobi\n";
            cout<<"5) Gauss-Seidel\n";
            cout<<"6) Factorizacion LU\n";
            do{
               cout<<"opcion: ";
               cin>>opcion2;
               if(opcion2<0 || opcion2>6) cout<<"Error: Opcion incorrecta\n";
            }while(opcion2<0 || opcion2>6);

            system("cls");
            switch(opcion2){
               case 0: menu();
               break;
               case 1: EliminacionGS();
               break;
               case 2: EliminacionGPP();
               break;
               case 3:
                    Encabezado("Gauss-Jordan");
                    cout<<"No disponible en la Version 1.0\n";
               break;
               case 4:
                    Encabezado("Jacobi");
                    cout<<"No disponible en la Version 1.0\n";
               break;
               case 5: GaussSeidel();
               break;
               case 6: FactorizacionLU();
               break;
            }
    break;
    //-----------------------------------------
       case 3:
            system("cls");
            Encabezado("AJUSTES DE CURVAS");
            cout<<"Selecciona una opcion: \n";

            cout<<"0) Volver\n";
            cout<<"1) Polinomio Interpolante (Diferencias Divididas de Newton)\n";
            cout<<"2) Polinomio Interpolante (Lagrange)\n";
            cout<<"3) Regresion Polinomial\n";
            do{
               cout<<"opcion: ";
               cin>>opcion2;
               if(opcion2<0 || opcion2>3) cout<<"Error: Opcion incorrecta\n";
            }while(opcion2<0 || opcion2>3);

            system("cls");
            switch(opcion2){
               case 0: menu();
               break;
               case 1: DiferenciasDivididas();
               break;
               case 2: Lagrange();
               break;
               case 3: Regresion();
               break;
            }
    break;
    //-----------------------------------------
       case 4:
            system("cls");
            Encabezado("INTEGRACION NUMERICA");
            cout<<"Selecciona una opcion: \n";

            cout<<"0) Volver\n";
            cout<<"1) Integracion por Trapecios\n";
            cout<<"2) Regla se simpson 1/3 y 3/8\n";
            do{
               cout<<"opcion: ";
               cin>>opcion2;
               if(opcion2<0 || opcion2>2) cout<<"Error: Opcion incorrecta\n";
            }while(opcion2<0 || opcion2>2);

            system("cls");
            switch(opcion2){
               case 0: menu();
               break;
               case 1: Trapecios();
               break;
               case 2: Simpson();
               break;
            }
    break;
    }
}
//******************************************************************************
void Encabezado(string s)
{
    for(int i =0;i<80;i++)  cout<<char(205);
    cout<<"\t\t\t"<<s<<endl<<endl;
    for(int i =0;i<80;i++)  cout<<char(205);
    cout<<endl<<endl;
}
//******************************************************************************
void Presentacion(int x)
{
    switch(x){
       case 1:
            coords(14,3);cout<<"            0\n";
            coords(14,0);cout<<"00   00  00000  00000   000   000     000    0000\n";
            coords(14,0);cout<<"0 0 0 0  0        0    0   0  0  0   0   0  0\n";
            coords(14,0);cout<<"0  0  0  000      0    0   0  0   0  0   0   000 \n";
            coords(14,0);cout<<"0     0  0        0    0   0  0  0   0   0      0\n";
            coords(14,0);cout<<"0     0  00000    0     000   000     000   0000 \n\n\n";
       break;
       case 2:
            coords(14,3);cout<<"            0\n";
            coords(14,0);cout<<"00   00  00000  00000   000   000     000    0000\n";
            coords(14,0);cout<<"0 0 0 0  0        0    0   0  0  0   0   0  0\n";
            coords(14,0);cout<<"0  0  0  000      0    0   0  0   0  0   0   000 \n";
            coords(14,0);cout<<"0     0  0        0    0   0  0  0   0   0      0\n";
            coords(14,0);cout<<"0     0  00000    0     000   000     000   0000 \n";
            coords(7,2);cout<<"                           0\n";
            coords(7,0);cout<<"00    0  0   0  00   00  00000  0000   000   0000   000    0000\n";
            coords(7,0);cout<<"0 0   0  0   0  0 0 0 0  0      0   0   0   0      0   0  0\n";
            coords(7,0);cout<<"0  0  0  0   0  0  0  0  000    0000    0   0      0   0   000\n";
            coords(7,0);cout<<"0   0 0  0   0  0     0  0      0  0    0   0      0   0      0\n";
            coords(7,0);cout<<"0     0   000   0     0  00000  0   0  000   0000   000   0000\n";
       break;
       case 3:
            coords(14,3);cout<<"            0\n";
            coords(14,0);cout<<"00   00  00000  00000   000   000     000    0000\n";
            coords(14,0);cout<<"0 0 0 0  0        0    0   0  0  0   0   0  0\n";
            coords(14,0);cout<<"0  0  0  000      0    0   0  0   0  0   0   000 \n";
            coords(14,0);cout<<"0     0  0        0    0   0  0  0   0   0      0\n";
            coords(14,0);cout<<"0     0  00000    0     000   000     000   0000 \n";
            coords(7,2);cout<<"                           0\n";
            coords(7,0);cout<<"00    0  0   0  00   00  00000  0000   000   0000   000    0000\n";
            coords(7,0);cout<<"0 0   0  0   0  0 0 0 0  0      0   0   0   0      0   0  0\n";
            coords(7,0);cout<<"0  0  0  0   0  0  0  0  000    0000    0   0      0   0   000\n";
            coords(7,0);cout<<"0   0 0  0   0  0     0  0      0  0    0   0      0   0      0\n";
            coords(7,0);cout<<"0     0   000   0     0  00000  0   0  000   0000   000   0000\n";
            coords(50,4);cout<<"Analisis Numerico I\n";
            coords(50,0);cout<<"Jose Juan Gurrola Cota\n\n";
       break;
       case 4: cout<<"Meto";
       break;
    }
}

void coords(int x, int y)
{
    for(int i=0;i<y;++i) cout<<"\n";
    for(int i=0;i<x;++i) cout<<" ";
}

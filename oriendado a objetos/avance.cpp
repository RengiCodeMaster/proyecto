#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include "encargados.h"
#include "elementos.h"
#include "equipos.h"
#include "login.h"
#include "laboratorios.h"
using namespace std;
void salir()
{
    cout << "Gracias por usar el sistema" << endl;
    exit(0);
}
void menu1()
{
    vector<Encargado> encargados;
    vector<Elementos> elementos;
    vector<Equipo> equipos;
    vector<Laboratorio> laboratorios;
    vector<Login> login;
    cout << "\033[1;91m--------------------------------------------------------------------------------\033[0m" << endl;
    cout << "\033[1;31mBienvenido al sistema de laboratorios\033[0m" << endl;
    cout << "\033[1;91m--------------------------------------------------------------------------------\033[0m" << endl;
    cout << "\033[1;97m1.- Ingresar encargados\033[0m" << endl;
    cout << "\033[1;97m2.- Ingresar laboratorios\033[0m" << endl;
    cout << "\033[1;97m3.- Ingresar elementos\033[0m" << endl;
    cout << "\033[1;97m4.- Ingresar equipos\033[0m" << endl;
    cout << "\033[1;97m5.- Mostrar laboratorios\033[0m" << endl;
    cout << "\033[1;97m6.- Mostrar elementos\033[0m" << endl;
    cout << "\033[1;97m7.- Mostrar equipos\033[0m" << endl;
    cout << "\033[1;97m8.- Mostrar encargados\033[0m" << endl;
    cout << "\033[1;97m9.- Salir\033[0m" << endl;
    cout << "\033[1;91m--------------------------------------------------------------------------------\033[0m" << endl;
}

int main()
{
    int opcion;
    do
    {
        menu1();
        cout << "\033[1;97mIngrese la opcion que desea: \033[0m";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            system("cls");
            Encargado enca;
            enca.IngresodeEncargados(encargados);
            break;
        }
        case 2:
        {
            system("cls");
            Laboratorio labo;
            labo.IngresodeLaboratorios(laboratorios);
            break;
        }
        case 3:
        {
            system("cls");
            Elementos elem;
            elem.IngresodeElementos(elementos);
            break;
        }
        case 4:
        {
            system("cls");
            Equipo equi;
            equi.IngresodeEquipos(equipos);
            break;
        }
        case 5:
        {
            system("cls");
            Laboratorio labo;
            labo.MostrarLaboratorios(laboratorios);
            break;
        }
        case 6:
        {
            system("cls");
            Elementos elem;
            elem.MostrarElementosporCodigo(elementos);
            break;
        }
        case 7:
        {
            system("cls");
            Equipo equi;
            equi.MostrarEquiposporID(equipos);
            break;
        }
        case 8:
        {
            system("cls");
            Encargado enca;
            enca.MostrarEncargados(encargados);
            break;
        }
        case 9:
        {
            system("cls");
            salir();
            break;
        }
        default:
        {
            system("cls");
            cout << "\033[1;31m***Opcion no valida***\033[0m" << endl;
            break;
        }
        }
    } while (opcion != 9);

    return 0;
}

#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include "laboratorios.h"
#include "GestorLaboratorio.h"
#include "Encargados.h"
using namespace std;
int opcion;
void salir()
{
    cout << "Gracias por usar el sistema" << endl;
    exit(0);
}

void menu1()
{
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
    vector<Encargado> encargados;
    vector<Elementos> elementos;
    vector<Equipo> equipos;
    vector<Laboratorio> laboratorios;

    setlocale(LC_ALL, "spanish.UTF-8");
    do
    {
        system("cls");
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
            cout << "\033[1;97m\nPresione 1 para volver al menu o 0 para salir del sistema: \033[0m";
            cin >> opcion;
            break;
        }
        case 2:
        {
            system("cls");
            ControldeSistema labo;
            labo.IngresodeLaboratorios(laboratorios);
            cout << "\033[1;97m\nPresione 1 para volver al menu o 0 para salir del sistema: \033[0m";
            cin >> opcion;
            break;
        }
        case 3:
        {
            system("cls");
            PrivilegiosElemento elem;
            elem.IngresodeElementos(elementos);
            cout << "\033[1;97m\nPresione 1 para volver al menu o 0 para salir del sistema: \033[0m";
            cin >> opcion;
            break;
        }
        case 4:
        {
            system("cls");
            PrivilegiosEquipos equi;
            equi.IngresodeEquipos(equipos);
            cout << "\033[1;97m\nPresione 1 para volver al menu o 0 para salir del sistema: \033[0m";
            cin >> opcion;
            break;
        }
        case 5:
        {
            system("cls");
            ControldeSistema labo;
            labo.MostrarLaboratorios(laboratorios);
            cout << "\033[1;97m\nPresione 1 para volver al menu o 0 para salir del sistema: \033[0m";
            cin >> opcion;
            break;
        }
        case 6:
        {
            ControldeSistema labo;
            labo.MostraID(laboratorios);
            Elementos elem;
            elem.MostrarElementosporCodigo(elementos);
            cout << "\033[1;97m\nPresione 1 para volver al menu o 0 para salir del sistema: \033[0m";
            cin >> opcion;
            break;
        }
        case 7:
        {
            system("cls");
            ControldeSistema labo;
            labo.MostraID(laboratorios);
            Equipo equi;
            equi.MostrarEquiposporCodigo(equipos);
            cout << "\033[1;97m\nPresione 1 para volver al menu o 0 para salir del sistema: \033[0m";
            cin >> opcion;
            break;
        }
        case 8:
        {
            system("cls");
            Encargado enca;
            enca.MostrarEncargados(encargados);
            cout << "\033[1;97m\nPresione 1 para volver al menu o 0 para salir del sistema: \033[0m";
            cin >> opcion;
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
    } while (opcion != 0);
    system("pause");

    return 0;
}

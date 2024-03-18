#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include "encargados.h"
#include "elementos.h"
#include "equipos.h"
#include "laboratorios.h"
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
            cout << "\nPresione 1 para volver al menu o 0 para salir del sistema: ";
            cin >> opcion;
            break;
        }
        case 2:
        {
            system("cls");
            Laboratorio labo;
            labo.IngresodeLaboratorios(laboratorios);
            cout << "\nPresione 1 para volver al menu o 0 para salir del sistema: ";
            cin >> opcion;
            break;
        }
        case 3:
        {
            Elementos elem;
            system("cls");
            elem.IngresodeElementos(elementos);
            cout << "\nPresione 1 para volver al menu o 0 para salir del sistema: ";
            cin >> opcion;
            break;
        }
        case 4:
        {
            Equipo equi;
            system("cls");
            equi.IngresodeEquipos(equipos);
            cout << "\nPresione 1 para volver al menu o 0 para salir del sistema: ";
            cin >> opcion;
            break;
        }
        case 5:
        {
            Laboratorio labo;
            system("cls");
            labo.MostrarLaboratorios(laboratorios);
            cout << "\nPresione 1 para volver al menu o 0 para salir del sistema: ";
            cin >> opcion;
            break;
        }
        case 6:
        {
            Elementos elem;
            Laboratorio labo;
            system("cls");
            labo.MostraID(laboratorios);
            elem.MostrarElementosporCodigo(elementos);
            cout << "\nPresione 1 para volver al menu o 0 para salir del sistema: ";
            cin >> opcion;
            break;
        }
        case 7:
        {
            Equipo equi;
            Laboratorio labo;
            system("cls");
            labo.MostraID(laboratorios);
            equi.MostrarEquiposporID(equipos);
            cout << "\nPresione 1 para volver al menu o 0 para salir del sistema: ";
            cin >> opcion;
            break;
        }
        case 8:
        {
            Encargado enca;
            system("cls");
            enca.MostrarEncargados(encargados);
            cout << "\nPresione 1 para volver al menu o 0 para salir del sistema: ";
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

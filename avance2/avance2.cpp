#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include<locale.h>
using namespace std;
struct Encargado
{
    int id;
    string nombre;
    string numero;
    string laboratorioalquePertenece;
    string fechadeInicio;
    string fechadeSalida;
};
struct Laboratorios
{
    int id;
    int aforo;
    string nombre;
    string encargado;
    string facultad;
    string ubicacion;
    string facultadesqueAtiende;
};
struct Elementos
{
    int id;
    string nombre;
    string estado;
    string caducidad;
    int cantidad;
};
struct Equipos
{
    int id;
    string nombre;
    string estado;
    int cantidad;
};
vector<Encargado> encargado;
vector<Laboratorios> laboratorios;
vector<Elementos> elementos;
vector<Equipos> equipos;
void GuardarEncargados(vector<Encargado> &encargado) // Guarda los encargados registrados
{
    ofstream archivo("encargados.txt", ios::app);
    for (const Encargado &lab : encargado)
    {
        archivo << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        archivo << "| ID: " << lab.id << "| Nombre: " << lab.nombre << "| Numero: " << lab.numero << "| Laboratorio al que pertenece: " << lab.laboratorioalquePertenece << endl;
        archivo << "| Fecha de inicio: " << lab.fechadeInicio << "| Fecha de salida: " << lab.fechadeSalida << endl;
        archivo << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    archivo.close(); 
}
void GuardarLaboratorios(vector<Laboratorios> &laboratorios) // Guarda los laboratorios registrados
{
    ofstream archivo("laboratorios.txt", ios::app);
    for (const Laboratorios &lab : laboratorios)
    {
        archivo << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        archivo << "| ID: " << lab.id << "| Nombre: " << lab.nombre << "| Aforo: " << lab.aforo << "| Encargado: " << lab.encargado << endl;
        archivo << "| Facultad: " << lab.facultad << "| Ubicacion: " << lab.ubicacion << "| Facultades que atiende: " << lab.facultadesqueAtiende << endl;
        archivo << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    archivo.close();
}
void GuardarElementos(vector<Elementos> &elementos)
{
    ofstream archivo("elementos.txt", ios::app);
    for (const Elementos &ele : elementos)
    {
        archivo<<ele.id<<".-ID "<<ele.id<<",Nombre: "<<ele.nombre<<",Estado: "<<ele.estado<<",Caducidad: "<<ele.caducidad<<",Cantidad: "<<ele.cantidad<<endl;
        
    }
    archivo.close();
}

void GuardarEquipos(vector<Equipos> &equipos) // Guarda los equipos registrados
{
    ofstream archivo("equipos.txt", ios::app);
    for (const Equipos &eq : equipos)
    {
        archivo << eq.id << ".-ID " << eq.id << ",Nombre: " << eq.nombre << ",Estado: " << eq.estado << ",Cantidad: " << eq.cantidad << endl;
    }
    archivo.close();
}
void BusquedaId(vector<Laboratorios> &laboratorios) // Guarda los ID de los laboratorios registrados
{
    ofstream archivo("IDyNombress.txt");
    for (const Laboratorios &lab : laboratorios)
    {
        archivo << lab.id << ".- ID: " << lab.id << ", Nombre: " << lab.nombre << endl;
    }
    archivo.close();
}
void IngresoEncargados(vector<Encargado> &encargado)
{
    int x;
    cout << "\033[1;91m***Bienvenido al registro de encargados***\033[0m" << endl;
    cout << "\033[1;97m";
    cout << "Ingrese el numero de encargados que desea registrar: ";
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < x; i++)
    {
        Encargado en;
        cout << "Ingrese el ID del encargado" << i + 1 << ": ";
        cin >> en.id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el nombre del encargado de ID " << en.id << ": ";
        getline(cin, en.nombre);

        cout << "Ingrese el numero de telefono del encargado: ";
        getline(cin, en.numero);

        cout << "Ingrese el laboratorio al que pertenece el encargado: ";
        getline(cin, en.laboratorioalquePertenece);

        cout << "Ingrese la fecha de inicio del encargado: ";
        getline(cin, en.fechadeInicio);

        cout << "Ingrese la fecha de salida del encargado: ";
        getline(cin, en.fechadeSalida);
        encargado.push_back(en);
    }
    cout << "\033[0m";
    GuardarEncargados(encargado);
}
void Ingresolaboratorios(vector<Laboratorios> &laboratorios) // Registro de laboratorios
{
    int x;
    cout << "\033[1;91m***Bienvenido al registro de laboratorios***\033[0m" << endl;
    cout << "\033[1;97m";
    cout << "Ingrese el numero de laboratorios que desea registrar: ";
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < x; i++)
    {
        Laboratorios lab;
        cout << "Ingrese el ID del laboratorio " << i + 1 << ": ";
        cin >> lab.id;

        cout << "Ingrese el aforo del laboratorio: ";
        cin >> lab.aforo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Ingrese el nombre del laboratorio de ID " << lab.id << ": ";
        getline(cin, lab.nombre);

        cout << "Ingrese el nombre del encargado: ";
        getline(cin, lab.encargado);

        cout << "Ingrese a qué facultad pertenece el laboratorio: ";
        getline(cin, lab.facultad);

        cout << "Ingrese la ubicacion del laboratorio: ";
        getline(cin, lab.ubicacion);

        cout << "Ingrese las facultades que atiende el laboratorio: ";
        getline(cin, lab.facultadesqueAtiende);

        laboratorios.push_back(lab);
    }

    cout << "\033[0m";
    GuardarLaboratorios(laboratorios);
    BusquedaId(laboratorios);
}

void IngresoDeElementos(vector<Elementos> &elementos) // Registro de elementos
{
    int x;
    cout << "\033[1;91m***Bienvenido al registro de elementos***\033[0m" << endl;
    cout << "\033[1;97m";
    cout << "Ingrese el numero de elementos que desea registrar: ";
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < x; i++)
    {
        Elementos ele;
        cout << "Ingrese el id del elemento " << i + 1 << ": ";
        cin >> ele.id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Ingrese el nombre del elemento de ID " << ele.id << ": ";
        getline(cin, ele.nombre);

        cout << "Ingrese el estado del elemento: ";
        getline(cin, ele.estado);

        cout << "Ingrese la fecha de caducidad del elemento: ";
        getline(cin, ele.caducidad);

        cout << "Ingrese la cantidad de Elementos disponibles: ";
        cin >> ele.cantidad;

        elementos.push_back(ele);
    }

    cout << "\033[0m";
    GuardarElementos(elementos);
}
void IngresoDeEquipos(vector<Equipos> &equipos) // Registro de equipos
{
    cout << "\033[1;91m***Bienvenido al registro de equipos***\033[0m" << endl;
    int x;
    cout << "\033[1;97m";
    cout << "Ingrese el número de equipos que desea registrar: ";
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < x; i++)
    {
        Equipos eq;
        cout << "Ingrese el ID del equipo " << i + 1 << ": ";
        cin >> eq.id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Ingrese el nombre del equipo de ID " << eq.id << ": ";
        getline(cin, eq.nombre);

        cout << "Ingrese el estado del equipo: ";
        getline(cin, eq.estado);

        cout << "Ingrese la cantidad de Equipos disponibles: ";
        cin >> eq.cantidad;

        equipos.push_back(eq);
    }

    cout << "\033[0m";
    GuardarEquipos(equipos);
}

void mostrarEncargados(vector<Encargado> &encargado) // Muestra los encargados registrados
{
    cout << "\033[1;91m****ENCARGADOS REGISTRADOS****\033[0m" << endl;
    ifstream archivo("encargados.txt");
    string linea;
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }
    archivo.close();
}
void mostrarLaboratorios(vector<Laboratorios> &laboratorios) // Muestra los laboratorios registrados
{
    cout << "\033[1;91m****LABORATORIOS REGISTRADOS****\033[0m" << endl;
    ifstream archivo("laboratorios.txt");
    string linea;
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }
    archivo.close();
}
void mostrarIDyNombres(vector<Laboratorios> &laboratorios) // Muestra los laboratorios registrados
{
    cout << "\033[1;91m****ID Y NOMBRES DE LABORATORIOS REGISTRADOS****\033[0m" << endl;
    ifstream archivo("IDyNombress.txt");
    string linea;
    cout << "\033[1;97m";
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }
    cout << "\033[0m";
    archivo.close();
}
void mostrarElementosPorID(vector<Elementos> &elementos) // Muestra los elementos registrados con un ID específico
{
    mostrarIDyNombres(laboratorios);
    ifstream archivo("elementos.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo 'elementos.txt'." << endl;
        return;
    }
    int id;
    cout << "\033[1;97m";
    while (cout << "Ingrese el ID para mostrar los equipos registrados con ese ID (o 0 para salir): " && cin >> id && id != 0)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bool encontrado = false;
        archivo.clear();
        archivo.seekg(0);
        string linea;
        while (getline(archivo, linea))
        {
            int lineId = stoi(linea.substr(0, linea.find(',')));
            if (lineId == id)
            {
                cout << linea << endl;
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            cout << "No se encontraron equipos registrados con el ID " << id << "." << endl;
        }
    }
    cout << "\033[0m";
    archivo.close();
}
void mostrarEquiposPorID(vector<Equipos> &equipos) // Muestra los equipos registrados con una ID específica
{
    ifstream archivo("equipos.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo 'equipos.txt'." << endl;
        return;
    }
    int id;
    cout << "\033[1;97m";
    while (cout << "Ingrese el ID para mostrar los equipos registrados con ese ID (o 0 para salir): " && cin >> id && id != 0)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bool encontrado = false;
        archivo.clear();
        archivo.seekg(0);
        string linea;
        while (getline(archivo, linea))
        {
            int lineId = stoi(linea.substr(0, linea.find(',')));
            if (lineId == id)
            {
                cout << linea << endl;
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            cout << "No se encontraron equipos registrados con el ID " << id << "." << endl;
        }
    }
    cout << "\033[0m";
    archivo.close();
}

void salir() // Mensaje de despedida
{
    cout << "\033[1;31m***Gracias por usar el programa ,hasta la proxima***\033[0m" << endl;
    exit(0);
}
int opcion;
void InformacionDelMenu()
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
    cout << "\033[1;97mIngrese la opcion que desea: \033[0m";
    cin >> opcion;
}
int main()
{
    setlocale(LC_ALL, "spanish.UTF-8");
    do
    {
        InformacionDelMenu();
        switch (opcion)
        {
        case 1:
            system("cls");
            IngresoEncargados(encargado);
            break;
        case 2:
            system("cls");
            Ingresolaboratorios(laboratorios);
            break;
        case 3:
            system("cls");
            IngresoDeElementos(elementos);
            break;
        case 4:
            system("cls");
            IngresoDeEquipos(equipos);
            break;
        case 5:
            system("cls");
            mostrarLaboratorios(laboratorios);
            break;
        case 6:
            system("cls");
            mostrarElementosPorID(elementos);
            break;
        case 7:
            system("cls");
            mostrarEquiposPorID(equipos);
            break;

        case 8:
            system("cls");
            mostrarEncargados(encargado);
            break;
        case 9:
            system("cls");
            salir();
            break;
        default:
            system("cls");
            cout << "\033[1;31m***Opcion no valida***\033[0m" << endl;
            break;
        }
    } while (opcion != 9);
    system("cls");
    return 0;
}
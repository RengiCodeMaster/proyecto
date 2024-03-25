#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;
class PrivilegiosElemento;
class PrivilegiosEquipos;
class Elementos
{
private:
    int codigo;
    string nombre;
    string estado;
    string caducidad;
    int cantidad;

public:
    Elementos() : codigo(), nombre(), estado(), caducidad(), cantidad() {}
    friend class PrivilegiosElemento;
    vector<Elementos> elementos;
    void MostrarElementosporCodigo(vector<Elementos> &elem)
    {
        ifstream archivo("elementos.txt");
        if (!archivo.is_open())
        {
            cout << "No se pudo abrir el archivo 'elementos.txt'." << endl;
            return;
        }
        int id;
        cout << "\033[1;97m";
        while (cout << "Ingrese el ID para mostrar los elementos registrados con ese ID (o 0 para salir): " && cin >> id && id != 0)
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
                cout << "No se encontraron elementos registrados con el ID " << id << "." << endl;
            }
        }
        cout << "\033[0m";
        archivo.close();
    }
};

class Equipo
{
private:
    int codigo;
    string nombre;
    string estado;
    int cantidad;

public:
    Equipo() : codigo(), nombre(), estado(), cantidad() {}
    friend class PrivilegiosEquipos;
    vector<Equipo> equipos;
    void MostrarEquiposporCodigo(vector<Equipo> &equi)
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
};

class PrivilegiosElemento
{
public:
    void GuardarElementos(vector<Elementos> &elem)
    {
        ofstream archivo("elementos.txt", ios::app);
        for (const Elementos &ele : elem)
        {
            archivo << ele.codigo << ".-ID " << ele.codigo << ",Nombre: " << ele.nombre << ",Estado: " << ele.estado << ",Caducidad: " << ele.caducidad << ",Cantidad: " << ele.cantidad << endl;
        }
        archivo.close();
        ;
    }
    void IngresodeElementos(vector<Elementos> &elem)
    {
        try
        {
            int cantidad;
            bool validInput = false;
            cout << "\033[1;97m";
            while (!validInput)
            {
                cout << "Ingrese el número de elementos que desea registrar: ";
                cin >> cantidad;
                if (cantidad <= 0 || cin.fail())
                {
                    cout << "La cantidad debe ser un número positivo. Por favor, intente nuevamente." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    validInput = true;
                }
            }
            cout << "\033[0m";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[1;97m";
            for (int i = 0; i < cantidad; ++i)
            {
                Elementos elemento;
                cout << "Ingrese el código del elemento: ";
                cin >> elemento.codigo;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ingrese el nombre del elemento: ";
                getline(cin, elemento.nombre);
                cout << "Ingrese el estado del elemento: ";
                getline(cin, elemento.estado);
                cout << "Ingrese la caducidad del elemento: ";
                getline(cin, elemento.caducidad);
                cout << "Ingrese la cantidad del elemento: ";
                cin >> elemento.cantidad;
                elem.push_back(elemento);
            }
            cout << "\033[0m";
            GuardarElementos(elem);
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
};
class PrivilegiosEquipos
{
public:
    void GuardarEquipos(vector<Equipo> &equi)
    {
        ofstream archivo("equipos.txt", ios::app);
        for (const Equipo &equipo : equi)
        {
            archivo << equipo.codigo << "|ID: " << equipo.codigo << "|Nombre: " << equipo.nombre << "|Estado: " << equipo.estado << "|Cantidad: " << equipo.cantidad << endl;
        }
        archivo.close();
    }
    void IngresodeEquipos(vector<Equipo> &equi)
    {
        try
        {
            int cantidad;
            bool validInput = false;
            cout << "\033[1;97m";
            while (!validInput)
            {
                cout << "Ingrese el número de equipos que desea registrar: ";
                cin >> cantidad;
                if (cantidad <= 0 || cin.fail())
                {
                    cout << "La cantidad debe ser un número positivo. Por favor, intente nuevamente." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    validInput = true;
                }
            }
            cout << "\033[0m";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[1;97m";
            for (int i = 0; i < cantidad; ++i)
            {
                Equipo equipo;
                cout << "Ingrese el código del equipo: ";
                cin >> equipo.codigo;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ingrese el nombre del equipo: ";
                getline(cin, equipo.nombre);
                cout << "Ingrese el estado del equipo: ";
                getline(cin, equipo.estado);
                cout << "Ingrese la cantidad del equipo: ";
                cin >> equipo.cantidad;
                equi.push_back(equipo);
            }
            cout << "\033[0m";
            GuardarEquipos(equi);
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
};
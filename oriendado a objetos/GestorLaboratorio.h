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
    friend PrivilegiosElemento;
};
vector<Elementos> elementos;
class Equipo
{
private:
    int codigo;
    string nombre;
    string estado;
    int cantidad;

public:
    Equipo() : codigo(), nombre(), estado(), cantidad() {}

    friend PrivilegiosEquipos;
};
vector<Equipo> equipos;
class Encargado
{
private:
    string codigo;
    string nombreyApellidos;
    string numero;
    string laboratorioAsignado;
    string fechadeIngreso;
    string fechadeSalida;

public:
    Encargado() : codigo(), nombreyApellidos(), numero(), laboratorioAsignado() {}
    void GuardarEncargados(const vector<Encargado> &enca);
    void IngresodeEncargados(vector<Encargado> &enca);
    void MostrarEncargados(const vector<Encargado> &enca);
};
vector<Encargado> encargados;
void Encargado::GuardarEncargados(const vector<Encargado> &enca)
{
    ofstream archivo("encargados.txt", ios::app);
    for (const Encargado &encargado : encargados)
    {
        archivo<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        archivo << "|ID: " << encargado.codigo << "|Nombres y Apellidos: " << encargado.nombreyApellidos << "|Numero: " << encargado.numero << "|Laboratorio Asignado: " << encargado.laboratorioAsignado << endl;
        archivo << "|Fecha de Ingreso: " << encargado.fechadeIngreso << "|Fecha de Salida: " << encargado.fechadeSalida << endl;
        archivo<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    }
    archivo.close();
}
void Encargado::IngresodeEncargados(vector<Encargado> &enca)
{
    int x;
    cout << "Ingrese el numero de encargados que desea registrar: ";
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        Encargado enca;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el codigo del encargado: ";
        getline(cin, enca.codigo);
        cout << "Ingrese el nombre y apellidos del encargado: ";
        getline(cin, enca.nombreyApellidos);
        cout << "Ingrese el numero del encargado: ";
        getline(cin, enca.numero);
        cout << "Ingrese el laboratorio asignado al encargado: ";
        getline(cin, enca.laboratorioAsignado);
        cout << "Ingrese la fecha de ingreso del encargado: ";
        getline(cin, enca.fechadeIngreso);
        cout << "Ingrese la fecha de salida del encargado: ";
        getline(cin, enca.fechadeSalida);
        encargados.push_back(enca);
    }
    Encargado::GuardarEncargados(encargados);
}
void Encargado::MostrarEncargados(const vector<Encargado> &enca)
{
    cout << "\033[1;91m****ENCARGADOS REGISTRADOS****\033[0m" << endl;
    ifstream archivo("encargados.txt");
    string texto;
    while (!archivo.eof())
    {
        getline(archivo, texto);
        cout << "\033[1;97m" << texto << "\033[0m" << endl;
    }
    archivo.close();
}
class PrivilegiosElemento
{
public:
    void IngresodeElementos(vector<Elementos> &elem)
    {
        
        int x;
        cout << "Ingrese el numero de elementos que desea registrar: ";
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            Elementos elem;
            cout << "Ingrese el codigo del elemento: ";
            cin >> elem.codigo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese el nombre del elemento: ";
            getline(cin, elem.nombre);
            cout << "Ingrese el estado del elemento: ";
            getline(cin, elem.estado);
            cout << "Ingrese la caducidad del elemento: ";
            getline(cin, elem.caducidad);
            cout << "Ingrese la cantidad del elemento: ";
            cin >> elem.cantidad;
            elementos.push_back(elem);
        }
        GuardarElementos(elementos);
    }
    void GuardarElementos(vector<Elementos> &elem)
    {
        ofstream archivo("elementos.txt", ios::app);
        for (const Elementos &ele : elementos)
        {
            archivo << ele.codigo << ".-ID " << ele.codigo << ",Nombre: " << ele.nombre << ",Estado: " << ele.estado << ",Caducidad: " << ele.caducidad << ",Cantidad: " << ele.cantidad << endl;
        }
        archivo.close();
        ;
    }
    void MostrarElementosporCodigo( vector<Elementos> &elem)
    {
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
};
class PrivilegiosEquipos
{
public:
    void GuardarEquipos( vector<Equipo> &equi)
    {
        ofstream archivo("equipos.txt", ios::app);
        for (const Equipo &equipo : equipos)
        {
            archivo << equipo.codigo << "|ID: " << equipo.codigo << "|Nombre: " << equipo.nombre << "|Estado: " << equipo.estado << "|Cantidad: " << equipo.cantidad << endl;
        }
        archivo.close();
    }
    void IngresodeEquipos(vector<Equipo> &equi)
    {
        int x;
        cout << "Ingrese el numero de equipos que desea registrar: ";
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < x; i++)
        {
            Equipo equi;
            cout << "Ingrese el codigo del equipo: ";
            cin >> equi.codigo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese el nombre del equipo: ";
            getline(cin, equi.nombre);
            cout << "Ingrese el estado del equipo: ";
            getline(cin, equi.estado);
            cout << "Ingrese la cantidad de equipos: ";
            cin >> equi.cantidad;
            equipos.push_back(equi);
        }
        GuardarEquipos(equipos);
    }
    void MostrarEquiposporID( vector<Equipo> &equi)
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
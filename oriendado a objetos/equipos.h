#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;
class Equipo
{
private:
    int codigo;
    string nombre;
    string estado;
    int cantidad;

public:
    Equipo() : codigo(), nombre(), estado(), cantidad() {}
    void GuardarEquipos(const vector<Equipo> &equi);
    void IngresodeEquipos(vector<Equipo> &equi);
    void MostrarEquiposporID(const vector<Equipo> &equi);
};
vector<Equipo> equipos;
void Equipo::GuardarEquipos(const vector<Equipo> &equi)
{
    ofstream archivo("equipos.txt", ios::app);
    for (const Equipo &equipo : equipos)
    {
        archivo << equipo.codigo << "|ID: " << equipo.codigo << "|Nombre: " << equipo.nombre << "|Estado: " << equipo.estado << "|Cantidad: " << equipo.cantidad << endl;
    }
    archivo.close();
}
void Equipo::IngresodeEquipos(vector<Equipo> &equi)
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
    Equipo::GuardarEquipos(equipos);
}
void Equipo::MostrarEquiposporID(const vector<Equipo> &equi)
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

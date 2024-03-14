#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;
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
    void GuardarElementos( vector<Elementos> &elem);
    void IngresodeElementos(vector<Elementos> &elem);
    void MostrarElementosporCodigo(const vector<Elementos> &elem);
};
vector<Elementos> elementos;
void Elementos::GuardarElementos( vector<Elementos> &elem)
{
    ofstream archivo("elementos.txt", ios::app);
    for (const Elementos &ele : elementos)
    {
        archivo << ele.codigo << ".-ID " << ele.codigo << ",Nombre: " << ele.nombre << ",Estado: " << ele.estado << ",Caducidad: " << ele.caducidad << ",Cantidad: " << ele.cantidad << endl;
    }
    archivo.close();
    ;
}
void Elementos::IngresodeElementos(vector<Elementos> &elem)
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
    Elementos::GuardarElementos(elementos);
}
void Elementos::MostrarElementosporCodigo(const vector<Elementos> &elem)
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
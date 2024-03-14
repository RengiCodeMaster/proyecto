#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;
class Encargado
{
private:
    string codigo;
    string nombreyApellidos;
    string numero;
    string laboratorioAsignado;

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
        archivo << "|ID: " << encargado.codigo << "|Nombres y Apellidos: " << encargado.nombreyApellidos << "|Numero: " << encargado.numero << "|Laboratorio Asignado: " << encargado.laboratorioAsignado << endl;
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
        encargados.push_back(enca);
    }
    Encargado::GuardarEncargados(encargados);
}
void Encargado::MostrarEncargados(const vector<Encargado> &enca)
{
    ifstream archivo("encargados.txt");
    string texto;
    while (!archivo.eof())
    {
        getline(archivo, texto);
        cout << texto << endl;
    }
    archivo.close();
}
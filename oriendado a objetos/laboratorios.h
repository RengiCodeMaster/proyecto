#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;

class Laboratorio
{
private:
    string aforo;
    string codigo;
    string nombre;
    string encargado;
    string facultad;
    string ubicacion;
    string facultadesqueAtiende;

public:
    Laboratorio() : aforo(), codigo(), nombre(), encargado(), facultad(), ubicacion(), facultadesqueAtiende() {}
    void GuardarLaboratorios(const vector<Laboratorio> &labo);
    void GuardarID(const vector<Laboratorio> &labo);
    void MostraID(const vector<Laboratorio> &labo);
    void IngresodeLaboratorios(vector<Laboratorio> &labo);
    void MostrarLaboratorios(const vector<Laboratorio> &labo);
};
vector<Laboratorio> laboratorios;
void Laboratorio::GuardarID(const vector<Laboratorio> &labo)
{
    ofstream archivo("IDlabo.txt", ios::app);
    for (const Laboratorio &labo: laboratorios)
    {
        archivo << labo.codigo <<" | "<<labo.nombre<< endl;
    }
    archivo.close();
}
void Laboratorio::MostraID(const vector<Laboratorio> &labo)
{
    ifstream archivo("IDlabo.txt");
    string texto;
    while (!archivo.eof())
    {
        getline(archivo, texto);
        cout << texto << endl;
    }
    archivo.close();
}
void Laboratorio::GuardarLaboratorios(const vector<Laboratorio> &labo)
{
    ofstream archivo("laboratorios.txt", ios::app);
    for (const Laboratorio &labo : laboratorios)
    {
        archivo << "|Aforo: " << labo.aforo << "|Codigo: " << labo.codigo << "|Nombre: " << labo.nombre << "|Encargado: " << labo.encargado << "|Facultad: " << labo.facultad << "|Ubicacion: " << labo.ubicacion << "|Facultades que atiende: " << labo.facultadesqueAtiende << endl;
    }
    archivo.close();
}
void Laboratorio::IngresodeLaboratorios(vector<Laboratorio> &labo)
{
    int x;
    cout << "Ingrese el numero de laboratorios que desea registrar: ";
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < x; i++)
    {
        Laboratorio labo;
        cout << "Ingrese el aforo del laboratorio nuemero " << i + 1 << ": ";
        getline(cin, labo.aforo);
        cout << "Ingrese el codigo del laboratorio numero " << i + 1 << ": ";
        getline(cin, labo.codigo);
        cout << "Ingrese el nombre del laboratorio numero " << i + 1 << ": ";
        getline(cin, labo.nombre);
        cout << "Ingrese el encargado del laboratorio: ";
        getline(cin, labo.encargado);
        cout << "Ingrese la facultad a la que pertenece el laboratorio: ";
        getline(cin, labo.facultad);
        cout << "Ingrese la ubicacion del laboratorio: ";
        getline(cin, labo.ubicacion);
        cout << "Ingrese las facultades que atiende el laboratorio: ";
        getline(cin, labo.facultadesqueAtiende);
        laboratorios.push_back(labo);
    }
    Laboratorio::GuardarLaboratorios(laboratorios);
    Laboratorio::GuardarID(laboratorios);
}
void Laboratorio::MostrarLaboratorios(const vector<Laboratorio> &labo)
{
    cout<<"**********Laboratorios**********"<<endl;
    ifstream archivo("laboratorios.txt");
    string texto;
    while (!archivo.eof())
    {
        getline(archivo, texto);
        cout << texto << endl;
    }
    archivo.close();
}
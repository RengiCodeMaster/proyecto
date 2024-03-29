#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
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
    Laboratorio(const string &codigo, const string &nombre, const string &encargado, const string &facultad, const string &ubicacion, const string &facultadesqueAtiende)
        : codigo(codigo), nombre(nombre), encargado(encargado), facultad(facultad), ubicacion(ubicacion), facultadesqueAtiende(facultadesqueAtiende) {}

    string getAforo() const { return aforo; }
    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    string getEncargado() const { return encargado; }
    string getFacultad() const { return facultad; }
    string getUbicacion() const { return ubicacion; }
    string getFacultadesqueAtiende() const { return facultadesqueAtiende; }
};

class OperacionLaboratorio
{
public:
    virtual void IngresodeLaboratorios(vector<Laboratorio> &laboratorios) = 0;
    virtual void GuardarLaboratorios(const vector<Laboratorio> &laboratorios) = 0;
    virtual void GuardarID(const vector<Laboratorio> &laboratorios) = 0;
    virtual void MostraID(const vector<Laboratorio> &laboratorios) = 0;
    virtual void MostrarLaboratorios(const vector<Laboratorio> &laboratorios) = 0;
};

class ControldeSistema : public Laboratorio, public OperacionLaboratorio
{
public:
    void IngresodeLaboratorios(vector<Laboratorio> &laboratorios) override
    {
        try
        {
            int cantidad;
            bool validInput = false;
            cout << "\033[1;97m";
            while (!validInput)
            {
                cout << "Ingrese el número de laboratorios que desea registrar: ";
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
                string codigo, nombre, encargado, facultad, ubicacion, facultadesqueAtiende;
                cout << "Ingrese los datos del laboratorio #" << (i + 1) << endl;
                cout << "Ingrese el codigo laboratorio: ";
                getline(cin, codigo);
                cout << "Ingrese el Nombre del Laboratorio: ";
                getline(cin, nombre);
                cout << "Ingrese el Encargado del Laboratorio: ";
                getline(cin, encargado);
                cout << "Ingrese a que Facultad pertenece: ";
                getline(cin, facultad);
                cout << "Ingrese la Ubicacion del Laboratorio: ";
                getline(cin, ubicacion);
                cout << "Facultades que atiende: ";
                getline(cin, facultadesqueAtiende);
                laboratorios.emplace_back(codigo, nombre, encargado, facultad, ubicacion, facultadesqueAtiende);
            }
            GuardarLaboratorios(laboratorios);
            GuardarID(laboratorios);
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void GuardarLaboratorios(const vector<Laboratorio> &laboratorios) override
    {
        ofstream archivo("laboratorios.txt", ios::app);
        for (const Laboratorio &labo : laboratorios)
        {
            archivo << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            archivo << "| ID: " << labo.getCodigo() << "|Nombre: " << labo.getNombre()<< "| Aforo: " << labo.getAforo() << "|Encargado: " << labo.getEncargado() << endl;
            archivo << "|Facultad: " << labo.getFacultad() << "|Ubicacion: " << labo.getUbicacion() << "|Facultades que atiende: " << labo.getFacultadesqueAtiende() << endl;
            archivo << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        archivo.close();
    }

    void GuardarID(const vector<Laboratorio> &laboratorios) override
    {

        ofstream archivo("IDyNombre.txt", ios::app);
        for (const Laboratorio &labo : laboratorios)
        {
            archivo << labo.getCodigo() << " | " << labo.getNombre() << endl;
        }
        archivo.close();
    }

    void MostraID(const vector<Laboratorio> &laboratorios) override
    {
        cout << "\033[1;31m***LABORATORIOS DISPONIBLES***\033[0m" << endl;
        ifstream archivo("IDyNombre.txt");
        string texto;
        while (!archivo.eof())
        {
            getline(archivo, texto);
            cout <<"\033[1;97m" << texto << "\033[0m"<< endl;
        }
        archivo.close();
    }

    void MostrarLaboratorios(const vector<Laboratorio> &laboratorios) override
    {  
        cout << "\033[1;31m***LABORATORIOS DISPONIBLES***\033[0m" << endl;

        ifstream archivo("laboratorios.txt");
        string texto;
        while (!archivo.eof())
        {
            getline(archivo, texto);
            cout << "\033[1;97m" << texto << "\033[0m" << endl;
        }
        archivo.close();
    }
};

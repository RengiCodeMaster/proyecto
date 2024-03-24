#include<iostream>
#include<vector>
#include<limits>
#include<fstream>
using namespace std;
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
    vector<Encargado> encargados;
    void GuardarEncargados(const vector<Encargado> &enca);
    void IngresodeEncargados(vector<Encargado> &enca);
    void MostrarEncargados(const vector<Encargado> &enca);
};
void Encargado::GuardarEncargados(const vector<Encargado> &enca)
{
    ofstream archivo("encargados.txt", ios::app);
    for (const Encargado &encargado : encargados)
    {
        archivo << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        archivo << "|ID: " << encargado.codigo << "|Nombres y Apellidos: " << encargado.nombreyApellidos << "|Numero: " << encargado.numero << "|Laboratorio Asignado: " << encargado.laboratorioAsignado << endl;
        archivo << "|Fecha de Ingreso: " << encargado.fechadeIngreso << "|Fecha de Salida: " << encargado.fechadeSalida << endl;
        archivo << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    archivo.close();
}
void Encargado::IngresodeEncargados(vector<Encargado> &enca)
{
    try
    {
        int cantidad;
        bool validInput = false;
        cout << "\033[1;97m";
        while (!validInput)
        {
            cout << "Ingrese el número de encargados  que desea registrar: ";
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
        for (int i = 0; i < cantidad; i++)
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
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
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
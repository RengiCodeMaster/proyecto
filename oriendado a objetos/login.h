#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;
class Login
{
private:
    string nombreU;
    string apellidoU;
    string correo;
    string contrasena;

public:
    Login() {}
    void registro(vector<Login> logi);
    void inicio_de_sesion(vector<Login> logi);
    void guardartxt(vector<Login> logi);
};
vector<Login> logins;
void Login::guardartxt(vector<Login> logi)
{
    ofstream archivo("usuarios.txt", ios::app);
    for (const Login &log : logins)
    {
        archivo << "nombre: " << log.nombreU << ", Apellido: " << log.apellidoU << ", Correo: " << log.correo << ", Contrasena: " << log.contrasena << endl;
    }
}
void Login::registro(vector<Login> logi)
{
    cout << "***BIENBENIDO AL REGISTRO ***" << endl;
    Login log;
    cout << "Ingrese sus nombres: ";
    getline(cin, log.nombreU);
    cout << "Ingrese susu apellidos: ";
    getline(cin, log.apellidoU);
    cout << "Ingrese su correo: ";
    getline(cin, log.correo);
    cout << "Ingrese su contrasena: ";
    getline(cin, log.contrasena);
    logins.push_back(log);
    Login::guardartxt(logins);
}

void Login::inicio_de_sesion(vector<Login> logi)
{
    string correo, contrasena;
    cout << "Ingrese su correo: ";
    getline(cin, correo);
    cout << "Ingrese su contrasena: ";
    getline(cin, contrasena);

    ifstream archivo("usuarios.txt");
    string line;
    bool found = false;
    while (getline(archivo, line))
    {
        size_t pos = line.find("Correo: " + correo + ", Contrasena: " + contrasena);
        if (pos != string::npos)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "***BIENVENIDO***" << endl;
        
    }
    else
    {
        cout << "***CORREO O CONTRASENA INCORRECTA***" << endl;
    }
}

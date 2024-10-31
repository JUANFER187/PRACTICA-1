#include <iostream>
#include <string.h>

using namespace std;

//------- CLASE -------------
class materia {
private:
    int clave;
    string nombre;
    string profT;
    string libroT;
//--------- OBJETO ---------------------
public:
    materia(int C, string N, string P, string L)
    {
        clave = C;
        nombre = N;
        profT = P;
        libroT = L;
    }

    //---------------------- SOBRECARGA DE OPERADORES ----------------------------------
    bool operator==(const materia& otro) const
    {
        return (clave == otro.clave);
    }

    bool operator!=(const materia& otro) const
    {
        return !(*this == otro);
    }

    friend ostream& operator << (ostream &o, const materia &mat)
    {
        o << "Clave: " << mat.clave << endl;
        o << "Nombre: " << mat.nombre << endl;
        o << "Profesor Titular: " << mat.profT << endl;
        o << "Libro de texto: " << mat.libroT << endl;
        return o;
    }
    friend istream& operator >> (istream &i, materia &mat)
    {
        cout << "Clave: ";
        i >> mat.clave;
        cout << "Nombre: ";
        i >> mat.nombre;
        cout << "Profesor Titular: ";
        i >> mat.profT;
        cout << "Libro de texto: ";
        i >> mat.libroT;

        return i;
    }

    materia operator+(const materia& otro) const
    {

    }

    //----------------- METODOS ------------------------
    void imprime()
    {
        cout << "Clave de materia: " << clave << endl;
        cout << "Nombre materia: " << nombre << endl;
        cout << "Profesor: " << profT << endl;
        cout << "Libro: " << libroT << endl;
        cout << "\n\n" << endl;
    }

    void cambiarClave(int nuevaClave)
    {
        clave = nuevaClave;
    }

    void cambiarProfesor(string nuevoProfesor)
    {
        profT = nuevoProfesor;
    }
};

int main()
{
    //----------- INSTANCIAS ------------------------
    materia Programacion(123, "Programacion", "Lugo", "Como Programar en C++, Deitel");
    materia BD(234, "Base de Datos", "Griselda", "Introduccion a Bases de Datos en PostgreSQL");

    //----------- VARIABLES -----------------------
    int opcion;

    do {
        //-------------- MENU ---------------------------
        cout << "Menu:" << endl;
        cout << "1. Cambiar clave de Programacion" << endl;
        cout << "2. Cambiar profesor de Base de Datos" << endl;
        cout << "3. Imprimir datos de la materia Base de Datos" << endl;
        cout << "4. Imprimir datos de la materia Programacion" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("PAUSE");
        system("cls");

        switch (opcion)
        {
            case 1:
                {
                int nuevaClave;
                cout << "Ingrese la nueva clave para Programacion: ";
                cin >> nuevaClave;
                Programacion.cambiarClave(nuevaClave);
                break;
                system("PAUSE");
                system("cls");
            }

            case 2:
            {
                string nuevoProfesor;
                cout << "Ingrese el NUEVO profesor para Base de Datos: ";
                cin.ignore();
                getline(cin, nuevoProfesor);
                BD.cambiarProfesor(nuevoProfesor);
                break;
                system("PAUSE");
                system("cls");
            }

            case 3:
            {
                BD.imprime();
                system("PAUSE");
                system("cls");
                break;
            }

            case 4:
            {
                Programacion.imprime();
                system("PAUSE");
                system("cls");
                break;
            }
            case 5:
            {
                cout << "Saliendo del programa..." << endl;
                break;
            }

            default:
            {
                cout << "Opcion no valida...\nIntente de nuevo." << endl;
                system("PAUSE");
                system("cls");
            }
        }

    } while (opcion != 5);

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

//----------- CLASE -----------------------------
class empleado
{

private:
    int claveEm;
    string nombre;
    string domicilio;
    float sueldo;
    string reportaA;

public:
    //-------------- OBJETOS ------------------------------
    empleado(int CE, string N, string D, float S, string R)
    {
        claveEm = CE;
        nombre = N;
        domicilio = D;
        sueldo = S;
        reportaA = R;
    }
    //---------------- METODOS -----------------------
    void imprime()
    {
        cout << "Clave de Empleado: " << claveEm << endl;
        cout << "Nombre Empleado: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta a: " << reportaA << endl;
        cout << "\n\n";
    }

    void cambiaDomic(string nuevoDomi)
    {
        domicilio = nuevoDomi;
    }

    void cambiaReporta(string nuevaPR)
    {
        reportaA = nuevaPR;
    }

    void actualizaSueldo(float porcentaje)
    {
        sueldo *= (1 + porcentaje / 100);
    }

    int obtenerClaveEm()
    {
        return claveEm;
    }
};

int main()
{
    //---------------- INSTANCIAS ---------------------------------
    empleado JefePlanta(123, "Michael Scott", "Av SiempreViva 123", 16500, "Toby");
    empleado JefePersonal(234, "Dwight Schrute", "Av del Parque 234", 7500, "Michael");

    //----------------- VARIABLES -----------------------------------
    int opcion;
    int claveEm;

    do {
        //---------------- MENU ----------------------------------
        cout << "Menu:" << endl;
        cout << "1. Cambiar domicilio del empleado" << endl;
        cout << "2. Actualizar sueldo del empleado" << endl;
        cout << "3. Imprimir datos de un empleado" << endl;
        cout << "4. Cambiar persona a quien reporta un empleado" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("PAUSE");
        system("cls");

        switch (opcion)
        {
            case 1:
            {
                cout << "Ingrese la clave del empleado: ";
                cin >> claveEm;
                string nuevoDomicilio;
                cout << "Ingrese el nuevo domicilio: ";
                cin.ignore();
                getline(cin, nuevoDomicilio);
                if (claveEm == JefePlanta.obtenerClaveEm()) {
                    JefePlanta.cambiaDomic(nuevoDomicilio);
                } else if (claveEm == JefePersonal.obtenerClaveEm()) {
                    JefePersonal.cambiaDomic(nuevoDomicilio);
                } else {
                    cout << "Empleado no encontrado." << endl;
                }
                system("PAUSE");
                system("cls");
                break;
            }
            case 2:
            {
                cout << "Ingrese la clave del empleado: ";
                cin >> claveEm;
                float porcentaje;
                cout << "Ingrese el porcentaje de incremento de sueldo: ";
                cin >> porcentaje;
                if (claveEm == JefePlanta.obtenerClaveEm())
                {
                    JefePlanta.actualizaSueldo(porcentaje);
                }
                else if (claveEm == JefePersonal.obtenerClaveEm())
                {
                    JefePersonal.actualizaSueldo(porcentaje);
                }
                else
                {
                    cout << "Empleado no encontrado." << endl;
                }
                system("PAUSE");
                system("cls");
                break;
            }
            case 3:
            {
                cout << "Ingrese la clave del empleado: ";
                cin >> claveEm;
                if (claveEm == JefePlanta.obtenerClaveEm())
                {
                    JefePlanta.imprime();
                }
                else if (claveEm == JefePersonal.obtenerClaveEm())
                {
                    JefePersonal.imprime();
                }
                else
                {
                    cout << "Empleado no encontrado." << endl;
                }
                system("PAUSE");
                system("cls");
                break;
            }
            case 4:
            {
                cout << "Ingrese la clave del empleado: ";
                cin >> claveEm;
                string nuevaPersonaReporta;
                cout << "Ingrese el nuevo nombre de la persona a quien reporta: ";
                cin.ignore();
                getline(cin, nuevaPersonaReporta);
                if (claveEm == JefePlanta.obtenerClaveEm())
                {
                    JefePlanta.cambiaReporta(nuevaPersonaReporta);
                }
                else if (claveEm == JefePersonal.obtenerClaveEm())
                {
                    JefePersonal.cambiaReporta(nuevaPersonaReporta);
                }
                else
                {
                    cout << "Empleado no encontrado." << endl;
                }
                system("PAUSE");
                system("cls");
                break;
            }

            case 5:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción inválida." << endl;
                system("PAUSE");
                system("cls");
                break;
        }
    } while (opcion != 5);

    return 0;
}

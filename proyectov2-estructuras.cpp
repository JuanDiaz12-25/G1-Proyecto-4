#include <iostream>
using namespace std;

struct InfoPrestamos {
    // Atributos
    int CodigoRecurso;
    string NombreRecurso;
    string NombreEstudiante;
    int ContadorRecursos;

    // Método
    void IngresarRecurso(InfoPrestamos codigo[], int contador);//eliminamos el & del contador
};

void InfoPrestamos::IngresarRecurso(InfoPrestamos codigo[], int contador) {
    cout << "Ingresar un Recurso" << endl;
    cout << "Ingrese el nombre del recurso: ";
    cin >> codigo[contador].NombreRecurso;
    codigo[contador].CodigoRecurso = contador + 1; // Asignamos un código único
    cout << "Recurso " << codigo[contador].NombreRecurso << " ingresado con el código: " << codigo[contador].CodigoRecurso << endl;
    contador++; // Incrementamos el contador de recursos
}

int main() {
    InfoPrestamos recursos[10]; 
    int opcion, opcion1;
    int contador = 0; 

    do {
        cout << "Central de Prestamos de la Universidad" << endl;
        cout << "Menu de opciones: " << endl;
        cout << "1. Ingresar un recurso" << endl;
        cout << "2. Agregar un estudiante" << endl;
        cout << "3. Prestar un recurso disponible" << endl;
        cout << "4. Consultar los prestamos de un estudiante" << endl;
        cout << "5. Consultar la informacion de un prestamo" << endl;
        cout << "6. Devolver un recurso prestado" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
            do{
                if (contador < 10) {
                    recursos[0].IngresarRecurso(recursos, contador);
                } else {
                    cout << "No se pueden ingresar más recursos." << endl;
                }
                cout<<"Desea Agregar otro recurso?"<<endl;
                cout<<"1. Ingresar otro recurso"<<endl;
                cout<<"0. Salir"<<endl;
                cin>>opcion1;
            }while(opcion1 != 0);
                break;
             case 2: {
                cout << "Agregar estudiante" << endl;
                
            }
            break;

            case 3: {
                cout << "Prestamo de recurso disponible" << endl;
                
            }
            break;

            case 4: {
                cout << "Consultar prestamos de estudiante" << endl;
                
            }
            break;

            case 5: {
                cout << "Consultar información de prestamo" << endl;
                
            }
            break;

            case 6: {
                cout << "Devolucion de prestamo" << endl;
                
            }
            break;

            case 0:
                break;

            default:
                cout << "Opción no válida" << endl;
        }

        if (opcion != 0) {
            cout << "¿Desea utilizar otra opción?" << endl;
            cout << "1. Continuar" << endl;
            cout << "0. Salir" << endl;
            cin >> opcion;
        }
    } while (opcion != 0);

    cout << "Gracias por usar mi app😁" << endl;
    return 0;
}

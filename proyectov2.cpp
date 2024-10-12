#include<iostream>
using namespace std;

int main() {
    int opcion, opcion1;
    int contadorRecursos = 0;
    string CodigoRecurso, NombreRecurso, CodigoEstudiante, NombreEstudiante;
    string CodRec[10][2];

    do {
        cout << "Central de Prestamos de la Universidad" << endl;
        cout << "Menú de opciones " << endl;
        cout << "1. Ingresar un recurso" << endl;
        cout << "2. Agregar un estudiante " << endl;
        cout << "3. Prestar un recurso disponible" << endl;
        cout << "4. Consultar los préstamos de un estudiante" << endl;
        cout << "5. Consultar la información de un préstamo" << endl;
        cout << "6. Devolver un recurso prestado" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                do {
                    if (contadorRecursos < 10) {
                        cout << "Ingresar un recurso" << endl;
                        cout << "Ingrese el nombre del Recurso" << endl;
                        cin >> NombreRecurso;
                        //aqui aun no pedimos el codigo del estudiante porque aun no hemos hecho el requerimiento funcional
                        //que nos registra un estudiante y nos da el codigo estudiantil
                        CodRec[contadorRecursos][0] = NombreRecurso;
                        CodRec[contadorRecursos][1] = to_string(contadorRecursos + 1); 

                        cout << "Recurso " << NombreRecurso << " Registrado con el código: " << CodRec[contadorRecursos][1] << endl;
                        contadorRecursos++;  

                        cout << "¿Desea ingresar otro recurso?" << endl;
                        cout << "1. Continuar" << endl;
                        cout << "0. Salir" << endl;
                        cin >> opcion1;
                    } else {
                        cout << "No se pueden registrar más recursos (máximo 10)." << endl;
                        opcion1 = 0;
                    }
                } while (opcion1 != 0);
                //por ahora vamos a generar un codigo de 1 digito, mas adelante cuando implementemos los requerimientos funcionales
                //que hacen falta para complementar este requerimiento, podemos generar codigos mas dinamicos.
            }
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

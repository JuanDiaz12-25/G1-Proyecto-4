//9 Noviembre 2024- Realizamos la implementacion de los requerimientos 2 y 3, implementamos la funcion de generar codigos unicos
//Implementamos validadores e hicimos algunos ajustes, estos mismos estaran tambien comentados para poder guiar al lector
#include <iostream>
#include <string>
#include <cstdlib> // Para srand y rand
#include <ctime>   // Para time
using namespace std;

struct InfoPrestamos {
    int CodigoRecurso;
    string NombreRecurso;
    string NombreEstudiante;
    bool Disponible;
    long long CodigoEstudiante;

    void IngresarRecurso(InfoPrestamos codigo[], int &contador);
};

//Funcion para generar codigos aleatorios de 6 digitos
int GenerarCodigo6Digitos() {
    return 100000 + rand() % 900000; // Genera un número aleatorio entre 100000 y 999999
}

// Funcion para generar codigos aleatorios de 11 digitos
long long generarunicoCodigo(){
    return 10000000000 + rand() % 90000000000; // número de 11 dígitos entre 10000000000 y 99999999999
}

//usamos "rand" para generar un numero aleatorio al cual lo llamaremos codigo

void InfoPrestamos::IngresarRecurso(InfoPrestamos codigo[], int &contador) {
    //Volvemos a colocar el & en el contador ya que resulta que
    //al eliminarlo, no se almacenaba correctamente la posicion del contador
    //resultando en que no se podia ejecutar la funcion de buscar el recurso en 
    //el requerimiento 3.
    cout << "Ingresar un Recurso" << endl;
    cout << "Ingrese el nombre del recurso: ";
    cin >> codigo[contador].NombreRecurso;
    codigo[contador].CodigoRecurso = GenerarCodigo6Digitos(); // Asignamos un código único con la funcion de numeros aleatorios
    codigo[contador].Disponible = true; // El recurso está disponible desde un inicio
    cout << "Recurso " << codigo[contador].NombreRecurso << " ingresado con el código: " << codigo[contador].CodigoRecurso << endl;
    contador++; // Incrementamos el contador de recursos
}

//Aqui usamos una funcion para verificar si el codigo tiene 6 digitos
bool VerificarCodigo6Digitos(int codigo) {
    return codigo >= 100000 && codigo <= 999999;
}

bool VerificarCodigo11Digitos(long long codigo){
    return codigo >= 10000000000 && codigo <= 99999999999;
}

int main() {
    InfoPrestamos recursos[10];
    int opcion, opcion1, opcion2;
    int contador = 0;
    long long CodigoEstudiante;
    string NombreEstudiante;
    srand(time(0)); // Inicializamos la semilla para la generación aleatoria, sin esto, siempre generaremos el mismo codigo, 
    //esta funcion viene con las nuevas librerias incluidas en nuestro cdigo

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
                do {
                    if (contador < 10) {
                        recursos[0].IngresarRecurso(recursos, contador);
                    } else {
                        cout << "No se pueden ingresar más recursos." << endl;
                    }
                    cout << "Desea Agregar otro recurso?" << endl;
                    cout << "1. Ingresar otro recurso" << endl;
                    cout << "0. Salir" << endl;
                    cin >> opcion1;
                } while(opcion1 != 0);
                break;

            case 2: do{
                cout << "Registrar estudiante" << endl; // Aquí implementamos el registro de un estudiante
                cout << "ingrese su nombre: ";
                cin >> NombreEstudiante;
                
                long long unicocogido = generarunicoCodigo();// Utilizamos long long, porque al utilizar un int normal, un numero de 11 digitos excede el limite
               
                cout << "\n¡Registro exitoso!" << endl;
                cout << "Nombre: " << NombreEstudiante << endl;
                cout << "Código único asignado: " << unicocogido << endl;
                 
                    
                    cout << "Desea Agregar otro estudiante?" << endl;
                    cout << "1. Ingresar otro estudiante" << endl;
                    cout << "0. Salir" << endl;
                    cin >> opcion1;
                }while(opcion1 != 0);
            break;

            case 3:do{
                cout << "Prestamo de recurso disponible" << endl;
                cout << "Ingresa el codigo estudiantil: ";
                cin >> CodigoEstudiante;
                if(!VerificarCodigo11Digitos(CodigoEstudiante)){ //Validador
                    cout << "Error: El código debe ser de 11 dígitos." << endl;
                    do{
                        cout<<"Ingresar Codigo de 11 digitos"<<endl;
                        cin>>CodigoEstudiante;
                        }while(!VerificarCodigo11Digitos(CodigoEstudiante));
                }
                // Suponiendo que el estudiante esta registrado, ya que para verificar esto, tendriamos que recuperar datos una vez
                //finalizada la ejecución de un codigo, pero como esta información se guarda en la memoria ram, al detener el codigo
                //esta información se pierde, por lo que por ahora no podemos implementar una funcion para verificar si estan registrados
                //tanto los estudiantes como los recursos.
                int codigoRecurso;
                cout << "Ingresa el Codigo del recurso: ";
                cin >> codigoRecurso;
                if(!VerificarCodigo6Digitos(codigoRecurso)){ //Validador
                    cout << "Error: El código debe ser de 6 dígitos." << endl;
                    do{
                        cout<<"Ingresar Codigo de 6 digitos"<<endl;
                        cin>>codigoRecurso;
                        }while(!VerificarCodigo6Digitos(codigoRecurso));
                }

                bool recursoEncontrado = false;
                for (int i = 0; i < contador; i++) {
                    if (recursos[i].CodigoRecurso == codigoRecurso) {
                        recursoEncontrado = true;
                        if (recursos[i].Disponible) {
                            recursos[i].Disponible = false; // Marcamos el recurso como prestado
                            recursos[i].NombreEstudiante = CodigoEstudiante;
                            cout << "Recurso " << recursos[i].NombreRecurso << " con el codigo " 
                                 << recursos[i].CodigoRecurso << " prestado al estudiante registrado con el codigo: " 
                                 << CodigoEstudiante << endl;
                        } else {
                            cout << "El recurso no está disponible." << endl;
                        }
                        break;
                    }
                }

                if (!recursoEncontrado) {
                    cout << "Código de recurso no encontrado." << endl;
                }
            cout << "Desea Agregar otro recurso?" << endl;
                    cout << "1. Ingresar otro recurso" << endl;
                    cout << "0. Salir" << endl;
                    cin >> opcion1;
                } while(opcion1 != 0);
        
            break;

            case 4: {
                cout << "Consultar prestamos de estudiante" << endl;
                // Aquí Implementaremos la consulta de prestamos de un estudiante en especifico
            }
            break;

            case 5: {
                cout << "Consultar información de prestamo" << endl;
                // Aquí implementaremos la informacion de prestamos con una lista, indicando si estan disponibles y sus respectivos codigos
            }
            break;

            case 6: {
                cout << "Devolucion de prestamo" << endl;
                // Aquí implementaremos la devolucion de un prestamo
            }
            break;

            case 0:
                break;

            default:
                cout << "Opción no válida" << endl;
        }
    } while (opcion != 0);

    cout << "Gracias por usar mi app😁" << endl;
    cout<<"Hecho por Juan Diaz y Stanlyn Monterroza."<<endl;
    return 0;
}

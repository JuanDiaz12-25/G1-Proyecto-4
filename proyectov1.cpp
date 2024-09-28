#include<iostream>
using namespace std;

int main()
{
int opcion;
string CodigoRecurso, NombreRecurso, CodigoEstudiante, NombreEstudiante;
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
    cin>>opcion;
    switch(opcion){
    case 1:{
    string 
    cout << "Ingresar un recurso" << endl;
    }
    break;
    case 2:{
    cout << "Agregar estudiante" << endl;
    }
    break;
    case 3:{
    cout << "Prestamo de recurso disponible" << endl;
    }
    break;
    case 4:{
    cout << "Consultar prestamos de estudiante" << endl;
    }
    break;
    case 5:{
    cout << "Consultar información de prestamo" << endl;
    }
    break;
    case 6:{
    cout << "Devolucion de prestamo" << endl;
    }
    break;
    }
    }while(opcion != 0);
    cout << "Gracias por usar mi app😁" << endl;
    return 0;
}
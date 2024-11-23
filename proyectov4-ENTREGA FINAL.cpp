#include <iostream>
#include <string>
using namespace std;
//Implementacion de nueva estructura para manejar los codigos de estudiantes
struct Estudiante {
	long long CodigoEstudiante;
	string NombreEstudiante;
};
struct InfoPrestamos {
	int CodigoRecurso;
	string NombreRecurso;
	string NombreEstudiante;
	bool Disponible;

	void IngresarRecurso(InfoPrestamos codigo[], int &contadorRecursos);
	void PrestarDinero();
};

void InfoPrestamos::IngresarRecurso(InfoPrestamos codigo[], int &contadorRecursos) {
	cout << "Ingresar un Recurso" << endl;
	cout << "Ingrese el nombre del recurso: ";
	cin >> codigo[contadorRecursos].NombreRecurso;
	codigo[contadorRecursos].CodigoRecurso = 100000 + contadorRecursos; // Asignamos un codigo unico
	codigo[contadorRecursos].Disponible = true; // El recurso esta disponible desde un inicio
	cout << "--------------------" << endl;
	cout << "Recurso " << codigo[contadorRecursos].NombreRecurso << " ingresado con el codigo: " << codigo[contadorRecursos].CodigoRecurso << endl;
	contadorRecursos++; // Incrementamos el contador de recursos

}
void InfoPrestamos::PrestarDinero() {
	float montoPrestamo, tasaInteres;
	int diasPrestamo;

	cout << "---------------------" << endl;
	cout << "Prestamo de dinero" << endl;
	cout << "---------------------" << endl;
	cout << "Ingrese el monto del prestamo: ";
	cin >> montoPrestamo;

	cout << "---------------------" << endl;
	cout << "Ingrese la tasa de interes anual hasta 50%: ";
	cin >> tasaInteres;

	while (tasaInteres < 1 || tasaInteres > 50) {
		cout << "El valor ingresado es erroneo (limite 50%)" << endl;
		cout << "Ingrese el valor correspondiente: ";
		cin >> tasaInteres;
	}

	cout << "---------------------" << endl;
	cout << "Ingrese el plazo del prestamo (limite 2920 dias): ";
	cin >> diasPrestamo;

	while (diasPrestamo < 1 || diasPrestamo > 2920 ) {
		cout << "El valor ingresado es invalido (limite 2920 dias)" << endl;
		cout << "Ingrese los dias dentro la franja valida: ";
		cin >> diasPrestamo;
	}

	// Calcular el monto total a pagar
	double montoTotal = montoPrestamo * (1 + (tasaInteres / 100) * (diasPrestamo / 365.0));
	cout << "\n--- Informacion del prestamo ---" << endl;
	cout << "Monto prestado: $" << montoPrestamo << endl;
	cout << "Tasa de interes anual: " << tasaInteres << "%" << endl;
	cout << "Plazo del prestamo: " << diasPrestamo << " dias" << endl;
	cout << "Monto total a pagar: $" << montoTotal << endl;
}

//Realizamos otro void igual al anterior con la nueva estructura estudiantes para asignar un codigo al estudiante, la forma en la que nos dijeron en la
//retroalimentacion, aunque esta bien, no nos ayuda a almacenar correctamente los codigos.
void RegistrarEstudiante(Estudiante estudiantes[], int &contadorEstudiantes, long long &codigoEstudianteGlobal) {
	cout << "Registrar estudiante" << endl;
	cout << "Ingrese el nombre del estudiante: ";
	cin >> estudiantes[contadorEstudiantes].NombreEstudiante;

	estudiantes[contadorEstudiantes].CodigoEstudiante = codigoEstudianteGlobal; // codigo unico para el estudiante
	cout << "--------------------" << endl;
	cout << "Registro exitoso!" << endl;
	cout << "Nombre: " << estudiantes[contadorEstudiantes].NombreEstudiante << endl;
	cout << "Codigo unico asignado: " << estudiantes[contadorEstudiantes].CodigoEstudiante << endl;

	codigoEstudianteGlobal++; // Incrementar el codigo global
	contadorEstudiantes++;
}

int main() {
	InfoPrestamos recursos[20];
	Estudiante estudiantes[100];
	int opcion, opcion1;
	int contadorRecursos = 0;
	int contadorEstudiantes = 0;
	long long codigoEstudianteGlobal = 10000000000;
	long long CodigoEstudiante;

	//elementos ingresados por defecto para facilitar las pruebas:

	recursos[contadorRecursos].CodigoRecurso = 100000; // Codigo inicial
	recursos[contadorRecursos].NombreRecurso = "Libro";
	recursos[contadorRecursos].Disponible = true;
	recursos[contadorRecursos].NombreEstudiante = -1; // No prestado
	contadorRecursos++; // Incrementamos el contador de recursos

	estudiantes[contadorEstudiantes].CodigoEstudiante = codigoEstudianteGlobal;
	estudiantes[contadorEstudiantes].NombreEstudiante = "Johan";
	contadorEstudiantes++;
	codigoEstudianteGlobal++;

	// Menu de opciones
	do {
		cout<<"----------------------------------"<<endl;
		cout << "Central de Prestamos de la Universidad" << endl;
		cout << "Elaborado por Stanlyn Monterroza y Juan Diaz"<<endl;
		cout<<"|----------------------------------|"<<endl;
		cout << "Menu de opciones: " << endl;
		cout << "1. Ingresar un recurso" << endl;
		cout << "2. Agregar un estudiante" << endl;
		cout << "3. Prestar un recurso disponible" << endl;
		cout << "4. Consultar los prestamos de un estudiante" << endl;
		cout << "5. Consultar la informacion de un prestamo" << endl;
		cout << "6. Devolver un recurso prestado" << endl;
		cout << "0. Salir" << endl;
		cout<<"----------------------------------"<<endl;
		cout<<"Ingresar opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			do {
				cout << "------------------------------" << endl;
				cout << "Seleccione una opcion:" << endl;
				cout << "1. Agregar recurso" << endl;
				cout << "2. Prestamo de dinero" << endl;
				cout << "------------------------------" << endl;
				cout << "Ingresar opcion: ";
				cin >> opcion;

        switch (opcion) {
		case 1:
				if (contadorRecursos < 20) {
						recursos[0].IngresarRecurso(recursos, contadorRecursos);
				} else {
				cout << "--------------------" << endl;
				cout << "No se pueden ingresar mas recursos." << endl;
				}
				break;


		case 2:
		recursos[0].PrestarDinero();
			    break;

				default:
				cout << "opcion no valida. Intente de nuevo." << endl;
				break;
				}

				cout << "------------------------------" << endl;
				cout << "Desea Agregar otro recurso?" << endl;
				cout << "1. ingresar otro recurso" << endl;
				cout << "0. salir" << endl;
				cout<<"------------------------------"<<endl;
				cout << "Ingresar opcion: ";
				cin >> opcion1;


			} while (opcion1 != 0);
			break;

		case 2:
			do {
				cout<<"------------------------------"<<endl;
				RegistrarEstudiante(estudiantes, contadorEstudiantes, codigoEstudianteGlobal);//hacemos la inclusion de otra estructura para facilitar todo
				cout<<"------------------------------"<<endl;
				cout << "Desea Agregar otro estudiante?" << endl;
				cout << "1. Ingresar otro estudiante" << endl;
				cout << "0. Salir" << endl;
				cout<<"------------------------------"<<endl;
				cout<<"Ingresar opcion: ";
				cin >> opcion1;
				if(opcion1 != 0 and opcion1 != 1) {
					do {
						cout << "--------------------" << endl;
						cout << "Valor introducido incorrecto" << endl;
						cout << "1. Ingresar otro recurso, 0.Salir" << endl;
						cout<<"Ingresar opcion: ";
						cin >> opcion1;
					} while(opcion1 != 0 and opcion1 != 1);
				}
			} while(opcion1 != 0);
			break;

		case 3:
			do {
				cout << "------------------------------" << endl;
				cout << "Prestamo de recurso disponible" << endl;
				cout << "Ingresa el codigo estudiantil: ";
				cin >> CodigoEstudiante;

				// Validar el codigo de estudiante
				if (CodigoEstudiante < 10000000000 || CodigoEstudiante > 99999999999) {
					cout << "Error: El codigo debe ser de 11 digitos." << endl;
					do {
						cout << "Ingresar Codigo de 11 digitos: ";
						cin >> CodigoEstudiante;
					} while (CodigoEstudiante < 10000000000 || CodigoEstudiante > 99999999999);
				}

				// Buscar al estudiante por su codigo
				string nombreEstudiante = "";
				for (int i = 0; i < contadorEstudiantes; i++) {
					if (estudiantes[i].CodigoEstudiante == CodigoEstudiante) {
						nombreEstudiante = estudiantes[i].NombreEstudiante;
						break;
					}
				}

				if (nombreEstudiante == "") {
					cout << "--------------------" << endl;
					cout << "El estudiante con el codigo " << CodigoEstudiante << " no esta registrado." << endl;
					break;
				}

				// Solicitar el codigo del recurso
				int codigoRecurso;
				cout << "Ingresa el Codigo del recurso: ";
				cin >> codigoRecurso;

				// Validar el cidigo del recurso
				if (codigoRecurso < 100000 || codigoRecurso > 999999) {
					cout << "Error: El codigo debe ser de 6 digitos." << endl;
					do {
						cout << "Ingresar Codigo de 6 digitos: ";
						cin >> codigoRecurso;
					} while (codigoRecurso < 100000 || codigoRecurso > 999999);
				}

				// Buscar el recurso por su codigo
				bool recursoEncontrado = false;
				for (int i = 0; i < contadorRecursos; i++) {
					if (recursos[i].CodigoRecurso == codigoRecurso) {
						recursoEncontrado = true;
						if (recursos[i].Disponible) {
							recursos[i].Disponible = false; // Marcar el recurso como prestado
							recursos[i].NombreEstudiante = nombreEstudiante; // Guardar el nombre del estudiante
							cout << "--------------------" << endl;
							cout << "Recurso " << recursos[i].NombreRecurso << " con el codigo "
							     << recursos[i].CodigoRecurso << " prestado a el estudiante: " << nombreEstudiante<<", registrado con el codigo "<<CodigoEstudiante << endl;
						} else {
							cout << "--------------------" << endl;
							cout << "El recurso no esta disponible." << endl;
							cout << "------------------------------" << endl;
				cout << "Desea realizar otro prestamo?" << endl;
				cout << "1. Si" << endl;
				cout << "0. No" << endl;
				cout << "Ingresar opcion: ";
				cin >> opcion1;

				if (opcion1 != 0 && opcion1 != 1) {
					do {
						cout << "--------------------" << endl;
						cout << "Valor introducido incorrecto." << endl;
						cout << "1. Si, 0. No" << endl;
						cout << "Ingresar opcion: ";
						cin >> opcion1;
					} while (opcion1 != 0 && opcion1 != 1);
				}
						}
						break;
					}
				}

				if (!recursoEncontrado) {
					cout << "--------------------" << endl;
					cout << "Codigo de recurso no encontrado." << endl;

				}

				cout << "------------------------------" << endl;
				cout << "Desea realizar otro prestamo?" << endl;
				cout << "1. Si" << endl;
				cout << "0. No" << endl;
				cout << "Ingresar opcion: ";
				cin >> opcion1;

				if (opcion1 != 0 && opcion1 != 1) {
					do {
						cout << "--------------------" << endl;
						cout << "Valor introducido incorrecto." << endl;
						cout << "1. Si, 0. No" << endl;
						cout << "Ingresar opcion: ";
						cin >> opcion1;
					} while (opcion1 != 0 && opcion1 != 1);
				}
			} while (opcion1 != 0);

			break;


		case 4: { // Implementacion requerimiento 4:
			long long Consultacodigo; // Nueva variable temporal
			do {
				cout << "------------------------------" << endl;
				cout << "Consultar prestamos de estudiante" << endl;
				cout << "Ingresar el codigo del estudiante: ";
				cin >> Consultacodigo;

				// Validar el codigo de estudiante
				if (Consultacodigo < 10000000000 || Consultacodigo > 99999999999) {
					cout << "--------------------" << endl;
					cout << "Error: El codigo debe ser de 11 digitos." << endl;
					do {
						cout << "Ingresar Codigo de 11 digitos: ";
						cin >> Consultacodigo;
					} while (Consultacodigo < 10000000000 || Consultacodigo > 99999999999);
				}

				// Buscar al estudiante por su codigo
				string nombreEstudiante = "";//creamos un string vacio para poder almacenar el nombre
				for (int i = 0; i < contadorEstudiantes; i++) {
					if (estudiantes[i].CodigoEstudiante == Consultacodigo) {
						nombreEstudiante = estudiantes[i].NombreEstudiante;//recorremos todos los espacios de contadorEstudiantes para ver si coinciden
						break;
					}
				}

				if (nombreEstudiante == "") {//estudiante no encontrado, entonces el string seguira vacio
					cout << "--------------------" << endl;
					cout << "El estudiante con el codigo " << Consultacodigo << " no esta registrado." << endl;
					cout << "------------------------------" << endl;
					cout << "Desea realizar otra consulta?" << endl;
					cout << "1. Si" << endl;
					cout << "0. No" << endl;
					cout << "Ingresar opcion: ";
					cin >> opcion1;

					if (opcion1 != 0 && opcion1 != 1) {
						do {
							cout << "Valor introducido incorrecto." << endl;
							cout << "1. Si, 0. No" << endl;
							cout << "Ingresar opcion: ";
							cin >> opcion1;
						} while (opcion1 != 0 && opcion1 != 1);
					}
					break;
				}

				// Buscar los recursos prestados al estudiante
				bool prestamosEncontrados = false;
				for (int i = 0; i < contadorRecursos; i++) {
					if (recursos[i].NombreEstudiante == nombreEstudiante) {
						prestamosEncontrados = true;
						cout << "--------------------" << endl;
						cout << "Recurso: " << recursos[i].NombreRecurso
						     << ", prestado al estudiante: "<<nombreEstudiante<<", con el codigo: " << recursos[i].CodigoRecurso << endl;
					}
				}

				if (!prestamosEncontrados) {
					cout << "--------------------" << endl;
					cout << "No se encontraron prestamos para el estudiante con el codigo: " << Consultacodigo << endl;
				}

				cout << "------------------------------" << endl;
				cout << "Desea realizar otra consulta?" << endl;
				cout << "1. Si" << endl;
				cout << "0. No" << endl;
				cout << "Ingresar opcion: ";
				cin >> opcion1;

				if (opcion1 != 0 && opcion1 != 1) {
					do {
						cout << "--------------------" << endl;
						cout << "Valor introducido incorrecto." << endl;
						cout << "1. Si, 0. No" << endl;
						cout << "Ingresar opcion: ";
						cin >> opcion1;
					} while (opcion1 != 0 && opcion1 != 1);
				}
			} while (opcion1 != 0);
		}
		break;

		case 5: {
			cout<<"------------------------------"<<endl;
			cout << "Consultar informacion de prestamos" << endl;
			int tipoPrestamo;
			do {
				cout << "--------------------" << endl;
				cout << "Seleccione una opcion:" << endl;
				cout << "1. Prestamo de recursos (libros, herramientas, etc.)" << endl;
				cout << "2. Prestamo de dinero" << endl;
				cout << "Ingrese su opcion: ";
				cin >> tipoPrestamo;
				if (tipoPrestamo < 1 || tipoPrestamo > 2) {
					do {
						cout << "--------------------" << endl;
						cout << "Valor introducido incorrecto." << endl;
						cout << "1. Prestamo de Recursos, 2. Prestamo de dinero" << endl;
						cout << "Ingresar opcion: ";
						cin >> tipoPrestamo;
					} while (tipoPrestamo < 1 || tipoPrestamo > 2);
				}
				if(tipoPrestamo == 1) {
					cout << "--------------------" << endl;
					cout << "Ingrese el codigo del recurso: ";
					int codigoRecurso;
					cin >> codigoRecurso;

					bool encontrado = false;
					for (int i = 0; i < contadorRecursos; i++) {
						if (recursos[i].CodigoRecurso == codigoRecurso) {
							encontrado = true;
							cout << "--------------------"<<endl;
							cout <<"Consultar informacion Prestamo de recurso"<<endl;
							cout << "--------------------" << endl;
							cout << "Recurso: " << recursos[i].NombreRecurso << endl;
							cout << "Codigo: " << recursos[i].CodigoRecurso <<endl;
							cout << "Estado: " << (recursos[i].Disponible ? "Disponible" : "Prestado") << endl;
							if (!recursos[i].Disponible) {
								cout << "Prestado a: " << recursos[i].NombreEstudiante << endl;
							}
							break;
						}
					}
					if (!encontrado) {
						cout << "Codigo de recurso no encontrado." << endl;
						cout << "------------------------------" << endl;
						cout << "Desea realizar otra consulta?" << endl;
						cout << "1. Si" << endl;
						cout << "0. No" << endl;
						cout << "Ingresar opcion: ";
						cin >> opcion1;

						if (opcion1 != 0 && opcion1 != 1) {
							do {
								cout<<"---------------------"<<endl;
								cout << "Valor introducido incorrecto." << endl;
								cout << "1. Si, 0. No" << endl;
								cout << "Ingresar opcion: ";
								cin >> opcion1;
							} while (opcion1 != 0 && opcion1 != 1);
						}
					}
				}
				else if (tipoPrestamo == 2) {
					double montoPrestamo, tasaInteres;
					int anosPrestamo;
					cout << "---------------------"<<endl;
					cout <<"Prestamo de dinero"<<endl;
					cout <<"---------------------"<<endl;
					cout << "Ingrese el monto del prestamo: ";
					cin >> montoPrestamo;
					if (montoPrestamo < 0 || montoPrestamo > 50000000) {
						do {
							cout <<"-----------------"<<endl;
							cout <<"El monto ingresado supera el limite (50 Millones)"<<endl;
							cout <<"Ingresa una cantidad adecuada : ";
							cin >> montoPrestamo;
						} while (montoPrestamo < 0 || montoPrestamo > 50000000);
					}
					cout <<"-----------------"<<endl;
					cout << "Ingrese la tasa de interes anual de 1% a 50%: ";
					cin >> tasaInteres;
					if(tasaInteres < 0 || tasaInteres > 50) {
						do {
							cout<< "-----------------"<<endl;
							cout<<"El valor ingresado es invaildo (limite 50%)"<<endl;
							cout<<"Ingresar el valor adecuado: ";
							cin>>tasaInteres;
						} while (tasaInteres < 0 || tasaInteres > 10);
					}
					cout<<"-----------------"<<endl;
					cout << "Ingrese el plazo del prestamo en años (limite 15 años): ";
					cin >> anosPrestamo;
					if(anosPrestamo <0 || anosPrestamo >5) {
						do {
							cout<< "-----------------"<<endl;
							cout<<"El valor ingresado es invaildo (limite 5 años)"<<endl;
							cout<<"Ingresar el valor adecuado: ";
							cin>>anosPrestamo;
						} while(anosPrestamo <0 || anosPrestamo >5);
					}

					// Calcular el monto total a pagar
					double montoTotal = montoPrestamo * (1 + (tasaInteres / 100) * anosPrestamo);

					cout << "\n--- Informacion del prestamo ---" << endl;
					cout << "Monto prestado: $" << montoPrestamo << endl;
					cout << "Tasa de interes anual: " << tasaInteres << "%" << endl;
					cout << "Plazo del prestamo: " << anosPrestamo << " años" << endl;
					cout << "Monto total a pagar: $" << montoTotal << endl;
				}
				cout << "------------------------------" << endl;
				cout << "Desea realizar otra consulta?" << endl;
				cout << "1. Si" << endl;
				cout << "0. No" << endl;
				cout << "Ingresar opcion: ";
				cin >> opcion1;

				if (opcion1 != 0 && opcion1 != 1) {
					do {
						cout << "--------------------" << endl;
						cout << "Valor introducido incorrecto." << endl;
						cout << "1. Si, 0. No" << endl;
						cout << "Ingresar opcion: ";
						cin >> opcion1;
					} while (opcion1 != 0 && opcion1 != 1);
				}
			} while (opcion1 != 0);
		}

		break;

		case 6: {// usamos la misma tecnica del caso 4, para pdoer buscar al estudiante

			long long Consultacodigo;//variable temporal
			cout<<"------------------------------"<<endl;
			cout << "Devolucion de prestamo" << endl;
			do {
				cout << "Ingresar el codigo del estudiante" << endl;
				cin >> Consultacodigo;

				if (Consultacodigo < 10000000000 || Consultacodigo > 99999999999) {
					cout << "--------------------" << endl;
					cout << "Error: El codigo debe ser de 11 digitos." << endl;
					do {
						cout << "Ingresar Codigo de 11 digitos: ";
						cin >> Consultacodigo;
					} while (Consultacodigo < 10000000000 || Consultacodigo > 99999999999);
				}

				// Buscar al estudiante por su codigo
				string nombreEstudiante = "";//creamos un string vacio para poder almacenar el nombre
				for (int i = 0; i < contadorEstudiantes; i++) {
					if (estudiantes[i].CodigoEstudiante == Consultacodigo) {
						nombreEstudiante = estudiantes[i].NombreEstudiante;//recorremos todos los espacios de contadorEstudiantes para ver si coinciden
						break;
					}
				}
				if (nombreEstudiante == "") {//estudiante no encontrado, entonces el string seguira vacio
					cout << "--------------------" << endl;
					cout << "El estudiante con el codigo " << Consultacodigo << " no esta registrado." << endl;
					cout << "------------------------------" << endl;
					cout << "Desea realizar otra consulta?" << endl;
					cout << "1. Si" << endl;
					cout << "0. No" << endl;
					cout << "Ingresar opcion: ";
					cin >> opcion1;

					if (opcion1 != 0 && opcion1 != 1) {
						do {
							cout<<"---------------------"<<endl;
							cout << "Valor introducido incorrecto." << endl;
							cout << "1. Si, 0. No" << endl;
							cout << "Ingresar opcion: ";
							cin >> opcion1;
						} while (opcion1 != 0 && opcion1 != 1);
					}
					break;
				}

				bool recursoPrestado = false;
				for (int i = 0; i < contadorRecursos; i++) {
					if (recursos[i].NombreEstudiante == nombreEstudiante && !recursos[i].Disponible) {// ! -> no estC! disponible osea esta prestado
						cout<<"--------------------"<<endl;
						cout << "Recurso: " << recursos[i].NombreRecurso << " (Codigo: " << recursos[i].CodigoRecurso << ")" << endl;
						cout << "Estado: Prestado al estudiante - "<<nombreEstudiante<<endl;
						recursoPrestado = true;
					}
				}

				if (!recursoPrestado) {
					cout << "--------------------" << endl;
					cout << "No hay recursos prestados por el estudiante." << endl;
					cout << "------------------------------" << endl;
					cout << "Desea realizar otra consulta?" << endl;
					cout << "1. Si" << endl;
					cout << "0. No" << endl;
					cout << "Ingresar opcion: ";
					cin >> opcion1;

					if (opcion1 != 0 && opcion1 != 1) {
						do {
							cout << "--------------------" << endl;
							cout << "Valor introducido incorrecto." << endl;
							cout << "1. Si, 0. No" << endl;
							cout << "Ingresar opcion: ";
							cin >> opcion1;
						} while (opcion1 != 0 && opcion1 != 1);
					}
					break;
				}

				// Solicitar el recurso a devolver
				int codigoRecurso;
				cout << "--------------------"<<endl;
				cout << "Ingrese el codigo del recurso a devolver: ";
				cin >> codigoRecurso;
				if (codigoRecurso < 100000 || codigoRecurso > 999999) {
					cout << "--------------------"<<endl;
					cout << "Error: El codigo debe ser de 6 digitos." << endl;
					do {
						cout << "Ingresar Codigo de 6 digitos: ";
						cin >> codigoRecurso;
					} while (codigoRecurso < 100000 || codigoRecurso > 999999);
				}

				// Procesar devoluciC3n
				bool recursoEncontrado = false;
				for (int i = 0; i < contadorRecursos; i++) {
					if (recursos[i].CodigoRecurso == codigoRecurso && recursos[i].NombreEstudiante == nombreEstudiante) {
						recursoEncontrado = true;
						recursos[i].Disponible = true;// marcamos como disponible denuevo
						recursos[i].NombreEstudiante = ""; // Limpiar registro del estudiante
						cout << "--------------------" << endl;
						cout << "El recurso " << recursos[i].NombreRecurso << " ha sido devuelto con exito." << endl;
						break;
					}
				}

				if (!recursoEncontrado) {
					do {
						cout << "--------------------" << endl;
						cout << "El recurso no coincide con los prestamos del estudiante." << endl;
						cout << "Ingresar el codigo del recurso a devolver o, 0. -> Salir"<<endl;
					} while(opcion1 != 0 && !recursoEncontrado);
				}

				cout << "------------------------------" << endl;
				cout << "Desea realizar otra devolucion?" << endl;
				cout << "1. Si" << endl;
				cout << "0. No" << endl;
				cout << "Ingrese su opcion: ";
				cin >> opcion1;

				if (opcion1 != 0 && opcion1 != 1) {
					do {
						cout << "--------------------" << endl;
						cout << "Valor introducido incorrecto. 1. Si, 0. No" << endl;
						cin >> opcion1;
					} while (opcion1 != 0 && opcion1 != 1);
				}

			} while (opcion1 != 0);
		}
		break;

		case 0:
			break;

		default:
			cout << "--------------------" << endl;
			cout << "Opcion no valida" << endl;
		}
	} while (opcion != 0);

	cout<<"------------------------------"<<endl;
	cout << "Gracias por usar mi app 😁" << endl;
	cout<<"Hecho por Juan Diaz y Stanlyn Monterroza."<<endl;
	return 0;
}
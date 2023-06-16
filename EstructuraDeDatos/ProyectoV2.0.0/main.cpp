#include "ListaTareas.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>

void altas(ListaTareas& lista) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string titulo, descripcion;

    std::cout << "Ingrese el titulo de la tarea: ";
    std::getline(std::cin, titulo);

    std::cout << "Ingrese la descripcion de la tarea: ";
    std::getline(std::cin, descripcion);

    lista.agregarTarea(titulo, descripcion);
    std::cout << "Tarea agregada correctamente." << std::endl;
}

int obtenerOpcionValida(int opcion) {
    while (!(std::cin >> opcion)) {
        std::cout << "Ingrese solo numeros, intente nuevamente: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }   
    return opcion;
}

void bajas(ListaTareas& lista) {
    int numero;
    std::cout << "Ingrese el numero de la tarea a eliminar: ";
    std::cin >> numero;
    //numero=obtenerOpcionValida(numero);
	lista.eliminarTarea(numero);
    std::cout << "Tarea eliminada correctamente." << std::endl;

}

void mostrar(ListaTareas& lista) {
    std::cout << "Listado de tareas:" << std::endl;
    lista.mostrarTareas();
}

void modificaciones() {
    std::string input;
    int auxNumero;

    std::cout << "Ingresa el número de la tarea que deseas modificar: ";
    std::cin >> input;

    // Verificar si el input es un número
    if (std::all_of(input.begin(), input.end(), ::isdigit)) {
        auxNumero = std::stoi(input);

        std::ofstream aux("auxiliar.txt", std::ios::out);
        std::ifstream lectura("tareas.txt", std::ios::in);

        if (aux.is_open() && lectura.is_open()) {
            int numero;
            std::string titulo;
            std::string descripcion;
            std::string fechaHora;

            bool encontrado = false;

            while (lectura >> numero >> titulo >> descripcion >> fechaHora) {
                if (auxNumero == numero) {
                    encontrado = true;
                    std::cout << "__________________________" << std::endl;
                    std::cout << "Numero: " << numero << ", Titulo: " << titulo << ", Descripcion: " << descripcion << ", Fecha y Hora: " << fechaHora << std::endl;
                    std::cout << "__________________________" << std::endl;

                    std::string auxTitulo;
                    std::string auxDescripcion;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ingresa el nuevo titulo de la tarea con numero " << numero << ": ";
                    std::getline(std::cin, auxTitulo);

                    std::cout << "Ingresa la nueva descripcion de la tarea con numero " << numero << ": ";
                    std::getline(std::cin, auxDescripcion);

                    // Obtener la fecha y hora actual
                    auto now = std::chrono::system_clock::now();
                    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
                    std::stringstream ss;
                    ss << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %H:%M:%S");
                    fechaHora = ss.str();

                    aux << numero << " " << auxTitulo << " " << auxDescripcion << " " << fechaHora << std::endl;

                    std::cout << "Tarea modificada correctamente." << std::endl;
                } else {
                    aux << numero << " " << titulo << " " << descripcion << " " << fechaHora << std::endl;
                }
            }

            if (!encontrado) {
                std::cout << "No se encontro ninguna tarea con numero " << auxNumero << std::endl;
            }

            aux.close();
            lectura.close();
            std::remove("tareas.txt");
            std::rename("auxiliar.txt", "tareas.txt");
        } else {
            std::cout << "No se pudo abrir el archivo o aun no ha sido creado." << std::endl;
        }
    } else {
        std::cout << "Entrada invalida. Debe ingresar un numero." << std::endl;
    }
}

void menu(ListaTareas& lista) {
    int opcion;
    std::string input;

    do {
        std::cout << "__________________________" << std::endl;
        std::cout << "          MENU" << std::endl;
        std::cout << "__________________________" << std::endl;
        std::cout << "1. Agregar tarea" << std::endl;
        std::cout << "2. Eliminar tarea" << std::endl;
        std::cout << "3. Mostrar tareas" << std::endl;
        std::cout << "4. Modificar tarea" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "__________________________" << std::endl;
        std::cout << "Ingrese la opcion deseada: ";
        std::cin >> input;

        // Verificar si el input es un número
        if (std::all_of(input.begin(), input.end(), ::isdigit)) {
            opcion = std::stoi(input);

            switch (opcion) {
                case 1:
                    altas(lista);
                    break;
                case 2:
                	//mostrar(lista);
                    bajas(lista);
                	break;
                case 3:
                    mostrar(lista);
                    break;
                case 4:
                	mostrar(lista);
                    modificaciones();
                    break;
                case 5:
                    std::cout << "Saliendo..." << std::endl;
                    break;
                default:
                    std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
                    break;
            }
        } else {
            std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
        }
    } while (opcion != 5);
}

int main() {
    ListaTareas lista;
    lista.cargarTareas();
    menu(lista);
    return 0;
}

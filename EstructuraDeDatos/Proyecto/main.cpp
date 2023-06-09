#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <ctime>

struct Nodo {
    int numero;
    std::string titulo;
    std::string descripcion;
    std::string fechaHora;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(int num, const std::string& tit, const std::string& desc, const std::string& fecha)
        : numero(num), titulo(tit), descripcion(desc), fechaHora(fecha), siguiente(nullptr), anterior(nullptr) {}
};

class ListaTareas {
private:
    Nodo* primero;
    Nodo* actual;
    int contador;

public:
    ListaTareas() : primero(nullptr), actual(nullptr), contador(1) {}
void agregarTarea(const std::string& titulo, const std::string& descripcion) {
	
        std::string fechaHora;
		auto now = std::chrono::system_clock::now();
        std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %H:%M:%S");
        fechaHora = ss.str();
        
    Nodo* nuevoNodo = new Nodo(contador, titulo, descripcion, fechaHora);
    if (primero == nullptr) {
        primero = nuevoNodo;
        actual = nuevoNodo;
    } else {
        actual->siguiente = nuevoNodo;
        nuevoNodo->anterior = actual;
        actual = nuevoNodo;
    }
    contador++;
    guardarTareas();  // Guardar tareas en el archivo después de agregar una
}
    void mostrarEnPantallaTarea(const std::string& titulo, const std::string& descripcion) {
		std::string fechaHora;
		auto now = std::chrono::system_clock::now();
        std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %H:%M:%S");
        fechaHora = ss.str();

        Nodo* nuevoNodo = new Nodo(contador, titulo, descripcion, fechaHora);
        if (primero == nullptr) {
            primero = nuevoNodo;
            actual = nuevoNodo;
        } else {
            actual->siguiente = nuevoNodo;
            nuevoNodo->anterior = actual;
            actual = nuevoNodo;
        }
        contador++;
          // Guardar tareas en el archivo después de agregar una
    }

void eliminarTarea(int numero) {
    Nodo* nodo = primero;
    while (nodo != nullptr) {
        if (nodo->numero == numero) {
            Nodo* nodoAEliminar = nodo;
            if (nodo->anterior != nullptr)
                nodo->anterior->siguiente = nodo->siguiente;
            if (nodo->siguiente != nullptr)
                nodo->siguiente->anterior = nodo->anterior;
            if (nodo == primero)
                primero = nodo->siguiente;
            if (nodo == actual)
                actual = nodo->anterior;
            nodo = nodo->siguiente;
            delete nodoAEliminar;
            contador--;
        } else {
            nodo = nodo->siguiente;
        }
    }
    guardarTareas();  // Guardar tareas en el archivo después de eliminar una
}
    
void mostrarTareas() {
    std::ifstream archivo("tareas.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
            
        }
        archivo.close();
    }
}

   void modificarTarea(int numero, const std::string& nuevoTitulo, const std::string& nuevaDescripcion) {
    Nodo* nodo = primero;
    while (nodo != nullptr) {
        if (nodo->numero == numero) {
            nodo->titulo = nuevoTitulo;
            nodo->descripcion = nuevaDescripcion;
            break;  // Salir del bucle una vez que se haya encontrado la tarea
        }
        nodo = nodo->siguiente;
    }
    guardarTareas();  // Guardar tareas en el archivo después de modificar la tarea específica
}


void cargarTareas() {
    std::ifstream archivo("tareas.txt");
    if (archivo.is_open()) {
        if (primero == nullptr) {
            int num;
            std::string tit, desc, fechaHora;
            Nodo* nodoAnterior = nullptr;  // Puntero al nodo anterior

            while (archivo >> num >> tit >> desc >> fechaHora) {
                Nodo* nuevoNodo = new Nodo(num, tit, desc, fechaHora);
                if (primero == nullptr) {
                    primero = nuevoNodo;
                    actual = nuevoNodo;
                } else {
                    actual->siguiente = nuevoNodo;
                    nuevoNodo->anterior = actual;
                    actual = nuevoNodo;
                }
                contador++;

                nodoAnterior = nuevoNodo;  // Actualizar el puntero al nodo anterior
            }

            // Enlazar el primer nodo con el último nodo existente en la lista
            if (nodoAnterior != nullptr) {
                primero->anterior = nodoAnterior;
                nodoAnterior->siguiente = primero;
            }
        }
        archivo.close();
    }
}


    void guardarTareas() {
        std::ofstream archivo("tareas.txt");
        if (archivo.is_open()) {
            Nodo* nodo = primero;
            while (nodo != nullptr) {
                archivo << nodo->numero << " " << nodo->titulo << " " << nodo->descripcion << " " << nodo->fechaHora << std::endl;
                nodo = nodo->siguiente;
            }
            archivo.close();
        }
    }
};

void altas(ListaTareas& lista) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string titulo, descripcion;

    std::cout << "Ingrese el título de la tarea: ";
    std::getline(std::cin, titulo);

    std::cout << "Ingrese la descripción de la tarea: ";
    std::getline(std::cin, descripcion);

    lista.agregarTarea(titulo, descripcion);
    std::cout << "Tarea agregada correctamente." << std::endl;
}

void bajas(ListaTareas& lista) {
    int numero;

    std::cout << "Ingrese el número de la tarea a eliminar: ";
    std::cin >> numero;

    lista.eliminarTarea(numero);
    std::cout << "Tarea eliminada correctamente." << std::endl;
}

void mostrar(ListaTareas& lista) {
    std::cout << "Listado de tareas:" << std::endl;
    lista.mostrarTareas();
}

void modificaciones() {
    std::ofstream aux;
    std::ifstream lectura;
    bool encontrado = false;
    int auxNumero = 0;
    std::string auxTitulo;
    std::string auxDescripcion;
    std::string auxFechaHora;

    aux.open("auxiliar.txt", std::ios::out);
    lectura.open("tareas.txt", std::ios::in);

    if (aux.is_open() && lectura.is_open()) {
        std::cout << "Ingresa el número de la tarea que deseas modificar: ";
        std::cin >> auxNumero;

        int numero;
        std::string titulo;
        std::string descripcion;
        std::string fechaHora;

        while (lectura >> numero >> titulo >> descripcion >> fechaHora) {
            if (auxNumero == numero) {
                encontrado = true;
                std::cout << "__________________________" << std::endl;
                std::cout << "Número: " << numero << ", Título: " << titulo << ", Descripción: " << descripcion << ", Fecha y Hora: " << fechaHora << std::endl;
                std::cout << "__________________________" << std::endl;

                std::cout << "Ingresa el nuevo título de la tarea con número " << numero << ": ";
                std::cin.ignore();
                std::getline(std::cin, auxTitulo);

                std::cout << "Ingresa la nueva descripción de la tarea con número " << numero << ": ";
                std::getline(std::cin, auxDescripcion);

                // Obtener la fecha y hora actual
                auto now = std::chrono::system_clock::now();
                std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
                std::stringstream ss;
                ss << std::put_time(std::localtime(&timestamp), "%Y-%m-%d %H:%M:%S");
                auxFechaHora = ss.str();

                aux << numero << " " << auxTitulo << " " << auxDescripcion << " " << auxFechaHora << std::endl;

                std::cout << "Tarea modificada correctamente." << std::endl;
            } else {
                aux << numero << " " << titulo << " " << descripcion << " " << fechaHora << std::endl;
            }
        }
    } else {
        std::cout << "No se pudo abrir el archivo o aún no ha sido creado." << std::endl;
    }

    if (!encontrado) {
        std::cout << "No se encontró ninguna tarea con número " << auxNumero << std::endl;
    }

    aux.close();
    lectura.close();
    std::remove("tareas.txt");
    std::rename("auxiliar.txt", "tareas.txt");
}

void menu(ListaTareas& lista) {
    int opcion;
    do {
        std::cout << "Agenda de Tareas" << std::endl;
        std::cout << "1. Agregar tarea" << std::endl;
        std::cout << "2. Eliminar tarea" << std::endl;
        std::cout << "3. Mostrar tareas" << std::endl;
        std::cout << "4. Modificar tarea" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "¿Qué deseas hacer? ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                altas(lista);
                break;
            case 2:
                bajas(lista);
                break;
            case 3:
                mostrar(lista);
                break;
            case 4:
                modificaciones();
                break;
            case 5:
                std::cout << "¡Hasta luego!" << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
        }
    } while (opcion != 5);
}

int main() {
    ListaTareas lista;
    lista.cargarTareas();  // Cargar tareas del archivo solo si la lista está vacía

    menu(lista);

    return 0;
}

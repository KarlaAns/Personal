#include "ListaTareas.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <ctime>
#include <iomanip>

ListaTareas::ListaTareas() : primero(nullptr), actual(nullptr), contador(1) {}

void ListaTareas::agregarTarea(const std::string& titulo, const std::string& descripcion) {
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

void ListaTareas::mostrarEnPantallaTarea(const std::string& titulo, const std::string& descripcion) {
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

void ListaTareas::eliminarTarea(int numero) {
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

void ListaTareas::mostrarTareas() {
    std::ifstream archivo("tareas.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        archivo.close();
    }
}

void ListaTareas::modificarTarea(int numero, const std::string& nuevoTitulo, const std::string& nuevaDescripcion) {
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

void ListaTareas::cargarTareas() {
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

void ListaTareas::guardarTareas() {
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

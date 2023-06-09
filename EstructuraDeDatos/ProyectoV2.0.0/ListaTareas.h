#ifndef LISTATAREAS_H
#define LISTATAREAS_H
#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <ctime>
#include <iomanip>

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
    ListaTareas();
    void agregarTarea(const std::string& titulo, const std::string& descripcion);
    void mostrarEnPantallaTarea(const std::string& titulo, const std::string& descripcion);
    void eliminarTarea(int numero);
    void mostrarTareas();
    void modificarTarea(int numero, const std::string& nuevoTitulo, const std::string& nuevaDescripcion);
    void cargarTareas();
    void guardarTareas();
};

#endif  // LISTATAREAS_H

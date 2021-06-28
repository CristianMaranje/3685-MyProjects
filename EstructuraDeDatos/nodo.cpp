#include "nodo.h"

Nodo::Nodo(Persona persona,Tabla tabla) {
    this->persona = persona;
    this->tabla = tabla;
}

Nodo *Nodo::getAnterior() {
    return anterior;
}

void Nodo::setAnterior(Nodo *nodo) {
    this->anterior = nodo;
}

Nodo *Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo *nodo) {
    this->siguiente = nodo;
}

Persona Nodo::getPersona() {
    return persona;
}

void Nodo::setPersona(Persona persona) {
    this->persona = persona;
}

Tabla Nodo::getTabla() {
    return tabla;
}

void Nodo::setTabla(Tabla tabla) {
    this->tabla = tabla;
}

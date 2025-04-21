#include "Tanque.h"

Tanque::Tanque(int id) : idTanque(id), vida(obtenerVidaPorTipo()) {}

int Tanque::obtenerVidaPorTipo() {
    return 100;
}

void Tanque::actualizarVida(int cantidad) {
    vida += cantidad;
    if (vida > 200) vida = 200;
    if (vida < 0) vida = 0;
}

int Tanque::getIdTanque() const {
    return idTanque;
}

int Tanque::getVida() const {
    return vida;
}

void Tanque::setId(int nuevoId) {
    idTanque = nuevoId;
}

void Tanque::setVida(int nuevaVida) {
    vida = nuevaVida;
}
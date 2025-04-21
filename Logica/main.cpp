#include <iostream>
#include "../Dominio/Tanques/TanquePesado.h"
#include "../Dominio/Nodos/NodoSistema.h"
using namespace std;

void recorrerTablero(NodoSistema* head) {
    NodoSistema* temp = head;
    cout << "--- Tablero generado ---" << endl;
    while (temp != nullptr) {
        cout << "Nodo ID: " << temp->getIdNodo()
             << ", Posicion: (" << temp->getPosX() << ", " << temp->getPosY() << ")"
             << ", Tipo de Terreno: " << temp->getTipoTerreno() << endl;
        temp = temp->getSiguiente();
    }
}

// Función que agrega un nodo al final de la lista doblemente enlazada
NodoSistema* agregarPosicion(NodoSistema* head, NodoSistema* nuevoNodo) {
    if (head == nullptr) {
        return nuevoNodo;
    }

    NodoSistema* temp = head;
    while (temp->getSiguiente() != nullptr) {
        temp = temp->getSiguiente();
    }

    temp->setSiguiente(nuevoNodo);
    nuevoNodo->setAnterior(temp);
    return head;
}

// Función que genera el tablero 5x5 con diferentes tipos de terreno
NodoSistema* crearTablero() {
    NodoSistema* listaPosiciones = nullptr;
    int contador = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int tipoTerreno;
            if (i == 0 || i == 4) {
                tipoTerreno = 1;
            } else if (i == 1 || i == 3) {
                tipoTerreno = 2;
            } else {
                tipoTerreno = 3;
            }

            NodoSistema* nuevoNodo = new NodoSistema(contador, i, j, tipoTerreno);
            listaPosiciones = agregarPosicion(listaPosiciones, nuevoNodo);
            contador++;
        }
    }

    return listaPosiciones;
}

void disparar(Tanque* tanque, NodoSistema* tablero, int posX, int posY) {
    // Implementar la lógica de disparo aquí
    cout << "Tanque ID: " << tanque->getIdTanque() << " disparando!" << endl;

    NodoSistema* temp = tablero;
    TanquePesado* tanquePesado = dynamic_cast<TanquePesado*>(tanque);
    if (tanquePesado == nullptr) {
        cout << "Error: El tanque no es de tipo TanquePesado." << endl;
        return;
    }

    while(temp != nullptr) {
        if (temp->getPosX() == posX && temp->getPosY() == posY) {
            Tanque* tanqueEnPosicion = temp->getTanque();
            if (tanqueEnPosicion != nullptr) {
                tanqueEnPosicion->actualizarVida(tanquePesado->getDaño());
                cout << "Tanque ID: " << tanqueEnPosicion->getIdTanque() << " ha sido alcanzado!" << endl;
                cout << "Vida restante: " << tanqueEnPosicion->getVida() << endl;
            } else {
                cout << "¡Fallaste! No hay tanque en la posición (" << posX << ", " << posY << ")." << endl;
            }
            break;
        }
        temp = temp->getSiguiente();
    }
}

int main() {
    // Crear el tablero y recorrerlo
    NodoSistema* tableroPosiciones = crearTablero();
    
    // Crear tanque pesado (con puntero)
    Tanque* tanque1 = new TanquePesado(1);
    Tanque* tanque2 = new TanquePesado(2);
    Tanque* tanque3 = new TanquePesado(3);
    Tanque* tanque4 = new TanquePesado(4);

    // Asignar tanques a ciertas posiciones del tablero
    NodoSistema* temp = tableroPosiciones;
    while (temp != nullptr) {
        int id = temp->getIdNodo();
    
        if (temp->getTanque() == nullptr) {
            if (id == 24) {
                temp->setTanque(tanque1);
            } else if (id == 0) {
                temp->setTanque(tanque2);
            } else if (id == 18) {
                temp->setTanque(tanque3);
            } else if (id == 13) {
                temp->setTanque(tanque4);
            }
        }
    
        temp = temp->getSiguiente();
    }
    
    // Disparar al tanque en la posición (0, 0)
    disparar(tanque1, tableroPosiciones, 0, 0); // Dispara al tanque en la posición (0, 0)
    return 0;
}

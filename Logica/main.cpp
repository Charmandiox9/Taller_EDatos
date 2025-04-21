#include <iostream>
#include "../Dominio/TanquePesado.h"
using namespace std;

int main(){
    TanquePesado tanque(1);

    cout << "ID del tanque: " << tanque.getIdTanque() << endl;
    cout << "Vida del tanque: " << tanque.getVida() << endl;
    cout << "Danio del tanque: " << tanque.getDaño() << endl;
    cout << "Movimiento base del tanque: " << tanque.getMovimientoBase() << endl;

    tanque.actualizarVida(50);

}
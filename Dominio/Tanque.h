#ifndef TANQUE_H
#define TANQUE_H

class Tanque {
protected:
    int idTanque;
    int vida;

public:
    Tanque(int id);
    virtual int obtenerVidaPorTipo();
    void actualizarVida(int cantidad);

    int getIdTanque() const;
    int getVida() const;

    void setId(int nuevoId);
    void setVida(int nuevaVida);

    virtual ~Tanque() = default;
};

#endif
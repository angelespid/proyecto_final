#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

class Personaje : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Personaje();
    void moverIzquierda();
    void moverDerecha();
    void saltar();
    void perderVida();
    int obtenerVidas() const;

private slots:
    void actualizarSalto();

private:
    int vidas;
    QTimer* saltoTimer;
    int alturaActual;  // Para controlar el progreso del salto
    bool estaSaltando;
};

#endif // PERSONAJE_H

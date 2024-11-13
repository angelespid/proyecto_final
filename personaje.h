#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class Personaje : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit Personaje(QObject *parent = nullptr);
    void moverIzquierda();
    void moverDerecha();
    void saltar();
    void perderVida();
    int obtenerVidas() const;

private:
    int vidas;
    QPixmap hojaSprites;
    int fotogramaActual;
    QTimer *saltoTimer;
    int alturaActual;
    bool estaSaltando;

    void actualizarSprite();
    void actualizarSalto();
};

#endif // PERSONAJE_H

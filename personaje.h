#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

class Personaje : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit Personaje(QObject *parent = nullptr);

    void moverPersonaje(QKeyEvent *event);  // Método para mover el personaje según la tecla
    void saltar();

private:
    int fotogramaActual;
    bool estaSaltando;
    QPixmap hojaSprites;
    QTimer *saltoTimer;

    void actualizarSprite();
};

#endif // PERSONAJE_H

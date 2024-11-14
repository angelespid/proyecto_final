#include "personaje.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Personaje::Personaje(QObject *parent)
    : QObject(parent), QGraphicsPixmapItem(), fotogramaActual(0), estaSaltando(false) {

    // Cargar el sprite de Goku, asegúrate de que la imagen esté en la ubicación correcta
    if (!hojaSprites.load("SpriteGoku.png")) {
        qDebug() << "Error: No se pudo cargar la imagen del sprite de Goku.";
    } else {
        // Muestra el primer fotograma del sprite
        setPixmap(hojaSprites.copy(0, 0, 32, 32));  // Ajusta el tamaño del fotograma según el sprite
        qDebug() << "Imagen del sprite de Goku cargada correctamente.";
    }
}

void Personaje::moverPersonaje(QKeyEvent *event) {
    int speed_x = 0;
    int speed_y = 0;

    // Detecta las teclas de flecha y ajusta la velocidad en consecuencia
    switch (event->key()) {
    case Qt::Key_Up:
        speed_y = -10;
        break;
    case Qt::Key_Left:
        speed_x = -10;
        break;
    case Qt::Key_Down:
        speed_y = 10;
        break;
    case Qt::Key_Right:
        speed_x = 10;
        break;
    default:
        return;  // Salir si no es una tecla de flecha
    }

    // Calcula la nueva posición del personaje
    QPointF nuevaPosicion = pos() + QPointF(speed_x, speed_y);

    // Limita el movimiento dentro de los límites de la escena
    if (scene() && scene()->sceneRect().contains(nuevaPosicion)) {
        setPos(nuevaPosicion);
    }
}


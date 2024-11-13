#include "personaje.h"
#include <QDebug>
#include <QGraphicsScene>

Personaje::Personaje(QObject *parent)
    : QObject(parent), vidas(3), fotogramaActual(0), estaSaltando(false), alturaActual(0) {

    // Cargar la hoja de sprites desde el archivo
    if (!hojaSprites.load("SpriteGoku.png")) {
        qDebug() << "Error: No se pudo cargar la imagen de sprites";
    } else {
        qDebug() << "Imagen de sprites cargada exitosamente.";
    }

    // Establecer el primer fotograma
    setPixmap(hojaSprites.copy(0, 0, 32, 32));  // Suponiendo que cada fotograma es de 32x32 px

    // Configurar el temporizador de salto
    saltoTimer = new QTimer(this);
    connect(saltoTimer, &QTimer::timeout, this, &Personaje::actualizarSalto);
}

void Personaje::moverIzquierda() {
    // Asegura que el personaje no se salga del límite izquierdo
    if (scene() && x() - 5 >= scene()->sceneRect().left()) {
        setX(x() - 5);  // Mover hacia la izquierda
        fotogramaActual = (fotogramaActual + 1) % 3;
        actualizarSprite();
    } else {
        qDebug() << "Límite izquierdo alcanzado";
    }
}

void Personaje::moverDerecha() {
    // Asegura que el personaje no se salga del límite derecho
    if (scene() && x() + 5 + pixmap().width() <= scene()->sceneRect().right()) {
        setX(x() + 5);  // Mover hacia la derecha
        fotogramaActual = (fotogramaActual + 1) % 3;
        actualizarSprite();
    } else {
        qDebug() << "Límite derecho alcanzado";
    }
}

void Personaje::actualizarSprite() {
    int xPos = fotogramaActual * 32;
    setPixmap(hojaSprites.copy(xPos, 0, 32, 32));
}

void Personaje::saltar() {
    if (!estaSaltando) {
        estaSaltando = true;
        alturaActual = 0;
        saltoTimer->start(30);
        qDebug() << "Personaje ha iniciado un salto.";
    }
}

void Personaje::actualizarSalto() {
    const int alturaMaxima = 100;
    const int velocidadSalto = 5;

    if (alturaActual < alturaMaxima && estaSaltando) {
        // Limita el salto para que no salga de la parte superior de la escena
        if (scene() && y() - velocidadSalto >= scene()->sceneRect().top()) {
            setPos(x(), y() - velocidadSalto);
            alturaActual += velocidadSalto;
        }
    } else if (alturaActual >= 0 && estaSaltando) {
        // Limita la caída para que no salga de la parte inferior de la escena
        if (scene() && y() + velocidadSalto + pixmap().height() <= scene()->sceneRect().bottom()) {
            setPos(x(), y() + velocidadSalto);
            alturaActual -= velocidadSalto;
        }

        // Detener el salto cuando el personaje vuelva al suelo
        if (alturaActual <= 0) {
            saltoTimer->stop();
            estaSaltando = false;
            setPos(x(), scene()->sceneRect().bottom() - pixmap().height());  // Asegura que quede en el suelo
            qDebug() << "Personaje ha terminado el salto. Posición:" << pos();
        }
    }
}

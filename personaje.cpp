#include "personaje.h"
#include <QDebug>

Personaje::Personaje() : vidas(3), estaSaltando(false), alturaActual(0) {
    setRect(0, 0, 50, 100);  // Representación del personaje como un rectángulo (50x100)

    saltoTimer = new QTimer(this);
    connect(saltoTimer, &QTimer::timeout, this, &Personaje::actualizarSalto);
}

void Personaje::moverIzquierda() {
    if (x() > 0) {  // Evita que el personaje salga del borde izquierdo
        setPos(x() - 10, y());
        qDebug() << "Personaje movido a la izquierda. Nueva posición:" << pos();
    }
}

void Personaje::moverDerecha() {
    if (x() < 750) {  // Evita que el personaje salga del borde derecho (asumiendo un ancho de escena de 800)
        setPos(x() + 10, y());
        qDebug() << "Personaje movido a la derecha. Nueva posición:" << pos();
    }
}

void Personaje::saltar() {
    if (!estaSaltando) {  // Solo permite un salto a la vez
        estaSaltando = true;
        alturaActual = 0;
        saltoTimer->start(30);  // Inicia el temporizador para la animación del salto
        qDebug() << "Personaje ha iniciado un salto.";
    }
}

void Personaje::actualizarSalto() {
    const int alturaMaxima = 100;  // Altura máxima del salto en píxeles
    const int velocidadSalto = 5;  // Incremento por cada actualización

    if (alturaActual < alturaMaxima && estaSaltando) {
        // Subir
        setPos(x(), y() - velocidadSalto);
        alturaActual += velocidadSalto;
    } else if (alturaActual >= 0 && estaSaltando) {
        // Bajar
        setPos(x(), y() + velocidadSalto);
        alturaActual -= velocidadSalto;

        // Cuando el personaje vuelve al suelo, detener el salto
        if (alturaActual <= 0) {
            saltoTimer->stop();
            estaSaltando = false;
            setPos(x(), y());  // Asegura que quede en el suelo
            qDebug() << "Personaje ha terminado el salto. Nueva posición:" << pos();
        }
    }
}

void Personaje::perderVida() {
    if (vidas > 0) {
        vidas--;
        qDebug() << "Vida perdida. Vidas restantes:" << vidas;
    } else {
        qDebug() << "El personaje no tiene vidas restantes.";
    }
}

int Personaje::obtenerVidas() const {
    return vidas;
}


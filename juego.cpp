#include "juego.h"
#include <QDebug>


Juego::Juego(int vidasIniciales, double tiempoInicial)
    : vidas(vidasIniciales), tiempo_restante(tiempoInicial), mundo(1) {
    // Inicializa el temporizador
    temporizador = new QTimer(this);
    connect(temporizador, &QTimer::timeout, this, &Juego::actualizarTiempo);
}

void Juego::iniciarJuego() {
    // Inicia el temporizador con intervalos de 1 segundo
    temporizador->start(1000);
    qDebug() << "Juego iniciado. Mundo:" << mundo << "Vidas:" << vidas << "Tiempo restante:" << tiempo_restante;
}

void Juego::perderVida() {
    if (--vidas <= 0) {
        qDebug() << "Has perdido todas las vidas. Reiniciando nivel.";
        reiniciarNivel();
    } else {
        qDebug() << "Vida perdida. Vidas restantes:" << vidas;
    }
}

void Juego::reiniciarNivel() {
    // Reinicia las vidas y el tiempo
    vidas = 3;               // Restaura el número de vidas (puede ser configurable)
    tiempo_restante = 60;    // Restaura el tiempo inicial del nivel
    temporizador->start(1000);
    qDebug() << "Nivel reiniciado. Vidas:" << vidas << "Tiempo restante:" << tiempo_restante;
}

void Juego::actualizarTiempo() {
    if (--tiempo_restante <= 0) {
        qDebug() << "Tiempo agotado. Reiniciando nivel.";
        reiniciarNivel();
    } else {
        qDebug() << "Tiempo restante:" << tiempo_restante;
    }
}

void Juego::ganarJuego() {
    temporizador->stop();
    qDebug() << "¡Nivel completado! Has ganado.";
    // Aquí podría avanzar al siguiente nivel o finalizar el juego
}

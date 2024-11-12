// juego.h
#ifndef JUEGO_H
#define JUEGO_H

#include <QObject>
#include <QTimer>

class Juego : public QObject {
    Q_OBJECT

private:
    int mundo;                // Representa el mundo actual
    int vidas;                // Número de vidas del jugador
    double tiempo_restante;   // Tiempo restante en el nivel
    QTimer *temporizador;     // Temporizador para controlar el tiempo en el nivel

public:
    Juego(int vidasIniciales, double tiempoInicial);
    void iniciarJuego();     // Método para iniciar el juego
    void perderVida();       // Método para restar una vida al jugador
    void reiniciarNivel();   // Método para reiniciar el nivel en caso de perder todas las vidas
    void ganarJuego();       // Método para indicar que se ha completado el nivel

public slots:
    void actualizarTiempo(); // Slot que se activa con el temporizador para reducir el tiempo restante
};

#endif

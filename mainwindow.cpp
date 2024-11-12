#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personaje.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QPainter>
#include <QBrush>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , personaje(new Personaje())
{
    ui->setupUi(this);

    // Crear la escena y configurar el color de fondo amarillo
    QGraphicsScene* escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 800, 600);             // Tamaño de la escena
    escena->setBackgroundBrush(QBrush(Qt::yellow));    // Fondo amarillo

    // Agregar el personaje a la escena
    escena->addItem(personaje);
    personaje->setPos(400, 500);                      // Posición inicial del personaje

    // Configurar la vista para que muestre la escena
    ui->graphicsView->setScene(escena);
    ui->graphicsView->setFixedSize(800, 600);         // Tamaño de la vista
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Configurar el título de la ventana
    this->setWindowTitle("Mundo 1");

    // Crear y configurar la etiqueta de vidas
    vidasLabel = new QLabel(this);
    vidasLabel->setGeometry(10, 10, 100, 30);         // Posición y tamaño de la etiqueta
    vidasLabel->setStyleSheet("font-size: 16px; color: red;");  // Estilo de la etiqueta
    actualizarVidas();                                // Mostrar las vidas iniciales
}

// Destructor
MainWindow::~MainWindow() {
    delete personaje;
    delete ui;
}

// Actualizar la etiqueta de vidas
void MainWindow::actualizarVidas() {
    int vidas = personaje->obtenerVidas();
    vidasLabel->setText("Vidas: " + QString::number(vidas));
}

// Evento de teclado para mover el personaje
void MainWindow::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    qDebug() << "Tecla presionada (valor entero):" << key;

    if (!personaje) return;

    switch (key) {
    case Qt::Key_Left:
        qDebug() << "Mover izquierda";
        personaje->moverIzquierda();
        break;
    case Qt::Key_Right:
        qDebug() << "Mover derecha";
        personaje->moverDerecha();
        break;
    case Qt::Key_Up:
        qDebug() << "Saltar";
        personaje->saltar();
        break;
    case Qt::Key_Space:
        qDebug() << "Perder vida";
        personaje->perderVida();     // Restar una vida al personaje
        actualizarVidas();           // Actualizar la visualización de vidas
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

// Evento para mostrar la ventana y establecer el foco
void MainWindow::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    this->setFocus();  // Establecer el foco en la ventana al mostrarla
}





#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personaje.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , personaje(new Personaje())  // Inicializar el personaje aquí
{
    ui->setupUi(this);

    // Crear la escena y establecer sus dimensiones
    QGraphicsScene* escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 800, 600);  // Tamaño de la escena

    // Agregar el personaje a la escena
    escena->addItem(personaje);
    personaje->setPos(400, 500);  // Posición inicial del personaje

    // Configurar la vista para que muestre la escena
    ui->graphicsView->setScene(escena);
    ui->graphicsView->setFixedSize(800, 600);  // Tamaño de la vista
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

// Destructor
MainWindow::~MainWindow() {
    delete personaje;  // Liberar el recurso del personaje
    delete ui;
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
    default:
        QMainWindow::keyPressEvent(event);
    }
}
void MainWindow::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    this->setFocus();  // Establecer el foco en la ventana al mostrarla
}




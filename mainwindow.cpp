#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), personaje(new Personaje()) {
    ui->setupUi(this);

    // Crear la escena y configurar sus dimensiones
    QGraphicsScene* escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 1080, 720);

    // Cargar la imagen de fondo
    QGraphicsPixmapItem* fondo = new QGraphicsPixmapItem(QPixmap("fondo.png"));
    if (fondo->pixmap().isNull()) {
        qDebug() << "Error: No se pudo cargar fondo.png";
    }
    fondo->setPos(0, 0);  // Posición inicial en la esquina superior izquierda
    escena->addItem(fondo);  // Agregar el fondo a la escena

    // Agregar el personaje a la escena y establecer su posición inicial sobre el fondo
    escena->addItem(personaje);
    personaje->setPos(400, 500);

    // Configurar la vista para que muestre la escena
    ui->graphicsView->setScene(escena);
    ui->graphicsView->setFixedSize(1080, 720);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

// Destructor
MainWindow::~MainWindow() {
    delete personaje;
    delete ui;
}

// Captura el evento de teclado para mover el personaje
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (personaje) {
        personaje->moverPersonaje(event);
    } else {
        QMainWindow::keyPressEvent(event);
    }
}

// Evento para enfocar la ventana al mostrarla
void MainWindow::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    this->setFocus();  // Asegura que el foco esté en la ventana al mostrarla
}

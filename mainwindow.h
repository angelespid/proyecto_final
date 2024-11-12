#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personaje.h"  // Incluir la cabecera de Personaje
#include <QKeyEvent>    // Incluir QKeyEvent para keyPressEvent
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;  // Declaración de keyPressEvent
     void showEvent(QShowEvent *event) override;



     private:
              Ui::MainWindow *ui;
     Personaje *personaje;
     QLabel *vidasLabel;  // Etiqueta para mostrar las vidas

     void actualizarVidas();  // Función para actualizar la etiqueta de vidas
};

#endif // MAINWINDOW_H

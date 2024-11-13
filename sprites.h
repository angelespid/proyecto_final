/*#ifndef SPRITES_H
#define SPRITES_H

#include <QObject>

class Sprites : public QObject
{
    Q_OBJECT
public:
    explicit Sprites(QObject *parent = nullptr);

signals:
};

#endif // SPRITES_H
*/
#ifndef SPRITES_H
#define SPRITES_H

#include <QObject>
#include <QPixmap>
#include <QVector>

class Sprites : public QObject {
    Q_OBJECT
public:
    explicit Sprites(const QString &filePath, int frameWidth, int frameHeight, QObject *parent = nullptr);

    // Cargar la hoja de sprites
    bool cargarHojaSprites(const QString &filePath);

    // Obtener un fotograma específico (por índice)
    QPixmap obtenerFotograma(int index) const;

    // Obtener la cantidad de fotogramas
    int cantidadFotogramas() const;

private:
    QPixmap hojaSprites;         // Imagen completa de la hoja de sprites
    QVector<QPixmap> fotogramas;  // Almacena los fotogramas individuales

    int frameWidth;              // Ancho de cada fotograma
    int frameHeight;             // Alto de cada fotograma

    void dividirEnFotogramas();  // Método para dividir la hoja en fotogramas
};

#endif // SPRITES_H

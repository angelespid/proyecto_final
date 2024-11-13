/*#include "sprites.h"

Sprites::Sprites(QObject *parent)
    : QObject{parent}
{}
*/

#include "sprites.h"
#include <QDebug>

Sprites::Sprites(const QString &filePath, int frameWidth, int frameHeight, QObject *parent)
    : QObject(parent), frameWidth(frameWidth), frameHeight(frameHeight) {
    cargarHojaSprites(filePath);
}

bool Sprites::cargarHojaSprites(const QString &filePath) {
    if (!hojaSprites.load(filePath)) {
        qDebug() << "Error: No se pudo cargar la imagen de sprites desde" << filePath;
        return false;
    }
    dividirEnFotogramas();
    return true;
}

void Sprites::dividirEnFotogramas() {
    // Divide la hoja de sprites en fotogramas individuales
    int columnas = hojaSprites.width() / frameWidth;
    int filas = hojaSprites.height() / frameHeight;

    for (int y = 0; y < filas; ++y) {
        for (int x = 0; x < columnas; ++x) {
            int posX = x * frameWidth;
            int posY = y * frameHeight;
            QPixmap fotograma = hojaSprites.copy(posX, posY, frameWidth, frameHeight);
            fotogramas.append(fotograma);
        }
    }
}

QPixmap Sprites::obtenerFotograma(int index) const {
    if (index >= 0 && index < fotogramas.size()) {
        return fotogramas[index];
    }
    return QPixmap();  // Retorna un QPixmap vacío si el índice es inválido
}

int Sprites::cantidadFotogramas() const {
    return fotogramas.size();
}


#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QList>
#include <QString>
#include <cstdlib>

#include "file_header.h"

int main()
{
    QFile file("temp.dat");
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Error: Could not open temp.dat for reading:" << file.errorString();
        return EXIT_FAILURE;
    }

    QDataStream in(&file);

    quint32 magic = 0;
    qint32 version = 0;
    in >> magic;
    in >> version;

    if (in.status() != QDataStream::Ok || magic != MAGIC) {
        qCritical() << "Error: Unexpected file format.";
        return EXIT_FAILURE;
    }

    if (version != VERSION) {
        qCritical() << "Error: Unsupported file version.";
        return EXIT_FAILURE;
    }

    in.setVersion(QDataStream::Qt_5_0);

    QList<QString> messages;
    in >> messages;

    if (in.status() != QDataStream::Ok) {
        qCritical() << "Error: Could not read the list from temp.dat.";
        return EXIT_FAILURE;
    }

    qDebug() << "Read" << messages.size() << "strings from temp.dat:";
    for (const QString &message : messages) {
        qDebug() << message;
    }

    return EXIT_SUCCESS;
}

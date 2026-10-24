
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
    if (!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Error: Could not open temp.dat for writing:" << file.errorString();
        return EXIT_FAILURE;
    }

    QDataStream out(&file);

    out << MAGIC;
    out << VERSION;

    out.setVersion(QDataStream::Qt_5_0);

    QList<QString> messages = {
        "Hello, world!",
        "This is a QDataStream test.",
        "The QList of QStrings was saved successfully."
    };

    out << messages;

    if (out.status() != QDataStream::Ok || !file.flush()) {
        qCritical() << "Error: Failed to write the list to temp.dat.";
        return EXIT_FAILURE;
    }

    qDebug() << "Wrote" << messages.size() << "strings to temp.dat:";
    for (const QString &message : messages) {
        qDebug() << message;
    }

    return EXIT_SUCCESS;
}

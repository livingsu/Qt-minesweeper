#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Qt-Minesweeper  Copyright (C) 2021  livingsu\n"
                "This is free software; see the source code for copying conditions. There is ABSOLUTELY NO\n"
                "WARRANTY; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n";

    QTranslator t;
    if (strncmp(MINESWEEPER_LANG, "en", 2) != 0)
    {
        bool loaded = t.load(QStringLiteral(":/lang/lang_") + MINESWEEPER_LANG, MINESWEEPER_SRC);
        qDebug() << MINESWEEPER_LANG << "loaded?" << loaded;
        a.installTranslator(&t);
    }

    MainWindow w;
    w.show();

    return a.exec();
}

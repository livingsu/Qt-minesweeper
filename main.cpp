#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;
    t.load(":/lang_cn.qm", ":/lang_cz.qm");
    a.installTranslator(&t);

    MainWindow w;
    w.show();

    return a.exec();
}

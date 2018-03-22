 //////////////////////////////////////////////////////////////////////////////
 // Praktikum Informatik 1 SS2013
 // Testprogramm_Qt:
 // Versuch00: Vorbereitung auf Praktikum
 //
 // Datei: main.cpp
 // Inhalt: Hauptprogramm
 ////////////////////////////////////////////////////////////////////////////

#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPushButton hello("Schließe mich!");

    hello.resize(400,300);
    QObject::connect(&hello, SIGNAL(clicked()),&app, SLOT(quit()));

    hello.show();


    return app.exec();
}

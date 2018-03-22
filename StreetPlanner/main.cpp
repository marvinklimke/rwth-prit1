/**
  * @file main.cpp
  * @brief This file contains the main entry point for the application StreetPlanner.
  */

#include "mainwindow.h"
#include <QApplication>

/// @mainpage StreetPlanner
/// This project is part of the "Praktikum Informatik 1" of RWTH Aachen University.
///
/// The application is capable of planning a map of small and big cities and smaller and bigger streets.
/// By using an implementation of the algorithm of dijkstra it calculates the shortest paths between two cities on the map.
///


/**
 * @brief This is the main method. It creates an instance of the MainWindow and shows it.
 * @param argc number of console line arguments.
 * @param argv the console line arguments.
 * @return 0 for successful execution.
 */
int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // HiDPI displays

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}

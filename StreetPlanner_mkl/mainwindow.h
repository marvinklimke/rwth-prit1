/**
 * @file mainwindow.h
 * @brief This file contains the declaration of the MainWindow class.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "map.h"
#include "mapio.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief This class represents the Main application window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actAddCity_triggered();

    void on_actAddStreet_triggered();

    void on_actFillMapNrw_triggered();

    void on_actClearMap_triggered();

    void on_actLoadFromDisk_triggered();

    void on_actSaveToDisk_triggered();

    void on_actTestDrawCity_triggered();

    void on_actTestDrawMap_triggered();

    void on_actTestDrawMapStreets_triggered();

    void on_actTestAbstractMap_triggered();

    void on_actTestDijkstra_triggered();

    void on_cmdFindRoute_clicked();

    void on_rbRoutingDistance_clicked();

    void on_rbRoutingTime_clicked();

    void cbRouteCityAddItem(City* city);

    void cbRouteCityClear();

    void cbRouteCityUpdate();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapio;
};

#endif // MAINWINDOW_H

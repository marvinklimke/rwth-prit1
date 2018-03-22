/**
 * @file mainwindow.h
 * @brief This file contains the class declaration of the MainWindow class.
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
    void on_pushButton_clicked();

    void on_testDrawCity_clicked();

    void on_testDrawMap_clicked();

    void on_testDrawMapStreets_clicked();

    void on_testAbstractMap_clicked();

    void on_cbHideTests_clicked();

    void on_cmdAddCity_clicked();

    void on_cmdFillMap_clicked();

    void on_testDijkstra_clicked();

    void on_cmdFindRoute_clicked();

    void on_cmdClearMap_clicked();

    void on_cmdAddStreet_clicked();

    void cbRouteCityAddItem(City* city);

    void cbRouteCityClear();

    void cbRouteCityUpdate();

    void on_cmdMapIoFile_clicked();

    void on_rbRoutingDistance_clicked();

    void on_rbRoutingTime_clicked();

    void on_cmdSaveToDisk_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapio;
};

#endif // MAINWINDOW_H

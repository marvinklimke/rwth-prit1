/**
 * @file dialognewcity.h
 * @brief This file contains the declaration of the DialogNewCity class.
 */

#ifndef DIALOGNEWCITY_H
#define DIALOGNEWCITY_H

#include <QDialog>

#include "bigtown.h"
#include "city.h"
#include "smalltown.h"

namespace Ui {
class DialogNewCity;
}

/**
 * @brief This class represents the dialog to create a new city.
 */
class DialogNewCity : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewCity(QWidget *parent = 0);
    ~DialogNewCity();

    City* getNewCity() const;

private:
    Ui::DialogNewCity *ui;
};

#endif // DIALOGNEWCITY_H

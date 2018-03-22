/**
 * @file dialognewstreet.h
 * @brief This file contains the declaration of the DialogNewStreet class.
 */

#ifndef DIALOGNEWSTREET_H
#define DIALOGNEWSTREET_H

#include <QDialog>

#include "abstractmap.h"
#include "motorway.h"
#include "stateroad.h"

namespace Ui {
class DialogNewStreet;
}

/**
 * @brief This class represents the dialog to create a new street.
 */
class DialogNewStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewStreet(QWidget *parent = 0);
    ~DialogNewStreet();

    void setCities(AbstractMap::CityList cities);
    Street* getNewStreet() const;

private:
    Ui::DialogNewStreet *ui;
    AbstractMap::CityList cities;
};

#endif // DIALOGNEWSTREET_H

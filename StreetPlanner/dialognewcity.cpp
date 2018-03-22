/**
  * @file dialognewcity.cpp
  * @brief This file contains the function definitions for DialogNewCity class.
  */

#include "dialognewcity.h"
#include "ui_dialognewcity.h"

/**
 * @brief Constructor for DialogNewCity class.
 * @param parent
 */
DialogNewCity::DialogNewCity(QWidget *parent)
    : QDialog(parent), ui(new Ui::DialogNewCity)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor for DialogNewCity class.
 * Deletes the ui instance.
 */
DialogNewCity::~DialogNewCity()
{
    delete ui;
}

/**
 * @brief This function provides access to the new City
 * It parses the data entered by the user and creates a new City object.
 * @return pointer on the new City object.
 */
City* DialogNewCity::getNewCity() const
{
    QString name = ui->leCityName->text();
    int coord_x = ui->sbCoordX->value();
    int coord_y = ui->sbCoordY->value();

    if(ui->rbSmallTown->isChecked())
        return new SmallTown(name, coord_x, coord_y);
    else if(ui->rbBigTown->isChecked())
        return new BigTown(name, coord_x, coord_y);
    else
        return NULL;
}

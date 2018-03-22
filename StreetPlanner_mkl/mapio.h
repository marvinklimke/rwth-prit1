/**
 * @file mapio.h
 * @brief This file contains the declaration of the abstract MapIO class.
 */

#ifndef MAPIO_H
#define MAPIO_H

#include "abstractmap.h"
#include "map.h"

/// This class adds Cities and Streeds to a Map.
class MapIo
{
public:
	/// this method adds Cities and Streets to the provided Map.
	virtual void fillMap(AbstractMap &map) = 0;

    /// this method saves the Cities and Streets to files on the disk.
    virtual void saveMap(Map, QString, QString)
    {
        throw; // just for MapIoFileinput
    }
};

#endif // MAPIO_H

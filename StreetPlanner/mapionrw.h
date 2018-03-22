/**
 * @file mapionrw.h
 * @brief This file contains the declaration of the MapIoNrw class.
 */

#ifndef MAPIONRW_H
#define MAPIONRW_H

#include "bigtown.h"
#include "mapio.h"
#include "stateroad.h"

/**
 * @brief This class provides a simple hardcoded Map.
 */
class MapIoNrw : public MapIo
{

public:

    /**
     * @brief Constructor for MapIoNrw class.
     */
	MapIoNrw();

    /**
     * @brief Default destructor.
     */
	~MapIoNrw();

    /**
     * @brief This function fills the map with hardcoded data.
     * @param map The Map to fill.
     */
	virtual void fillMap(AbstractMap &map);

};

#endif // MAPIONRW_H

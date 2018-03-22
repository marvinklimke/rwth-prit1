/**
  * @file mapionrw.cpp
  * @brief This file contains the function definitions of the MapIoNrw class.
  */

#include "mapionrw.h"

MapIoNrw::MapIoNrw()
{
}

MapIoNrw::~MapIoNrw()
{
}

void MapIoNrw::fillMap(AbstractMap &map)
{
    BigTown *aachen      = new BigTown("Aachen",   -100,  100);
    BigTown *bonn        = new BigTown("Bonn",        0,  200);
    BigTown *koeln       = new BigTown("Köln",        0,    0);
    BigTown *duesseldorf = new BigTown("Düsseldorf", 50, -100);

    StateRoad *aachen_koeln = new StateRoad(aachen,      koeln);
    StateRoad *bonn_koeln   = new StateRoad(bonn,        koeln);
    StateRoad *ddorf_koeln  = new StateRoad(duesseldorf, koeln);

	map.addCity(aachen);
	map.addCity(bonn);
	map.addCity(koeln);
	map.addCity(duesseldorf);

	map.addStreet(aachen_koeln);
	map.addStreet(bonn_koeln);
	map.addStreet(ddorf_koeln);
}

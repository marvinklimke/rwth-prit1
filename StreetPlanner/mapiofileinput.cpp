/**
 * @file mapiofileinput.cpp
 * @brief This file contains the function definitions of the MapIoFileinput class.
 */

#include "mapiofileinput.h"

#include <sstream>
#include <fstream>
#include <typeinfo>
#include <QDebug>

#define CITY_EXTENSION
#define STREET_EXTENSION


#ifdef CITY_EXTENSION
	#include "bigtown.h"
    #include "smalltown.h"
#endif
#ifdef STREET_EXTENSION
	#include "motorway.h"
	#include "stateroad.h"
#endif



MapIoFileinput::MapIoFileinput(QString pathToCityFile, QString pathToStreetFile):
	pathToCityFile(pathToCityFile),
	pathToStreetFile(pathToStreetFile)
{

}

MapIoFileinput::~MapIoFileinput()
{

}

void MapIoFileinput::fillMap(AbstractMap &map)
{
	map_init_from_file(map, pathToCityFile, pathToStreetFile);
}

void MapIoFileinput::saveMap(Map &map, QString cities_file, QString streets_file)
{
    save_changes_to_file(cities_file, streets_file, map.getCities(), map.getStreets());
}

void MapIoFileinput::map_init_from_file(AbstractMap &map, QString pathToCityFile, QString pathToStreetFile)
{
	// translate to std::string
	std::string path_to_city_file(pathToCityFile.toStdString());
	std::string path_to_street_file(pathToStreetFile.toStdString());
	// Declare Variables to be used
	std::string line, name, x_position_string, y_position_string, first_city_name, second_city_name;

#ifdef CITY_EXTENSION
	std::string city_typ;
#endif
#ifdef STREET_EXTENSION
	std::string street_typ;
#endif
	int x_position, y_position;
	std::ifstream city_file(path_to_city_file.c_str());
	std::ifstream street_file(path_to_street_file.c_str());

	if (!city_file.is_open()) {
		qDebug() << "Failed to open city file: " << pathToCityFile;
		return;
	}

	if (!street_file.is_open()) {
		qDebug() << "Failed to open street file: " << pathToStreetFile;
		return;
	}

	// Read in City File
	while (getline(city_file, line))
	{
		// Using a String Stream to split the string into the single words.
		std::stringstream line_stream(line);
		line_stream >> name;
		line_stream >> x_position_string;
		line_stream >> y_position_string;

#ifdef CITY_EXTENSION
		line_stream >> city_typ;
#endif

		// Convert the strings into Integers
		x_position = atoi(x_position_string.c_str());
		y_position = atoi(y_position_string.c_str());

		City *city;

#ifdef CITY_EXTENSION
		if (city_typ.compare("BigTown") == 0)
		{
			city = new BigTown(QString::fromStdString(name), x_position, y_position);
		}
		else
		{
			city = new SmallTown(QString::fromStdString(name), x_position, y_position);
		}
#else
		city = new City(QString::fromStdString(name), x_position, y_position);
#endif
		map.addCity(city);
	}

	// Read in Street File
	while (getline(street_file, line))
	{
		// Using a String Stream to split the string into the single words.
		std::stringstream line_stream(line);
		line_stream >> first_city_name;
		line_stream >> second_city_name;
#ifdef STREET_EXTENSION
		line_stream >> street_typ;
#endif

		City *city1 = map.find_city(QString::fromStdString(first_city_name));
		City *city2 = map.find_city(QString::fromStdString(second_city_name));

		if (!city1) {
			qDebug() << "Failed to create Street. First city not found Data: " << QString::fromStdString(line);
		}
		if (!city2) {
			qDebug() << "Failed to create Street. Second city not found Data: " << QString::fromStdString(line);
		}

		Street *street;

#ifdef STREET_EXTENSION
		if (street_typ.compare("Motorway") == 0)
		{
            street = new Motorway(city1, city2);
		}
		else
		{
            street = new StateRoad(city1, city2);
		}
#else
		street = new Street(city1, city2);
#endif

		bool success = map.addStreet(street);
		if (success == false)
		{
			qDebug() << "Failed to create Street. Data: " << QString::fromStdString(line);
		}
	}

	street_file.close();
	city_file.close();

}

void MapIoFileinput::save_changes_to_file(QString pathToCityFile, QString pathToStreetFile,
                          AbstractMap::CityList new_cities, AbstractMap::StreetList new_streets)
{
    // translate to std::string
    std::string path_to_city_file(pathToCityFile.toStdString());
    std::string path_to_street_file(pathToStreetFile.toStdString());

    // File out streams
    std::ofstream city_file, street_file;
    city_file.open(path_to_city_file.c_str());
    street_file.open(path_to_street_file.c_str());

    if (!city_file.is_open()) {
        qDebug() << "Failed to open city file: " << pathToCityFile;
        return;
    }

    if (!street_file.is_open()) {
        qDebug() << "Failed to open street file: " << pathToStreetFile;
        return;
    }

    // Write in City File
    AbstractMap::CityList::const_iterator ic;
    for(ic = new_cities.begin(); ic != new_cities.end(); ic++)
    {
        city_file << (*ic)->getName().toStdString() << " " << (*ic)->getX() << " " << (*ic)->getY();
#ifdef CITY_EXTENSION
        city_file << " " << (typeid(**ic) == typeid(BigTown) ? "BigTown" : "SmallTown");
#endif
        city_file << std::endl;
    }

    // Write in Street File
    AbstractMap::StreetList::const_iterator is;
    for(is = new_streets.begin(); is != new_streets.end(); is++)
    {
        street_file << (*is)->getCity1()->getName().toStdString() << " " << (*is)->getCity2()->getName().toStdString();
#ifdef STREET_EXTENSION
        street_file << " " << (typeid(**is) == typeid(Motorway) ? "Motorway" : "StateRoad");
#endif
        street_file << std::endl;
    }

    street_file.close();
    city_file.close();

}

/**
 * @file mapiofileinput.h
 * @brief This file contains the declaration of the MapIoFileinput class.
 */

#ifndef MAPIOFILEINPUT_H
#define MAPIOFILEINPUT_H

#include "mapio.h"

/**
 * @brief This class implements the abstract MapIo class for use with files on the disk containing data about the cities and streets.
 */
class MapIoFileinput : public MapIo
{

public:

    /**
     * @brief Constructor for MapIoFileinput class.
     * @param pathToCityFile Path of the file containing the cities information.
     * @param pathToStreetFile Path of the file containing the streets information.
     */
    MapIoFileinput(QString pathToCityFile, QString pathToStreetFile);

    /**
     * @brief Default destructor.
     */
	~MapIoFileinput();

    /**
     * @brief This function fills the map with the cities and streets from the files.
     * It implements the abstract MapIo function.
     * @param map Map to fill in the cities and streets.
     */
	virtual void fillMap(AbstractMap &map);

    /**
     * @brief This function saves the cities and streets from the map to the given files.
     * @param map Map to read out cities and streets.
     * @param cities_file File to store the cities in.
     * @param streets_file File to store the streets in.
     */
    virtual void saveMap(Map &map, QString cities_file, QString streets_file);

	/**
	 * @brief A static helper function to initialize the Map from two files.
	 * @param map Map to add the streets and citys to.
     * @param pathToCityFile Path of the file that contains the informations about the citys.
     * @param pathToStreetFile Path of the file that contains the informations about the streets.
	 */
    static void map_init_from_file(AbstractMap &map, QString pathToCityFile, QString pathToStreetFile);

    /**
     * @brief A static helper function to save the cities and streets from a map to the disk.
     * @param pathToCityFile Path of the file to store the cities.
     * @param pathToStreetFile Path of the file to store the streets.
     * @param new_cities Citylist to read the cities from.
     * @param new_streets Streetlist to read the streets from.
     */
    static void save_changes_to_file(QString pathToCityFile, QString pathToStreetFile,
                                     AbstractMap::CityList new_cities, AbstractMap::StreetList new_streets);
private:

    /**
     * @brief Path of the file containing the cities information.
     */
	QString pathToCityFile;

    /**
     * @brief Path of the file containing the streets information.
     */
	QString pathToStreetFile;

};

#endif // MAPIOFILEINPUT_H

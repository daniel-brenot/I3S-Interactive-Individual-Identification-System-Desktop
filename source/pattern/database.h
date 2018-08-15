#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "metadata.h"

//The types of elements
#define YESNO 0
#define NUMBER 1
#define SMALLMEDIUMLARGE 2
#define CUSTOM 3

enum LoadResult{success, failure, needsUpgrade};

class Photo{
    std::string imageFile;
    std::string fingerprintFile;
};

class Individual{
    std::vector<Photo> photos;
};

//Stores the metadata and idividuals of a database
class Database
{
public:
    Database();
    //Loads the database from a provided folder path
    static Database loadDatabase(std::string, LoadResult&);
    //Creates a new database at the given location
    bool newDatabase (std::string);
    //Loads a database in the older xml format
    bool upgradeOldDatabase(std::string);
    //Saves the database to the file
    void saveDatabase();
    //Reloads the databases contents
    bool reload();
    //Renames the database
    void rename(std::string newName);

    //All the individuals stored in the database
    std::vector<Individual> individuals;
    //The file location of the database
    std::string databaseFolder;

    Metadata metadata;
};

#endif // DATABASE_H

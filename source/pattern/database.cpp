#include "database.h"
#include "tinyxml2/tinyxml2.h"
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "QDir"

using namespace tinyxml2;

//Reads a file into a string object(thanks stackoverflow)
inline std::string readStringFromFile (const std::string& path) {
  std::ostringstream buf; std::ifstream input (path.c_str()); buf << input.rdbuf(); return buf.str();
}

//Simply checks if a file exists(thanks stackoverflow)
inline bool file_exists (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

//checks if folder is empty
inline bool isEmpty(std::string path){
    if(QDir(path.c_str()).entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries).count() == 0)
        return true;
    return false;
}

Database::Database()
{}

//Loads an existing database by checking if it is an old version and if it is, checking if the user wants to upgrade
Database Database::loadDatabase(std::string folder, LoadResult & result){
    //Appends a trailing slash to the directory if its needed
    if(folder[folder.length()-1]!='/'){folder+='/';}
    //Detects the old database settings if they exist so the old databases can be upgraded
    if(file_exists(folder+"metadata.xml")){result=needsUpgrade;return Database();}
    //If there is no metadata for the database, then it basically isnt a database
    if(!file_exists(folder+"metadata.json")){result=failure;return Database();};
    //Code to load the database settings into the object
    std::string fileContents = readStringFromFile(folder+"metadata.json");
    result=success;
    Database db=JSON::consumer<Database>::convert(fileContents);
    //Just incase the database has been moved since the last time it was opened(which happens often)
    db.databaseFolder=folder;
    return db;
}

//Loads a database in the older xml format
bool Database::upgradeOldDatabase(std::string folder){
    std::string metadata = folder+"metadata.xml";

    XMLDocument doc;
    doc.LoadFile(metadata.c_str());
    XMLElement *species = doc.FirstChildElement("species");
    this->metadata.databaseName=species->Attribute("type");
}

//Saves the database settings to its folder in json format
void Database::saveDatabase(){
    std::string toSave = JSON::producer<Database>::convert(*this);
    std::ofstream myfile;
    myfile.open (databaseFolder+"metadata.json");
    myfile << toSave;
    myfile.close();
}

//Creates a new database in a given folder
bool Database::newDatabase(std::string folder){
    //Check if folder contains any files
    if(!isEmpty(folder))return false;
    //if not, save the database

}

//Reloads the databases contents
bool Database::reload(){
    return true;
}
//Renames the database
void Database::rename(std::string newName){
    this->metadata.databaseName=newName;
    return saveDatabase();
}

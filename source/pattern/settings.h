#ifndef SETTINGS_H
#define SETTINGS_H

#include "stdlib.h"
#include <string>
#include "QSettings"

/*Defines the usable values for each setting*/
//If results should be logged to a file
enum LoggingResultsSettings {loggingOn, loggingOff};
//Whether the folder the observation is in should be shown or the image itself
enum ResultsTypeSettings {fileResults, folderResults};
//Whether all the matching images should be shown or just the most likely one
enum MatchTypeSettings {allMatches, bestMatching};
//How many results should be shown
enum NumResultsSettings {fiftyResults, allResults};
//If expert mode should be enabled
enum ExpertModeSettings {expertOn, expertOff};
//Policy on updates
enum UpdatePolicySettings {autoUpdate, askUpdate, neverUpdate};

//Stores the values for a color
class Color{
public:
    Color(unsigned char,unsigned char,unsigned char);
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

/*
 * Stores the settings for the application and can save the settings when changed
*/
class Settings{
public:
    Settings(QSettings*);
    void loadSettings();
    void saveSettings();
    QSettings * settings;
    LoggingResultsSettings loggingResults;
    ResultsTypeSettings resultsType;
    MatchTypeSettings matchType;
    NumResultsSettings numResults;
    int batchResults;
    ExpertModeSettings expertMode;
    UpdatePolicySettings updatePolicy;
    Color referenceColor;
    Color regionColor;
    Color circleColor;
    Color centerColor;
    int numThreads;
    //The file location of the database that was open on last launch
    std::string lastDB;
    //All databases known to this version of the appication
    QStringList dbList;
};

#endif // SETTINGS_H

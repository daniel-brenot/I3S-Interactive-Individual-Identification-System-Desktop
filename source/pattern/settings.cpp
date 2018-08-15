#include "settings.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue) : red(red), green(green), blue(blue) {}

Settings::Settings(QSettings * settings) :
    settings(settings),
    loggingResults(loggingOff),
    resultsType(fileResults),
    matchType(allMatches),
    numResults(fiftyResults),
    batchResults(20),
    expertMode(expertOff),
    updatePolicy(askUpdate),
    referenceColor(0,0,255),
    regionColor(0,255,0),
    circleColor(255,0,0),
    centerColor(255,0,0),
    numThreads(2)
{
    loadSettings();
    saveSettings();
}

void Settings::loadSettings(){
    //Results settings
    if(settings->contains("loggingResults"))
        loggingResults = (LoggingResultsSettings)(settings->value("loggingResults").toInt());
    if(settings->contains("resultsType"))
        resultsType = (ResultsTypeSettings)(settings->value("resultsType").toInt());
    if(settings->contains("matchType"))
        matchType = (MatchTypeSettings)(settings->value("matchType").toInt());
    if(settings->contains("numResults"))
        numResults = (NumResultsSettings)(settings->value("numResults").toInt());
    if(settings->contains("batchResults"))
        batchResults = (settings->value("batchResults").toInt());
    if(settings->contains("expertMode"))
        expertMode = (ExpertModeSettings)(settings->value("expertMode").toInt());
    if(settings->contains("updatePolicy"))
        updatePolicy = (UpdatePolicySettings)(settings->value("updatePolicy").toInt());
    if(settings->contains("referenceColorRed"))
        referenceColor = Color(settings->value("referenceColorRed").toUInt(),settings->value("referenceColorGreen").toUInt(),settings->value("referenceColorBlue").toUInt());
    if(settings->contains("regionColorRed"))
        regionColor = Color(settings->value("regionColorRed").toUInt(),settings->value("regionColorGreen").toUInt(),settings->value("regionColorBlue").toUInt());
    if(settings->contains("circleColorRed"))
        circleColor = Color(settings->value("circleColorRed").toUInt(),settings->value("circleColorGreen").toUInt(),settings->value("circleColorBlue").toUInt());
    if(settings->contains("centerColorRed"))
        centerColor = Color(settings->value("centerColorRed").toUInt(),settings->value("centerColorGreen").toUInt(),settings->value("centerColorBlue").toUInt());
    if(settings->contains("numThreads"))
        numThreads = settings->value("numThreads").toInt();
    if(settings->contains("lastDB"))
        lastDB = settings->value("lastDB").toString().toStdString();
    if(settings->contains("dbList"))
        dbList = settings->value("dbList").toStringList();
}

//Sets the values in the settings on disk to the ones set in the program
void Settings::saveSettings(){
    settings->setValue("loggingResults",loggingResults);
    settings->setValue("resultsType",resultsType);
    settings->setValue("matchType",matchType);
    settings->setValue("numResults",numResults);
    settings->setValue("batchResults",batchResults);
    settings->setValue("expertMode",expertMode);
    settings->setValue("updatePolicy",updatePolicy);
    settings->setValue("referenceColorRed",referenceColor.red);
    settings->setValue("referenceColorGreen",referenceColor.green);
    settings->setValue("referenceColorBlue",referenceColor.blue);
    settings->setValue("regionColorRed",regionColor.red);
    settings->setValue("regionColorGreen",regionColor.green);
    settings->setValue("regionColorBlue",regionColor.blue);
    settings->setValue("circleColorRed",circleColor.red);
    settings->setValue("circleColorGreen",circleColor.green);
    settings->setValue("circleColorBlue",circleColor.blue);
    settings->setValue("centerColorRed",centerColor.red);
    settings->setValue("centerColorGreen",centerColor.green);
    settings->setValue("centerColorBlue",centerColor.blue);
    settings->setValue("numThreads",numThreads);
    settings->setValue("lastDB",lastDB.c_str());
    settings->setValue("dbList",dbList);
}

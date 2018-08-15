#include "metadata.h"

Metadata::Metadata():
    databaseName("Short description of database contents"),
    reference1("Reference point 1"),
    reference2("Reference point 2"),
    reference3("Reference point 3"),
    keyPoints(35),
    warpDistance(500),
    relKeyPointDistance(0.05f),
    redWeight(0.299f),
    greenWeight(0.587f),
    blueWeight(0.114f),
    maxDistance(0.01f),
    minDistance(1.5f),
    minRatioArea(0.5f)
{

}

void Element::serialize(JSON::Adapter& adapter){
    JSON::Class root(adapter,"Element");
    JSON_E(adapter,name);
    JSON_E(adapter,type);
    JSON_T(adapter,values);
}

void Metadata::serialize(JSON::Adapter& adapter){
    // this pattern is required
    JSON::Class root(adapter,"Metadata");
    JSON_E(adapter,reference1);
    JSON_E(adapter,reference2);
    JSON_E(adapter,reference3);
    JSON_E(adapter,keyPoints);
    JSON_E(adapter,warpDistance);
    JSON_E(adapter,relKeyPointDistance);
    JSON_E(adapter,redWeight);
    JSON_E(adapter,greenWeight);
    JSON_E(adapter,blueWeight);
    JSON_E(adapter,maxDistance);
    JSON_E(adapter,minDistance);
    JSON_E(adapter,minRatioArea);
    JSON_T(adapter,metadataElements);
}

std::string Metadata::toJson(){
    std::string jsonString;



    return jsonString;
}

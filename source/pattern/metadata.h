#ifndef METADATA_H
#define METADATA_H

#include <stdlib.h>
#include <string>
#include "vector"
#include "esj/json_writer.h"
#include "esj/json_reader.h"


//Stores a single metadata element
class Element{
public:
    //The name of the element
    std::string name;
    //The type of the element
    unsigned char type;
    //The array of values that the element can represent
    std::vector<std::string> values;
    //The function allowing the class to serialize to json
    void serialize(JSON::Adapter& adapter);
};

class Metadata
{
public:
    Metadata();
    bool loadFromJson(std::string jsonString);
    bool loadFromXML(std::string xmlString);
    std::string toJson();
    std::string databaseName;

    //The function allowing the class to serialize to json
    void serialize(JSON::Adapter& adapter);

    //Description of the first reference point
    std::string reference1;
    //Description of the second reference point
    std::string reference2;
    //Description of the third reference point
    std::string reference3;
    //The number of points that are to be found in the recognition area
    int keyPoints;
    //The amount each image should be normalized to ensuring that distance dosnt affect the matching
    float warpDistance;
    //The minimum distance% between key points before weaker points are discarded
    float relKeyPointDistance;
    //The weight to put on the red channel for the final comparison image
    float redWeight;
    //The weight to put on the green channel fot the final comparison image
    float greenWeight;
    //The weight to put on the blue channel for the final comparison image
    float blueWeight;
    //The maximum distance squared between the key point in the source image and the key points in the matching images
    float maxDistance;
    //The minimum distance squared between the key point in the source image and the key points in the matching images
    float minDistance;
    //The amount the key points can scale from the source in order to match key points of other images
    float minRatioArea;
    //The metadata elements an image can be categorized by
    std::vector<Element> metadataElements;
};

#endif // METADATA_H

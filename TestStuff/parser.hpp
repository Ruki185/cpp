#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "point.hpp"

// Parser that can read Points from streams.
// The StreamT can be any iostream such as fstream or stringstream.
template <typename StreamT>
class Parser {
public:

     /* Extracts the points from the given stream and puts them into the container.*/
     void parse(StreamT& stream, PointContainer& container) {
       Parser<std::stringstream> parser;
       std::string ln;


       while (std::getline(stream, ln)) {
         std::stringstream strstream(ln);
         parser.parsePoint(strstream, container);
       }

     }
     /* Parses a single point and puts it into the container.*/
     void parsePoint(StreamT& stream, PointContainer& container) {
       int px,py;
       std::string start, end;

       stream >> start >> px >> py >> end;
       container.push_back(Point(px, py));
     }
private:

};

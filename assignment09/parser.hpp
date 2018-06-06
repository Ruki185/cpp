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

      /* Extracts the points from the given stream and puts them into the container.
       * todo: implement
       */
     void parse(StreamT& stream, PointContainer& container) {
       Parser<std::stringstream> parser;
       std::string ln;


       while (std::getline(stream, ln)) {
         std:stringstream strstream(ln);
         parser.parsePoint(strstream, container);
       }

     }
      /* Parses a single point and puts it into the container.
       * todo: implement
       * hint: You can use formated stream in operators (">>").
       *       Syntax errors do not need to be handled.
       */
     void parsePoint(StreamT& stream, PointContainer& container) {
       int px,py;
       std::string anfang, ende;

       stream >> anfang >> px >> py >> ende;
       container.push_back(Point(px, py));
     }
private:

};

#pragma once
#include <vector>

struct Point {
    int x,y;

    Point (int _x, int _y) {
      x = _x;
      y = _y;
    }
};

using PointContainer = std::vector<Point>;

#include <iostream>
#include <algorithm>
#include <vector>
#include "renderer.hpp"

Renderer::Renderer(int rows, int colums)
  : m_rows(rows), m_colums(colums) {

}

//own comp / unique functions because the std ones didn't work properly
//(std in like "build in by sort / erase")
bool _comp(Point x, Point y) {
  if (x.y < y.y) {
    return true;
  } else if (x.y == y.y) {
    if (x.x < y.x) {
      return true;
    }
  }
  return false;
}

bool _unique(Point x, Point y) {
  if (x.x == y.x && x.y == y.y) {
    return true;
  }
  return false;
}

//remove duplicates, mostly given trough the task
//vector implemented in a previous assignment
void sortCont(PointContainer& points) {
  std::sort(points.begin(), points.end()/*, _comp*/);
  points.erase(std::unique(points.begin(), points.end()/*, _unique*/), points.end());
}

void Renderer::draw(PointContainer& points) {
  sortCont(points);
  int index = 0;
  for(int pos_y = 0; pos_y < m_rows; pos_y++) {
    for(int pos_x = 0; pos_x < m_colums; pos_x++) {
      if(points[index].x == pos_x && points[index].y == pos_y) {
        std::cout << "#";
        index++;
      }
      else
        std::cout << " ";
    }
    std::cout << "\n";
  }
}

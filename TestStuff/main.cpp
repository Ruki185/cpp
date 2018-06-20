#include <fstream>
#include <sstream>
#include "parser.hpp"
#include "renderer.hpp"

using namespace std;

/* todo: * implement missing definitions
 *       * open the file data.txt
 *       * read all points using the Parser
 *       * draw the points with the Renderer
 */

int main() {
  ifstream data("data.txt");
  Parser<ifstream> parser;
  PointContainer points;
  Renderer renderer(30, 120);

  parser.parse(data, points);
  renderer.draw(points);

  return 0;
}

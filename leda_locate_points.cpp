#include <iostream>
#include <map>

using namespace std;

/*
http://www.algorithmic-solutions.info/leda_manual/namespaces_interaction_with.html
http://www.algorithmic-solutions.info/leda_manual/integer.html
http://www.algorithmic-solutions.info/leda_manual/point.html
http://www.algorithmic-solutions.info/leda_manual/bgraph.html
http://www.algorithmic-solutions.info/leda_manual/subdivision.html
*/

#include <LEDA/numbers/integer.h>
#include <LEDA/geo/point.h>
#include <LEDA/graph/graph.h>
#include <LEDA/geo/subdivision.h>

using leda::integer;
using leda::point;
using leda::GRAPH;
using leda::node;
using leda::subdivision;

char tab = '\t';

int main(int argc, char** argv) {
  if(argc < 3) {
	cout << "Usage:" << endl
		 << tab << argv[0] << " segments_file points_file " << endl
		 << tab << "Where segments_file is a file containing the segments" << endl
		 << tab << "and points_file is a file containing the query points" << endl;
	return 1;
  }
  map<string,node> node_map;
  GRAPH<point,integer> g;
  // iterate through segments file
  ifstream seg_file(argv[1]);
  while(!seg_file.eof()) {
	integer x, y;
	seg_file >> x >> y;
	// add new node to g
	// save node to node_map
	// retrieve nodes from node_map, add edge
  }
  // create subdivision
  subdivision<integer> s(g);
  // iterate through points file
  // query the location of each point
  return 0;
}

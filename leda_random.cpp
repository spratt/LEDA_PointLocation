#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/*
http://www.algorithmic-solutions.info/leda_manual/namespaces_interaction_with.html
http://www.algorithmic-solutions.info/leda_guide/basic_data_types/list.html
http://www.algorithmic-solutions.info/leda_manual/integer.html
http://www.algorithmic-solutions.info/leda_manual/rational.html
http://www.algorithmic-solutions.info/leda_manual/rat_point.html
http://www.algorithmic-solutions.info/leda_manual/point_generators.html
*/

#include <LEDA/core/list.h>
#include <LEDA/numbers/rational.h>
#include <LEDA/geo/rat_point.h>
#include <LEDA/geo/random_rat_point.h>

using leda::list;
using leda::rational;
using leda::rat_point;

char tab = '\t';

int main(int argc, char** argv) {
  if(argc < 3) {
	cout << "Usage:" << endl
		 << tab << argv[0] << " n maxc" << endl
		 << "Which will generate n points with coordinates between [-maxc..maxc]"
		 << endl;
	return 1;
  }
  int n = atoi(argv[1]);
  int maxc = atoi(argv[2]);
  list<rat_point> L;
  random_points_in_square(n,maxc,L);
  rat_point p;
  int i = 1;
  forall(p,L) {
	// Node format: http://www.cs.cmu.edu/~quake/triangle.node.html
	cout << i++ << " " << p.xcoord().numerator() << " " << p.ycoord().numerator()
		 << endl;
  }
  return 0;
}

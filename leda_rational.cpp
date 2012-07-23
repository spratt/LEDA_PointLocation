#include <iostream>

using std::cout;
using std::endl;

/*
http://www.algorithmic-solutions.info/leda_manual/namespaces_interaction_with.html
http://www.algorithmic-solutions.info/leda_manual/integer.html
http://www.algorithmic-solutions.info/leda_manual/rational.html
http://www.algorithmic-solutions.info/leda_manual/rat_point.html
*/

#include <LEDA/numbers/rational.h>
#include <LEDA/geo/rat_point.h>

using leda::rational;
using leda::rat_point;

int main(int argc, char** argv) {
  rational x(1,5);
  cout << "My first rational is: " << x << endl;
  rational y(1,3);
  cout << "My second rational is: " << y << endl;
  rat_point p(x,y);
  cout << "My rational point is: " << p << endl
	   << "X coordinate: " << p.xcoord() << endl
	   << "Y coordinate: " << p.ycoord() << endl;
  return 0;
}

#include <iostream>

using std::cout;
using std::endl;

#include <LEDA/numbers/rational.h>

using leda::rational;

int main(int argc, char** argv) {
  cout << "Standard library works." << endl;
  rational q(1,3);
  cout << "My rational is: " << q << endl;
  return 0;
}

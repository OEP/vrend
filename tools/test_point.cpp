#include <iostream>
#include "Point.h"
#include "Vector.h"

using namespace std;
using namespace vr;

int main()
{
  Point p;
  Point q(1, 2, 3);
  Vector r(1, 1, 1);
  cout << p << endl;
  cout << q << endl;
  cout << (q-p).magnitude() << endl;
  cout << q + r << endl;
  cout << q.distance(p) << endl;
}

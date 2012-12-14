#include <iostream>
#include "Ray.h"

using namespace std;
using namespace vr;

int main()
{
  Ray s;
  Ray r(Point(0,0,0), Vector(1,0,0));

  cout << r << endl;
  cout << r.origin().X() << endl;
  cout << r.direction().X() << endl;
  cout << r.trace(30) << endl;
  cout << s.trace(30) << endl;
}


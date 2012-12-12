#include <iostream>
#include "Vector.h"

using namespace std;
using namespace vr;

int main()
{
  Vector a;
  Vector b(1, 2, 3);
  Vector c(4, 5, 6);

  cout << "A: " << a << endl;
  cout << "B: " << b << endl;
  cout << "C: " << c << endl;
  cout << "B*C: " << b*c << endl;
  cout << "B+C: " << b+c << endl;
  cout << "B^C: " << (b^c) << endl;
  cout << "B-C: " << b-c << endl;

  cout << "Unit(B): " << b.unit() << endl;
  b.normalize();
  cout << "Normalize(B): " << b << endl;
}

#include <iostream>
#include "VolumeSimulation.h"

using namespace std;
using namespace vr;

int main()
{
  Box b;
  VolumeSimulation v(b, 64, 64, 64);

  cout << v.size() << endl;
}

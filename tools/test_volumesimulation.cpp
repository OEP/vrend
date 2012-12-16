#include <iostream>
#include "VolumeSimulation.h"

using namespace std;
using namespace vr;

int main()
{
  VolumeSimulation v(64, 64, 64);

  cout << v.size() << endl;
}

#include <iostream>
#include "VolumeSimulation.h"
#include "SphereTestSimulationStrategy.h"

using namespace std;
using namespace vr;

int main()
{
  Box b;
  VolumeSimulation v(new SphereTestSimulationStrategy(4.0), b, 64, 64, 64);

  cout << v.size() << endl;
}

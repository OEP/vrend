#include <iostream>

#include "raygen.h"
#include "Box.h"
#include "Image.h"
#include "VolumeSimulation.h"
#include "Scene.h"
#include "SphereTestSimulationStrategy.h"

using namespace std;
using namespace vr;

int main()
{
  stack<CameraRay> rays;
  Camera c;
  Box b(Point(-0.5, -0.5, -1.5), Point(0.5, 0.5, -2.5));
  VolumeSimulation v(new SphereTestSimulationStrategy(25.0), b, 256, 256, 256);
  Image im(1280, 720, 4);
  Scene sc(c);

  sc.addVolumeSimulation(&v);
  sc.render(im, 1, 255);

  im.write("output.exr");
}

#include <iostream>

#include "raygen.h"
#include "Box.h"
#include "Image.h"

using namespace std;
using namespace vr;

int main()
{
  stack<CameraRay> rays;
  Camera c;
  Box b(Point(-0.5, -0.5, -1.5), Point(0.5, 0.5, -2.5));

  int width = 1280, height = 720, spp = 20;
  
  generate_rays(rays, c, width, height, spp);

  Image im(width, height, 3);
  while(rays.size() > 0)
  {
    CameraRay r = rays.top();
    rays.pop();
    const int
      id = r.getRayId(),
      x = id % width,
      y = id / width;

    if(b.intersects(r))
    {
      im.add(x, y, 1.0f);
    }
    else
    {
      im.add(x, y, 0.0f);
    }
  }

  im.write("output.exr");
}

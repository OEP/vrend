#include <iostream>

#include "raygen.h"

using namespace std;
using namespace vr;

int main()
{
  stack<Ray> rays;
  Camera c;

  generate_rays(rays, c, 1920, 1080, 10);

}

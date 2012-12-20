#include <stack>

#include "Camera.h"
#include "CameraRay.h"

namespace vr
{
  extern void generate_rays(std::stack<CameraRay>&, const Camera&, int width, int height, int spp);
}

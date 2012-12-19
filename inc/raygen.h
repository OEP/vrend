#include <stack>

#include "Camera.h"
#include "Ray.h"

namespace vr
{
  extern void generate_rays(std::stack<Ray>&, const Camera&, int width, int height, int spp);
}

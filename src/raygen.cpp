#include <stack>

#include "raygen.h"
#include "Camera.h"
#include "CameraRay.h"

using namespace vr;

void vr::generate_rays(std::stack<CameraRay> &raybundle, const Camera &cam, int width, int height, int spp)
{
  const double
    dx = 1 / (double) width,
    dy = 1 / (double) height;

  for( int j = 0 ; j < height ; j++ )
  {
    const double y = j / (double) (height-1);
    for( int i = 0 ; i < width  ; i++ )
    {
      const double x = i / (double) (width-1);
      for( int k = 0; k < spp; k++)
      {
        const double
          xx = x + drand48() * dx,
          yy = y + drand48() * dy;

        raybundle.push(CameraRay(cam.getRay(xx, yy), j * width + i));
      }
    }
  }
}

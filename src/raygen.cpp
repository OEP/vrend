#include "raygen.h"

using namespace vr;

void generate_rays(std::stack<Ray> &raybundle, const Camera &cam, int width, int height, int spp)
{
  const double
    dhfov = cam.horizontalFOV() / width,
    dvfov = cam.verticalFOV() / height,
    hstart = -cam.horizontalFOV() / 2,
    vstart = -cam.verticalFOV() / 2;

  for( int j = 0 ; j < height ; j++ )
  {
    const double vfov = vstart + j * cam.verticalFOV() / height;
    for( int i = 0 ; i < width  ; i++ )
    {
      const double hfov = hstart + i * cam.horizontalFOV() / width; 
      for( int k = 0; k < spp; k++)
      {
        
      }
    }
  }
}

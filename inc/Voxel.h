#ifndef VOXEL_H_
#define VOXEL_H_

#include "Color.h"

namespace vr
{
  class Voxel
  {
    private:
    protected:
    public:
      Voxel() : color(Color(0,0)) {};

      double dvalue;
      Color color;
  };
}

#endif

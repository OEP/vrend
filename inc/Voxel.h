#ifndef VOXEL_H_
#define VOXEL_H_

#include "Color.h"

namespace vr
{
  class Voxel
  {
    private:
      Voxel();
    protected:
    public:
      virtual const Color toColor() = 0;
  };
}

#endif

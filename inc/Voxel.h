#ifndef VOXEL_H_
#define VOXEL_H_

#include "Color.h"

namespace vr
{
  class Voxel
  {
    private:
    protected:
      Voxel() {};
    public:
      virtual const Color toColor() const = 0;
  };
}

#endif

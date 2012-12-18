#ifndef BASESHADESTRATEGY_H_
#define BASESHADESTRATEGY_H_

#include "Voxel.h"
#include "Color.h"

namespace vr
{
  class BaseShadeStrategy
  {
    private:
    protected:
    public:
      virtual const Color shade(const Voxel&) const;
  };
}

#endif

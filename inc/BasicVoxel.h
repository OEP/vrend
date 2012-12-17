#ifndef BASICVOXEL_H_
#define BASICVOXEL_H_

#include "Voxel.h"
#include "Color.h"

namespace vr
{
  class BasicVoxel : public Voxel
  {
    private:
    protected:
      double m_Value;
    public:
      BasicVoxel(double);

      const Color toColor() const;
  };
}

#endif

#include "BaseShadeStrategy.h"
#include "Voxel.h"
#include "Color.h"

using namespace vr;

const Color BaseShadeStrategy::shade(const Voxel &v) const
{
  return Color(v.value);
}

#include "BasicVoxel.h"
#include "Color.h"

using namespace vr;

BasicVoxel::BasicVoxel(double value)
{
  m_Value = value;
}

const Color BasicVoxel::toColor() const
{
  return Color(m_Value);
}

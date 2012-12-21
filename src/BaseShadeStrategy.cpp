#include <iostream>
#include "BaseShadeStrategy.h"
#include "Voxel.h"
#include "Color.h"

using namespace vr;

const Color BaseShadeStrategy::shade(const Voxel &v) const
{
//  std::cout << "Found color: " << v.value << std::endl;
  const Color c = Color(v.value);
//  std::cout << "Returning: " << c << std::endl;
  return c;
}

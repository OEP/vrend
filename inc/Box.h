#ifndef BOX_H_
#define BOX_H_

#include "Point.h"
#include "Ray.h"

namespace vr
{
  class Box
  {
    private:
      Point m_Bounds[2];
    protected:
    public:
      Box() {}
      Box(const Point&, const Point&);

      bool intersects(const Ray&);
      bool intersects(const Ray&, double&, double&);

  };
}
#endif

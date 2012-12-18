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
      Box();
      Box(const Point&, const Point&);
      Box(const Box&);

      bool intersects(const Ray&) const;
      bool intersects(const Ray&, double&, double&) const;

      double sizeX() const;
      double sizeY() const;
      double sizeZ() const;

      const Point transform(const Point&) const;
  };
}
#endif

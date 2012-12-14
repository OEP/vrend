#ifndef RAY_H_
#define RAY_H_

#include <ostream>

#include "Vector.h"
#include "Point.h"

namespace vr
{
  class Ray
  {
    private:
      Point m_Origin;
      Vector m_Direction;
    protected:
    public:
      Ray() {}
      Ray(const Point &p, const Vector &direction);
      
      const Point& origin() const;
      const Vector& direction() const;
      const Point trace(const double) const;
  };

  std::ostream& operator<<(std::ostream& out, const Ray &r);
}

#endif

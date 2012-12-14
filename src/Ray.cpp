#include "Ray.h"
#include "Vector.h"

using namespace vr;

Ray::Ray(const Ray &other)
{
  m_Origin = Point(other.origin());
  m_Direction = Vector(other.direction());
}

Ray::Ray(const Point &p, const Vector &direction)
{
  m_Origin = Point(p);
  m_Direction = direction.unit();
}

const Point& Ray::origin() const
{
  return m_Origin;
}

const Vector& Ray::direction() const
{
  return m_Direction;
}

ostream& vr::operator<<(ostream& out, const Ray &r)
{
  out << "[" << r.origin() << ", " << r.direction() << "]";
  return out;
}

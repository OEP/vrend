#include "Point.h"

using namespace vr;
using namespace std;

Point::Point()
{
  m_XYZ[0] = m_XYZ[1] = m_XYZ[2] = 0.0;
}

Point::Point(const double x, const double y, const double z)
{
  m_XYZ[0] = x;
  m_XYZ[1] = y;
  m_XYZ[2] = z;
}

double Point::X() const
{
  return m_XYZ[0];
}

double Point::Y() const
{
  return m_XYZ[1];
}

double Point::Z() const
{
  return m_XYZ[2];
}

const double Point::distance(const Point &other) const
{
  return (*this - other).magnitude();
}

const Point Point::operator+(const Vector &other) const
{
  return Point(
    other.X() + X(),
    other.Y() + Y(),
    other.Z() + Z());
}

const Vector Point::operator-(const Point &other) const
{
  return Vector(
    other.X() - X(),
    other.Y() - Y(),
    other.Z() - Z());
}

ostream& vr::operator<<(ostream& out, const Point &p)
{
  out << "(" <<
    p.X() << ", " <<
    p.Y() << ", " <<
    p.Z() << ")";
  return out;
}

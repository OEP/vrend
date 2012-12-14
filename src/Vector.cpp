#include <ostream>
#include <cmath>
#include "Vector.h"

using namespace std;
using namespace vr;

Vector::Vector()
{
  m_XYZ[0] = m_XYZ[1] = m_XYZ[2] = 0.0;
}

Vector::Vector(const double x, const double y, const double z)
{
  m_XYZ[0] = x;
  m_XYZ[1] = y;
  m_XYZ[2] = z;
}

const double Vector::X() const
{
  return m_XYZ[0];
}

const double Vector::Y() const
{
  return m_XYZ[1];
}

const double Vector::Z() const
{
  return m_XYZ[2];
}

const Vector Vector::unit() const
{
  const double mag = magnitude();
  return Vector(X() / mag, Y() / mag, Z() / mag);
}

void Vector::normalize()
{
  const double mag = magnitude();
  m_XYZ[0] /= mag;
  m_XYZ[1] /= mag;
  m_XYZ[2] /= mag;
}

const double Vector::magnitude() const
{
  return std::sqrt(X() * X() + Y() * Y() + Z() * Z());
}

const Vector Vector::operator+ (const Vector &other) const
{
  return Vector(
    X() + other.X(),
    Y() + other.Y(),
    Z() + other.Z());
}

const Vector Vector::operator- (const Vector &other) const
{
  return Vector(
    X() - other.X(),
    Y() - other.Y(),
    Z() - other.Z());
}

const Vector Vector::operator/ (const double amt) const
{
  return Vector(X() / amt, Y() / amt, Z() / amt);
}

const Vector Vector::operator* (const double amt) const
{
  return Vector(X() * amt, Y() * amt, Z() * amt);
}

const double Vector::operator* (const Vector& other) const
{
  return X() * other.X() + Y() * other.Y() + Z() * other.Z();
}

const Vector Vector::operator^ (const Vector& other) const
{
  return Vector(
    Y() * other.Z() - Z() * other.Y(),
    -( X() * other.Z() - Z() * other.X()),
    X() * other.Y() - Y() - other.X());
}

ostream& vr::operator<< (ostream& out, const vr::Vector &v)
{
  out << "<" <<
    v.X() << ", " <<
    v.Y() << ", " <<
    v.Z() << ">";
  return out;
}

const Vector vr::operator*(const double t, const Vector &v)
{
  return Vector(t * v.X(), t * v.Y(), t * v.Z());
}

#include "Vector.h"

using namespace vr;

Vector::Vector()
{
  m_XYZ[0] = m_XYZ[1] = m_XYZ[2] = 0.0;
}

Vector::Vector(double x, double y, double z)
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

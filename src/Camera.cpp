#include <cmath>
#include "Camera.h"
#include "Ray.h"
using namespace vr;

Camera::Camera()
{
  m_Eye = Point(0,0,0);
  m_Up = Vector(0, 1, 0);
  m_Right = Vector(1, 0, 0);
  m_View = m_Up ^ m_Right;
  m_FOV = 60.0 * M_PI / 180.0;
  m_AspectRatio = 1.6;
}

Camera::Camera(const Vector &up, const Vector &right)
{
  m_Eye = Point(0,0,0);
  m_Up = up.unit();
  m_Right = right.unit();
  m_View = m_Up ^ m_Right;
  m_FOV = 60.0 * M_PI / 180.0;
  m_AspectRatio = 1.6;
}

void Camera::look(double eyeX, double eyeY, double eyeZ,
  double sX, double sY, double sZ,
  double upX, double upY, double upZ)
{
  m_Eye = Point(eyeX, eyeY, eyeZ);
  m_Up = Vector(upX, upY, upZ).unit();

  Point subject = Point(sX, sY, sZ);
  m_View = (subject - m_Eye).unit();
  m_Right = m_View ^ m_Up;
}

const Ray Camera::getRay(const double x, const double y) const
{
  const double
    htanfov = tan(horizontalFOV()),
    vtanfov = tan(verticalFOV());
  const double
    xx = (2.0 * x - 1.0) * htanfov,
    yy = (2.0 * y - 1.0) * vtanfov;

  return Ray(eye(), yy * up() + xx * right() + view());
}

double Camera::horizontalFOV() const
{
  return m_FOV;
}

double Camera::verticalFOV() const
{
  return m_FOV / m_AspectRatio;
}

const Point& Camera::eye() const
{
  return m_Eye;
}

const Vector& Camera::view() const
{
  return m_View;
}

const Vector& Camera::up() const
{
  return m_Up;
}

const Vector& Camera::right() const
{
  return m_Right;
}

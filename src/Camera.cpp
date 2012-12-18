#include <cmath>
#include "Camera.h"

using namespace vr;

Camera::Camera()
{
  m_Eye = Point(0,0,0);
  m_AxisUp = Vector(0, 1, 0);
  m_AxisRight = Vector(1, 0, 0);
  m_AxisView = m_AxisUp ^ m_AxisRight;
  m_FOV = 60.0 * M_PI / 180.0;
  m_AspectRatio = 1.6;
}

Camera::Camera(const Vector &up, const Vector &right)
{
  m_Eye = Point(0,0,0);
  m_AxisUp = up.unit();
  m_AxisRight = right.unit();
  m_AxisView = m_AxisUp ^ m_AxisRight;
  m_FOV = 60.0 * M_PI / 180.0;
  m_AspectRatio = 1.6;
}

void Camera::look(double eyeX, double eyeY, double eyeZ,
  double sX, double sY, double sZ,
  double upX, double upY, double upZ)
{
  m_Eye = Point(eyeX, eyeY, eyeZ);
  m_AxisUp = Vector(upX, upY, upZ).unit();

  Point subject = Point(sX, sY, sZ);
  m_AxisView = (subject - m_Eye).unit();
  m_AxisRight = m_AxisView ^ m_AxisUp;
}

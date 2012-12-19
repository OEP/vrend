#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector.h"
#include "Point.h"
#include "Ray.h"

namespace vr
{
  class Camera
  {
    private:
      Point m_Eye;
      Vector m_Up, m_Right, m_View;
      double m_FOV;
      double m_AspectRatio;
    protected:
    public:
      Camera();
      Camera(const Vector&, const Vector&);

      void look(double, double, double,
        double, double, double,
        double, double, double);
      void setAspectRatio(double);
      void setFOV(double);

      double horizontalFOV() const;
      double verticalFOV() const;

      const Point& eye() const;
      const Vector& view() const;
      const Vector& up() const;
      const Vector& right() const;
      const Ray getRay(const double, const double) const;
  };
}

#endif

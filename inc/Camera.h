#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector.h"
#include "Point.h"

namespace vr
{
  class Camera
  {
    private:
      Point m_Eye;
      Vector m_AxisUp, m_AxisRight, m_AxisView;
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
  };
}

#endif

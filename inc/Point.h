#ifndef POINT_H_
#define POINT_H_

#include <iostream>

#include "Vector.h"

namespace vr
{
  class Point
  {
    private:
      double m_XYZ[3];
    protected:
    public:
      Point();
      Point(const double, const double, const double);
    
      double X() const;
      double Y() const;
      double Z() const;

      const double distance(const Point&) const;

      const Point operator+(const Vector&) const;
      const Vector operator-(const Point&) const;
      friend std::ostream& operator<< (std::ostream& output, const Vector& v);
  };

  std::ostream& operator<< (std::ostream& output, const Point& v);
}

#endif

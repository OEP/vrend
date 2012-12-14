#include <limits>

#include "Box.h"
#include "Point.h"
#include "Ray.h"
#include "Vector.h"

using namespace vr;

Box::Box(const Point& min, const Point& max)
{
  m_Bounds[0] = min;
  m_Bounds[1] = max;
}

bool Box::intersects(const Ray& r)
{
  double dump1, dump2;
  return intersects(r, dump1, dump2);
}

bool Box::intersects(const Ray& r, double& t0, double& t1)
{
  double tmin, tmax, tymin, tymax, tzmin, tzmax;

  if(r.direction().X() >= 0)
  {
    tmin = (m_Bounds[0].X() - r.origin().X()) / r.direction().X();
    tmax = (m_Bounds[1].X() - r.origin().X()) / r.direction().X();
  }
  else
  {
    tmax = (m_Bounds[0].X() - r.origin().X()) / r.direction().X();
    tmin = (m_Bounds[1].X() - r.origin().X()) / r.direction().X();
  }


  if(r.direction().Y() >= 0)
  {
    tymin = (m_Bounds[0].Y() - r.origin().Y()) / r.direction().Y();
    tymax = (m_Bounds[1].Y() - r.origin().Y()) / r.direction().Y();
  }
  else
  {
    tymax = (m_Bounds[0].Y() - r.origin().Y()) / r.direction().Y();
    tymin = (m_Bounds[1].Y() - r.origin().Y()) / r.direction().Y();
  }

  if(tmin > tymax || tymin > tmax)
  {
    return false;
  }

  tmin = std::max(tmin, tymin);
  tmax = std::min(tmax, tymax);

  if(r.direction().Z() >= 0)
  {
    tzmin = (m_Bounds[0].Z() - r.origin().Z()) / r.direction().Z();
    tzmax = (m_Bounds[1].Z() - r.origin().Z()) / r.direction().Z();
  }
  else
  {
    tzmax = (m_Bounds[0].Z() - r.origin().Z()) / r.direction().Z();
    tzmin = (m_Bounds[1].Z() - r.origin().Z()) / r.direction().Z();
  }

  if(tmin > tzmax || tzmin > tmax)
  {
    return false;
  }

  tmin = std::max(tmin, tzmin);
  tmax = std::min(tmax, tzmax);

  t0 = std::max(tmin,  0.0);
  t1 = std::min(tmax, std::numeric_limits<double>::max());

  return true;
}

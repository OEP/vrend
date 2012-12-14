#ifndef VECTOR_H_
#define VECTOR_H_

#include <ostream>

using namespace std;

namespace vr
{
  class Vector
  {
    private:
      double m_XYZ[3];

    protected:
    public:
      Vector();
      Vector(const Vector&);
      Vector(const double x, const double y, const double z);

      const double magnitude() const;
      const Vector unit() const;
      void normalize();

      const double X() const;
      const double Y() const;
      const double Z() const;

      const Vector operator- (const Vector& v) const;
      const Vector operator/ (const double)    const;
      const Vector operator+ (const Vector& v) const;
      const double operator* (const Vector& v) const;
      const Vector operator* (const double)    const;
      const Vector operator^ (const Vector& v) const;

      friend ostream& operator<< (ostream& output, const Vector& v);
      friend const Vector operator* (const double, const Vector& v);
  };
  
  ostream& operator<< (ostream& output, const Vector& v);
  const Vector operator*(const double, const Vector& v);
}


#endif

#ifndef VECTOR_H_
#define VECTOR_H_

namespace vr
{
  class Vector
  {
    private:
      double m_XYZ[3];

    protected:
    public:
      Vector();
      Vector(const double x, const double y, const double z);

      const double magnitude() const;
      const Vector normalize() const;

      const double X() const;
      const double Y() const;
      const double Z() const;

      const Vector operator- (const Vector& v) const;
      const Vector operator/ (const Vector& v) const;
      const Vector operator+ (const Vector& v) const;
      const double operator* (const Vector& v) const;
      const Vector operator* (const double)    const;
      const Vector operator^ (const Vector& v) const;

  };
}

#endif

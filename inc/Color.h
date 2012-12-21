#ifndef COLOR_H_
#define COLOR_H_

#include <ostream>

namespace vr
{
  class Color
  {
    private:
      float m_RGBA[3];
    protected:
    public:
      Color();
      Color(float);
      Color(float, float);
      Color(float, float, float);
      Color(float, float, float, float);
      Color(const Color&);

      float red() const;
      float green() const;
      float blue() const;
      float alpha() const;

      const Color operator+(const Color&) const;
      const Color operator-(const Color&) const;
      const Color operator*(const double) const;
      const Color operator|(const Color&) const;
      const Color& operator=(const Color&);

      friend const Color operator*(const double, const Color &);
  };

  const Color operator*(const double, const Color &);
  std::ostream& operator<<(std::ostream&, const Color&);
}

#endif

#ifndef COLOR_H_
#define COLOR_H_

namespace vr
{
  class Color
  {
    private:
      float m_RGBA[3];
    protected:
    public:
      Color(float);
      Color(float, float, float);
      Color(float, float, float, float);

      float red() const;
      float green() const;
      float blue() const;
      float alpha() const;
  };
}

#endif

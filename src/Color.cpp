#include "Color.h"

using namespace std;
using namespace vr;

Color::Color(float grey)
{
  m_RGBA[0] = m_RGBA[1] = m_RGBA[2] = grey;
  m_RGBA[3] = 1.0f;
}

Color::Color(float r, float g, float b)
{
  m_RGBA[0] = r;
  m_RGBA[1] = g;
  m_RGBA[2] = b;
  m_RGBA[3] = 1.0f;
}

Color::Color(float r, float g, float b, float a)
{
  m_RGBA[0] = r;
  m_RGBA[1] = g;
  m_RGBA[2] = b;
  m_RGBA[3] = a;
}

float Color::red() const
{
  return m_RGBA[0];
}

float Color::green() const
{
  return m_RGBA[1];
}

float Color::blue() const
{
  return m_RGBA[2];
}

float Color::alpha() const
{
  return m_RGBA[3];
}

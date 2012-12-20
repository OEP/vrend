#include <assert.h>
#include <OpenImageIO/imageio.h>
OIIO_NAMESPACE_USING

#include "Image.h"

using namespace vr;

Image::Image(int width, int height, int depth)
{
  m_Values = new float[width * height * depth];
  m_Frequency = new int[width * height * depth];
  m_Shape[0] = width;
  m_Shape[1] = height;
  m_Shape[2] = depth;
  initialize();
}

Image::~Image()
{
  delete [] m_Values;
  delete [] m_Frequency;
}

void Image::initialize()
{
  _fill(0.0f, 0);
}

void Image::add(int i, int j, float value)
{
  _set(i, j, value, 1);
}

void Image::add(int i, int j, float *value)
{
  _set(i, j, value, 1);
}

void Image::add(int i, int j, const Color &value)
{
  _set(i, j, value, 1);
}

void Image::set(int i, int j, float value)
{
  _set(i, j, value, -1);
}

void Image::set(int i, int j, float *value)
{
  _set(i, j, value, -1);
}

void Image::set(int i, int j, const Color &value)
{
  _set(i, j, value, -1);
}

void Image::fill(float value)
{
  _fill(value, -1);
}

void Image::fill(const Color &value)
{
  _fill(value, -1);
}

void Image::fill(float *value)
{
  _fill(value, -1);
}

void Image::fillAdd(float value)
{
  _fill(value, 1);
}

void Image::fillAdd(const Color &value)
{
  _fill(value, 1);
}

void Image::fillAdd(float *value)
{
  _fill(value, 1);
}

void Image::_fill(float value, const int mode)
{
  float tmp[depth()];
  for(int i = 0; i < depth(); i++)
  {
    tmp[i] = value;
  }
  _fill(tmp, mode);
}

void Image::_fill(const Color &value, const int mode)
{
  assert(depth() == 4);
  float c[] = { value.red(), value.green(), value.blue(), value.alpha() };
  _fill(c, mode);
}

void Image::_fill(const float *value, const int mode)
{
  float *p = m_Values;
  int *c = m_Frequency;
  for(int i = 0; i < size(); i++, p++, c++)
  {
    if(mode > 0)
    {
      *p += mode * value[i % depth()];
      *c += mode;
    }
    else
    {
      *p = value[i % depth()];
      *c = abs(mode);
    }
  }
}

void Image::_set(int i , int j, float value, const int mode)
{
  float tmp[depth()];
  for(int k = 0; k < depth(); k++)
  {
    tmp[k] = value;
  }
  _set(i, j, tmp, mode);
}

void Image::_set(int i, int j, const Color &value, const int mode)
{
  assert(depth() == 4);
  float tmp[] = {value.red(), value.green(), value.blue(), value.alpha()};
  _set(i, j, tmp, mode);
}

void Image::_set(int i, int j, const float *value, const int mode)
{
  float *p = m_Values + (j * width() * depth() + i * depth());
  int *c = m_Frequency + (j * width() * depth()+ i * depth());

  for(int k = 0; k < depth(); k++, p++, c++)
  {
    if(mode > 0)
    {
      *p += mode * value[k];
      *c += mode;
    }
    else
    {
      *p = value[k];
      *c = abs(mode);
    }
  }
}

void Image::_normalize(float *values) const
{
  float *p = m_Values;
  int *c = m_Frequency;
  for(int i = 0; i < size(); i++, p++, c++, values++)
  {
    *values = (*c > 0) ? *p / *c : *p;
  }
}

void Image::write(const char *filename) const
{
  png::image< png::rgba_pixel > im(width(), height());

  float *imgdata = new float[size()];
  _normalize(imgdata);

  ImageOutput *out = ImageOutput::create(filename);

  if(!out)
  {
    delete [] imgdata;
    return;
  }
  
  ImageSpec spec(width(), height(), depth(), TypeDesc::FLOAT);
  out->open(filename, spec);
  out->write_image(TypeDesc::FLOAT, imgdata);
  out->close();

  delete out;
  delete [] imgdata;
}

int Image::size() const
{
  return width() * height() * depth();
}

int Image::width() const
{
  return m_Shape[0];
}

int Image::height() const
{
  return m_Shape[1];
}

int Image::depth() const
{
  return m_Shape[2];
}

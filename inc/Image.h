#ifndef IMAGE_H_
#define IMAGE_H_

#include <png++/png.hpp>

#include "Color.h"

namespace vr
{
  class Image
  {
    private:
      int m_Shape[3];
      int *m_Frequency;
      float *m_Values;
    protected:
      void _normalize(float *values) const;
      void _fill(float value, int mode);
      void _fill(const Color &c, int mode);
      void _fill(const float *value, int mode);
      void _set(int i, int j, float value, int mode);
      void _set(int i, int j, const Color &c, int mode);
      void _set(int i, int j, const float *value, int mode);
    public:
      Image(int width, int height, int depth=4);
      ~Image();

      void initialize();

      void fill(float value);
      void fill(float *value);
      void fill(const Color &value);
      
      void fillAdd(float value);
      void fillAdd(float *value);
      void fillAdd(const Color &value);
      
      void add(int i, int j, float value);
      void add(int i, int j, int c, float value);
      void add(int i, int j, float *value);
      void add(int i, int j, const Color &value);

      void set(int i, int j, float value);
      void set(int i, int j, int c, float value);
      void set(int i, int j, float *value);
      void set(int i, int j, const Color &value);

      void read(int i, int j, float *out) const;
      float read(int i, int j, int c) const;
      const Color readColor(int i, int j) const;

      void write(const char *filename) const;

      int width() const;
      int height() const;
      int depth() const;
      int pixels() const;
      int size() const;
  };
}

#endif

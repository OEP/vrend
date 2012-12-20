#ifndef VOLUMESIMULATION_H_
#define VOLUMESIMULATION_H_

#include "Voxel.h"
#include "Box.h"
#include "Color.h"
#include "BaseShadeStrategy.h"

namespace vr
{
  class VolumeSimulation
  {
    private:
      Box m_Bounds;
      Voxel *m_Grid;
      int m_Shape[3];
      BaseShadeStrategy m_ShadeStrategy;
    protected:
      int index(int,int,int) const;
    public:
      VolumeSimulation(const Box &b, int, int, int);
      ~VolumeSimulation();

      const Color shade(const Ray&, int) const;
      const Color shade(const Point&) const;
      const Color shade(int, int, int) const;
      
      int sizeX() const;
      int sizeY() const;
      int sizeZ() const;
      int size() const;

      double DX() const;
      double DY() const;
      double DZ() const;
  };
}

#endif

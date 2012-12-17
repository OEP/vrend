#ifndef VOLUMESIMULATION_H_
#define VOLUMESIMULATION_H_

#include "Voxel.h"

namespace vr
{
  class VolumeSimulation
  {
    private:
      Voxel **m_Grid;
      int m_Shape[3];
    protected:
    public:
      VolumeSimulation(int, int, int);
      ~VolumeSimulation();
      
      int sizeX();
      int sizeY();
      int sizeZ();
      int size();
  };
}

#endif

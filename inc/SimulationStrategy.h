#ifndef SIMULATIONSTRATEGY_H_
#define SIMULATIONSTRATEGY_H_

#include "Voxel.h"

namespace vr
{
  class SimulationStrategy
  {
    private:
    protected:
    public:
      virtual void initialize(Voxel*, int, int, int) = 0;
      virtual void update(Voxel*, int, int, int, double) = 0;
  };
}

#endif

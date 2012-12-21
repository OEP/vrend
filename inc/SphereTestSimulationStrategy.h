#ifndef SPHERETESTSIMULATIONSTRATEGY_H_
#define SPHERETESTSIMULATIONSTRATEGY_H_

#include "SimulationStrategy.h"

namespace vr
{
  class SphereTestSimulationStrategy : public SimulationStrategy
  {
    private:
      double m_Radius;
    protected:
    public:
      SphereTestSimulationStrategy(double radius);
      virtual void initialize(Voxel*, int, int, int);
      virtual void update(Voxel*, int, int, int, double);
  };
}

#endif

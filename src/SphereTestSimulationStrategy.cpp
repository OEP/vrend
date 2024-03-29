#include <cmath>
#include <iostream>
using namespace std;
#include "SphereTestSimulationStrategy.h"

using namespace vr;

SphereTestSimulationStrategy::SphereTestSimulationStrategy(double r)
  : m_Radius(r)
{
}

void SphereTestSimulationStrategy::initialize(Voxel *grid, int sx, int sy, int sz)
{
  const int
    mx = sx / 2,
    my = sy / 2,
    mz = sz / 2;
  int index = 0;
  for(int k = 0; k < sz; k++)
  {
    const int dz = k - mz;
    for(int j = 0; j < sy; j++)
    {
      const int dy = j - my;
      for(int i = 0; i < sx; i++)
      {
        const int dx = i - mx;
        const double dist = std::sqrt(dx*dx+dy*dy+dz*dz);
        if(dist < m_Radius)
        {
          grid[index].dvalue = 0.7;
          grid[index].color = Color(1.0, 0.7);
        }
        else
        {
          grid[index].dvalue = 0.2;
          grid[index].color = Color(1.0, 0.02);
        }
        index++;
      }
    }
  }
}

void SphereTestSimulationStrategy::update(Voxel *grid, int sx, int sy, int sz, double dt)
{
}

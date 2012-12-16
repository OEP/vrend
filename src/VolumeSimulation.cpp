#include "VolumeSimulation.h"

VolumeSimulation::VolumeSimulation(int x, int y, int z)
{
  m_Shape[0] = x;
  m_Shape[1] = y;
  m_Shape[2] = z;
  m_Grid = new Voxel[x*y*z];
}

VolumeSimulation::~VolumeSimulation()
{
  delete [] m_Grid;
}

int VolumeSimulation::sizeX()
{
  return m_Shape[0];
}

int VolumeSimulation::sizeY()
{
  return m_Shape[1];
}

int VolumeSimulation::sizeZ()
{
  return m_Shape[2];
}

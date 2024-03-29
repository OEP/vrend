#include "VolumeSimulation.h"
#include "Color.h"

using namespace vr;

VolumeSimulation::VolumeSimulation(SimulationStrategy *strategy, const Box &b, int x, int y, int z)
  : m_SimStrategy(strategy)
{
  m_Bounds = b;
  m_Shape[0] = x;
  m_Shape[1] = y;
  m_Shape[2] = z;
  m_Grid = new Voxel[x*y*z];
  m_SimStrategy->initialize(m_Grid, m_Shape[0], m_Shape[1], m_Shape[2]);
}

VolumeSimulation::~VolumeSimulation()
{
  delete [] m_Grid;
}

const Color VolumeSimulation::shade(const Ray &r, int steps) const
{
  double t0, t1;
  if(!m_Bounds.intersects(r, t0, t1))
  {
    return Color(0.0, 0.0);
  }

  Color tmp = shade(r.trace(t1));
  for(int i = steps-1; i >= 0; i--)
  {
    const Color c = shade(r.trace(t0 + i * (t1-t0) / steps));
    tmp = tmp | c;
  }


  return tmp;
}

const Color VolumeSimulation::shade(const Point &p) const
{
  const Point q = m_Bounds.transform(p);
  const double
    gx = q.X() / DX(),
    gy = q.Y() / DY(),
    gz = q.Z() / DZ();
  const int
    ix = (int) gx,
    iy = (int) gy,
    iz = (int) gz;
  const double
    wx = gx - ix,
    wy = gy - iy,
    wz = gz - iz;

  const Color c =
    wx     * wy     * wz     * shade(ix  , iy  , iz  ) +
    wx     * wy     * (1-wz) * shade(ix  , iy  , iz+1) +
    wx     * (1-wy) * wz     * shade(ix  , iy+1, iz  ) +
    wx     * (1-wy) * (1-wz) * shade(ix  , iy+1, iz+1) +
    (1-wx) * wy     * wz     * shade(ix+1, iy  , iz  ) +
    (1-wx) * wy     * (1-wz) * shade(ix+1, iy  , iz+1) +
    (1-wx) * (1-wy) * wz     * shade(ix+1, iy+1, iz  ) +
    (1-wx) * (1-wy) * (1-wz) * shade(ix+1, iy+1, iz+1);

  return c;
}

const Color 
VolumeSimulation::shade(const int i, const int j, const int k) const
{
  if(!_inBounds(i,j,k))
  {
    const Color c = Color(0.0, 0.0);
    return c;
  }

  const Color c = m_ShadeStrategy.shade(m_Grid[index(i,j,k)]);
  return c;
}

bool VolumeSimulation::_inBounds(const int i, const int j, const int k) const
{
  return i >= 0 && j >= 0 && k >= 0 &&
    i < sizeX() && j < sizeY() && k < sizeZ();
}

int VolumeSimulation::index(int i, int j, int k) const
{
  return k * sizeX() * sizeY() + j * sizeX() + i;
}

double VolumeSimulation::DX() const
{
  return m_Bounds.sizeX() / sizeX();
}

double VolumeSimulation::DY() const
{
  return m_Bounds.sizeY() / sizeY();
}

double VolumeSimulation::DZ() const
{
  return m_Bounds.sizeZ() / sizeZ();
}

int VolumeSimulation::size() const
{
  return sizeX() * sizeY() * sizeZ();
}

int VolumeSimulation::sizeX() const
{
  return m_Shape[0];
}

int VolumeSimulation::sizeY() const
{
  return m_Shape[1];
}

int VolumeSimulation::sizeZ() const
{
  return m_Shape[2];
}

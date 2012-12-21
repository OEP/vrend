#include <vector>

#include "Scene.h"
#include "raygen.h"

using namespace vr;
using namespace std;

Scene::Scene(const Camera &cam)
  : m_Camera(cam)
{
}

void Scene::render(Image &im, int rpp, int spv) const
{
  vector<CameraRay> rays;
  generate_rays(rays, m_Camera, im.width(), im.height(), rpp);

  #pragma omp parallel for 
  for(int i = 0; i < rays.size(); i++)
  {
    CameraRay &r = rays[i];
    const int
      id = r.getRayId(),
      x = id % im.width(),
      y = id / im.width();

    Color tmp(0.0);

    list<VolumeSimulation*>::const_iterator it = m_Simulations.begin();
    while(it != m_Simulations.end())
    {
      const VolumeSimulation *v = *it;
      tmp = tmp | v->shade(r, spv);
      it++;
    }

    im.add(x, y, tmp);
  }
}

void Scene::addVolumeSimulation(VolumeSimulation *v)
{
  m_Simulations.push_back(v);
}

#ifndef SCENE_H_
#define SCENE_H_

#include <list>

#include "Camera.h"
#include "VolumeSimulation.h"
#include "Image.h"

namespace vr
{
  class Scene
  {
    private:
      Camera m_Camera;
      
      std::list<VolumeSimulation*> m_Simulations;
    protected:
    public:
      Scene(const Camera&);

      void render(Image&, int, int) const;
      void addVolumeSimulation(VolumeSimulation*);
  };
}

#endif

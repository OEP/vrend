#include <iostream>
#include "Box.h"

using namespace std;
using namespace vr;

int main()
{
  Box a;
  Box b(Point(0,0,0), Point(1,1,1));

  Ray r(Point(0.5, 1.5, 0.5), Vector(0, -1, 0));
  Ray s(Point(1.5, 1.5, 1.5), Vector(0, -1, 0));
  Ray t(Point(0.5, 0.5, 0.5), Vector(0, -1, 0));

  double t0, t1;
  
  if(b.intersects(r, t0, t1))
  {
    cout << "Intersection: " << t0 << ": " << r.trace(t0) << endl;
    cout << "Intersection: " << t1 << ": " << r.trace(t1) << endl;
  }
  else
  {
    cout << "Errant miss." << endl;
  }

  if(b.intersects(s, t0, t1))
  {
    cout << "Errant Intersection: " << t0 << ": " << s.trace(t0) << endl;
    cout << "Errant Intersection: " << t1 << ": " << s.trace(t1) << endl;
  }
  else
  { 
    cout << "Successfully detected a miss." << endl;
  }

  if(b.intersects(t, t0, t1))
  {
    cout << "Intersection: " << t0 << ": " << t.trace(t0) << endl;
    cout << "Intersection: " << t1 << ": " << t.trace(t1) << endl;
  }
  else
  {
    cout << "Errant miss." << endl;
  }
}

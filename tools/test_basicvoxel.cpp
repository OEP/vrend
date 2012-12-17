#include <iostream>

#include "BasicVoxel.h"

using namespace std;
using namespace vr;

int main()
{
  BasicVoxel bv(0.5);

  Color r = bv.toColor();

  cout << r.red() << endl;
}

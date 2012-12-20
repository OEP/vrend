#include <iostream>
#include "Image.h"

using namespace vr;
using namespace std;

int main()
{
  Image c(1920, 1080, 4);

  c.fillAdd(Color(1.0, 0.0, 0.0, 1.0));
  c.fillAdd(Color(1.0, 1.0, 0.0, 1.0));

  c.set(40, 40, 1.0f);

  c.write("test_image.png");
}

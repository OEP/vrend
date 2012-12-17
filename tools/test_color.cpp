#include <iostream>
#include "Color.h"

using namespace vr;
using namespace std;

int main()
{
  Color c(1.0f);

  cout << c.red() << endl;
  cout << c.green() << endl;
  cout << c.blue() << endl;
  cout << c.alpha() << endl;
}

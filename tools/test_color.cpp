#include <iostream>
#include "Color.h"

using namespace vr;
using namespace std;

int main()
{
  Color c(1.0f);
  Color b(0, 0, 0, 0.3);

  cout << c.red() << endl;
  cout << c.green() << endl;
  cout << c.blue() << endl;
  cout << c.alpha() << endl;

  Color a = c | b;

  cout << a.red() << endl;
}

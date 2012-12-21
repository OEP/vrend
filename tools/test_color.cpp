#include <iostream>
#include "Color.h"

using namespace vr;
using namespace std;

int main()
{
  Color a(0,0);
  Color b(1,1);

  Color ab = a | b;
  Color ba = b | a;

  cout << a << " | " << b  << " = " << ab << endl;
  cout << b << " | " << a  << " = " << ba << endl;

}

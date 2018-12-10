
// Notice that double quotes are for headers in the current directory
#include "function.h"

// Notice that brackets are for headers in the search paths given by -I 
#include <math.h>

double function(double x, int n)
{
  double val = 0.0;
  for (int i = 1; i <= n; ++i)
  {
    val += pow(x, i); 
  } 
  return val;
}

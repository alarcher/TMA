
#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main()
{
  int ret = 0;
  double x = M_PI;
  int    N = 8;
  printf("x = %.16e\n", x);
  printf("%-8s\t%s\n", "n", "y");
  for (int n = 0; n < N; ++n)
  {
    double y = function(x, n);
    printf("%-8d\t%.16e\n", n, y);
  }
  return 0;
}

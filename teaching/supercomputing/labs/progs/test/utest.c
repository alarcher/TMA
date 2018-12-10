
#include "function.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int ret = 0;
  double x = 2.0;
  int    n = 2;
  double ye = 2.0 + 2.0*2.0;
  double yc = function(x, n);
  printf("Result ye = %e; yc = %e\n\n", ye, yc);
  double rel_err = 1.0 - yc / ye;
  printf("Relative error rel_err = %.16e\n\n", rel_err);
  if(rel_err > 1.0e-15) ret = 1;
  printf("Unit test %s.\n", (ret == 0 ? "success" : "failure"));
  return 0;
}


#include "function.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    printf("Error: program requires two arguments\n");
    return 1;
  }
  double x = atof(argv[1]);
  int    n = atof(argv[2]);

  printf("Calling function with x = %e and n = %d\n", x, n);
  double y = function(x, n);
  printf("Result y = %e\n\n", y);
  return 0;
}

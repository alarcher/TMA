
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <mpi.h>

#ifndef M_PI
#define M_PI acos(-1.0)
#endif

int main(int argc, char ** argv)
{
  MPI_Init(&argc, &argv);
  //--------------------------------------------------------------------------
  if(argc < 2)
  {
    printf("Invalid number of arguments < 2\n");
    exit(1);
  }
  int const d = atoi(argv[1]);
  if (d < 0 || d > sizeof(int)*8 - 2)
  {
    printf("Invalid power of two '%d'\n", d);
    exit(1);
  }
  // Set number of local intervals as a power of two
  int const n = 1 << d;

  int rank;
  int size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  //int wtime_is_global = 1;
  //MPI_Comm_set_attr(MPI_COMM_WORLD, MPI_WTIME_IS_GLOBAL, &wtime_is_global);
  double const Wstart = MPI_Wtime();
  double const h = 1.0/(double) (n*size);
  int const nsamples = 1000;
  double global_sum;
  double aerror_sum;
  double rerror_sum;
  for (int k = 0; k < nsamples; ++k)
  {

    // Local sum
    double sum = 0.0;
    for (int i = n*rank; i < n*(rank+1); ++i)
    {
      double const x = (i + 0.5)*h;
      sum+= 1.0/(1.0 + (x*x));
    }
    sum*=h;
    sum*=4.0;

    // Reduce
    MPI_Reduce(&sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  }
  double const Wdiff = MPI_Wtime() - Wstart;
  if(rank == 0)
  {
    aerror_sum = fabs(M_PI - global_sum);
    rerror_sum = aerror_sum / M_PI;
    printf("%2d; sum = %.16e; abs error = %.16e; rel error = %.16e; t = %.16e\n", 
           d, global_sum, aerror_sum, rerror_sum, Wdiff);
  }

  //--------------------------------------------------------------------------
  MPI_Finalize();
  return 0;
}
 

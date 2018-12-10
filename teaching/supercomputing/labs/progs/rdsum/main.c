
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
  int const E = atoi(argv[1]);
  if (E < 0 || E > sizeof(int)*8 - 2)
  {
    printf("Invalid power of two '%d'\n", E);
    exit(1);
  }
  // Set number of local intervals as a power of two
  int const N = 1 << E;

  int rank;
  int size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Status status;

  if((size & (size - 1)) != 0)
  {
    printf("Error comm size is not a power of two");
  }

  int const maxD = sizeof(size)*8-2;
  int D = 0;
  if (size > 1)
  {
    for (; D < maxD; ++D)
    {
       if((size << D) == (1 << maxD))
       {
         D = maxD - D;
         break;
       }
    }
  }
  if (D == maxD)
  {
    if(rank == 0)
      printf("Number of processes is not a power of two\n");
    exit(1);
  }
  else
  {
    if(rank == 0)
      printf("Number of processes is 2^%d\n", D);
  }

  double sum = 1.0;
  double gsm;

  double const Wstart0 = MPI_Wtime();
  for (int k = 0; k < 1000; ++k)
  {
    gsm = sum;
    for (int d = 0; d < D; ++d)
    {
      int mask = rank ^ (1 << d); // Flip d-th bit
      //printf("%2d: mask = %d\n", rank, mask);
      if (rank == mask)
      {
        printf("Rank is equal to mask: %d == %d", rank, mask);
        exit(1);
      }
  
      double rcv = 0.0;
      MPI_Sendrecv(&gsm, 1, MPI_DOUBLE, mask, 0,
                   &rcv, 1, MPI_DOUBLE, mask, 0,
                   MPI_COMM_WORLD, &status);
      gsm += rcv;
    } 
  }
  double const Wdiff0 = MPI_Wtime() - Wstart0;
  if(rank == 0)
    printf("sum = %.16e; time = %.16e;\n", gsm, Wdiff0);
  double const Wstart1 = MPI_Wtime();
  for (int k = 0; k < 1000; ++k)
  {
     MPI_Allreduce(&sum, &gsm, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  }
  double const Wdiff1 = MPI_Wtime() - Wstart1;
  if(rank == 0)
    printf("sum = %.16e; time = %.16e;\n", gsm, Wdiff1);

  //--------------------------------------------------------------------------
  MPI_Finalize();
  return 0;
}
 

#include <stdio.h>
#include <stdlib.h>

typedef int v4si __attribute__ ((vector_size (16)));
typedef union {
   int s[4];
   v4si v;
} v4si_u;

#define RUN_ITERATIONS 0xFFFFFFFF

void usage(char **argv)
{
   printf("Usage: %s [1|2]\n1: SIMD mode\n2: SISD mode\n", argv[0]);
   exit(1);
}



int run_test1()
{

   printf("Starting test #1\n");

   int aa[4] = { 1, 2, 3, 4 },
               bb[4] = { 4, 3, 2, 1 };
   v4si_u a, b;
   int i, j;

   for (i = 0; i < 4; ++i) {
      a.s[i] = aa[i];
      b.s[i] = bb[i];
   }

   for (i = 0; i < RUN_ITERATIONS; ++i)
      a.v = a.v * b.v;

   return 0;
}


int run_test2()
{

   printf("Starting test #2\n");

   int aa[4] = { 1, 2, 3, 4 },
               bb[4] = { 4, 3, 2, 1 };
   v4si_u a, b;
   int i, j;

   for (i = 0; i < 4; ++i) {
      a.s[i] = aa[i];
      b.s[i] = bb[i];
   }

   for (i = 0; i < RUN_ITERATIONS; ++i)
      for (j = 0; j < 4; ++j)
         aa[j] = aa[j] * bb[j];

   return 0;
}

int main(int argc, char **argv)
{

   if (argc < 2)
      usage(argv);


   if (argv[1][0] == '1')
      run_test1();
   else if (argv[1][0] == '2')
      run_test2();
   else
      usage(argv);

   return 0;
}


#include <stdio.h>
#include <stdlib.h>
 
typedef int v4si __attribute__ ((vector_size (16)));
typedef union { int s[4]; v4si v; } v4si_u;
 
 
void usage(char **argv){
  printf("Usage: &#37;s [1|2]\n1: SIMD mode\n2: SISD mode\n", argv[0]);
  exit(1);
}
 
int main(int argc, char **argv){
 
  int aa[4] = { 1, 2, 3, 4 },
    bb[4] = { 4, 3, 2, 1 };
  v4si_u a, b;
  int i, j;
 
  if(argc < 2)
    usage(argv);
 
  for(i = 0; i < 4; ++i){
    a.s[i] = aa[i];
    b.s[i] = bb[i];
  }
 
  if(argv[1][0] == '1')
    for(i = 0; i < 0xFFFFFFFF; ++i)
      a.v = a.v * b.v;
  else if(argv[1][0] == '2')
    for(i = 0; i < 0xFFFFFFFF; ++i)
      for(j = 0; j < 4; ++j)
    aa[j] = aa[j] * bb[j];
  else
    usage(argv);
 
  return 0;
}


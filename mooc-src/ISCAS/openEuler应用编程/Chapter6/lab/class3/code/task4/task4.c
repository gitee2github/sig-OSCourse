#include <stdio.h>

#include <stdlib.h>

int cmpfunc(const void * a,
  const void * b) {
  return ( * (int * ) a - * (int * ) b);
}
int main() {
  int * values = NULL;
  int i;
  int total = 0;
  printf("printf the num\n");
  scanf("%d", & total);
  values = (int * ) malloc(total * sizeof(int));
  printf("Before sorting the list is: \n");
  for (i = 0; i < total; i++) {
    scanf("%d", & values[i]);
  }
  qsort(values, total, sizeof(int), cmpfunc);
  printf("After sorting the list is: \n");
  for (i = 0; i < total; i++) {
    printf("%d\n", values[i]);
  }
  free(values);
  return (0);
}

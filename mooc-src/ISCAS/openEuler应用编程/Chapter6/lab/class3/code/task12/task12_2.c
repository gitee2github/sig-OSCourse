#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAXLEN 100

void lcsLength(char * x, char * y, int m, int n, int c[][MAXLEN], int b[][MAXLEN]) {
  int i, j;
  for (i = 0; i <= m; i++)
    c[i][0] = 0;
  for (j = 1; j <= n; j++)
    c[0][j] = 0;

  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (x[i - 1] == y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = 0;
      } else if (c[i][j - 1] > c[i - 1][j]) {
        c[i][j] = c[i][j - 1];
        b[i][j] = -1;
      } else {
        c[i][j] = c[i - 1][j];
        b[i][j] = 1;

      }
    }
  }

}

void printLCS(int b[][MAXLEN], char * x, int i, int j) {
  if (i == 0 || j == 0)
    return;
  if (b[i][j] == 0) {
    printLCS(b, x, i - 1, j - 1);
    printf("%c", x[i - 1]);
  } else if (b[i][j] == 1) {
    printLCS(b, x, i - 1, j);
  } else {
    printLCS(b, x, i, j - 1);
  }

}

int main(int argc, char ** argv) {
  if (argc != 3) {
    printf("usage: lcs string1 string2\n");
    return -1;
  }

  int b[MAXLEN][MAXLEN];
  int c[MAXLEN][MAXLEN];
  int m, n;

  m = strlen(argv[1]);
  n = strlen(argv[2]);
  lcsLength(argv[1], argv[2], m, n, c, b);
  printLCS(b, argv[1], m, n);
  printf("\n");
  return 0;
}

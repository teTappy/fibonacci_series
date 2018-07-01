#include <stdio.h>

#define G_RATIO 1.6180339887498948482

void fib_terms(double *n, double *m, int num);

void print_terms(double a, int num);

int main(void)
{
  double ratio, percent;
  int num;
  double a;
  double b;
  printf("Enter an int(n) to find the n'th term of fib series\n");
  scanf("%i", &num);

  if (num > 50)
  {
    printf("sorry that term is too high\n");
    return 0;
  }

  fib_terms(&a, &b, num);
  print_terms(a, num);

  ratio = a / b;

  if (ratio < G_RATIO)
  {
    percent = G_RATIO - ratio;
  }
  else if (ratio > G_RATIO)
  {
    percent = ratio - G_RATIO;
  }
  else
  {
    percent = 0;
  }

  percent = 100 - ((percent / G_RATIO) * 100);

  printf("The ratio = %.20f and is within %.20f%%\n", ratio, percent);

  return 0;
}

void fib_terms(double *n, double *m, int num)
{
  int a = 0;
  int b = 1;
  int tmp;

  for (int i = 0; i < num; i++)
  {
    tmp = a + b;
    a = b;
    b = tmp;
  }

  *n = b;
  *m = a;
}

void print_terms(double a, int num)
{
  if ((num == 1 || (num % 10) == 1) && num != 11)
  {
    printf("The %ist term of the fibonacci series is: %.01f\n", num, a);
  }
  else if ((num == 2 || (num % 10) == 2) && num != 12)
  {
    printf("The %ind term of the fibonacci series is: %.01f\n", num, a);
  }
  else if ((num == 3 || (num % 10) == 3) && num != 13)
  {
    printf("The %ird term of the fibonacci series is: %.01f\n", num, a);
  }
  else
  {
    printf("The %ith term of the fibonacci series is: %.01f\n", num, a);
  }
}

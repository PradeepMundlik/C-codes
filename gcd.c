//Euclids Algorithm
//Computes gcd of two natural numbers. 
#include <stdio.h>
int max(int a, int b)
{

  if (a > b)
  {
    return a;
  }
  else if (b > a)
  {
    return b;
  }
}
int min(int a, int b)
{
  if (a < b)
  {
    return a;
  }
  else if (b < a)
  {
    return b;
  }
}

int gcd(int a, int b)
{
  int c = min(a, b);
  int d = max(a, b);

  switch (d % c)
  {
  case 0:
    return c;
    break;

  default:
    return gcd(d % c, c);
    break;
  }
}

int main()
{
  int a, b;

  while (scanf("%d %d", &a, &b) != -1)
  {

    printf("%d\n", gcd(a, b));
  }

  return (0);
}

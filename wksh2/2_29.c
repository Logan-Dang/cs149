#include <stdio.h>
#include <math.h>

int main()
{
  double x, y, z;
  scanf("%lf %lf %lf", &x, &y, &z);
  printf("%.2lf %.2lf %.2lf %.2lf\n",
         pow(x, z),
         pow(x, pow(y, 2)),
         fabs(y),
         sqrt(pow(x * y, z)));

  return 0;
}

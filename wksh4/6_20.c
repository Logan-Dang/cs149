#include <stdio.h>

double lapsToMiles(double laps)
{
  return laps / 4;
}

int main(int argc, char const *argv[])
{
  double laps;
  scanf("%lf", &laps);
  printf("Number of miles %0.2f\n", lapsToMiles(laps));
  return 0;
}

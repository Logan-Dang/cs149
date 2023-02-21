#include <stdio.h>

int main()
{
    int current, prev;
    scanf("%d %d", &current, &prev);
    int diff = current - prev;
    double mortgage = current * 0.051 / 12;
    printf("This house is $%d. The change is $%d since last month.\nThe estimated monthly mortage is $%f.\n", current, diff, mortgage);

    return 0;
}

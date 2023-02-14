#include <stdio.h>

int main()
{
    int userNum, x;
    scanf("%d %d", &userNum, &x);
    for (int i = 0; i < 3; i++)
    {
        userNum /= x;
        printf("%d ", userNum);
    }

    return 0;
}

#include <stdio.h>

int a[] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};

int main()
{
    int i, j, l, n, ret = 0, z;
    scanf("%d", &z);
    for(i = 0; i < z; i++)
    {
        ret = 0;
        scanf("%d", &n);
        for(j = 0; j < 12; j++)
        {
            l = n / a[j];
            if(l <= 0)
                break;
            ret += l;
        }
        printf("%d\n", ret);
    }
    return 0;
}
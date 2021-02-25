#include "DECIDE.h"
#include <math.h>
#include <stdio.h>

boolean LIC_0(void)
{
    double diff_x, diff_y, distance;
    int i = 0;

    while (i < NUMPOINTS)
    {
        diff_x = X[i] - X[i + 1];
        diff_y = Y[i] - Y[i + 1];
        distance = sqrt((diff_x * diff_x) + (diff_y * diff_y));

        switch (DOUBLECOMPARE(distance, PARAMETERS.LENGTH1))
        {

        case GT:
            return 1;

        case LT:;

        case EQ:;
        }
        i++;
    }
    return 0;
}
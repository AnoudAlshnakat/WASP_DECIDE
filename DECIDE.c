#include "DECIDE.h"
#include <math.h>
#include <stdio.h>

/************************************************************
LIC_0: 
There exists at least one set of two consecutive data points 
that are a distance greater than the length, LENGTH1, apart.
************************************************************/
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

double length(x1, y1, x2, y2)
{
    double diff_x = x1 - x2;
    double diff_y = y1 - y2;
    double len = sqrt(pow(diff_x, 2) + pow(diff_y, 2));
    return len;
}



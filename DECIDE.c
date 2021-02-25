#include "DECIDE.h"
#include <math.h>
#include <stdio.h>

/************************************************************
LIC_0: 
There exists at least one set of two consecutive data points 
that are a distance greater than the length, LENGTH1, apart.
************************************************************/
boolean LIC_0(double p_len)
{
    double diff_x, diff_y, distance;
    int i = 0;

    while (i < NUMPOINTS)
    {
        diff_x = X[i] - X[i + 1];
        diff_y = Y[i] - Y[i + 1];
        distance = sqrt((diff_x * diff_x) + (diff_y * diff_y));

        switch (DOUBLECOMPARE(distance, p_len))
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




/************************************************************
LIC_1: 
There exists at least one set of three consecutive data points
that cannot all be contained within or on a circle of radius RADIUS1.
************************************************************/

double length(x1, y1, x2, y2)
{
    double diff_x = x1 - x2;
    double diff_y = y1 - y2;
    double len = sqrt(pow(diff_x, 2) + pow(diff_y, 2));
    return len;
}


boolean LIC_1(double p_rad)
{
    int i;
    double len1,len2,len3;          //triengles sides length
    double sp,a ;                   //semi parameter and area of the tringle
    double measured_r ;             //measured radius


    for (i = 0; i < (NUMPOINTS -2); i++)
    {
        //calculate the length which is the distance between all the points, to form a tringle
            
        len1 = length(X[i],Y[i],X[i+1],Y[i+1]); 
        len2 = length(X[i+1],Y[i+1],X[i+2],Y[i+2]);
        len3 = length(X[i+2],Y[i+2],X[i],Y[i]);
    
       //calculaute the semi-perimeter of the tringle
        sp = (len1 + len2 + len3)/2;

        //area of tringle
        a = sqrt(sp*(sp-len1)*(sp-len2)*(sp-len3));

        if (DOUBLECOMPARE(a, 0)==EQ) 
        {
            measured_r= fmax(len1,len2);
            measured_r= fmax(measured_r,len2);
        } 
        else
        {   //circle circumscribing a triangle is r = len1 len2 len3 / (4* tringle area)
            measured_r= len1*len2*len3/(4*a);
        } 
         
        if (DOUBLECOMPARE(measured_r, p_rad) == GT) 
        {
            printf("here 1 measured_r %f \n", measured_r);
             return 1;
        } 



    }
    printf("here 2 measured_r %f \n", measured_r);
    return 0;
}

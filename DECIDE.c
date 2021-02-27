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
        diff_x = P.X[i] - P.X[i + 1];
        diff_y = P.Y[i] - P.Y[i + 1];
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






double length(double x1, double y1, double x2, double y2)
{   
    double diff_x = x1 - x2;
    double diff_y = y1 - y2;
    double len = sqrt(pow(diff_x, 2) + pow(diff_y, 2));
    return len;
}

/************************************************************
LIC_1: 
There exists at least one set of three consecutive data points
that cannot all be contained within or on a circle of radius RADIUS1.
************************************************************/
boolean LIC_1()
{
    int i;
    double len1,len2,len3;          //triengles sides length
    double sp,a ;                   //semi parameter and area of the tringle
    double measured_r ;             //measured radius


    for (i = 0; i < (NUMPOINTS -2); i++)
    {
        //calculate the length which is the distance between all the points, to form a tringle
            
        len1 = length(P.X[i],P.Y[i],P.X[i+1],P.Y[i+1]); 
        len2 = length(P.X[i+1],P.Y[i+1],P.X[i+2],P.Y[i+2]);
        len3 = length(P.X[i+2],P.Y[i+2],P.X[i],P.Y[i]);
    
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
         
        if (DOUBLECOMPARE(measured_r, PARAMETERS.RADIUS1) == GT) 
        {
            printf("here 1 measured_r %f \n", measured_r);
             return 1;
        } 



    }
    printf("here 2 measured_r %f \n", measured_r);
    return 0;
}



double calculate_angle(x1, x2, x3, y1, y2, y3)
{
     double p1_c = sqrt(pow(x2-x1,2)+ pow(y2-y1,2)); // from first point to teh base  
    double p2_c = sqrt(pow(x2-x3,2)+ pow(y2-y3,2)); // from second point to the base
    double p1_2 = sqrt(pow(x3-x1,2)+ pow(y3-y1,2)); // from point 1 to point 2
    return acos((p2_c*p2_c+p1_c*p1_c-p1_2*p1_2)/(2*p2_c*p1_c));
} 




/************************************************************
LIC_2: 
There exists at least one set of three consecutive data points 
which form an angle such that: 
angle < (PI−EPSILON) or angle > (PI+EPSILON)
************************************************************/
boolean LIC_2()
{
    int i;
    double ang;
    for (i = 0; i < (NUMPOINTS - 2); i++)
    {
        ang = calculate_angle(P.X[i], P.X[i + 1], P.X[i + 2], P.Y[i], P.Y[i + 1], P.Y[i + 2]);

        printf("PI - PARAMETERS.EPSILON %f \n", PI - PARAMETERS.EPSILON);

        if (isnan(ang))
        {
            
        }
        else if (((DOUBLECOMPARE(ang, (PI - PARAMETERS.EPSILON)) == LT) || (DOUBLECOMPARE(ang, (PI + PARAMETERS.EPSILON)) == GT)))
        {
            return 1;
        }
    }
    return 0;
}



/************************************************************
LIC_3: 
3. There exists at least one set of three consecutive data points 
that are the vertices of a triangle with area greater than AREA1.
(0 ≤ AREA1)
************************************************************/
boolean LIC_3()
{
    
    int i;
    double len1, len2, len3; //triengles sides length
    double sp, a;            //semi parameter and area of the tringle
    


    if ( 0 > PARAMETERS.AREA1) return 0;
    for (i = 0; i < (NUMPOINTS - 2); i++)
    {

        //calculate the length which is the distance between all the points, to form a tringle
        len1 = length(P.X[i], P.Y[i], P.X[i + 1], P.Y[i + 1]);
        len2 = length(P.X[i + 1], P.Y[i + 1], P.X[i + 2], P.Y[i + 2]);
        len3 = length(P.X[i + 2], P.Y[i + 2], P.X[i], P.Y[i]);

        //calculaute the semi-perimeter of the tringle
        sp = (len1 + len2 + len3) / 2;

        //area of tringle
        a = sqrt(sp * (sp - len1) * (sp - len2) * (sp - len3));

        if (DOUBLECOMPARE(a,  PARAMETERS.AREA1) == GT)
        {
            return 1;
        }
    }
    return 0;
}




which_quad(x,y)
{
        if ((DOUBLECOMPARE(x,0) == GT) || (DOUBLECOMPARE(x,0) == EQ)) 
          {  if (DOUBLECOMPARE(y,0) == GT)
             return 1;
             else
             return 4;
          }
        else
        { if ((DOUBLECOMPARE(y,0) == GT) || (DOUBLECOMPARE(y,0) == EQ))
             return 2;
             else
             return 3;

        }
}

/************************************************************
LIC_4: 
There exists at least one set of Q PTS consecutive data 
points that lie in more than QUADS quadrants.
************************************************************/
boolean LIC_4()
{   int i,j;
    boolean Q[4]= {0,0,0,0};
    printf("qPts %d \n", PARAMETERS.Q_PTS);
     printf("nQuad %d \n", PARAMETERS.QUADS);
    if ((2 > PARAMETERS.Q_PTS || PARAMETERS.Q_PTS > NUMPOINTS) || (PARAMETERS.QUADS>3 ||PARAMETERS.QUADS<1  )) {
            return 0;
        }
        
    for(i=0 ; i <= NUMPOINTS-PARAMETERS.Q_PTS ; i++)
    {   
        for(j=0 ; j < PARAMETERS.Q_PTS ; j++)
        { 
            int index = j+i;
            
            switch (which_quad (P.X[index],P.Y[index]))
          {  case 1:
              Q[0]=1;
              
            case 2:
              Q[1]=1;
              
            case 3:
              Q[2]=1;
              
            case 4:
              Q[3]=1;
              }     
        }
        printf("Q0 %d, Q1 %d, Q2 %d , Q3 %d  \n", Q[0] , Q[1], Q[2], Q[3] );
        if(Q[0]==1 && Q[1]==1 && Q[2]==1 && Q[3]==1){
            return 1;
        }
     
    } 
    return 0;   


}

/************************************************************
LIC_5: 
There exists at least one set of two consecutive data points, 
(X[i],Y[i]) and (X[j],Y[j]), 
such that X[j] - X[i] < 0. (where i = j-1)
************************************************************/
boolean LIC_5()
{
    int i;
    for (i = 0; i < NUMPOINTS - 1; i++)
    {
        if (DOUBLECOMPARE((P.X[i + 1]) - (P.X[i]), 0) == LT)
        {
            return 1;
        }
    }
    return 0;
}

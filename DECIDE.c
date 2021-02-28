#include "DECIDE.h"
#include <math.h>
#include <stdio.h>

/************************************************************
LIC_0: 
There exists at least one set of two consecutive data points 
that are a distance greater than the length, LENGTH1, apart.
************************************************************/
boolean LIC_0()
{
    double diff_x, diff_y, distance;
    int i = 0;

    while (i < NUMPOINTS)
    {
        diff_x = P.X[i] - P.X[i + 1];
        diff_y = P.Y[i] - P.Y[i + 1];
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



double calculate_angle(double x1, double x2, double x3, double y1, double y2, double y3)
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




which_quad(double x,double y)
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



/************************************************************
LIC_6: 
There exists at least one set of N PTS consecutive data points 
such that at least one of the points lies a distance greater 
than DIST from the line joining the first and last of these 
N PTS points. If the first and last points of these N PTS are 
identical, then the calculated distance to compare with DIST 
will be the distance from the coincident point to all other 
points of the N PTS consecutive points.
************************************************************/
boolean LIC_6()
{   
    int i = 0,j;
    int start_p, end_p;
    double dst_coinc;
    double height, area, sp;
    double len1,len2,len3;
    
     if (NUMPOINTS < 3) return 0;
     
     if (((3 > PARAMETERS.N_PTS || PARAMETERS.N_PTS > NUMPOINTS) || (0 > PARAMETERS.DIST))) return 0;


    for (i = 0 ; i <= NUMPOINTS - PARAMETERS.N_PTS ; i++ )
    {
        start_p = i;
        end_p = i+ PARAMETERS.N_PTS -1; 
       
        //if the first point equals to the last point
       if ( ((DOUBLECOMPARE( P.X[start_p], P.X[end_p] )) == EQ) && (DOUBLECOMPARE(P.Y[start_p],P.Y[end_p])==EQ)  )
        {     
           for(j = 1 ; j > PARAMETERS.N_PTS-1 ; j++)
           {   //distance from the coincident point to all other points
               dst_coinc = length(P.X[start_p],P.Y[start_p],P.X[start_p+j],P.Y[start_p+j]);
               //compare with DIST, should return 1 when it is larger.
               if (DOUBLECOMPARE(dst_coinc, PARAMETERS.DIST) == GT)  
               {
                   return 1;
               }
           }
        }
        else
        { 
            for(j = 1 ; j < PARAMETERS.N_PTS-1 ; j++)
            {
                len1 = length(P.X[start_p],P.Y[start_p],P.X[end_p],P.Y[end_p]); //the base of the trangle
                len2 = length(P.X[end_p],P.Y[end_p],P.X[start_p+j],P.Y[start_p+j]);
                len3 = length(P.X[start_p+j],P.Y[start_p+j],P.X[start_p],P.Y[start_p]);
    
                //calculaute the semi-perimeter of the tringle
                sp = (len1 + len2 + len3)/2;

                //area of tringle
                area = sqrt(sp*(sp-len1)*(sp-len2)*(sp-len3));

                //height of tringle, which is the distance beween the ponnt and the base line
                height = (area * 2) / len1;
                if(DOUBLECOMPARE(height, PARAMETERS.DIST) == GT)
                {
                    return 1;
                }

                
            }
            

        }

    }


    return 0;

}


/************************************************************
LIC_7: 
There exists at least one set of two data points separated by 
exactly K PTS consecutive in- tervening points that are a 
distance greater than the length, LENGTH1, apart. 
The condition is not met when NUMPOINTS < 3
************************************************************/
boolean LIC_7( )
{   
    int i;
    double dist;


    if (NUMPOINTS<3) return 0;
    if ((PARAMETERS.K_PTS > (NUMPOINTS -2) ) || PARAMETERS.K_PTS<1) return 0;
    
     
    for (i=0; i < (NUMPOINTS - PARAMETERS.K_PTS -1); i++){
        dist = length(P.X[i], P.Y[i], P.X[i+PARAMETERS.K_PTS +1], P.Y[i+PARAMETERS.K_PTS +1]);
        if (DOUBLECOMPARE(dist, PARAMETERS.LENGTH1) == GT){
            return 1;
        }

    }
    return 0;

}

/************************************************************
LIC_8: 
There exists at least one set of three data points separated 
by exactly A PTS and B PTS consecutive intervening points, 
respectively, that cannot be contained within or on a circle 
of radius RADIUS1.The condition is not met when NUMPOINTS < 5.
************************************************************/
boolean LIC_8(){
    if (NUMPOINTS<5) return 0;
    if (PARAMETERS.A_PTS<1 || PARAMETERS.B_PTS<1) return 0;
    if ((PARAMETERS.A_PTS + PARAMETERS.B_PTS) > (NUMPOINTS -3)) return 0;


    int i;
    double len1,len2,len3;          //triengles sides length
    double sp,a ;                   //semi parameter and area of the tringle
    double measured_r ;             //measured radius


    for (i=0; i < NUMPOINTS - PARAMETERS.A_PTS - PARAMETERS.B_PTS -2 ; i++) 
    {
        //calculate the length which is the distance between all the points, to form a tringle
            
        len1 = length(P.X[i],  P.Y[i],
                     P.X[i + PARAMETERS.A_PTS + 1],   P.Y[i + PARAMETERS.A_PTS + 1]); 

        len2 = length(P.X[i + PARAMETERS.A_PTS + 1],   P.Y[i + PARAMETERS.A_PTS + 1],
                     P.X[i + PARAMETERS.A_PTS + PARAMETERS.B_PTS+2],   P.Y[i + PARAMETERS.A_PTS + PARAMETERS.B_PTS+2]);

        len3 = length(P.X[i + PARAMETERS.A_PTS + PARAMETERS.B_PTS+2],   P.Y[i+ PARAMETERS.A_PTS + PARAMETERS.B_PTS +2],
                      P.X[i],  P.Y[i]);
    
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


/************************************************************
LIC_9: 
There exists at least one set of three data points separated 
by exactly C PTS and D PTS consecutive intervening points, 
respectively, that form an angle such that:
angle < (PI−EPSILON) or angle > (PI+EPSILON)
************************************************************/
boolean LIC_9()
{    
    if(NUMPOINTS < 5)return 0;
    if (PARAMETERS.C_PTS<1 || PARAMETERS.D_PTS<1) return 0;
    if ((PARAMETERS.C_PTS + PARAMETERS.D_PTS) > (NUMPOINTS -3)) return 0;

    int i;
    double ang;
    for (i = 0; i < (NUMPOINTS - PARAMETERS.C_PTS - PARAMETERS.D_PTS - 2); i++)
    {
        ang = calculate_angle(P.X[i], P.X[i + PARAMETERS.C_PTS +1], P.X[i +  PARAMETERS.C_PTS + PARAMETERS.D_PTS + 2], 
                              P.Y[i], P.Y[i + PARAMETERS.C_PTS +1], P.Y[i +  PARAMETERS.C_PTS + PARAMETERS.D_PTS + 2]);

          printf("ang %f \n", ang);
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
LIC_10: 
There exists at least one set of three data points separated 
by exactly E PTS and F PTS con- secutive intervening points, 
respectively, that are the vertices of a triangle with area
 greater than AREA1. 
 The condition is not met when NUMPOINTS < 5.
************************************************************/

boolean LIC_10()
{
    int i;
    double len1, len2, len3; //triengles sides length
    double sp, a;            //semi parameter and area of the tringle
    
    if(NUMPOINTS < 5)return 0;
    if (PARAMETERS.E_PTS<1 || PARAMETERS.F_PTS<1) return 0;
    if ((PARAMETERS.E_PTS + PARAMETERS.F_PTS) > (NUMPOINTS -3)) return 0;

    if ( 0 > PARAMETERS.AREA1) return 0;
    for (i = 0; i < (NUMPOINTS - PARAMETERS.F_PTS- PARAMETERS.E_PTS - 2); i++)
    {

        //calculate the length which is the distance between all the points, to form a tringle
        len1 = length(P.X[i], P.Y[i], 
                      P.X[i + PARAMETERS.E_PTS +1], P.Y[i + PARAMETERS.E_PTS +1]);

        len2 = length(P.X[i + PARAMETERS.E_PTS +1],  P.Y[i + PARAMETERS.E_PTS +1], 
                      P.X[i + PARAMETERS.F_PTS + PARAMETERS.E_PTS + 2],  P.Y[i + PARAMETERS.F_PTS + PARAMETERS.E_PTS + 2]);

        len3 = length(P.X[i + PARAMETERS.F_PTS + PARAMETERS.E_PTS + 2], P.Y[i + PARAMETERS.F_PTS + PARAMETERS.E_PTS + 2], 
                      P.X[i], P.Y[i]);

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






/************************************************************
LIC_11: 
There exists at least one set of two data points, 
(X[i],Y[i]) and (X[j],Y[j]), separated by exactly G PTS 
consecutive intervening points, such that X[j] - X[i] < 0. 
(where i < j ) The condition is not met when NUMPOINTS < 3.
************************************************************/
boolean LIC_11()
{   
     
    if(NUMPOINTS < 3) return 0;
    if (PARAMETERS.G_PTS<1 || PARAMETERS.G_PTS< NUMPOINTS -2) return 0;
   
    int i ,ind1, ind2;
    for(i=0; i< NUMPOINTS - PARAMETERS.G_PTS - 1  ; i++)
    {
          ind1 = i;
          ind2 = NUMPOINTS + 1 + PARAMETERS.G_PTS;

          if ((DOUBLECOMPARE((P.X[ind2] - P.X[ind1]) , 0) == LT))
          {
              return 1;
          }

    }
    return 0;
}



/************************************************************
LIC_12: 
There exists at least one set of two data points, separated 
by exactly K PTS consecutive intervening points, which are 
a distance greater than the length, LENGTH1, apart. 
In addition, there exists at least one set of two data points 
(which can be the same or different from the two data 
points just mentioned), separated by exactly K PTS consecutive 
intervening points, that are a distance less than the length, 
LENGTH2, apart. Both parts must be true for the LIC to be true.
************************************************************/
boolean LIC_12()
{

    if(NUMPOINTS < 3) return 0;
    if(PARAMETERS.LENGTH2 < 0) return 0;
    
    int i;
    boolean cond1 = 0, cond2 = 0;
    double x1,x2,y1,y2, dist;

    for (i=0; i< NUMPOINTS - PARAMETERS.K_PTS -1 ; i++ )
    {
        x1 = P.X[i];
        y1 = P.Y[i];
        x2 = P.X[NUMPOINTS - PARAMETERS.K_PTS +1 ];
        y2 = P.Y[NUMPOINTS - PARAMETERS.K_PTS +1 ];

        dist = length(x1,y1,x2,y2);

         if (DOUBLECOMPARE(dist,PARAMETERS.LENGTH1) == GT)
         {
             cond1 = 1;
         } 
         else if (DOUBLECOMPARE(dist,PARAMETERS.LENGTH2) == LT)  
         {
             cond2 = 1;
         }
         else 
         {
             ;
         }        
    }

    if (cond1 ==1 && cond2 == 1) 
    {return 1;}
     else 
     {return 0;};  

}




/************************************************************
LIC_12: 
There exists at least one set of three data points, separated 
by exactly A_PTS and B_PTS consecutive intervening points, 
respectively, that cannot be contained within or on a circle of 
radius RADIUS1. In addition, there exists at least one set of 
three data points separated by exactly A_PTS and 
B_PTS consecutive intervening points, respectively, that can 
be contained in or on a circle of radius RADIUS2. 
************************************************************/

boolean LIC_13()
{
    if(NUMPOINTS < 5) return 0;
    if(PARAMETERS.RADIUS2 < 0) return 0;

        int i;
    double len1,len2,len3;          //triengles sides length
    double sp,a ;                   //semi parameter and area of the tringle
    double measured_r ;             //measured radius
    boolean cond1 = 0 , cond2 = 0;


    for (i=0; i < NUMPOINTS - PARAMETERS.A_PTS - PARAMETERS.B_PTS -2 ; i++) 
    {
        //calculate the length which is the distance between all the points, to form a tringle
            
        len1 = length(P.X[i],  P.Y[i],
                     P.X[i + PARAMETERS.A_PTS + 1],   P.Y[i + PARAMETERS.A_PTS + 1]); 

        len2 = length(P.X[i + PARAMETERS.A_PTS + 1],   P.Y[i + PARAMETERS.A_PTS + 1],
                     P.X[i + PARAMETERS.A_PTS + PARAMETERS.B_PTS +2],   P.Y[i + PARAMETERS.A_PTS + PARAMETERS.B_PTS +2]);

        len3 = length(P.X[i + PARAMETERS.A_PTS + PARAMETERS.B_PTS +2],   P.Y[i+ PARAMETERS.A_PTS + PARAMETERS.B_PTS +2],
                      P.X[i],  P.Y[i]);
    
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
         
        printf("measured_r %f \n", measured_r);
        printf("RADIUS1 %f \n", PARAMETERS.RADIUS1);

        if (DOUBLECOMPARE(measured_r, PARAMETERS.RADIUS1) == GT) 
        {
            cond1 = 1;
            printf("cond1 %d \n", DOUBLECOMPARE(measured_r, PARAMETERS.RADIUS1) == GT);
        }  
         if (DOUBLECOMPARE(measured_r, PARAMETERS.RADIUS2) != GT)
        {
            cond2 = 1;
            printf("cond2 %d \n", (DOUBLECOMPARE(measured_r, PARAMETERS.RADIUS2) != GT));
        }

       if (cond1 ==1 && cond2 == 1) 
      {return 1;}

        printf("here 1\n");

  
    }
     printf("here 2\n");
     return 0;


}

/************************************************************
There exists at least one set of three data points, separated 
by exactly E_PTS and F_PTS con-secutive intervening points, 
respectively, that are the vertices of a triangle with area 
greater than AREA1. In addition, there exist three data points 
 separated by exactly E PTS and F PTS consec- utive intervening 
 points, respectively, that are the vertices of a triangle with 
 area less than AREA2. 
************************************************************/
boolean LIC_14()
{
    if(NUMPOINTS < 5) return 0;
    if(PARAMETERS.AREA2 < 0) return 0;

    int i;
    double len1,len2,len3;          //triengles sides length
    double sp,a ;                   //semi parameter and area of the tringle
    double measured_r ;             //measured radius
    boolean cond1 = 0 , cond2 = 0;

     for (i=0; i < NUMPOINTS - PARAMETERS.F_PTS - PARAMETERS.F_PTS -2 ; i++) 
    {
               //calculate the length which is the distance between all the points, to form a tringle
            
        len1 = length(P.X[i],  P.Y[i],
                     P.X[i + PARAMETERS.E_PTS + 1],   P.Y[i + PARAMETERS.E_PTS + 1]); 

        len2 = length(P.X[i + PARAMETERS.E_PTS + 1],   P.Y[i + PARAMETERS.E_PTS + 1],
                     P.X[i + PARAMETERS.E_PTS + PARAMETERS.F_PTS +2],   P.Y[i + PARAMETERS.E_PTS + PARAMETERS.F_PTS +2]);

        len3 = length(P.X[i + PARAMETERS.E_PTS + PARAMETERS.F_PTS +2],   P.Y[i+ PARAMETERS.E_PTS + PARAMETERS.F_PTS +2],
                      P.X[i],  P.Y[i]);
    
       //calculaute the semi-perimeter of the tringle
        sp = (len1 + len2 + len3)/2;

        //area of tringle
        a = sqrt(sp*(sp-len1)*(sp-len2)*(sp-len3));
        printf("area %f \n", a);

        if (DOUBLECOMPARE(a, PARAMETERS.AREA1) == GT)
        {
            cond1 = 1;
            printf("cond1 %d \n", DOUBLECOMPARE(a, PARAMETERS.AREA1) == GT);

        }

        if (DOUBLECOMPARE(a, PARAMETERS.AREA2) == LT)
        {
            cond2 = 1;
            printf("cond2 %d \n", (DOUBLECOMPARE(a, PARAMETERS.AREA2) == LT));
        }

        if(cond1 == 1 && cond2 == 1)
        {
            return 1;
        }

    }
    return 0;

}

/*
function to generate the Conditions Met Vector (CMV)
*/
void generate_CMV()
{ 
    CMV[0] = LIC_0();
    CMV[1] = LIC_1();
    CMV[2] = LIC_2();
    CMV[3] = LIC_3();
    CMV[4] = LIC_4();
    CMV[5] = LIC_5();
    CMV[6] = LIC_6();
    CMV[7] = LIC_7();
    CMV[8] = LIC_8();
    CMV[9] = LIC_9();
    CMV[10] = LIC_10();
    CMV[11] = LIC_11();
    CMV[12] = LIC_12();
    CMV[13] = LIC_13();
    CMV[14] = LIC_14();
}


/*
function to generate the Preliminary Unlocking Matrix (PUM)
*/
void generate_PUM()
{
    int i,j;
    boolean cond1 =0, cond2=0;
    for(i = 0 ; i < 15 ; i++)
    {
        for(j = 0 ; j < 15 ; j++)
        {
           if (LCM[i][j] == ANDD) 
           {
              cond1= CMV[i];
              cond2= CMV[j];
              PUM[i][j] = cond1 && cond2;
           }
           else if (LCM[i][j] == ORR)
           {
              cond1= CMV[i];
              cond2= CMV[j];              
            PUM[i][j] = cond1 || cond2;
           } 
           else 
           {
            PUM[i][j] = 1;
           }
        }
    }
}



boolean row_true (int row)
{
    for (int j = 0; j < 15; j++) 
    {
        if(PUM[row][j] == 0)  return  0;
    }
return 1;
}




void DECIDE(void)
{
generate_CMV();


}
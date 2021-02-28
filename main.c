#include "DECIDE.h"
#include <stdio.h>
#include <string.h>


//LIC1, LIC2 , LIC0
//NUMPOINTS = 5;

//LIC3
NUMPOINTS = 10;


int main()
{  
  /**************LIC0**************/
/*
    static double x[5] = {5,3,5,8};
    static double y[5] = {9,7,10,11};
  P.X=x;
  P.Y=y;
  PARAMETERS.LENGTH1 = 100;
  boolean a = LIC_0(PARAMETERS.LENGTH1);

    if (a == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
 */

  /**************LIC1**************/
 //passing test
/*
  PARAMETERS.RADIUS1 = 3;
    double X[5];
    X[0]=3;
    X[1]=5;
    X[2]=10;
    X[3]=1;
    X[4]=2;
  P.X = X;

  double Y[5];
    Y[0]=3;
    Y[1]=7;
    Y[2]=19;
    Y[3]=4;
    Y[4]=50;
  P.Y = Y;
*/

//failing test
/*  PARAMETERS.RADIUS1 = 1;
    double X[5];
    X[0]=1;
    X[1]=2;
    X[2]=3;
    X[3]=4;
    X[4]=5;
  P.X = X;

  double Y[5];
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
  P.Y = Y;


  if (LIC_1() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/

  /**************LIC2**************/


//passing test
/* double X[5];
    X[0]=0;
    X[1]=0;
    X[2]=1;
    X[3]=2;
    X[4]=3;

    P.X = X;

    double Y[5];
    Y[0]=1;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=3;
    P.Y = Y;
    PARAMETERS.EPSILON=1; */

//failing test
/* double X[5];
    X[0]=0;
    X[1]=0;
    X[2]=0;
    X[3]=0;
    X[4]=3;

    P.X = X;

    double Y[3];
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=3;
    P.Y = Y;
    PARAMETERS.EPSILON=0.000001;

    if (LIC_2() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/
  /**************LIC3**************/
  //passing
  /*
  double X[10];
  X[0] = 3;
  X[1] = 1;
  X[2] = 1;
  X[3] = 1;
  X[4] = 5;
  X[5] = 1;
  X[6] = 3;
  X[7] = 1;
  X[8] = 1;
  X[9] = 1;
  P.X = X;

  double Y[10];
  Y[0] = 1;
  Y[1] = 1;
  Y[2] = 1;
  Y[3] = 1;
  Y[4] = 3;
  Y[5] = 1;
  Y[6] = 6;
  Y[7] = 1;
  Y[8] = 1;
  Y[9] = 1;
  P.Y = Y;
  PARAMETERS.AREA1 = 3;
  */

//failing test
/* double X[10];
  X[0] = -1;
  X[1] = 0;
  X[2] = 1;
  X[3] = 1;
  X[4] = 5;
  X[5] = 1;
  X[6] = 3;
  X[7] = 1;
  X[8] = 1;
  X[9] = 1;
  P.X = X;

  double Y[10];
  Y[0] = 0;
  Y[1] = 0;
  Y[2] = 0;
  Y[3] = 1;
  Y[4] = 3;
  Y[5] = 1;
  Y[6] = 6;
  Y[7] = 1;
  Y[8] = 1;
  Y[9] = 1;
  P.Y = Y;
  PARAMETERS.AREA1 = -1;

  

  if (LIC_3() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/

 /**************LIC4**************/

//passing test
/*
PARAMETERS.Q_PTS = 2;
PARAMETERS.QUADS = 2;
  double X[10];
  X[0] = 3;
  X[1] = -1;
  X[2] = 1;
  X[3] = -1;
  X[4] = 5;
  X[5] = 1;
  X[6] = 3;
  X[7] = 1;
  X[8] = 1;
  X[9] = 1;
  P.X = X;


 double Y[10];
  Y[0] = 1;
  Y[1] = 1;
  Y[2] = -1;
  Y[3] = -1;
  Y[4] = 3;
  Y[5] = 1;
  Y[6] = 6;
  Y[7] = 1;
  Y[8] = 1;
  Y[9] = 1;
  P.Y = Y;
*/

//failing test case
/*
PARAMETERS.Q_PTS = 1;
PARAMETERS.QUADS = 1;
  double X[10];
  X[0] = 3;
  X[1] = 1;
  X[2] = 1;
  X[3] = 1;
  X[4] = 5;
  X[5] = 1;
  X[6] = 3;
  X[7] = 1;
  X[8] = 1;
  X[9] = 1;
  P.X = X;


 double Y[10];
  Y[0] = 1;
  Y[1] = 1;
  Y[2] = 1;
  Y[3] = 1;
  Y[4] = 3;
  Y[5] = 1;
  Y[6] = 6;
  Y[7] = 1;
  Y[8] = 1;
  Y[9] = 1;
  P.Y = Y;
  if (LIC_4() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
  */


 /**************LIC5**************/
//failing test
/*  double X[10];
  X[0] = 1;
  X[1] = 1;
  X[2] = 1;
  X[3] = 1;
  X[4] = 1;
  X[5] = 1;
  X[6] = 1;
  X[7] = 1;
  X[8] = 1;
  X[9] = 1;
   P.X = X;
*/


//passing test
/*
double X[10];
  X[0] = 1;
  X[1] = 3;
  X[2] = 6;
  X[3] = 7;
  X[4] = 9;
  X[5] = 10;
  X[6] = 14;
  X[7] = 15;
  X[8] = 12;
  X[9] = 0;
   P.X = X;


    if (LIC_5() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/


 /**************LIC6**************/
 //failing test case 
 /* double X[10];
  X[0] = 1;
  X[1] = 2;
  X[2] = 3;
  X[3] = 4;
  X[4] = 5;
  X[5] = 6;
  X[6] = 7;
  X[7] = 8;
  X[8] = 9;
  X[9] = 10;
  P.X = X;


 double Y[10];
  Y[0] = 1;
  Y[1] = 1;
  Y[2] = 1;
  Y[3] = 1;
  Y[4] = 1;
  Y[5] = 1;
  Y[6] = 1;
  Y[7] = 1;
  Y[8] = 1;
  Y[9] = 1;
  P.Y = Y;
    PARAMETERS.DIST= 1;    
  PARAMETERS.N_PTS= 3; 

 
 //failing test case
  double X[10];
  X[0] = 1;
  X[1] = 2;
  X[2] = 3;
  X[3] = 4;
  X[4] = 5;
  X[5] = 6;
  X[6] = 7;
  X[7] = 8;
  X[8] = 9;
  X[9] = 10;
  P.X = X;


 double Y[10];
  Y[0] = 1;
  Y[1] = 13;
  Y[2] = 1;
  Y[3] = 1;
  Y[4] = 1;
  Y[5] = 1;
  Y[6] = 1;
  Y[7] = 1;
  Y[8] = 1;
  Y[9] = 1;
  P.Y = Y; 
    PARAMETERS.DIST= 1;    
  PARAMETERS.N_PTS= 3; 

      if (LIC_6() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/



 /**************LIC7**************/
  //passing test case
/* double X[10];
  X[0] = 1;
  X[1] = 2;
  X[2] = 3;
  X[3] = 4;
  X[4] = 5;
  X[5] = 6;
  X[6] = 7;
  X[7] = 8;
  X[8] = 9;
  X[9] = 10;
  P.X = X;


 double Y[10];
  Y[0] = 1;
  Y[1] = 13;
  Y[2] = 1;
  Y[3] = 1;
  Y[4] = 1;
  Y[5] = 1;
  Y[6] = 1;
  Y[7] = 1;
  Y[8] = 1;
  Y[9] = 1;
  P.Y = Y; 

PARAMETERS.LENGTH1 =  1;
PARAMETERS.K_PTS   =  1;


//failing test case

double X[10];
  X[0] = 0;
  X[1] = 1;
  X[2] = 2;
  X[3] = 3;
  X[4] = 4;
  X[5] = 5;
  X[6] = 6;
  X[7] = 7;
  X[8] = 8;
  X[9] = 9;
  P.X = X;


 double Y[10];
  Y[0] = 0;
  Y[1] = 0;
  Y[2] = 0;
  Y[3] = 0;
  Y[4] = 0;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
  P.Y = Y; 

PARAMETERS.LENGTH1 =  2;
PARAMETERS.K_PTS   =  1;

      if (LIC_7() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/

 /**************LIC8**************/

//failing test case
/*
double X[10];
  X[0] = 0;
  X[1] = 1;
  X[2] = 2;
  X[3] = 3;
  X[4] = 4;
  X[5] = 5;
  X[6] = 6;
  X[7] = 7;
  X[8] = 8;
  X[9] = 9;
  P.X = X;


 double Y[10];
  Y[0] = 0;
  Y[1] = 0;
  Y[2] = 0;
  Y[3] = 0;
  Y[4] = 0;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
  P.Y = Y; 
  PARAMETERS.A_PTS=1;   
  PARAMETERS.B_PTS=1;
  PARAMETERS.RADIUS1=2;

  


//passing test case
double X[10];
  X[0] = 0;
  X[1] = 2;
  X[2] = 4;
  X[3] = 6;
  X[4] = 8;
  X[5] = 10;
  X[6] = 12;
  X[7] = 14;
  X[8] = 16;
  X[9] = 18;
  P.X = X;


 double Y[10];
  Y[0] = 0;
  Y[1] = 0;
  Y[2] = 0;
  Y[3] = 0;
  Y[4] = 0;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
  P.Y = Y; 
  PARAMETERS.A_PTS=2;   
  PARAMETERS.B_PTS=1;
  PARAMETERS.RADIUS1=3.5;




  if (LIC_8() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/



 /**************LIC9**************/

/*
//passed test case
double X[10];
  X[0] = 0;
  X[1] = 0;
  X[2] = 0;
  X[3] = 0;
  X[4] = 1;
  X[5] = 0;
  X[6] = 0;
  X[7] = 0;
  X[8] = 0;
  X[9] = 0;
  P.X = X;


 double Y[10];
  Y[0] = 0;
  Y[1] = 0;
  Y[2] = 1;
  Y[3] = 0;
  Y[4] = 1;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
  P.Y = Y; 
    PARAMETERS.C_PTS=1;       
     PARAMETERS.D_PTS=1;
    PARAMETERS.EPSILON=1;


//failing test case
double X[10];
  X[0] = 0;
  X[1] = 0;
  X[2] = 0;
  X[3] = 0;
  X[4] = 0;
  X[5] = 0;
  X[6] = 0;
  X[7] = 0;
  X[8] = 0;
  X[9] = 0;
  P.X = X;


 double Y[10];
  Y[0] = 0;
  Y[1] = 0;
  Y[2] = 0;
  Y[3] = 0;
  Y[4] = 0;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
  P.Y = Y;

    PARAMETERS.C_PTS=1;       
    PARAMETERS.D_PTS=2;
    PARAMETERS.EPSILON=PI/2;
    

  if (LIC_9() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/


 /**************LIC10**************/

//failing test case
/*
double X[10];
  X[0] = 0;
  X[1] = 0;
  X[2] = 1;
  X[3] = 0;
  X[4] = 2;
  X[5] = 2;
  X[6] = 0;
  X[7] = 0;
  X[8] = 0;
  X[9] = 0;
  P.X = X;


 double Y[10];
  Y[0] = 0;
  Y[1] = 0;
  Y[2] = 2;
  Y[3] = 0;
  Y[4] = 0;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
  P.Y = Y;

  PARAMETERS.AREA1 = 2;  //lower the area to make it pass, t.ex.1.8
  PARAMETERS.F_PTS = 1;
  PARAMETERS.E_PTS = 1;


  if (LIC_10() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }

*/



 /**************LIC11**************/

 //passing test case
 /*
 double X[10];
  X[0] = 0;
  X[1] = 0;
  X[2] = 1;
  X[3] = 0;
  X[4] = 2;
  X[5] = 2;
  X[6] = 0;
  X[7] = 0;
  X[8] = 0;
  X[9] = 0;
  P.X = X; 


//failing test case.
  double X[10];
  X[0] = 0;
  X[1] = 1;
  X[2] = 2;
  X[3] = 3;
  X[4] = 4;
  X[5] = 5;
  X[6] = 6;
  X[7] = 7;
  X[8] = 8;
  X[9] = 9;
  P.X = X;

  double Y[10];
  Y[0] = 0;
  Y[1] = 0;
  Y[2] = 2;
  Y[3] = 0;
  Y[4] = 0;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
  P.Y = Y; 

  PARAMETERS.G_PTS=2;

  if (LIC_11() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/


 /**************LIC12**************/
 //passing test case
/*  double X[10];
  X[0] = 1;
  X[1] = 0;
  X[2] = 5;
  X[3] = 5;
  X[4] = 1;
  X[5] = 5;
  X[6] = 6;
  X[7] = 7;
  X[8] = 8;
  X[9] = 9;
  P.X = X;

  double Y[10];
  Y[0] = 1;
  Y[1] = 0;
  Y[2] = 5;
  Y[3] = 5;
  Y[4] = 2;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
  P.Y = Y; 

  PARAMETERS.LENGTH1 = 4;
  PARAMETERS.LENGTH2 = 1;
  PARAMETERS.K_PTS = 2;



//failing test case
  double X[10];
  X[0] = 0;
  X[1] = 1;
  X[2] = 2;
  X[3] = 3;
  X[4] = 4;
  X[5] = 5;
  X[6] = 6;
  X[7] = 7;
  X[8] = 8;
  X[9] = 9;
  P.X = X;

  double Y[10];
  Y[0] = 0;
  Y[1] = 0;
  Y[2] = 0;
  Y[3] = 0;
  Y[4] = 0;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
    P.Y = Y;

  PARAMETERS.LENGTH1 = 5;
  PARAMETERS.LENGTH2 =10;
  PARAMETERS.K_PTS = 2;

  if (LIC_12() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/

 /**************LIC13**************/
//double X[] = {1,2,3,4,5,6,7,8}; 
//failing test case
 double X[10];
  X[0] = 1;
  X[1] = 0;
  X[2] = 5;
  X[3] = 5;
  X[4] = 1;
  X[5] = 5;
  X[6] = 6;
  X[7] = 7;
  X[8] = 8;
  X[9] = 9;
  P.X = X; 

  double Y[10];
  Y[0] = 1;
  Y[1] = 0;
  Y[2] = 5;
  Y[3] = 5;
  Y[4] = 2;
  Y[5] = 0;
  Y[6] = 0;
  Y[7] = 0;
  Y[8] = 0;
  Y[9] = 0;
  P.Y = Y; 

PARAMETERS.RADIUS1 = 4; //to make it pass make it 0.5
PARAMETERS.RADIUS2 = 3;
PARAMETERS.A_PTS = 2;
PARAMETERS.B_PTS = 2;

  if (LIC_13() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }




  return 0;
}



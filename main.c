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
  /**************LIC2**************/
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
 double X[10];
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


/*
PARAMETERS.Q_PTS = 2;
PARAMETERS.QUADS = 2;
int qPts = PARAMETERS.Q_PTS;
int nQuad = PARAMETERS.QUADS;

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

  boolean a4 = LIC_4( qPts, nQuad);

  if (a4 == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/


/*
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

  boolean a5 = LIC_5();

    if (a5 == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/
  
  /*
  
   x[5] = {0,1,2,0};
  P.X=x;

    if (LIC_5() == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/
  return 0;
}



#include "DECIDE.h"
#include <stdio.h>
#include <string.h>

NUMPOINTS = 10;
int main()
{
  //LIC0
  /*
   NUMPOINTS = 5;
  PARAMETERS.LENGTH1 = 2;
  X[0] = 5;
  X[1] = 3;
  X[2] = 5;
  X[3] = 8;
  X[4] = 6;
  Y[0] = 9;
  Y[1] = 7;
  Y[2] = 10;
  Y[3] = 11;
  Y[4] = 11;

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

  /*
  PARAMETERS.RADIUS1 = 3;
  
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


  boolean a = LIC_1(PARAMETERS.RADIUS1);

  if (a == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/

/*
PARAMETERS.EPSILON =39;

  X[0] = 3;
  X[1] = 1;
  X[2] = 1;
  X[3] = 1;
  X[4] = 1;
  X[5] = 1;
  X[6] = 3;
  X[7] = 1;
  X[8] = 1;
  X[9] = 1;

  Y[0] = 1;
  Y[1] = 1;
  Y[2] = 1;
  Y[3] = 1;
  Y[4] = 3;
  Y[5] = 1;
  Y[6] = 1;
  Y[7] = 1;
  Y[8] = 1;
  Y[9] = 1;

  boolean a2 = LIC_2(PARAMETERS.EPSILON);

    if (a2 == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }
*/
  
PARAMETERS.AREA1 = 2;

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

  
  PARAMETERS.AREA1 = 100;
  boolean a3 = LIC_3(PARAMETERS.AREA1);

  if (a3 == 1)
  {
    printf("passed \n");
  }
  else
  {
    printf("failed \n");
  }

  return 0;
}



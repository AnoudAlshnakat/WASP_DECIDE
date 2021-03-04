#include "DECIDE.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

/****************************************
LIC0 test cases: 2 failing and 1 passing
****************************************/

boolean LIC_0_Pass_case1()
{
    //test inputs: Number of points = 10, the parameter LENGTH1 = 4 unit, and coordinates of 10 points.
    NUMPOINTS = 10;
    double X[] = {5, 3, 5, 8, 5, 3, 5, 8, 2, 3};
    double Y[] = {1, 4, 3, 1, 5, 6, 1, 6, 1, 4};
    P.X = X;
    P.Y = Y;
    PARAMETERS.LENGTH1 = 4;
    //LIC_0 should pass because there is a distance between two consequent points
    //on a distance that are larger than LENGTH1
    boolean result = LIC_0();
    assert(result == 1);
    return result; 
}

boolean LIC_0_Fail_case1()
{
    //test inputs: Number of points = 10, the parameter LENGTH1 = 100 unit, and coordinates of 10 points.
    NUMPOINTS = 10;
    double X[] = {5, 3, 5, 8, 5, 3, 5, 8, 2, 3};
    double Y[] = {1, 4, 3, 1, 5, 6, 1, 6, 1, 4};
    P.X = X;
    P.Y = Y;
    PARAMETERS.LENGTH1 = 100;

    //LIC_0 should fail because there is no distance between 
    //any two consequent points larger than LENGTH1
    boolean result = LIC_0();
    assert(result == 0);
    return result; 
}


boolean LIC_0_Fail_case2()
{
    //test inputs: Number of points = 10, the parameter LENGTH1 = -3 unit, and coordinates of 10 points.
    NUMPOINTS = 10;
    double X[] = {5, 3, 5, 8, 5, 3, 5, 8, 2, 3};
    double Y[] = {1, 4, 3, 1, 5, 6, 1, 6, 1, 4};
    P.X = X;
    P.Y = Y;
    PARAMETERS.LENGTH1 = -3;
    //LIC_0 should fail because LENGTH1 is less than 0
    boolean result = LIC_0();
    assert(result == 0);
    return result; 
}


//function to call the LICs test cases and prints the result
test_all_LIC()
{   //LIC0 test cases call 

   if (LIC_0_Pass_case1() == 1) 
   printf("LIC_0 test case 1 for passing input : PASSED \n");
   else
   printf("LIC_0 test case 1 for passing input : FAILED \n");


   if (LIC_0_Fail_case1() == 0) 
   printf("LIC_0 test case 1 for failing input : PASSED \n");
   else
   printf("LIC_0 test case 1 for failing input : FAILED \n");


   if (LIC_0_Fail_case2() == 0) 
   printf("LIC_0 test case 2 for failing input : PASSED \n");
   else
   printf("LIC_0 test case 2 for failing input : FAILED \n");
 
}


void main()
{ //Test the requirements function call
  test_all_LIC();

}
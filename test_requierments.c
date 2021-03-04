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


/****************************************
LIC1 test cases: 1 passing and 1 failing
****************************************/

boolean LIC_1_Pass_case1()
{
    //test inputs: Number of points = 5, the parameter RADIUS1 = 3 unit, and coordinates of 5 points.
    NUMPOINTS = 5;
    double X[] = {3, 5, 10, 1, 2};
    double Y[] = {3, 7, 19, 4, 50};
    P.X = X;
    P.Y = Y;
    PARAMETERS.RADIUS1 = 3;
    //LIC_1 should pass because the first three points cannot be contained or on a
    //circle with RADIUS1 3
    boolean result = LIC_1();
    assert(result == 1);
    return result;
}


boolean LIC_1_Fail_case1()
{
    //test inputs: Number of points = 5, the parameter RADIUS1 = 1 unit, and coordinates of 5 points.
    NUMPOINTS = 5;
    double X[] = {1,2,3,4,5};
    double Y[] = {0,0,0,0,0};
    P.X = X;
    P.Y = Y;
    PARAMETERS.RADIUS1 = 1;
    //LIC_1 should fail because the first three points can be contained or on a
    //circle with RADIUS1 1
    boolean result = LIC_1();
    assert(result == 0);
    return result;
}


/****************************************
LIC2 test cases: 1 passing and 1 failing
****************************************/
boolean LIC_2_Pass_case1()
{
    //test inputs: Number of points = 5, the parameter EPSILON = 1 unit, and coordinates of 5 points.
    NUMPOINTS = 5;
    double X[] = {0, 0, 1, 2, 3};
    double Y[] = {1, 0, 0, 0, 3};
    P.X = X;
    P.Y = Y;
    PARAMETERS.EPSILON=1;
    //LIC_2 should pass because the angle created in the first three points is 90 degrees
    //which is larger than PI+EPSILON, thus requirement is satisfied.
    boolean result = LIC_2();
    assert(result == 1);
    return result;
}

boolean LIC_2_Fail_case1()
{
    //test inputs: Number of points = 5, the parameter EPSILON = 1 unit, and coordinates of 5 points.
    NUMPOINTS = 5;
    double X[] = {3, 4, 5, 6, 7};
    double Y[] = {0, 0, 0, 0, 0};
    P.X = X;
    P.Y = Y;
    PARAMETERS.EPSILON=1;
    //LIC_2 should fail because the angle created is 0, so it is not larger that PI+EPSILON 
    //or smaller than PI-EPSILON
    boolean result = LIC_2();
    assert(result == 0);
    return result;
}


/****************************************
LIC3 test cases: 1 passing and 1 failing
****************************************/
boolean LIC_3_Pass_case1()
{
    //test inputs: Number of points = 10, the parameter AREA = 3 unit, and coordinates of 10 points.
    NUMPOINTS = 10;
    double X[] = {3, 1, 1, 1, 5, 1, 3, 1, 1, 1};
    double Y[] = {1, 1, 1, 1, 3, 1, 6, 1, 1, 1};
    P.X = X;
    P.Y = Y;
    PARAMETERS.AREA1 = 3;
    //LIC_3 should pass because there exsist three points X[4]-X[6] with Y[4]-Y[6]
    //form a trangle with an area = 8  which is greater than AREA1
    boolean result = LIC_3();
    assert(result == 1);
    return result;
}


boolean LIC_3_Fail_case1()
{
    //test inputs: Number of points = 10, the parameter AREA = 3 unit, and coordinates of 10 points.
    NUMPOINTS = 10;
    double X[] = {3, 1, 1, 1, 5, 1, 3, 1, 1, 1};
    double Y[] = {1, 4, 3, 1, 3, 1, 6, 1, 6, 1};
    P.X = X;
    P.Y = Y;
    PARAMETERS.AREA1 = 9.5;
    //LIC_3 should fail because there is not exsist three points
    //form a trangle with an area larger than AREA1 9.5
    boolean result = LIC_3();
    assert(result == 0);
    return result;
}


/****************************************
LIC4 test cases: 1 passing and 1 failing
****************************************/
boolean LIC_4_Pass_case1()
{
    //test inputs: Number of points = 10, the parameter Q_PTS = 3, QUADS = 3, and coordinates of 10 points.
    NUMPOINTS = 10;
    double X[] = {3, -1, 1, -1, 5, 1, 3, 1, 1, 1};
    double Y[] = {1, 1, -1, -1, 3, 1, 6, 1, 1, 1};
    P.X = X;
    P.Y = Y;
    PARAMETERS.Q_PTS = 3;
    PARAMETERS.QUADS = 3;
    //LIC_4 should pass because there exist three points Q_pts with coordinates lay in three 
    //different QUADS 
    boolean result = LIC_4();
    assert(result == 1);
    return result;
}

boolean LIC_4_Fail_case1()
{
    //test inputs: Number of points = 10, the parameter Q_PTS = 3, QUADS = 3, and coordinates of 10 points.
    NUMPOINTS = 10;
    double X[] = {3, 1, 1, 1, 5, 1, 3, 1, 1, 1};
    double Y[] = {1, 1, 1, 1, 3, 1, 6, 1, 1, 1};
    P.X = X;
    P.Y = Y;
    PARAMETERS.Q_PTS = 2;
    PARAMETERS.QUADS = 1;
    //LIC_4 should fail because all the exsisting points are in the first Quadrant 
    boolean result = LIC_4();
    assert(result == 0);
    return result;
}

/****************************************
LIC5 test cases: 1 passing and 1 failing
****************************************/
boolean LIC_5_Pass_case1()
{
    //test inputs: Number of points with X coordinate = 10
    NUMPOINTS = 10;
    double X[] = {1, 2, 3, 5, 4, 2, 1, 1, 0, 0};
    double Y[] = {3, 6, 2,-1, 7, 8, 1, 3, 4, 5};
    P.X = X;
    P.Y = Y;
    //LIC_5 should pass because there exist at least two consecutive points
    //where the second one - first one is a negative value
    boolean result = LIC_5();
    assert(result == 1);
    return result;
}

boolean LIC_5_Fail_case1()
{
    //test inputs: Number of points with X coordinate = 10
    NUMPOINTS = 10;
    double X[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double Y[] = {1, 1, 1, 1, 3, 1, 6, 1, 1, 1};
    P.X = X;
    P.Y = Y;
    //LIC_5 should fail there are no consecutive points that satisfies the LIC5 condition
    boolean result = LIC_5();
    assert(result == 0);
    return result;
}

/****************************************
LIC6 test cases: 1 passing and 1 failing
****************************************/
boolean LIC_6_Pass_case1()
{
    //test inputs: Number of points = 10, the parameter N_PTS = 3, DIST = 1, and coordinates of 10 points.
    NUMPOINTS = 10;
    double X[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    double Y[] = {3, 12, 3, 3, 3, 3, 3, 3, 3, 3};
    P.X = X;
    P.Y = Y;
    PARAMETERS.DIST= 0.5;    
    PARAMETERS.N_PTS= 3;
    //LIC_6 should pass because the there is a set of 3 N_PTS points such that 
    //the distance between them is greater than DIST = 0.5 unit. 
    boolean result = LIC_6();
    assert(result == 1);
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

    //LIC1 test cases call 
   if (LIC_1_Pass_case1() == 1) 
   printf("LIC_1 test case 1 for passing input : PASSED \n");
   else
   printf("LIC_1 test case 1 for passing input : FAILED \n");

   if (LIC_1_Fail_case1() == 0) 
   printf("LIC_1 test case 1 for failing input : PASSED \n");
   else
   printf("LIC_1 test case 1 for failing input : FAILED \n");

    //LIC2 test cases call
   if (LIC_2_Pass_case1() == 1) 
   printf("LIC_2 test case 1 for passing input : PASSED \n");
   else
   printf("LIC_2 test case 1 for passing input : FAILED \n");

   if (LIC_2_Fail_case1() == 0) 
   printf("LIC_2 test case 1 for failing input : PASSED \n");
   else
   printf("LIC_2 test case 1 for failing input : FAILED \n");

   //LIC3 test cases call
   if (LIC_3_Pass_case1() == 1) 
   printf("LIC_3 test case 1 for passing input : PASSED \n");
   else
   printf("LIC_3 test case 1 for passing input : FAILED \n");

   if (LIC_3_Fail_case1() == 0) 
   printf("LIC_3 test case 1 for failing input : PASSED \n");
   else
   printf("LIC_3 test case 1 for failing input : FAILED \n");

   //LIC4 test cases call
   if (LIC_4_Pass_case1() == 1) 
   printf("LIC_4 test case 1 for passing input : PASSED \n");
   else
   printf("LIC_4 test case 1 for passing input : FAILED \n");

   if (LIC_4_Fail_case1() == 0) 
   printf("LIC_4 test case 1 for failing input : PASSED \n");
   else
   printf("LIC_4 test case 1 for failing input : FAILED \n");

   //LIC5 test cases call
   if (LIC_5_Pass_case1() == 1) 
   printf("LIC_5 test case 1 for passing input : PASSED \n");
   else
   printf("LIC_5 test case 1 for passing input : FAILED \n");

   if (LIC_5_Fail_case1() == 0) 
   printf("LIC_5 test case 1 for failing input : PASSED \n");
   else
   printf("LIC_5 test case 1 for failing input : FAILED \n");

   //LIC6 test cases call
   if (LIC_6_Pass_case1() == 1) 
   printf("LIC_6 test case 1 for passing input : PASSED \n");
   else
   printf("LIC_6 test case 1 for passing input : FAILED \n");
 
}


void main()
{ //Test the requirements function call
  test_all_LIC();

}
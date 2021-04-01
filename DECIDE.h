// This is version 4 of this file.
#include <math.h>

//type declarations
typedef enum
{
    NOTUSED = 777,
    ORR,
    ANDD
} CONNECTORS;

//pointer to an array of 100 doubles
typedef double *COORDINATE;

//pointer to a 2D array of [15,15] connectors
typedef CONNECTORS **CMATRIX;

//always in the range [0..1]
typedef int boolean;

// pointer to a 2D array of [15, 15] booleans
typedef boolean **BMATRIX;

// pointer to an array of 15 booleans
typedef boolean *VECTOR;

typedef enum
{
    LT = 111,
    EQ,
    GT
} COMPTYPE;

//inputs to the decide () function
typedef struct
{
    double LENGTH1; //Length in LICs 0,7,12
    double RADIUS1; //RADIUS in LICS 1,8.13
    double EPSILON; //DEVIATION from pi in LICs 2,9
    double AREA1;   //AREA in LICs 2,9
    int Q_PTS;      //No. of consecutive points in LIC 4
    int QUADS;      //No. of quads in LIC 4
    double DIST;    //Distance in LIC 6
    int N_PTS;      // No. ofconsecutive pts . in LIC 6
    int K_PTS;      // No . of int . pts . in LICs 7 , 12
    int A_PTS;      // No . of int . pts . in LICs 8 , 13
    int B_PTS;      // No . of int . pts . in LICs 8 , 13
    int C_PTS;      // No . of int . pts . in LICs 9
    int D_PTS;      // No . of int . pts . in LICs 9
    int E_PTS;      // No . of int . pts . in LICs 10 , 14
    int F_PTS;      // No . of int . pts . in LICs 10 , 14
    int G_PTS;      // No . of int . pts . in LICs 11
    double LENGTH2; // Maximum length in LIC 12
    double RADIUS2; // Maximum radius in LIC 13
    double AREA2;   // Maximum area in LIC 13
} PARAMETERS_T;

//////////// global variable declarations ////////////
PARAMETERS_T PARAMETERS;
static PARAMETERS_T PARAMETERS2;

// X coordinates of data points
//COORDINATE X [];
static COORDINATE X2;

// Y coordinates of data points
//COORDINATE Y [];
static COORDINATE Y2;

typedef struct
{
    COORDINATE X;
    COORDINATE Y;
} POINT_COORDNATE;

POINT_COORDNATE P;

// Number of data points -planar data points
int NUMPOINTS;
static int NUMPOINTS2;

// Logical Connector Matrix
CMATRIX LCM;
static CMATRIX LCM2;

// Preliminary Unlocking Matrix
BMATRIX PUM;
static BMATRIX PUM2;

// Conditions Met Vector
VECTOR CMV;
static VECTOR CMV2;

// Final Unlocking Vector
VECTOR FUV;
static VECTOR FUV2;

// Decision : Launch or No Launch
boolean LAUNCH;
static boolean LAUNCH2;

//Final unlocking vector
VECTOR PUV;

// compares floating point numbers -- see Nonfunctional Requirements
static inline COMPTYPE DOUBLECOMPARE(double A, double B)
{
    if (fabs(A - B) < 0.000001)
        return EQ;
    if (A < B)
        return LT;
    return GT;
}

// function you must write
void DECIDE(void);
boolean LIC_0();
boolean LIC_1();
boolean LIC_2();
boolean LIC_3();
boolean LIC_4();
boolean LIC_5();
boolean LIC_6();
boolean LIC_7();
boolean LIC_8();
boolean LIC_9();
boolean LIC_10();
boolean LIC_11();
boolean LIC_12();
boolean LIC_13();
boolean LIC_14();

//////////// end of file /////////////
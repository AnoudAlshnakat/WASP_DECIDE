// This is version 4 of this file.
#include <math.h>

// constant declaration
static const double PI = 3.1415926535;


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


// Preliminary Unlocking Matrix
BMATRIX PUM;


// Conditions Met Vector
VECTOR CMV;


// Final Unlocking Vector
VECTOR FUV;


// Decision : Launch or No Launch
boolean LAUNCH;


//Final unlocking vector
VECTOR PUV;



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
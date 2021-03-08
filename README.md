# Launch Interceptor program
This repository is a simple hypothetical anti-ballistic missile system written in C.
The inputs are Radar echo-planar data points, Logical Connector Matrix (LCM) and Preliminary Unlocking Vector (PUV).

Based on those inputs the output is determined. The output is in a form of a boolean launch signal (i.e. True or False) that will determine if the interceptor should be launched or not.

The code contains 15 Launch Interceptor Conditions (LIC). Then it generates a Conditions Met Vector (CMV) out of the LICs, afterwards it calculates the Preliminary Unlocking Matrix (PUM) and Final Unlocking Vector (FUV). In the end, the DECIDE function will calculate whether the missile should be launched or not. 

You can find the implementation in the file DECIDE.c and the header file DECIDE.h.

The project repository uses `TRAVIS Continous Integration`, to support the development process. Also, please note that the atomic development phase of the project is done in the branch `initial code`, which it got merged to the main branch. 


## Test and Results
unit-testing has been accomplished for 16 requirements, both passing cases and failing cases. Thus, in the `test_requirements.c` you will find 31 test cases, that could be run using the command on the bottom.

## Files and contents:
`DECIDE.c` contains the DECIDE function library implementation.

`DECIDE.h` is the header file for the decide project, given in the excercise.

`test_requirement.c` contains many test cases that covers the LICs requirements.

`makfile` is the c makefile for this project.

`.travis.yml` contains the initial configration for travic CI.


## getting Started
To get started, the project requires gcc-compiler to be installed.
All versions are supposed to be okay to use, however, in this project the used one is: gcc (Ubuntu 7.5.0-3 ubuntu1~18.04) 7.5.0


## install and test
1. clone the repository. Use the following command:
  ```
   git clone https://github.com/AnoudAlshnakat/WASP_DECIDE.git
   ```
2. To compile the test, use the following command:
  ```
   make test
   ```
3. To run the test, use the following command:
    ```
    ./test
    ```


## references
https://www.monperrus.net/martin/decide.pdf
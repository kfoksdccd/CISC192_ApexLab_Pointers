//
// Don't modify code in this file, with the exception
// of adding test cases.
//
#include <iostream>
#include <iomanip>
#include <random>
#include "apex_code.h"

using namespace std;

bool near(double expected, double result, double threshold)
{
    return abs(expected - result) < threshold;
}

// Use when testing double values
bool testNear(double expected, double result)
{
    if(false == near(expected, result, 0.002))
    {
        cout << "FAILED: Expected " << expected << ", received " << result << ".\n";
    }
    else {
        cout << "PASS\n";
    }

    return expected == result;
}

// Use for everything other than doubles/floats
template<typename T> bool test(T expected, T result)
{
    if(expected != result)
    {
        cout << "FAILED: Expected " << expected << ", received " << result << ".\n";
    }
    else {
        cout << "PASS\n";
    }

    return expected == result;
}
int main()
{
    // To add a test case, duplicate the test lines below
    // You can add more local cup instances

    Cup unitCup(1, 1, 1);
    Cup twoCup(2, 1, 1);
    Cup cup(5.3, 4.0, 9.0);

    Cup* twoCupPtr = new Cup(twoCup);
    Cup* cupPtr = new Cup(cup);

    (void)testNear(3.1415, unitCup.capacityInMls());
    (void)testNear(615.3437, cup.capacityInMls());
    (void)testNear(7.3303, twoCup.capacityInMls());

    twoCupPtr->HeightCms = 2;
    (void)testNear(14.6608, twoCupPtr->capacityInMls());
  
    (void)test<bool>(false, addFluid(twoCupPtr, 400));
    (void)test<bool>(true, addFluid(twoCupPtr, 10));
    (void)test<bool>(false, addFluid(twoCupPtr, -12));

    (void)testNear(68.2093, howFull(*twoCupPtr));
    (void)test<bool>(true, addFluid(cupPtr, 480));
    (void)testNear(78.0052, howFull(*cupPtr));

    double       output;
    (void)test<bool>(true, mlPerDollar(cup, 3.25, output));
    (void)testNear(189.3365, output);
    output = 0.0;
    
    (void)test<bool>(false, mlPerDollar(twoCup, -6.25, output));
    (void)testNear(0.0, output);
    output = 0.0;
    
    (void)test<bool>(true, mlPerDollar(twoCup, 6.25, output));
    (void)testNear(1.17286, output);
    output = 0.0;
    
    return 0;
}

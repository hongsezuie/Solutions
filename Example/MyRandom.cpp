#include "MyRandom.h"
#include <cstdlib>
#include <cmath>

using namespace std;

MyRandom::MyRandom()
{

}

MyRandom::~MyRandom()
{

}

double MyRandom::SampleBoxMuller()
{
    double result;
    double x;
    double y;
    double xysquare;
    do
    {
        x = 2.0*rand()/static_cast<double>(RAND_MAX)-1;
        y = 2.0*rand()/static_cast<double>(RAND_MAX)-1;
        xysquare = x*x + y*y;
    }
    while( xysquare >= 1.0);
        result = x*sqrt(-2*log(xysquare)/xysquare);
    return result;
}

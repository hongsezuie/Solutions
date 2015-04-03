#include "solution.h"
#include <string>
#include <math.h>

Solution::Solution()
{

}

Solution::~Solution()
{

}

std::string Solution::convertToTitle(int n)
{
    std::string s;

    while(n>0)
    {
        n-=1;
        char m=n%26+65;
        s=m+s;
        n/=26;
    }

    return s;
}

#include <stdio.h>

// nHm
// n+m-1Cm
// n+m-1Pm/m!
// (n+m-1)!/(n-1)!m!
//




unsigned long long int facs[30] = {1, };


unsigned long long int fac(int a)
{
    if (facs[a]!=0)
    {
        return facs[a];
    }
    facs[a] = facs[a-1]*a;
    return facs[a];

}



int main()
{

}
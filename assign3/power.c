#include "power.h"

int power(int a, int b)
{
    int j=1;
    while(b>0)
    {
	j=j*a;
	b--;
    }
    return(j);
}

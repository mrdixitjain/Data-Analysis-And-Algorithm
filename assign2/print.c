#include "smart_calci.h"

void print(num n)
{
	int i=0;
	int l =strlen(n.nm);
	while(i<l)
	{
		printf("%c",n.nm[i]);
		i++;
	}
	printf("(%d)",n.base);
}

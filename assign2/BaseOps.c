#include "smart_calci.h"

int initializeBase(FILE *fptr)
{
	char z;
	int i=0;
	while(!feof(fptr))
    {
    	fscanf(fptr,"%c", &z);
    	if(z!=' ')
    	{
    		task1.c[i]=z;
    		i++;
    	}
    }
    return(i-1);
}

int lookup(char d)
{
	int i=0;
	for(;i<maxbase;i++)
		if(task1.c[i]==d)
		{
			return(i);
			break;
		}
	if(i==maxbase)
	{
		printf("error: not a proper notation");
		exit(0);
	}
}

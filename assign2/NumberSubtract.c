int subtract(int a[], int c[], int e[], int n2, int n1, int b1)
{
	int i=0,j=0;
	while(n2-i>=0)
    {
    	if(c[n1-i-1]>=a[i])
    		e[i]=c[n1-i-1]-a[i];
    	else
    	{
    		e[i]=b1+c[n1-1-i]-a[i];
    		c[n1-i-2]=c[n1-i-2]-1;
    	}
    	i++;
    }
    while(i<n1)
    {
		if(c[i]>=0)
			e[i]=c[n1-i-1];
		else
		{
			e[i]=b1+c[n1-1-i];
    		c[n1-i-2]=c[n1-i-2]-1;
		}
		i++;
    }
    i--;
    if(n2<n1)
    	printf("-");
    print(e,i);

}


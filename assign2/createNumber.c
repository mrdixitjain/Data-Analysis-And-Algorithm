int number(int c[], char c1[])
{
	int i=0,j,l;
    while(c1[i]!=' ')
    	i++;
    i++;
    j=0;
	l=strlen(c1);
    while(i<l)
    {
        c[j]=(int)(c1[i]-'0');
        i++;
        j++;
    }
	return(j);
}

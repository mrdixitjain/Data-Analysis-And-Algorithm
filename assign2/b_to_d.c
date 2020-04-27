int b_to_d(char c[], int base)
{
    int z,j,l,i=0;
    while(c[i]!=' ')
        i++;
    i++;
    l=strlen(c);
    j=0;
    while(l-j>i)
    {
        z=z+(int)(c[l-1-j]-'0')*power(base,j);
        j++;
    }
    return(z);
}

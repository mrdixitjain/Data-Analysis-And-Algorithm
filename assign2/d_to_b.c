int d_to_b(int a[], int z, int base)
{
    int i=0;
    while(z/base!=0)
    {
        a[i]=z%base;
        z=z/base;
        i++;
    }
    a[i]=z;
    return(i);
}

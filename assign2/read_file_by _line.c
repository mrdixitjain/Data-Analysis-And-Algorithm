read_file(FILE *fptr)
{
	char i;
	int a;
	fscanf(fptr, "%c", &i);
	while (!feof (fptr))
	{
		char c[10];
		a=0;
		while(i!='\n')
		{
			c[a]=i;
      		fscanf (fptr, "%c", &i);  
      		a++;   
    	}
    	c[a]='\0';
    	puts(c);
    }
}

void main()
{
	FILE *fptr;
	fptr=fopen("task1.txt","w");
	int i;
	for(i=0;i<50;i++)
	{
		fprintf(fptr, "%c", scanf("%c"));
	}
	fclose(fptr);
	fptr=fopen("task1.txt","r");
	read_file(fptr);
}
    	


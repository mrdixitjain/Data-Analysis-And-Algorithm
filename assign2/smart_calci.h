#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct base
{
	char c[100];
}bas;
bas task1;
int maxbase;

typedef struct number
{
	int base;
	char nm[10];
	int decimal;
}num;

void add(num n1, num n2);
int b_to_d(char c[], int base);
struct number d_to_b(int z, int base);
struct number createNumber(char d[]);
void subtract(num n1, num n2);
int initializeBase(FILE *fptr);
int lookup(char d);
int power(int a, int b);
void print(num n);


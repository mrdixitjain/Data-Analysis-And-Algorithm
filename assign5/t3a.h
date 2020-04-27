#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int index1[100], len[100], l1, l2;

int maxt(int len[], int i);
void longest_seq(char x[], char y[]);
void print_lcs(int len[], int index1[], int max, int l1, int l2, char x[]);

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int l1, l2;

int maxt(int len[][100], int i);
void longest_seq(char x[], char y[], int index1[][100], int len[][100]);
void print_lcs(int len[][100], int index1[][100], int max, int l1, int l2, char x[]);

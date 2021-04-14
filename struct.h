#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bakery{
	char name[40];
	int  weight;
	int price;
}bakery;

void printAll(int a, bakery* array);
void push(int * a, bakery* array);
void del(int * a, bakery* array);
bakery * find1(int a, bakery* array);
bakery * find2(int a, bakery* array);
bakery * find3(int a, bakery* array);

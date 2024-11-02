#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int max = 5;
char arrayBuku[5][50];
int top = 0;

void pushArray(char data[])
{
	if(top >= max)
	{
		printf("Data penuh!!!\n");
	}
	else
	{
		strcpy(arrayBuku[top], data);
		top++;
	}
}

void displayArray()
{
	int i;
	
	printf("Data stack array\n");
	
	for(i = top-1; i >= 0; i--)
	{
		printf("Data : %s\n", arrayBuku[i]);
	}
}

int main()
{
	pushArray("Matematika");
	pushArray("Fisika");
	pushArray("Biologi");
	displayArray();
	
	printf("==================\n");
	
	pushArray("Geografi");
	displayArray();
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DEGREE 5
#define ITEM DEGREE + 1
#define NUMBER 2

typedef struct
{
	int Coefficient[ITEM];
}Polynomial;

bool Add_Polynomial(Polynomial *polynomial, int number, Polynomial *summand);
bool print_Polynomial(Polynomial *polynomial);

int main(void)
{
	Polynomial polynomial[NUMBER], summand;
	memset((void*)polynomial, 0, sizeof(polynomial) * NUMBER);
	memset((void*)&summand, 0, sizeof(summand));

	polynomial[0].Coefficient[4] = 7;
	polynomial[0].Coefficient[2] = 3;
	polynomial[0].Coefficient[0] = 4;

	polynomial[1].Coefficient[5] = 6;
	polynomial[1].Coefficient[4] = 5;
	polynomial[1].Coefficient[2] = 1;
	polynomial[1].Coefficient[1] = 7;
	polynomial[1].Coefficient[0] = 9;

	Add_Polynomial(polynomial, NUMBER, &summand);
	print_Polynomial(&summand);
	return 0;
}

bool Add_Polynomial(Polynomial *polynomial, int number, Polynomial *summand)
{
	if (NULL == polynomial || 0 > number || NULL == summand)
	{
		return false;
	}
	while (0 <= --number)
	{
		for (size_t i = 0; i < ITEM; i++)
		{
			summand->Coefficient[i] += polynomial[number].Coefficient[i];
		}
	}
	return true;
}

bool print_Polynomial(Polynomial *polynomial)
{
	if (NULL == polynomial)
	{
		return false;
	}

	int max = 0;
	for (int i = DEGREE; 0 <= i; i--)
	{
		if (0 != polynomial->Coefficient[i])
		{
			if (0 == max++)
			{
				printf("% dx^%d", polynomial->Coefficient[i], i);
			}
			else if (0 == i)
			{
				printf("%+d", polynomial->Coefficient[i]);
			}
			else
			{
				printf("%+dx^%d", polynomial->Coefficient[i], i);
			}
		}
	}
	return true;
}
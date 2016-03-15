#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	unsigned long long *pPrime = NULL;
	unsigned long long trial = 0;
	int count = 0;
	int total = 0;
	printf("How many primes do you want?(At least 4 )\n");
	scanf("%d", &total);
	total = total < 4 ? 4 : total;
	pPrime = (unsigned long long *)malloc(total * sizeof(unsigned long long));
	*pPrime = 2ULL;
	*(pPrime + 1) = 3ULL;
	*(pPrime + 2) = 5ULL;
	count = 3;
	trial = 5;
	bool found = false;
	while (count < total)
	{
		trial += 2ULL;

		for (int i = 1; i < count; ++i)
		{
			if (!(found = (trial % *(pPrime + i))))
				break;
		}
		if (found)
			*(pPrime + count++) = trial;
	}

	for (int i = 0; i < total; ++i)
	{
		printf("%12llu", *(pPrime + i));
		if (!((i + 1) % 5))
			printf("\n");
	}
		printf("\n");
		free(pPrime);
		pPrime = NULL;
		return 0;
}

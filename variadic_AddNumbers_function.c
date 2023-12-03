#include <stdarg.h>
#include <stdio.h>

int	AddNumbers(int n, ...)
{
	int sum;
	int i;
	va_list ptr;
	va_start(ptr, n);

	sum = 0;
	i = 0;
	while(i < n)
	{
		sum += va_arg(ptr, int);
		i++;
	}
	va_end(ptr);

	return (sum);
}

int main(void)
{
	printf("\n Variadic functions: \n");
	printf("\n 1 + 2 = %d ", AddNumbers(2, 1, 2));
	printf("\n 3 + 4 + 5 = %d ", AddNumbers(3, 3, 4, 5));
	printf("\n 6 + 7 + 8 + 9 = %d ", AddNumbers(4, 6, 7, 8, 9));
	printf("\n\n");
	return (0);
}

#include <stdarg.h>
#include <stdio.h>

float	average(int n, ...);

int main(void)
{
	float average_age;
	int n;

	n = 5;
	// average is a function that we will define using variadic functions
	// This 'n(5)' is a flag
	// All the others inputs are the actual arguments
	average_age = average(n, 18, 45, 32, 100, 7);
	printf("The average age of those %d people is: %f\n", n, average_age);
	return (0);
}

float	average(int n, ...)
{
	// ap stands for argument pointer(is the standard)
	// ap is pointing to the first argument, which in this case is n
	va_list ap;
	float total;
	int i;

	// va_start is a macro which is inside the standard argument header
	// as input we give 'ap', the argument pointer, and the first argument which is 'n'
	// we are shifting one position our argument pointer
	// we want to skip the 'n', because the 'n' is not a normal argument
	// 'n' indeed is a signaling argument 
	// with this 'n' we want to say how many arguments are gonna be there
	va_start(ap, n);
	total  = 0;
	i = 0;
	while (i < n)
	{
		// va_arg is a special macro
		// va_arg is a function to fetch the next argument
		total+= va_arg(ap, int);
		i++;
	}
	return ((float)total / n);
}



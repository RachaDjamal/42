#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	char *test = "Hello les copains\n";
	char test1 = 'R';
	int		test2 = -2147483648;
//	unsigned int test3 = -255;


	printf("resultat True : %d\n", printf("True Printf = %.3s %c %.10d %.10x %.10X %.10u %p\n", test, test1, test2, test2, test2, test2, test));
	ft_printf("resultat Mine : %d\n", ft_printf("Mine Printf = %.3s %c %.10d %.10x %.10X %.10u %p\n", test, test1, test2, test2, test2, test2, test));
}
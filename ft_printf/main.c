#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	char *test = "Salut les petits salauds";
	char test1 = 'A';
	int		test2 = INT_MAX;
	unsigned int test3 = UINT_MAX;


	printf("resultat True : %d\n", printf("True Printf = %--.14s %c %.12d %.10x %.5X %.10u %p %.%\n", test, test1, test2, test2, test3, test3, test));
	ft_printf("resultat Mine : %d\n", ft_printf("Mine Printf = %--.14s %c %.12d %.10x %.5X %.10u %p %.%\n", test, test1, test2, test2, test3, test3, test));

	
}
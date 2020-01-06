#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	char *test = "Sucepute\n";
	char test1 = 0;
	int		test2 = -1000;
//	unsigned int test3 = -255;


	printf("resultat True : %d\n", printf("True Printf = |%c| %d %.20x %X %.155u %p\n", test1, test2, test2, test2, test2, test));
	ft_printf("resultat Mine : %d\n", ft_printf("Mine Printf = |%c| %d %.20x %X %.155u %p\n", test1, test2, test2, test2, test2, test));
}
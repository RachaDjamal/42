#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	char *test = "";
	char *testdup;
	char test1 = 'A';
	int		test2 = -10;
	unsigned int test3 = UINT_MAX;

	testdup = ft_strdup(test);
	printf("resultat True : %d\n", printf("True Printf = |%s| |%c| |%-12.4d| |%.10x| |%.X| |%.0u| |%p| |%-12.%|\n", "", test1, test2, test3, test3, test3, test));
	ft_printf("resultat Mine : %d\n", ft_printf("Mine Printf = |%s| |%c| |%-12.4d| |%.10x| |%.X| |%.0u| |%p| |%-12.%|\n", "", test1, test2, test3, test3, test3, test));

	printf("resultat True : %d\n", printf("True Printf = %-*.*d\n", -4, 7, 1230));
	ft_printf("resultat Mine : %d\n", ft_printf("Mine Printf = %-*.*d\n", -4, 7, 1230));

	printf("resultat True : %d\n", printf("True Printf = |%s|\n", testdup));
	ft_printf("resultat Mine : %d\n", ft_printf("Mine Printf = |%s|\n", testdup));
}
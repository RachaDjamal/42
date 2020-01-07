#include "libft.h"

int		ft_isdigit_w0(int c)
{
	if (c > 48 && c < 58)
		return (1);
	else
		return (0);
}

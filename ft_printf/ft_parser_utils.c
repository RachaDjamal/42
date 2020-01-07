#include "ft_printf.h"

int		ft_is_type(const char to_parse)
{
	int		i;

	i = 0;
	while (PF_TYPES[i])
	{
		if (PF_TYPES[i] == to_parse)
			return (1);
		i++;
	}
	return (0);
}

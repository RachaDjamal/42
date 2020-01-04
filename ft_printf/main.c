#include "ft_printf.h"

t_printf	*setup_struct(void)
{
	t_printf	*setup;

	if (!(setup = malloc(sizeof(t_printf))))
		return (NULL);
	setup->type = '\0';
	setup->width = 0;
	setup->accuracy = 0;
	setup->result = 0;
	return (setup);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	*pf;
	int			i;

	if (!(pf = setup_struct()))
		return (-1);
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_parser(format + i + 1, pf);
		else
			pf->result += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	free(pf);
	printf("\nType = %c\n", pf->type);
	return (pf->result);
}
int		main(void)
{
	printf("%d", ft_printf("0123456789 %p"));
}

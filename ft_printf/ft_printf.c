/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 10:22:23 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 10:22:27 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*ft_reset_struct(t_printf **pf)
{
	t_printf	*setup;

	if (!(setup = malloc(sizeof(t_printf))))
		return (NULL);
	setup = *pf;
	setup->type = '\0';
	setup->flagzero = 0;
	setup->flagminus = 0;
	setup->width = 0;
	setup->accuracy = 1;
	setup->point = 0;
	return (setup);
}

t_printf	*ft_setup_struct(void)
{
	t_printf	*setup;

	if (!(setup = malloc(sizeof(t_printf))))
		return (NULL);
	setup->type = '\0';
	setup->flagzero = 0;
	setup->flagminus = 0;
	setup->width = 0;
	setup->accuracy = 1;
	setup->point = 0;
	setup->result = 0;
	return (setup);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	*pf;
	int			i;
	int			res;

	if (!(pf = ft_setup_struct()))
		return (-1);
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += ft_parser(format + i + 1, pf, ap);
		}
		else
			pf->result += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	res = pf->result;
	free(pf);
	return (res);
}

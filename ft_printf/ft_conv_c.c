/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_conv_c.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 13:24:30 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 13:24:32 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_conv_pcent(t_printf *pf, va_list ap)
{
	char c;

	c = (const char)va_arg(ap, int);
	pf->result += write(1, "%", 1);
}

void		ft_conv_ptr(t_printf *pf, va_list ap)
{
	unsigned long long int	ptr;
	char					*res;
	int						i;

	ptr = (unsigned long long int)va_arg(ap, void *);
	if (!(res = ft_lltoa_base(ptr, "0123456789abcdef")))
		return ;
	i = 0;
	pf->result += write(1, "0x", 2);
	while (res[i])
	{
		pf->result += write(1, &res[i], 1);
		i++;
	}
	free(res);
}

void		ft_conv_str(t_printf *pf, va_list ap)
{
	char	*str;
	int		i;
	char	*arg;

	arg = va_arg(ap, char *);
	if (!(arg))
	{
		if (!(str = ft_strdup("(null)")))
			return ;
	}
	else if (!(str = ft_strdup(arg)))
		return ;
	i = 0;
	while (str[i])
	{
		pf->result += write(1, &str[i], 1);
		i++;
	}
}

void		ft_conv_c(t_printf *pf, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	pf->result += write(1, &c, 1);
}

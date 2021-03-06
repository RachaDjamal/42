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
	int		i;
	char	flag;

	i = 0;
	ap = 0;
	if (pf->width > 1)
	{
		flag = pf->flagzero == 0 ? ' ' : '0';
		if (pf->flagminus == 0)
		{
			while (i++ < (pf->width - 1))
				pf->result += write(1, &flag, 1);
		}
	}
	pf->result += write(1, "%", 1);
	if (pf->width > 1)
	{
		if (pf->flagminus == 1)
		{
			while (i++ < pf->width - 1)
				pf->result += write(1, " ", 1);
		}
	}
}

void		ft_conv_ptr(t_printf *pf, va_list ap)
{
	unsigned long int		ptr;
	char					*res;
	int						width;

	ptr = (unsigned long long int)va_arg(ap, void *);
	if (!ptr && pf->point == 1 && pf->width != 0)
	{
		width = pf->width;
		while (--width > 1 && pf->flagminus == 0)
			pf->result += write(1, " ", 1);
		pf->result += write(1, "0x", 2);
		while (--width >= 1 && pf->flagminus == 1)
			pf->result += write(1, " ", 1);
		return ;
	}
	if (!(res = ft_ulltoa_base(ptr, "0123456789abcdef")))
		return ;
	ft_write_ptr(pf, res, ptr);
}

void		ft_conv_str(t_printf *pf, va_list ap)
{
	char	*str;
	char	*arg;
	int		i;

	i = 0;
	if (ft_accu_null(pf) == 1)
		return ;
	arg = va_arg(ap, char *);
	if (!(arg))
	{
		if (!(str = ft_strdup("(null)")))
			return ;
	}
	else if (!(str = ft_strdup(arg)))
		return ;
	if (!str[i] && pf->width == 0)
	{
		free(str);
		return ;
	}
	if (pf->point == 1 && pf->accuracy == 1 && pf->flagwild == 1)
		pf->accuracy = ft_strlen(str);
	ft_write_conv_str(pf, str);
	free(str);
}

void		ft_conv_c(t_printf *pf, va_list ap)
{
	char	c;
	int		i;

	c = va_arg(ap, int);
	i = 0;
	if (pf->width > 1)
	{
		if (pf->flagminus == 0)
			while (i++ < (pf->width - 1))
				pf->result += write(1, " ", 1);
	}
	pf->result += write(1, &c, 1);
	if (pf->width > 1)
	{
		if (pf->flagminus == 1)
			while (i++ < (pf->width - 1))
				pf->result += write(1, " ", 1);
	}
}

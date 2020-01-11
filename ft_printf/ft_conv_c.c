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
	int						i;
	int						width;

	ptr = (unsigned long int)va_arg(ap, void *);
	if (!(res = ft_lltoa_base(ptr, "0123456789abcdef")))
		return ;
	i = 0;
	width = pf->width - ft_strlen(res);
	while (--width > 1 && pf->flagminus == 0)
		pf->result += write(1, " ", 1);
	pf->result += write(1, "0x", 2);
	if (pf->accuracy == 0 && ptr == 0)
	{
		free(res);
		return ;
	}
	while (res[i])
		pf->result += write(1, &res[i++], 1);
	while (--width >= 1 && pf->flagminus == 1)
		pf->result += write(1, " ", 1);
	free(res);
}

void		ft_conv_str(t_printf *pf, va_list ap)
{
	char	*str;
	int		i;
	int		accu;
	char	*arg;

	arg = va_arg(ap, char *);
	if (!(arg))
	{
		if (!(str = ft_strdup("(null)")))
			return ;
	}
	else if (!(str = ft_strdup(arg)))
		return ;
	accu = pf->point == 0 ? (int)ft_strlen(str) : pf->accuracy;
	i = accu == 0 ? pf->width : pf->width - ft_strlen(str);
	while (--i >= 0 && pf->flagminus == 0)
		pf->result += write(1, " ", 1);
	i = 0;
	while (str[i] && i < accu)
		pf->result += write(1, &str[i++], 1);
	i = accu == 0 ? pf->width : pf->width - ft_strlen(str);
	while (--i >= 0 && pf->flagminus == 1)
		pf->result += write(1, " ", 1);
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

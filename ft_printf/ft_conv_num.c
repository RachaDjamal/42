/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_conv_num.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 12:38:58 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 12:39:00 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_conv_bx(t_printf *pf, va_list ap)
{
	char	*res;
	int		i;

	if (!(res = ft_lltoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF")))
		return ;
	i = 0;
	if (res[i] == '0' && pf->accuracy == 0)
	{
		while (pf->width-- > 0)
			pf->result += write(1, " ", 1);
		free(res);
		return ;
	}
	if (pf->flagzero == 1 && pf->point == 1)
		pf->flagzero = 0;
	ft_write_conv_x(pf, res, i);
	free(res);
}

void		ft_conv_x(t_printf *pf, va_list ap)
{
	char	*res;
	int		i;

	if (!(res = ft_lltoa_base(va_arg(ap, unsigned int), "0123456789abcdef")))
		return ;
	i = 0;
	if (res[i] == '0' && pf->accuracy == 0)
	{
		while (pf->width-- > 0)
			pf->result += write(1, " ", 1);
		free(res);
		return ;
	}
	if (pf->flagzero == 1 && pf->point == 1)
		pf->flagzero = 0;
	ft_write_conv_x(pf, res, i);
	free(res);
}

void		ft_conv_u(t_printf *pf, va_list ap)
{
	char	*res;
	int		i;

	if (!(res = ft_lltoa_base(va_arg(ap, unsigned int), "0123456789")))
		return ;
	i = 0;
	if (res[i] == '0' && pf->accuracy == 0)
	{
		while (pf->width-- > 0)
			pf->result += write(1, " ", 1);
		free(res);
		return ;
	}
	if (pf->flagzero == 1 && pf->point == 1)
		pf->flagzero = 0;
	ft_write_conv_u(pf, res, i);
	free(res);
}

void		ft_conv_d(t_printf *pf, va_list ap)
{
	char	*res;
	int		i;
	int		arg;

	arg = va_arg(ap, int);
	if (!(res = ft_itoa(arg)))
		return ;
	i = 0;
	if (arg == 0 && pf->accuracy == 0)
	{
		while (pf->width-- > 0)
			pf->result += write(1, " ", 1);
		free(res);
		return ;
	}
	if (pf->flagzero == 1 && pf->point == 1)
		pf->flagzero = 0;
	ft_write_conv_d(pf, res, i, arg);
	free(res);
}

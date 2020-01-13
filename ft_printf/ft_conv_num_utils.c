/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_conv_num_utils.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 16:49:09 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 16:54:42 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_conv_x(t_printf *pf, char *res, int i)
{
	int		len;
	int		j;
	char	flag;

	len = (int)ft_strlen(res);
	j = pf->accuracy > len ? pf->accuracy : len;
	flag = (pf->flagminus == 0 && pf->flagzero == 1) ? '0' : ' ';
	while (pf->flagminus == 0 && pf->width-- > j)
		pf->result += write(1, &flag, 1);
	if (pf->accuracy <= len)
		while (res[i])
			pf->result += write(1, &res[i++], 1);
	else if (pf->accuracy > len)
		while (len++ < pf->accuracy)
			pf->result += write(1, "0", 1);
	while (res[i])
		pf->result += write(1, &res[i++], 1);
	while (pf->flagminus == 1 && pf->width-- > j)
		pf->result += write(1, " ", 1);
}

void		ft_write_conv_u(t_printf *pf, char *res, int i)
{
	int		len;
	int		j;
	char	flag;

	len = (int)ft_strlen(res);
	j = pf->accuracy > len ? pf->accuracy : len;
	flag = (pf->flagminus == 0 && pf->flagzero == 1) ? '0' : ' ';
	while (pf->flagminus == 0 && pf->width-- > j)
		pf->result += write(1, &flag, 1);
	if (pf->accuracy <= len)
		while (res[i])
			pf->result += write(1, &res[i++], 1);
	else if (pf->accuracy > len)
		while (len++ < pf->accuracy)
			pf->result += write(1, "0", 1);
	while (res[i])
		pf->result += write(1, &res[i++], 1);
	while (pf->flagminus == 1 && pf->width-- > j)
		pf->result += write(1, " ", 1);
}

void		ft_write_conv_d(t_printf *pf, char *res, int i, int arg)
{
	int		j;
	int		len;
	int		neg;

	len = ft_strlen(res);
	neg = arg < 0 ? 1 : 0;
	j = pf->accuracy > len - neg ? pf->accuracy + neg : len;
	while (pf->flagzero == 0 && pf->flagminus == 0 && pf->width-- > j)
		pf->result += write(1, " ", 1);
	if (arg < 0 && len--)
		pf->result += write(1, &res[i++], 1);
	while (pf->flagzero == 1 && pf->flagminus == 0 && pf->width-- > j)
		pf->result += write(1, "0", 1);
	if (pf->accuracy <= len)
		while (res[i])
			pf->result += write(1, &res[i++], 1);
	else if (pf->accuracy > len)
		while (len++ < pf->accuracy)
			pf->result += write(1, "0", 1);
	while (res[i])
		pf->result += write(1, &res[i++], 1);
	while (pf->flagminus == 1 && pf->width-- > j)
		pf->result += write(1, " ", 1);
}

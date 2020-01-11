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

void		ft_write_conv_d(t_printf *pf, char *res, int i, int arg)
{
	int		j;
	int		len;
	int		neg;

	len = ft_strlen(res);
	neg = arg < 0 ? 1 : 0;
	j = pf->accuracy > len - neg ? pf->accuracy + neg : len;
	while (pf->flagminus == 0 && pf->width-- > j)
		pf->result += write(1, " ", 1);
	if (arg < 0)
	{
		pf->result += write(1, &res[i++], 1);
		len--;
	}
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

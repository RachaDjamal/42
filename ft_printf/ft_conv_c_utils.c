/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_conv_c_utils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 12:39:10 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 12:39:12 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_accu_null(t_printf *pf)
{
	if (pf->point == 1 && pf->accuracy == 0 && pf->flagwild == 0)
	{
		while (pf->width-- > 0)
			pf->result += write(1, " ", 1);
		return (1);
	}
	return (0);
}

void		ft_write_conv_str(t_printf *pf, char *str)
{
	int		i;
	int		j;
	int		accu;
	int		len;

	j = 0;
	len = ft_strlen(str);
	accu = pf->point == 0 ? len : pf->accuracy;
	accu = accu > len ? len : accu;
	if (pf->width != 0)
	{
		i = (accu == 0 && len > accu) ? pf->width : pf->width - (len +
		(accu - len));
		if (i <= 0 && pf->point == 1 && accu > len)
			i = 1;
	}
	else
		i = (accu == 0 || len > accu) ? 0 : len - accu;
	while (i-- > 0 && pf->flagminus == 0)
		pf->result += write(1, " ", 1);
	while (str[j] && j < accu)
		pf->result += write(1, &str[j++], 1);
	i = accu == 0 ? pf->width : pf->width - (len - (len - accu));
	while (i-- > 0 && pf->flagminus == 1)
		pf->result += write(1, " ", 1);
}

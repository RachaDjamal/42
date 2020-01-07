/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 13:54:35 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 13:54:38 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_manager(t_printf *pf, va_list ap, char type)
{
	if (type == 'd' || type == 'i')
		ft_conv_d(pf, ap);
	else if (type == 'x')
		ft_conv_x(pf, ap);
	else if (type == 'X')
		ft_conv_bx(pf, ap);
	else if (type == 'u')
		ft_conv_u(pf, ap);
	else if (type == 'c')
		ft_conv_c(pf, ap);
	else if (type == 's')
		ft_conv_str(pf, ap);
	else if (type == 'p')
		ft_conv_ptr(pf, ap);
	else if (type == '%')
		ft_conv_pcent(pf, ap);
}

int		ft_accu_manager(const char *to_parse, t_printf *pf,
va_list ap, int index)
{
	char *accu;

	ap = 0;
	pf->point++;
	index++;
	if (ft_is_type(to_parse[index]) == 1)
	{
		pf->accuracy = 0;
		return (index);
	}
	if (!(accu = (char *)ft_calloc(sizeof(char), 1)))
		return (-1);
	while (ft_is_type(to_parse[index]) == 0)
	{
		accu = ft_strjoin_free(to_parse[index], accu);
		index++;
	}
	pf->accuracy = ft_atoi(accu);
	free(accu);
	return (index);
}

int		ft_flags_manager(const char *to_parse, t_printf *pf,
va_list ap, int index)
{
	ap = 0;
	while (to_parse[index] == '-' || to_parse[index] == '0')
	{
		if (to_parse[index] == '0')
			pf->flagzero = 1;
		else if (to_parse[index] == '-')
			pf->flagminus = 1;
		index++;
	}
	return (index);
}

int		ft_width_manager(const char *to_parse, t_printf *pf,
va_list ap, int index)
{
	char	*res;

	ap = 0;
	if (!(res = (char *)ft_calloc(sizeof(char), 1)))
		return (-1);
	while (ft_isdigit(to_parse[index]) == 1)
	{
		res = ft_strjoin_free(to_parse[index], res);
		index++;
	}
	pf->width = ft_atoi(res);
	free(res);
	return (index);
}

int		ft_parser(const char *to_parse, t_printf *pf, va_list ap)
{
	int i;
	t_printf	*pfn;

	i = 0;
	while (to_parse[i])
	{
		if (to_parse[i] == '-' || to_parse[i] == '0')
			i = ft_flags_manager(to_parse, pf, ap, i);
		if ((ft_isdigit_w0(to_parse[i])) == 1)
			i = ft_width_manager(to_parse, pf, ap, i);
		if (to_parse[i] == '.')
			i = ft_accu_manager(to_parse, pf, ap, i);
		if (ft_is_type(to_parse[i]) == 1)
		{
			ft_conv_manager(pf, ap, (pf->type = to_parse[i]));
			pfn = ft_reset_struct(&pf);
			return (++i);
		}
		i++;
	}
	return (i);
}

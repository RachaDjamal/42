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

int		ft_is_type(const char to_parse)
{
	int i;

	i = 0;
	while (PF_TYPES[i])
	{
		if (PF_TYPES[i] == to_parse)
			return (1);
		i++;
	}
	return (0);
}

void	ft_parser(const char *to_parse, t_printf *pf)
{
	int i;

	i = 0;
	while (to_parse[i])
	{
		if (ft_is_type(to_parse[i]) == 1)
			pf->type = to_parse[i];
		i++;
	}
}

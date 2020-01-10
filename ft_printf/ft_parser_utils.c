/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser_utils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 10:41:35 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 10:41:38 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_type(const char to_parse)
{
	int		i;

	i = 0;
	while (PF_TYPES[i])
	{
		if (PF_TYPES[i] == to_parse)
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 15:27:19 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 15:27:23 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_base(char *baseset)
{
	int	i;
	int	j;

	i = 0;
	while (baseset[i])
	{
		j = i + 1;
		while (baseset[j++])
		{
			if (baseset[i] == baseset[j])
				return (-1);
		}
		i++;
	}
	return (i);
}

char	*ft_lltoa_base(long long n, char *baseset)
{
	static char		buf[66] = {0};
	int				i;
	int				neg;
	long long		base;

	i = 63;
	base = ft_check_base(baseset);
	neg = (n < 0 ? -1 : 1);
	n = n < 0 ? -n : n;
	while (1)
	{
		buf[i--] = baseset[n % base];
		n /= base;
		if (n == 0)
			break ;
	}
	if (neg == -1)
		buf[i] = '-';
	return (neg == -1 ? ft_strdup(buf + i) : ft_strdup(buf + 1 + i));
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulltoa_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 17:19:48 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 17:19:50 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long int n, char *baseset)
{
	static char				buf[66] = {0};
	int						i;
	unsigned long long int	base;

	i = 63;
	base = 16;
	while (1)
	{
		buf[i--] = baseset[n % base];
		n /= base;
		if (n == 0)
			break ;
	}
	return (ft_strdup(buf + 1 + i));
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 13:58:52 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 11:31:30 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!(dst) && !(src))
		return (NULL);
	if (dst < src)
	{
		while (i < (int)len)
		{
			d[i] = s[i];
			i++;
		}
		return (d);
	}
	i = len - 1;
	while (i >= 0)
	{
		d[i] = s[i];
		i--;
	}
	return (d);
}

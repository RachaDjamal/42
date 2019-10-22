/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 12:20:27 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 10:20:34 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*src2;

	i = 0;
	if (src == NULL && dst == NULL && n != 0)
		return (NULL);
	str = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (i < n)
	{
		str[i] = src2[i];
		i++;
	}
	return (dst);
}

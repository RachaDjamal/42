/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 13:58:52 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 12:57:23 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	temp[len];

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst == NULL && src == NULL && len != 0)
		return (NULL);
	while (i < len)
	{
		temp[i] = src2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst2[i] = temp[i];
		i++;
	}
	return (dst2);
}

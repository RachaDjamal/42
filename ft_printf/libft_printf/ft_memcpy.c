/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 12:20:27 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 12:08:56 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*str;
	char			*src2;

	i = 0;
	str = (char *)dst;
	src2 = (char *)src;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = src2[i];
		i++;
	}
	return (str);
}

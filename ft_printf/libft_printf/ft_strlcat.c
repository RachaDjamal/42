/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 08:17:08 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 16:43:14 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	len = i + j;
	if (size == 0 && !(dst))
		return (ft_strlen(src));
	if (i < size)
	{
		j = 0;
		while (src[j] && (i + j + 1) < size)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
		return (len);
	}
	return (j + size);
}

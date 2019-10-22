/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 10:19:54 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 10:25:46 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = (char *)haystack;
	if (needle[j] == '\0')
		return (res);
	while (haystack[i] && needle[j])
	{
		while (haystack[i] == needle[j] && i < len)
		{
			if (needle[j + 1] == '\0')
				return (res + (i - j));
			i++;
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

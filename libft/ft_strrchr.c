/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strrchr.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 18:49:08 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 10:23:47 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
		i++;
	if (c == 0)
		return (str + i);
	while (i >= 0)
	{
		if (c == str[i])
			return (str + i);
		i--;
	}
	return (NULL);
}

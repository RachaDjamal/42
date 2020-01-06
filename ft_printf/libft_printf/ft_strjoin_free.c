/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_free.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 16:26:28 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 16:26:30 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char s1, char *s2)
{
	int		i;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 2))))
		return (NULL);
	i = 0;
	while (s2[i])
	{
		res[i] = s2[i];
		i++;
	}
	res[i] = s1;
	res[i + 1] = '\0';
	free(s2);
	return (res);
}

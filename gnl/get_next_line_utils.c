/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 11:11:03 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 11:11:06 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dst;

	i = ft_strlen(s1);
	if (!(dst = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_memchr(char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = s;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i + 1);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!(s1) || !(s2))
		return (ft_strdup("\0"));
	j = 0;
	while (s2[j] && s2[j] != '\n')
		j++;
	if (!(str = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + j + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

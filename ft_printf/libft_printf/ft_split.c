/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 10:07:33 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/01 16:03:58 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i + 1])
				i++;
			words++;
		}
		i++;
	}
	return (words);
}

int		ft_le(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		len++;
	}
	return (len);
}

int		ft_sep(const char *s, char c, int k)
{
	while (s[k] == c)
		k++;
	return (k);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = -1;
	k = 0;
	if (!(s))
		return (ft_calloc(1, sizeof(char *)));
	if (!(res = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	k = ft_sep(s, c, k);
	while (++i < ft_countwords(s, c))
	{
		if (!(res[i] = (char *)malloc(sizeof(char) * (ft_le(s, c, k) + 1))))
			return (NULL);
		j = 0;
		while (s[k] && s[k] != c)
			res[i][j++] = s[k++];
		res[i][j] = '\0';
		k = ft_sep(s, c, k);
	}
	res[i] = NULL;
	return (res);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 10:10:16 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 17:56:32 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countfirstsep(char const *s1, char const *set)
{
	int		count;
	int		stop;
	int		i;
	int		j;

	i = -1;
	j = -1;
	stop = i + 1;
	count = 0;
	while (s1[++i] && count == 0)
	{
		while (set[++j])
		{
			if (s1[i] == set[j])
			{
				count++;
				i++;
				j = -1;
			}
		}
		if (stop == i)
			return (count);
		j = 0;
	}
	return (count);
}

int		ft_countlastsep(const char *s1, const char *set)
{
	int		count;
	int		i;
	int		j;
	int		stop;

	i = ft_strlen(s1);
	stop = i - 1;
	j = -1;
	count = 0;
	while (--i != 0 && count == 0)
	{
		while (set[++j])
		{
			if (s1[i] == set[j])
			{
				count++;
				i--;
				j = -1;
			}
		}
		if (stop == i)
			return (count);
		j = 0;
	}
	return (count);
}

char	*ft_mallocgoodsize(char const *s1, char const *set)
{
	int		firstsep;
	int		lastsep;
	int		len;
	int		goodlen;
	char	*res;

	firstsep = ft_countfirstsep(s1, set);
	lastsep = ft_countlastsep(s1, set);
	len = ft_strlen(s1);
	goodlen = len - firstsep - lastsep;
	if (goodlen <= 0)
		return ("\0");
	if (!(res = (char *)malloc(sizeof(char) * (goodlen + 1))))
		return (NULL);
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		first;
	int		i;
	int		goodlen;

	first = ft_countfirstsep(s1, set);
	goodlen = ft_strlen(s1) -
		ft_countfirstsep(s1, set) - ft_countlastsep(s1, set);
	if (goodlen <= 0)
		return ("\0");
	res = ft_mallocgoodsize(s1, set);
	if (!res)
		return (NULL);
	i = 0;
	while (i < goodlen)
	{
		res[i] = s1[first];
		i++;
		first++;
	}
	res[i] = '\0';
	return (res);
}

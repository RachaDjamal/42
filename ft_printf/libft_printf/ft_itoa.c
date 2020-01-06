/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 09:51:51 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 10:21:06 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_len(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb == 0)
	{
		len = 1;
		return (len);
	}
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_swap(char *s)
{
	int		i;
	int		size;
	char	temp;

	size = 0;
	while (s[size])
		size++;
	i = 0;
	while (i < (size / 2))
	{
		temp = s[size - i - 1];
		s[size - i - 1] = s[i];
		s[i] = temp;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	long	save;
	char	*res;

	i = 0;
	save = n;
	len = ft_len(n);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
		save = -save;
	while (save > 0)
	{
		res[i++] = save % 10 + '0';
		save = save / 10;
	}
	if (n < 0)
		res[i++] = '-';
	if (n == 0)
		res[i++] = '0';
	res[i] = '\0';
	res = ft_swap(res);
	return (res);
}

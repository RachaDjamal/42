/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 10:29:19 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 10:43:54 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_scan(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_init_check(int fd, char buf[BUFFER_SIZE + 1],
		char **tampon, char **line)
{
	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, &buf, 0) == -1))
		return (NULL);
	if (!(*tampon))
		if (!(*tampon = ft_strdup("")))
			return (NULL);
	if (!(*line = ft_strdup("")))
		return (NULL);
	buf[0] = '\0';
	return (*tampon);
}

int		ft_end_read(char **temp, char **tampon, char buf[BUFFER_SIZE + 1])
{
	if (ft_scan(buf) == 1)
	{
		*temp = *tampon;
		if (!(*tampon = ft_strdup(ft_memchr(buf, '\n'))))
			return (-1);
		free(*temp);
		return (1);
	}
	else
	{
		free(*tampon);
		*tampon = NULL;
		return (0);
	}
}

int		ft_static_save(char **tampon, char **temp)
{
	if (ft_scan(*tampon) == 1)
	{
		*temp = *tampon;
		if (!(*tampon = ft_strdup(ft_memchr(*tampon, '\n'))))
			return (-1);
		free(*temp);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*tampon;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	int			res;
	int			err;

	if (!(ft_init_check(fd, buf, &tampon, line)) ||
	!(*line = ft_strjoin_free(*line, tampon)))
		return (-1);
	if ((err = ft_static_save(&tampon, &temp)) != 0)
		return (err);
	while (!(ft_scan(buf) == 1))
	{
		res = read(fd, &buf, BUFFER_SIZE);
		buf[res] = '\0';
		if (!(*line = ft_strjoin_free(*line, buf)))
			return (-1);
		if (res != BUFFER_SIZE)
			return (ft_end_read(&temp, &tampon, buf));
	}
	temp = tampon;
	if (!(tampon = ft_strdup(ft_memchr(buf, '\n'))))
		return (-1);
	free(temp);
	return (1);
}

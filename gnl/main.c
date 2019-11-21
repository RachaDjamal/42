/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 14:05:35 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 14:07:02 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		i;
	int		ret;
	int		fd;
	char	*line;

	i = 1;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			printf("%d error", ret);
			return (0);
		}
		printf("(%d) %d - ", i, ret);
		printf("%s\n", line);
		free(line);
		i++;
	}
	printf("(%d) %d - ", i, ret);
	printf("%s\n", line);
	free(line);
	printf("Lignes lues = %d\n", i);
	return (0);
}

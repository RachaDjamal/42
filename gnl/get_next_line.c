/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 10:29:19 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 14:03:58 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_scan(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if(line[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char        *ft_init_check(int fd, char buf[BUFFER_SIZE + 1], char **tampon, char **line)
{
    if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, &buf, 0) == -1))
        return (NULL);
    if (!(*tampon))
        *tampon = ft_strdup("");
    *line = ft_strdup("");
    buf[0] = '\0';
    return (*tampon);
}

int     ft_end_read(char **temp, char **tampon, char buf[BUFFER_SIZE + 1])
{
    if (ft_scan(buf) == 1)
    {
        *temp = *tampon;
        *tampon = ft_strdup(ft_memchr(buf, '\n'));
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


int		get_next_line(int fd, char **line)
{
    static char *tampon;
    char        *temp;
    char        buf[BUFFER_SIZE + 1];
    int         res;

    if(!(ft_init_check(fd, buf, &tampon, &*line)))
        return (-1);
    if (ft_scan(tampon) == 1)
    {
        *line = ft_strjoin_free(*line, tampon);
        temp = tampon;
        tampon = ft_strdup(ft_memchr(tampon,'\n'));
        free(temp);
        return (1);
    }
    if (ft_scan(tampon) == 0)
        *line = ft_strjoin_free(*line, tampon);
    while (!(ft_scan(buf) == 1))
    {
        res = read(fd, &buf, BUFFER_SIZE);
        buf[res] = '\0';
        *line = ft_strjoin_free(*line, buf);
        if (res != BUFFER_SIZE)
            return(ft_end_read(&temp, &tampon, buf));
    }  
    temp = tampon;
    tampon = ft_strdup(ft_memchr(buf, '\n'));
    free(temp);
    return (1);
}

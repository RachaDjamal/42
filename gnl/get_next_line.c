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

/*char    **ft_init(int fd, int BUFFER_SIZE, char *buf, char **tampon)
{
    if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, &buf, 0) == -1))
        return (NULL);
    if (!(*tampon = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (NULL);
    *tampon[0] = '\0';
    return (tampon);
}*/

int		get_next_line(int fd, char **line)
{
    static char *tampon;
    char        *temp;
    char        buf[BUFFER_SIZE + 1];
    int         res;

    if (!(tampon))
        tampon = ft_strdup("");
    *line = ft_strdup("");
    buf[0] = '\0';
    if (ft_scan(tampon) == 1)
    {
        *line = ft_strjoin_free(*line, tampon);
        temp = tampon;
        tampon = ft_strdup(ft_memchr(tampon,'\n'));
        free(temp);
        return (1);
    }
    if (ft_scan(tampon) == 0)
    {
        *line = ft_strjoin_free(*line, tampon);
    }
    while (!(ft_scan(buf) == 1))
    {
        res = read(fd, &buf, BUFFER_SIZE);
        buf[res] = '\0';
        *line = ft_strjoin_free(*line, buf);
        if (res != BUFFER_SIZE)
        {
            if (ft_scan(buf) == 1)
           {
                temp = tampon;
                tampon = ft_strdup(ft_memchr(buf, '\n'));
                free(temp);
                return (1);
            }
            else
            {
                free(tampon);
                tampon = NULL;
                return (0);
            }
        }
    }  
    temp = tampon;
    tampon = ft_strdup(ft_memchr(buf, '\n'));
    free(temp);
    return (1);
}


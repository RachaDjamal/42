/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 11:11:14 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 11:11:15 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int     ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_memchr(char *s, int c);
char	*ft_strjoin_free(char *s1, char *s2);
int		get_next_line(int fd, char **line);

#endif
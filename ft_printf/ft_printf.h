/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 19:00:10 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 19:00:48 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft_printf/libft.h"
# define PF_TYPES = "cspdiuxX"

typedef struct	s_printf
{
	char type;
	int width;
	int accuracy;
	int result;
} 				t_printf;
t_printf		*setup_struct(void);
int				ft_check_base(char *baseset);
char			*ft_lltoa_base(long long n, char *baseset);
void			ft_parser(const char *to_parse, t_printf *pf);
int				ft_is_type(const char to_parse);
int				ft_printf(const char *format, ...);

#endif

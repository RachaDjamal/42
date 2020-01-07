/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 12:11:18 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 12:11:22 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft_printf/libft.h"
# define PF_TYPES "cspdiuxX%"

typedef struct		s_printf
{
	char	type;
	int		flagzero;
	int		flagminus;
	int		width;
	int		accuracy;
	int		point;
	int		result;
}					t_printf;
t_printf			*ft_setup_struct(void);
t_printf			*ft_reset_struct(t_printf **pf);
int					ft_is_type(const char to_parse);
int					ft_accu_manager(const char *to_parse, t_printf *pf,
va_list ap, int index);
void				ft_conv_manager(t_printf *pf, va_list ap, char type);
void				ft_conv_d(t_printf *pf, va_list ap);
void				ft_conv_u(t_printf *pf, va_list ap);
void				ft_conv_x(t_printf *pf, va_list ap);
void				ft_conv_bx(t_printf *pf, va_list ap);
void				ft_conv_c(t_printf *pf, va_list ap);
void				ft_conv_str(t_printf *pf, va_list ap);
void				ft_conv_ptr(t_printf *pf, va_list ap);
void				ft_conv_pcent(t_printf *pf, va_list ap);
int					ft_parser(const char *to_parse, t_printf *pf, va_list ap);
int					ft_printf(const char *format, ...);

#endif

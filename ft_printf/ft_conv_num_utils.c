#include "ft_printf.h"

void        ft_write_conv_d(t_printf *pf, char *res, int i, int len)
{
    char    flag;
    int     j;

	len += (int)ft_strlen(res);
    j = 0;
    flag = ' ';
    while (pf->flagminus == 0 && pf->width > len + j++)
        pf->result += write(1, &flag, 1);
	if (pf->accuracy <= len)
	{
		while (res[i])
			pf->result += write(1, &res[i++], 1);
	}
	else if (pf->accuracy > len)
	{
		while (len++ < pf->accuracy)
			pf->result += write(1, "0", 1);
		while (res[i])
			pf->result += write(1, &res[i++], 1);
	}
    while (pf->flagminus == 1 && pf->width > len + j++)
        pf->result += write(1, &flag, 1);
}
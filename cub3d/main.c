/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:06:55 by smallet           #+#    #+#             */
/*   Updated: 2020/02/24 13:02:39 by smallet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_key_manager(int key, t_cub3d *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		free(param);
		exit(EXIT_SUCCESS);
		return (1);
	}
	return (0);
}

t_cub3d	*ft_setup_struc(void)
{
	t_cub3d		*setup;
	if (!(setup = malloc(sizeof(t_cub3d))))
		return (NULL);
	setup->mlx_ptr = NULL;
	setup->win_ptr = NULL;
	return (setup);
}

int		main(void)
{
	t_cub3d	*mlx_struc;
	int		x;
	int		y;

	if (!(mlx_struc = ft_setup_struc()))
		return (-1);
	mlx_struc->mlx_ptr = mlx_init();
	mlx_struc->win_ptr = mlx_new_window(mlx_struc->mlx_ptr, 600, 600, "Coucou");
	x = 0;
	y = 0;
	while (y < 601 && x < 601)
	{
		mlx_pixel_put(mlx_struc->mlx_ptr, mlx_struc->win_ptr, x, y, 0xFFFFFF);
		x++;
		y++;
	}
	mlx_key_hook(mlx_struc->win_ptr, ft_key_manager, mlx_struc);
	mlx_loop(mlx_struc->mlx_ptr);
}

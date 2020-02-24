/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:31:29 by smallet           #+#    #+#             */
/*   Updated: 2020/02/24 13:31:32 by smallet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct      s_cub3d
{
    void        *mlx_ptr;
    void        *win_ptr;
}                   t_cub3d;


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:16:09 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 14:19:56 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution_bonus.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	create_image(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	if (!data->img)
		exit_game("Failed to create image", data, -1, 1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		exit_game("Failed to get image address", data, -1, 1);
}

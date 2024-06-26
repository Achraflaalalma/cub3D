/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderwall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:06:33 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 14:08:12 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	render_textures(t_data *data, int rayId)
{
	int		i;

	i = -1;
	while (++i < S_HEIGHT)
	{
		if (i < data->walltop_pixel)
			my_mlx_pixel_put(data, rayId, i,
				rgb_to_int(data->ceiling_color_rgb));
		else if (i > data->walltop_pixel && i < data->wallbottom_pixel)
		{
			data->texture_offsety = (int)(i - data->walltop_pixel)
				* ((float)TILE_SIZE / data->wallstrip_height);
			data->texture_color = get_texture_color(data,
					data->texture_offsetx, data->texture_offsety);
			my_mlx_pixel_put(data, rayId, i, data->texture_color);
		}
		else
			my_mlx_pixel_put(data, rayId, i, rgb_to_int(data->floor_color_rgb));
	}
}

void	render_column(t_data *data, int rayId,
	double distance, double ray_angle)
{
	data->correct_distance = distance * cos(ray_angle - data->player->angle);
	data->distance_proj_plane = (S_WIDTH / 2) / tan(FOV_ANGLE / 2);
	data->wallstrip_height = (TILE_SIZE / data->correct_distance)
		* data->distance_proj_plane;
	data->walltop_pixel = (S_HEIGHT / 2) - (data->wallstrip_height / 2);
	if (data->walltop_pixel < 0)
		data->walltop_pixel = 0;
	data->wallbottom_pixel = (S_HEIGHT / 2)
		+ (data->wallstrip_height / 2);
	if (data->wallbottom_pixel > S_HEIGHT)
		data->wallbottom_pixel = S_HEIGHT;
	data->texture_offsetx = (int)data->rays->wallhitx % TILE_SIZE;
	data->texture_offsety = (int)data->rays->wallhity % TILE_SIZE;
	if (data->rays->washitvertical)
		data->texture_offsetx = (int)data->rays->wallhity % TILE_SIZE;
	if (data->wallstrip_height >= S_HEIGHT)
		data->walltop_pixel -= (data->wallstrip_height - S_HEIGHT) / 2;
	render_textures(data, rayId);
}
